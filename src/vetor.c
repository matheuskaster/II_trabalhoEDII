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
    int id = get_id_vertice(v);
    vet->vertices[id - 1] = v; // porque começa do 1 e não do zero
}

Vertice busca_vetor (Vetor vetor, int id) {
    StrVetor* vet = (StrVetor*) vetor;
    if (id < 0 || id > vet->tam_vetor) {
        printf("[ERRO] tentativa de buscar, no vetor, um vértice inexistente");
        exit(1);
    }
    Vertice v = vet->vertices[id - 1]; // porque começa do 1 e não do zero
    return v;
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