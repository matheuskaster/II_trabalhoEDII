//
// Created by Matheus on 29/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"
#include "../include/aresta.h"

typedef struct StrElemento {
    Aresta chave;
    struct StrElemento *prox;
} StrElemento;

typedef struct StrElemento* pont;

typedef struct {
    int tam;
    pont inicio;
    pont fim;
    pont percorre;
} StrLista;

Lista cria_lista () {
    StrLista* l = (StrLista*)malloc(sizeof(StrLista));
    if (l == NULL) {
        printf("[ERRO] não foi possível alocar memória para criar lista. \n");
        exit(1);
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->percorre = NULL;
    l->tam = 0;
    return ((StrLista*)l);
}

void percorrer_do_inicio_lista (Lista l) {
    ((StrLista*)l)->percorre = ((StrLista*)l)->inicio;
}

bool tem_proximo_lista (Lista l) {
    if (((StrLista*)l)->percorre != NULL) return true;
    return false;
}

Elemento get_proximo_lista (Lista lis) {
    StrLista* l = (StrLista*)lis;
    if (l->percorre == NULL) {
        printf("[ERRO] Não tem um próximo elemento na lista.\n");
        exit(1);
    }
    Aresta proximo = l->percorre->chave;
    l->percorre = l->percorre->prox;
    return proximo;
}

int tam_lista (Lista l) {
    return ((StrLista*)l)->tam;
}

void insere_lista (Lista lis, Aresta a) {
    StrLista* l = (StrLista*)lis;
    StrElemento* novo = (StrElemento*)malloc(sizeof(StrElemento));
    if (novo == NULL) {
        printf("[ERRO] não foi possível alocar memória para inserir um novo elemento na lista. \n");
        exit(1);
    }
    novo->chave = a;
    novo->prox = NULL;

    if (l->inicio == NULL) {
            l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }

    l->fim = novo;
    l->tam++;
}

void remove_elemento_especifico_lista(Lista lis, Aresta a) {
    StrLista* l = (StrLista*)lis;
    if (l->inicio == NULL) return;
    pont ant = NULL;
    pont atual = l->inicio;
    while (atual != NULL && atual->chave != a) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;
    if (ant == NULL) {
        l->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    if (atual == l->fim) {
        l->fim = ant;
    }

    if (l->percorre == atual) {
        l->percorre = atual->prox;
    }
    free(atual);
    l->tam--;
}

Elemento remove_lista (Lista lis) {
    StrLista* l = (StrLista*)lis;
    if (l->inicio == NULL) {
        printf("[ERRO] Tentativa falha de retornar um elemento da lista.\n");
        exit (1);
    }
    pont atual = l->inicio;

    if (l->inicio == NULL) {
        printf("Não foi possível encontrar o elemento desejado da lista.\n");
        return NULL;
    }

    l->inicio = atual->prox;
    Aresta chave = atual->chave;
    free(atual);

    l->tam--;
    return chave;
}

void libera_lista (Lista l) {
    if (l == NULL) {
        printf("[ERRO] Falha na tentativa de liberar a lista, pois ela é nula. \n");
        return;
    }
    pont atual = ((StrLista*)l)->inicio;
    while (atual != NULL) {
        pont proximo = atual->prox;

        if (atual->chave != NULL) {
            libera_aresta (atual->chave);
        }
        free(atual);
        atual = proximo;
    }
    free(l);
}