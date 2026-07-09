//
// Created by Matheus on 09/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/fila_de_prioridade.h"

typedef struct {
    int id_vertice;
    double prioridade;
} StrItem;

typedef struct {
    StrItem* item;
    int* posicoes;
    int tamanho;
    int capacidade;
} StrFilaPrioridade;

// Troca dois elementos de lugar na fila e atualiza as posições
void troca_nos(StrFilaPrioridade* fila, int i, int j) {
    StrItem temp = fila->item[i];
    fila->item[i] = fila->item[j];
    fila->item[j] = temp;

    fila->posicoes[fila->item[i].id_vertice] = i;
    fila->posicoes[fila->item[j].id_vertice] = j;
}

// Corrige a fila de baixo para cima (quando inserimos algo ou diminuímos a prioridade)
void sobe_heap(StrFilaPrioridade* fila, int indice) {
    int pai = (indice - 1) / 2;

    // Enquanto não chegar na raiz e o filho for MENOR que o pai
    while (indice > 0 && fila->item[indice].prioridade < fila->item[pai].prioridade) {
        troca_nos(fila, indice, pai);
        indice = pai;
        pai = (indice - 1) / 2;
    }
}

// Corrige o heap de cima para baixo (usado ao extrair o mínimo)
void desce_heap(StrFilaPrioridade* fila, int indice) {
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    // Verifica se o filho da esquerda existe e é menor que o nó atual
    if (esquerda < fila->tamanho && fila->item[esquerda].prioridade < fila->item[menor].prioridade) {
        menor = esquerda;
    }
    // Verifica se o filho da direita existe e é menor que o menor encontrado
    if (direita < fila->tamanho && fila->item[direita].prioridade < fila->item[menor].prioridade) {
        menor = direita;
    }

    // Se o menor não for o nó atual, eles trocam de lugar e a correção continua descendo
    if (menor != indice) {
        troca_nos(fila, indice, menor);
        desce_heap(fila, menor);
    }
}

FilaPrioridade cria_fila_prioridade(int capacidade) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) malloc(sizeof(StrFilaPrioridade));
    if (fila == NULL) {
        printf("[ERRO] tentativa falha de alocar memória para a criação da fila de prioridade");
        exit(1);
    }
    fila->capacidade = capacidade;
    fila->tamanho = 0;

    fila->item = (StrItem*) malloc(capacidade * sizeof(StrItem));
    fila->posicoes = (int*) malloc(capacidade * sizeof(int));

    for (int i = 0; i < capacidade; i++) {
        fila->posicoes[i] = -1;
    }

    return fila;
}

int tam_fila_prioridade(FilaPrioridade f) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL) return 0;
    return fila->tamanho;
}

bool esta_vazia_fila_prioridade(FilaPrioridade f) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL) return true;
    return fila->tamanho == 0;
}

bool contem_fila_prioridade(FilaPrioridade f, int id_vertice) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL || id_vertice >= fila->capacidade || id_vertice < 0) return false;

    return fila->posicoes[id_vertice] != -1;
}

void insere_fila_prioridade(FilaPrioridade f, int id_vertice, double prioridade) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL || fila->tamanho == fila->capacidade || contem_fila_prioridade(f, id_vertice)) return;

    int i = fila->tamanho;
    fila->tamanho++;

    fila->item[i].id_vertice = id_vertice;
    fila->item[i].prioridade = prioridade;

    fila->posicoes[id_vertice] = i;

    sobe_heap(fila, i);
}

int extrai_minimo(FilaPrioridade f) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL || fila->tamanho == 0) return -1;

    StrItem raiz = fila->item[0];

    fila->posicoes[raiz.id_vertice] = -1;

    if (fila->tamanho > 1) {
        StrItem ultimo = fila->item[fila->tamanho - 1];
        fila->item[0] = ultimo;
        fila->posicoes[ultimo.id_vertice] = 0;
    }

    fila->tamanho--;

    if (fila->tamanho > 0) {
        desce_heap(fila, 0);
    }

    return raiz.id_vertice;
}

void diminui_prioridade(FilaPrioridade f, int id_vertice, double nova_prioridade) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila == NULL || !contem_fila_prioridade(f, id_vertice)) return;

    int indice = fila->posicoes[id_vertice];

    if (nova_prioridade > fila->item[indice].prioridade) return;

    fila->item[indice].prioridade = nova_prioridade;

    sobe_heap(fila, indice);
}

void libera_fila_prioridade(FilaPrioridade f) {
    StrFilaPrioridade* fila = (StrFilaPrioridade*) f;
    if (fila != NULL) {
        if (fila->item) free(fila->item);
        if (fila->posicoes) free(fila->posicoes);
        free(fila);
    }
}