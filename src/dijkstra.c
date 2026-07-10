//
// Created by Matheus on 09/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h> // DBL_MAX infinito, do algoritmo
#include "../include/dijkstra.h"
#include "../include/fila_de_prioridade.h"
#include "../include/grafo.h"
#include "../include/mapa.h"

typedef struct {
    int* rota;
    int tamanho_rota;
    double custo_total;
    bool alcancavel;
    Grafo grafo;
} StrCaminhoMinimo;

CaminhoMinimo calcula_caminho_dijkstra(Grafo g, int id_origem, int id_destino, peso criterio) {
    int num_vertices = get_num_vertices(g);

    StrCaminhoMinimo* caminho = (StrCaminhoMinimo*) malloc(sizeof(StrCaminhoMinimo));
    if (caminho == NULL) {
        printf("[ERRO] tentativa falha de alocar memória para a criação do grafo.\n");
        exit(1);
    }
    caminho->grafo = g;
    caminho->alcancavel = false;
    caminho->custo_total = 0.0;
    caminho->tamanho_rota = 0;
    caminho->rota = NULL;

    double* distancias = (double*) malloc(num_vertices * sizeof(double));
    int* pais = (int*) malloc(num_vertices * sizeof(int));

    FilaPrioridade fila = cria_fila_prioridade(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        distancias[i] = DBL_MAX;
        pais[i] = -1;

        if (i == id_origem) {
            distancias[i] = 0.0;
            insere_fila_prioridade(fila, i, 0.0);
        } else {
            insere_fila_prioridade(fila, i, DBL_MAX);
        }
    }

    Mapa mapa = get_mapa_grafo(g);
    while (!esta_vazia_fila_prioridade(fila)) {

        int u = extrai_minimo(fila);

        if (u == id_destino || distancias[u] == DBL_MAX) {
            break;
        }

        Lista lista_arestas = adjacentes(g, u);

        if (lista_arestas != NULL) {
            percorrer_do_inicio_lista(lista_arestas);
            while (tem_proximo_lista(lista_arestas)) {

                Aresta aresta_atual = (Aresta) get_proximo_lista(lista_arestas);

                Vertice destino = get_vertice_j_aresta(aresta_atual);

                char* id_string = get_id_vertice(destino);

                int v = traduz_id(mapa, id_string);

                double peso_aresta = 0.0;
                if (criterio == DISTANCIA) {
                    peso_aresta = get_cmp_aresta(aresta_atual);
                }
                else if (criterio == TEMPO) {
                    peso_aresta = get_cmp_aresta(aresta_atual) / get_vm_aresta(aresta_atual);
                }

                if (distancias[u] + peso_aresta < distancias[v]) {
                    distancias[v] = distancias[u] + peso_aresta;
                    pais[v] = u;

                    diminui_prioridade(fila, v, distancias[v]);
                }
            }
        }
    }

    if (distancias[id_destino] != DBL_MAX) {
        caminho->alcancavel = true;
        caminho->custo_total = distancias[id_destino];

        int atual = id_destino;
        int contagem = 0;
        while (atual != -1) {
            contagem++;
            atual = pais[atual];
        }

        caminho->tamanho_rota = contagem;
        caminho->rota = (int*) malloc(contagem * sizeof(int));

        atual = id_destino;
        for (int i = contagem - 1; i >= 0; i--) {
            caminho->rota[i] = atual;
            atual = pais[atual];
        }
    }

    free(distancias);
    free(pais);
    libera_fila_prioridade(fila);

    return caminho;
}

bool caminho_eh_alcancavel(CaminhoMinimo caminho) {
    StrCaminhoMinimo* c = (StrCaminhoMinimo*) caminho;
    if (c == NULL) return false;
    return c->alcancavel;
}

double get_custo_caminho(CaminhoMinimo caminho) {
    StrCaminhoMinimo* c = (StrCaminhoMinimo*) caminho;
    if (c == NULL || !c->alcancavel) return -1.0;
    return c->custo_total;
}

int get_tamanho_caminho(CaminhoMinimo caminho) {
    StrCaminhoMinimo* c = (StrCaminhoMinimo*) caminho;
    if (c == NULL || !c->alcancavel) return 0;
    return c->tamanho_rota;
}

int get_vertice_caminho(CaminhoMinimo caminho, int indice) {
    StrCaminhoMinimo* c = (StrCaminhoMinimo*) caminho;

    if (c == NULL || !c->alcancavel || indice < 0 || indice >= c->tamanho_rota) {
        return -1;
    }

    int id_vertice_numerico = c->rota[indice];

    return id_vertice_numerico;
}

void libera_caminho_minimo(CaminhoMinimo caminho) {
    StrCaminhoMinimo* c = (StrCaminhoMinimo*) caminho;
    if (c != NULL) {
        if (c->rota != NULL) {
            free(c->rota);
        }
        free(c);
    }
}