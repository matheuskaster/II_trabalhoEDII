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

// Esimular o Grafo Não Direcionado internamente.
typedef struct no_adj {
    int v;
    double peso;
    struct no_adj* prox;
} NoAdj;

static void libera_adj_nd(NoAdj** adj_nd, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        NoAdj* atual = adj_nd[i];
        while (atual != NULL) {
            NoAdj* prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
    free(adj_nd);
}

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

    NoAdj** adj_nd = (NoAdj**) calloc(num_vertices, sizeof(NoAdj*));
    Mapa mapa = get_mapa_grafo(g);

    for (int u = 0; u < num_vertices; u++) {
        Lista lista_arestas = adjacentes(g, u);
        if (lista_arestas != NULL) {
            percorrer_do_inicio_lista(lista_arestas);
            while (tem_proximo_lista(lista_arestas)) {
                Aresta aresta_atual = (Aresta) get_proximo_lista(lista_arestas);

                int v = traduz_id(mapa, get_vertice_j_aresta(aresta_atual));
                double peso = get_cmp_aresta(aresta_atual);

                // Adiciona aresta de ida (u -> v)
                NoAdj* novo_ida = (NoAdj*) malloc(sizeof(NoAdj));
                novo_ida->v = v;
                novo_ida->peso = peso;
                novo_ida->prox = adj_nd[u];
                adj_nd[u] = novo_ida;

                // Adiciona aresta de volta (v -> u) garantindo o não-direcionamento
                NoAdj* novo_volta = (NoAdj*) malloc(sizeof(NoAdj));
                novo_volta->v = u;
                novo_volta->peso = peso;
                novo_volta->prox = adj_nd[v];
                adj_nd[v] = novo_volta;
            }
        }
    }

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

    while (!esta_vazia_fila_prioridade(fila)) {

        int u = extrai_minimo(fila);

        // Ao invés de calcular só uma ilha, ele as junta em um grafo só.
        if (custos[u] == DBL_MAX) {
            custos[u] = 0.0;
        }

        visitados[u] = true;

        NoAdj* atual = adj_nd[u];
        while (atual != NULL) {
            int v = atual->v;
            double peso_aresta = atual->peso;

            if (!visitados[v] && peso_aresta < custos[v]) {
                custos[v] = peso_aresta;
                arvore->pai[v] = u;

                diminui_prioridade(fila, v, custos[v]);
            }
            atual = atual->prox;
        }
    }
    free(custos);
    free(visitados);
    libera_fila_prioridade(fila);
    libera_adj_nd(adj_nd, num_vertices);

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