//
// Created by Matheus on 14/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#include "../include/mobilidade.h"
#include "../include/hash.h"
#include "../include/quadra.h"
#include "../include/vetor.h"
#include "../include/vertice.h"
#include "../include/aresta.h"
#include "../include/grafo.h"
#include "../include/registrador.h"
#include "../include/lista.h"
#include "../include/arvore_geradora.h"
#include "../include/dijkstra.h"
#include "../include/svg.h"
#include "../include/txt.h"

static bool ponto_dentro_retangulo(double px, double py, double x, double y, double w, double h) {
    return (px >= x && px <= x + w && py >= y && py <= y + h);
}

static int encontra_vertice_mais_proximo(Grafo g, double target_x, double target_y) {
    int num_vertices = get_num_vertices(g);
    int indice_mais_proximo = -1;
    double min_dist = DBL_MAX;

    for (int i = 0; i < num_vertices; i++) {
        Vertice v = busca_vertice_vetor(g, i);
        double x = get_x_vertice(v);
        double y = get_y_vertice(v);

        double dx = x - target_x;
        double dy = y - target_y;
        double dist = sqrt(dx * dx + dy * dy);

        if (dist < min_dist) {
            min_dist = dist;
            indice_mais_proximo = i;
        }
    }
    return indice_mais_proximo;
}

void o(Gerenciador quadras, Registradores r, char* reg, char* cep, char face, int num, FILE* file_svg, FILE* file_txt) {
    Registro reg_quadra = busca_registro(quadras, cep);
    char* dados_quadra = get_dados_registro(reg_quadra);
    Quadra q = reconstroi_quadra(cep, dados_quadra);

    double x = get_x_quadra(q);
    double y = get_y_quadra(q);
    double w = get_w_quadra(q);
    double h = get_h_quadra(q);

    double px = x;
    double py = y;

    switch (face) {
        case 'N': case 'n': px = x + num; py = y + h; break;
        case 'S': case 's': px = x + num; py = y;       break;
        case 'L': case 'l': px = x + w; py = y + num; break;
        case 'O': case 'o': px = x;       py = y + num; break;
        default: exit(1);
    }
    insere_registrador(r, reg, px, py);

    reporta_coordenada_txt(file_txt, reg, cep, face, num, px, py);
    desenha_linha_registrador_svg(file_svg, px, py, reg);
    libera_quadra(q);
}

void mvm(Grafo g, double v, double x, double y, double w, double h) {
    int num_vertices = get_num_vertices(g);
    Mapa mapa = get_mapa_grafo(g);

    for (int u = 0; u < num_vertices; u++) {
        Lista adj = adjacentes(g, u);
        if (adj == NULL) continue;

        percorrer_do_inicio_lista(adj);
        while (tem_proximo_lista(adj)) {
            Aresta a = (Aresta) get_proximo_lista(adj);
            int dest_index = traduz_id(mapa, get_vertice_j_aresta(a));

            Vertice v_origem = busca_vertice_vetor(g, u);
            Vertice v_destino = busca_vertice_vetor(g, dest_index);

            double ox = get_x_vertice(v_origem);
            double oy = get_y_vertice(v_origem);
            double dx = get_x_vertice(v_destino);
            double dy = get_y_vertice(v_destino);

            if (ponto_dentro_retangulo(ox, oy, x, y, w, h) && ponto_dentro_retangulo(dx, dy, x, y, w, h)) {
                set_vm_aresta(a, v);
            }
        }
    }
}

void regs(Grafo g, double vl, FILE* file_svg, FILE* file_txt) {
    int num_vertices = get_num_vertices(g);
    Mapa mapa = get_mapa_grafo(g);
    bool* visitados = (bool*) calloc(num_vertices, sizeof(bool));
    int componentes_cont = 0;

    for (int i = 0; i < num_vertices; i++) {
        if (!visitados[i]) {
            double min_x = DBL_MAX, max_x = -DBL_MAX;
            double min_y = DBL_MAX, max_y = -DBL_MAX;
            bool componente_valida = false;

            int* fila = (int*) malloc(num_vertices * sizeof(int));
            int inicio = 0, fim = 0;

            fila[fim++] = i;
            visitados[i] = true;

            while (inicio < fim) {
                int u = fila[inicio++];
                Vertice vert = busca_vertice_vetor(g, u);
                double ux = get_x_vertice(vert);
                double uy = get_y_vertice(vert);

                if (ux < min_x) min_x = ux;
                if (ux > max_x) max_x = ux;
                if (uy < min_y) min_y = uy;
                if (uy > max_y) max_y = uy;

                Lista adj = adjacentes(g, u);
                if (adj != NULL) {
                    percorrer_do_inicio_lista(adj);
                    while (tem_proximo_lista(adj)) {
                        Aresta a = (Aresta) get_proximo_lista(adj);
                        double velocidade = get_vm_aresta(a);

                        if (velocidade < vl) {
                            componente_valida = true;
                            int dest = traduz_id(mapa, get_vertice_j_aresta(a));
                            if (!visitados[dest]) {
                                visitados[dest] = true;
                                fila[fim++] = dest;
                            }
                        }
                    }
                }
            }
            free(fila);

            if (componente_valida) {
                // código para gerar uma cor diferente toda a vez
                char cor_hex[8];
                int valor_cor = (componentes_cont * 0x37A9F1) % 0xFFFFFF;
                sprintf(cor_hex, "#%06X", valor_cor);
                desenha_bounding_box_svg(file_svg, min_x, min_y, max_x - min_x, max_y - min_y, cor_hex);
                componentes_cont++;
            }
        }
    }
    free(visitados);
    reporta_qtd_componentes_txt(file_txt, componentes_cont, vl);
}

void expande(Grafo g, double vl, FILE* file_svg) {
    Arvore arvore_geradora_minima = calcula_arvore_geradora(g);
    int num_vertices = get_tamanho_arvore(arvore_geradora_minima);

    for (int i = 0; i < num_vertices; i++) {
        int pai = get_pai_vertice_arvore(arvore_geradora_minima, i);
        if (pai != -1) {
            // Checa a via original de ambos os lados (já que o grafo é direcionado)
            Aresta e_ida = acha_aresta_pelos_indices(g, pai, i);
            Aresta e_volta = acha_aresta_pelos_indices(g, i, pai);

            Aresta a = (e_ida != NULL) ? e_ida : e_volta;
            if (a != NULL) {
                double vm = get_vm_aresta(a);
                if (vm < vl) {
                    if (e_ida != NULL)   set_vm_aresta(e_ida, vm * 1.5);
                    if (e_volta != NULL) set_vm_aresta(e_volta, vm * 1.5);

                    Vertice v_pai = busca_vertice_vetor(g, pai);
                    Vertice v_filho = busca_vertice_vetor(g, i);

                    desenha_aresta_arvore_svg(file_svg, get_x_vertice(v_pai), get_y_vertice(v_pai), get_x_vertice(v_filho), get_y_vertice(v_filho));
                }
            }
        }
    }
    libera_arvore_geradora(arvore_geradora_minima);
}

void p(Grafo g, Registradores r, char* reg1, char* reg2, char* cc, char* cr, FILE* file_svg, FILE* file_txt) {
    double x1, y1, x2, y2;

    int u_origem = encontra_vertice_mais_proximo(g, x1, y1);
    int u_destino = encontra_vertice_mais_proximo(g, x2, y2);

    CaminhoMinimo cm_curto  = calcula_caminho_dijkstra(g, u_origem, u_destino, DISTANCIA);
    CaminhoMinimo cm_rapido = calcula_caminho_dijkstra(g, u_origem, u_destino, TEMPO);

    if (!caminho_eh_alcancavel(cm_curto)) {
        reporta_destino_inacessivel_txt(file_txt, reg1, reg2);
        libera_caminho_minimo(cm_curto);
        libera_caminho_minimo(cm_rapido);
        return;
    }

    reporta_descricao_caminho_txt(file_txt, g, cm_curto, "mais curto");
    reporta_descricao_caminho_txt(file_txt, g, cm_rapido, "mais rápido");

    desenha_caminho_svg(file_svg, g, cm_curto, cc);
    desenha_caminho_svg(file_svg, g, cm_rapido, cr);

    Vertice v_ini = busca_vertice_vetor(g, u_origem);
    Vertice v_fim = busca_vertice_vetor(g, u_destino);
    desenha_placa_svg(file_svg, get_x_vertice(v_ini), get_y_vertice(v_ini), 'I', "green");
    desenha_placa_svg(file_svg, get_x_vertice(v_fim), get_y_vertice(v_fim), 'F', "red");

    libera_caminho_minimo(cm_curto);
    libera_caminho_minimo(cm_rapido);
}