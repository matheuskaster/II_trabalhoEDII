//
// Created by Matheus on 08/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/vetor.h"

typedef struct {
    Vertice* vertices;
    int tam_vetor;
} StrVetor;

Vetor cria_vetor (int tamanho) {
    StrVetor* vetor = (StrVetor*)malloc(sizeof(StrVetor));
    if (vetor == NULL) {
        printf("[ERRO] tentativa falha de alocar memória para o vetor.\n");
        exit (1);
    }
    vetor->vertices = (Vertice*)malloc(sizeof(Vertice)*tamanho);
    vetor->tam_vetor = tamanho;
    return vetor;
}

void insere_vetor (Vetor vetor, Vertice v) {
    StrVetor* vet = (StrVetor*) vetor;
    int i = get_id_vertice(v);
    vet->vertices[i] = v;
}

Vertice busca_vetor (Vetor vetor, int id) {
    StrVetor* vet = (StrVetor*) vetor;
    for (int i = 0; i < vet->tam_vetor; i++) {
        Vertice v = vet->vertices[i];
        if (get_id_vertice(v) == id) return v;
    }
    printf("[ERRO] tentativa de buscar, no vetor, um vértice inexistente");
    exit(1);
}

void libera_vetor (Vetor vetor) {
    StrVetor* vet = (StrVetor*) vetor;
    if (vet) {
        for (int i = 0 ; i < vet->tam_vetor; i++) {
            Vertice v = vet->vertices[i];
            libera_vertice(v);
        }
        free(vet->vertices);
        free(vet);
    }
}