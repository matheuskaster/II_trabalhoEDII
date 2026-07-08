//
// Created by Matheus on 08/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/mapa.h"

typedef struct {
    char id[32];
    int indice;
} StrElemento;

typedef struct {
    int tamanho;
    StrElemento* elementos;
} StrMapa;

int compara_elementos(const void* a, const void* b) {
    StrElemento* A = (StrElemento*) a;
    StrElemento* B = (StrElemento*) b;
    return strcmp(A->id, B->id);
}

Mapa cria_mapa(int tamanho) {
    StrMapa* m = (StrMapa*) malloc(sizeof(StrMapa));
    if (m == NULL) {
        printf("[ERRO] Falha ao alocar memória para o Mapa.\n");
        exit(1);
    }

    m->elementos = (StrElemento*) malloc(tamanho * sizeof(StrElemento));
    if (m->elementos == NULL) {
        printf("[ERRO] Falha ao alocar memória para o vetor dos elementos do Mapa.\n");
        exit(1);
    }
    return (Mapa) m;
}


void insere_mapa(Mapa m, char* id, int contador) {
    StrMapa* mapa = (StrMapa*) m;

    strcpy(mapa->elementos[contador].id, id);
    mapa->elementos[contador].indice = contador;
}

void ordena_mapa(Mapa m) {
    StrMapa* mapa = (StrMapa*) m;
    qsort(mapa->elementos, mapa->tamanho, sizeof(StrElemento), compara_elementos);
}

int traduz_id(Mapa m, char* id) {
    StrMapa* mapa = (StrMapa*) m;

    StrElemento chave_busca;
    strcpy(chave_busca.id, id);

    StrElemento* resultado = (StrElemento*) bsearch(
        &chave_busca,
        mapa->elementos,
        mapa->tamanho,
        sizeof(StrElemento),
        compara_elementos
    );

    if (resultado != NULL) {
        return resultado->indice;
    }

    return -1;
}

void libera_mapa(Mapa m) {
    StrMapa* mapa = (StrMapa*) m;
    if (mapa != NULL) {
        free(mapa->elementos);
        free(mapa);
    }
}