//
// Created by Matheus on 29/06/2026.
//

#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

typedef void* Lista;
typedef void* Elemento;

/// @brief Cria dinâmicamente uma lista vazia, sem elementos.
/// @return Retorna um ponteiro para a lista.
Lista cria_lista();

/// @brief O ponteiro que vai percorrer a lista, começará apontando para o início da fila.
/// @param l É um ponteiro que aponta para a lista l.
void percorrer_do_inicio_lista(Lista l);

/// @brief Verifica ainda tem algum elemento da lista para ser percorrido.
/// @param l É um ponteiro que aponta para a lista l.
/// @return Retorna um bool, true se tem outros elementos para percorrer, ou false, caso contrário.
bool tem_proximo_lista(Lista l);

/// @brief Se existir, entrega próximo elemento da lista desde a última vez que essa função foi chamada, sem de fato
/// remover da lista, só serve para observar quem está na lista.
/// @param l É um ponteiro que aponta para a lista l.
/// @return Retorna a geometria que deseja observar, para poder fazer algo, sem "marcar como concluído" na lista.
Elemento get_proximo_lista(Lista l);

/// @brief Verifica o tamanho da lista, a quantidade de elementos que ela possui.
/// @param l É o ponteiro que aponta para a lista.
/// @return Retorna qual é o tamanho da lista.
int tam_lista(Lista l);

/// @brief Insere um novo elemento no fim da lista.
/// @param l É o ponteiro que aponta para a lista.
/// @param e O elemento que será inserido na lista, podendo ser uma variável de qualquer tipo.
void insere_lista(Lista l, Elemento e);

/// @brief Ao receber uma forma genérica, a função a encontra e a remove da lista.
/// @param l É o ponteiro que aponta para a lista.
/// @param e É o ponteiro que aponta para a elemento que será removida da lista.
void remove_elemento_especifico_lista(Lista l, Elemento e);

/// @brief Remove o elemento do início da lista
/// @param l É o ponteiro que aponta para a lista.
Elemento remove_lista (Lista l);

/// @brief Libera a memória alocada para a lista.
/// @param l É o ponteiro que aponta para a lista.
void libera_lista(Lista l);

#endif
