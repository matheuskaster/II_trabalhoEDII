//
// Created by Matheus on 10/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/componentes.h"
#include "../include/grafo.h"
#include "../include/mapa.h"

typedef struct {
    int* vetor_componentes;
    int quantidade_componentes;
    int num_vertices;
} StrComponentes;


// DFS - Busca em Profundidade
void dfs_visita(Grafo g, int u, int cor, int* vetor_componentes, Mapa mapa) {

    if (vetor_componentes == NULL) {
        return;
    }
    vetor_componentes[u] = cor;

    Lista lista_arestas = adjacentes(g, u);

    if (lista_arestas != NULL) {
        percorrer_do_inicio_lista(lista_arestas);

        while (tem_proximo_lista(lista_arestas)) {
            Aresta aresta_atual = (Aresta) get_proximo_lista(lista_arestas);

            char* id_string = get_vertice_j_aresta(aresta_atual);
            int v = traduz_id(mapa, id_string);

            // Se for um vértice válido, no fim da aresta, que não foi visitado (marcado com -1)
            if (v != -1 && vetor_componentes[v] == -1) {
                // pinta vizinho recursivamente
                dfs_visita(g, v, cor, vetor_componentes, mapa);
            }
        }
    }
}

Componentes calcula_componentes_conexos(Grafo g) {
    int num_vertices = get_num_vertices(g);

    StrComponentes* cc = (StrComponentes*) malloc(sizeof(StrComponentes));
    if (cc == NULL) {
        printf("[ERRO] Falha ao alocar memória para os componentes conexos.\n");
        exit(1);
    }

    cc->num_vertices = num_vertices;
    cc->quantidade_componentes = 0;
    cc->vetor_componentes = (int*) malloc(num_vertices * sizeof(int));
    if (cc->vetor_componentes == NULL) {
        printf("[ERRO] Falha ao alocar memória para o vetor com as cores dos componentes conexos.\n");
        exit(1);
    }

    for (int i = 0; i < num_vertices; i++) {
        cc->vetor_componentes[i] = -1;
    }

    Mapa mapa = get_mapa_grafo(g);

    for (int i = 0; i < num_vertices; i++) {

        if (cc->vetor_componentes[i] == -1) {

            dfs_visita(g, i, cc->quantidade_componentes, cc->vetor_componentes, mapa);

            cc->quantidade_componentes++;
        }
    }

    return cc;
}

int get_quantidade_componentes(Componentes cc) {
    StrComponentes* c = (StrComponentes*) cc;
    if (c == NULL) return 0;

    return c->quantidade_componentes;
}

int get_vertice_componente(Componentes cc, int indice_vertice) {
    StrComponentes* c = (StrComponentes*) cc;

    if (c == NULL || indice_vertice < 0 || indice_vertice >= c->num_vertices) {
        return -1;
    }

    return c->vetor_componentes[indice_vertice];
}

void libera_componentes(Componentes cc) {
    StrComponentes* c = (StrComponentes*) cc;
    if (c != NULL) {
        if (c->vetor_componentes != NULL) {
            free(c->vetor_componentes);
        }
        free(c);
    }
}