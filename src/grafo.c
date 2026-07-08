//
// Created by Matheus on 22/06/2026.
//

# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <string.h>
# include "../include/grafo.h"
# include "../include/vetor.h"

typedef struct {
    Vetor vertices;
    Lista* listas_adjacencia;
    int num_vertices;
} StrGrafo;

Grafo cria_grafo(int tamanho) {
    StrGrafo* g = (StrGrafo*) malloc(sizeof(StrGrafo));
    if (g == NULL) {
        printf("[ERRO] tentativa falha de alocar memória para a criação do grafo.\n");
        exit(1);
    }
    g->num_vertices = tamanho;

    g->vertices = cria_vetor(tamanho);
    if (g->vertices == NULL) {
        printf("[ERRO] falha ao criar o vetor de vértices, do grafo. \n");
        exit(1);
    }

    g->listas_adjacencia = (Lista*) malloc(tamanho * sizeof(Lista));
    for(int i = 0; i < tamanho; i++) {
        g->listas_adjacencia[i] = cria_lista();
    }
    return g;
}

void insere_vertice_grafo(Grafo g, Vertice v, int indice) {
    StrGrafo* grafo = (StrGrafo*) g;
    insere_vertice_vetor(grafo->vertices, v, indice);
}

void insere_aresta_grafo(Grafo g, Aresta a, int indice_origem) {
    StrGrafo* grafo = (StrGrafo*) g;

    if (indice_origem >= 0 && indice_origem < grafo->num_vertices) {
        insere_lista(grafo->listas_adjacencia[indice_origem], a);
    }
}

void define_velocidade_media(Grafo g, int indice_origem, int indice_destino, double velocidade) {
    StrGrafo* grafo = (StrGrafo*) g;
    Lista ruas_da_origem = grafo->listas_adjacencia[indice_origem];
    Vertice vertice_destino_procurado = busca_vertice_vetor(grafo->vertices, indice_destino);

    percorrer_do_inicio_lista(ruas_da_origem);
    while (tem_proximo_lista(ruas_da_origem)) {
        Aresta rua = get_proximo_lista(ruas_da_origem);

        if (get_vertice_j_aresta(rua) == get_id_vertice(vertice_destino_procurado) ) {
            set_vm_aresta(rua, velocidade);
            break;
        }
    }
}

bool eh_adjacente(Grafo g, int indice_origem, int indice_destino) {
    StrGrafo* grafo = (StrGrafo*) g;
    Lista ruas_da_origem = grafo->listas_adjacencia[indice_origem];
    Vertice vertice_destino_procurado = busca_vertice_vetor(grafo->vertices, indice_destino);

    percorrer_do_inicio_lista(ruas_da_origem);
    while (tem_proximo_lista(ruas_da_origem)) {
        Aresta rua = get_proximo_lista(ruas_da_origem);

        if (get_vertice_j_aresta(rua) == get_id_vertice(vertice_destino_procurado) ) {
            return true;
        }
    }

    return false;
}

void remove_aresta(Grafo g, int indice_origem, int indice_destino) {
    StrGrafo* grafo = (StrGrafo*) g;
    Lista ruas_da_origem = grafo->listas_adjacencia[indice_origem];
    Vertice vertice_destino_procurado = busca_vertice_vetor(grafo->vertices, indice_destino);

    percorrer_do_inicio_lista(ruas_da_origem);
    while (tem_proximo_lista(ruas_da_origem)) {
        Aresta rua = get_proximo_lista(ruas_da_origem);

        if (get_vertice_j_aresta(rua) == get_id_vertice(vertice_destino_procurado) ) {
            remove_elemento_especifico_lista(ruas_da_origem, rua);
            libera_aresta(rua);
            break;
        }
    }
}

Lista adjacentes(Grafo g, int indice_vertice) {
    StrGrafo* grafo = (StrGrafo*) g;
    if (indice_vertice >= 0 && indice_vertice < grafo->num_vertices) {
        return grafo->listas_adjacencia[indice_vertice];
    }
    return NULL;
}

void libera_grafo(Grafo g) {
    StrGrafo* grafo = (StrGrafo*) g;
    if (grafo == NULL) return;

    libera_vetor(grafo->vertices);

    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->listas_adjacencia[i] != NULL) {
            libera_lista(grafo->listas_adjacencia[i]);
        }
    }
    free(grafo->listas_adjacencia);
    free(grafo);
}