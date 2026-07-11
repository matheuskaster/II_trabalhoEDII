//
// Created by Matheus on 10/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h> // DBL_MAX, infinito

#include "../include/arvore_geradora.h"
#include "../include/fila_de_prioridade.h"
#include "../include/grafo.h"
#include "../include/mapa.h"

typedef struct {
    int num_vertices;
    int* pai;
} StrArvore;

Arvore calcula_arvore_geradora(Grafo g) {
    int num_vertices = get_num_vertices(g);

    StrArvore* arvore = (StrArvore*) malloc(sizeof(StrArvore));
    if (arvore == NULL) {
        printf("[ERRO] tentativa falha de alocar memoria para a criacao da arvore.\n");
        exit(1);
    }

    arvore->num_vertices = num_vertices;
    arvore->pai = (int*) malloc(num_vertices * sizeof(int));

    double* custos = (double*) malloc(num_vertices * sizeof(double));
    bool* visitados = (bool*) malloc(num_vertices * sizeof(bool));

    FilaPrioridade fila = cria_fila_prioridade(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        arvore->pai[i] = -1;
        custos[i] = DBL_MAX;
        visitados[i] = false;

        if (i == 0) {
            custos[i] = 0.0;
            insere_fila_prioridade(fila, i, 0.0);
        } else {
            insere_fila_prioridade(fila, i, DBL_MAX);
        }
    }

    Mapa mapa = get_mapa_grafo(g);

    while (!esta_vazia_fila_prioridade(fila)) {

        int u = extrai_minimo(fila);

        // Segurança, vê se existe uma ilha, que não faz parte do vértice arbitrário.
        if (custos[u] == DBL_MAX) {
            break;
        }

        visitados[u] = true;

        Lista lista_arestas = adjacentes(g, u);

        if (lista_arestas != NULL) {
            percorrer_do_inicio_lista(lista_arestas);
            while (tem_proximo_lista(lista_arestas)) {

                Aresta aresta_atual = (Aresta) get_proximo_lista(lista_arestas);

                char* id_string = get_vertice_j_aresta(aresta_atual);
                int v = traduz_id(mapa, id_string);

                double peso_aresta = get_cmp_aresta(aresta_atual);

                if (!visitados[v] && peso_aresta < custos[v]) {
                    custos[v] = peso_aresta;
                    arvore->pai[v] = u;

                    diminui_prioridade(fila, v, custos[v]);
                }
            }
        }
    }
    free(custos);
    free(visitados);
    libera_fila_prioridade(fila);

    return arvore;
}


int get_tamanho_arvore(Arvore a) {
    StrArvore* arvore = (StrArvore*) a;
    if (arvore == NULL) return 0;

    return arvore->num_vertices;
}

int get_pai_vertice_arvore(Arvore a, int indice) {
    StrArvore* arvore = (StrArvore*) a;

    if (arvore == NULL || indice < 0 || indice >= arvore->num_vertices) {
        return -1;
    }

    return arvore->pai[indice];
}

void libera_arvore_geradora(Arvore a) {
    StrArvore* arvore = (StrArvore*) a;
    if (arvore != NULL) {
        if (arvore->pai != NULL) {
            free(arvore->pai);
        }
        free(arvore);
    }
}