//
// Created by Matheus on 08/06/2026.
//

#ifndef VETOR_H
#define VETOR_H

#include "vertice.h"

typedef void* Vetor;

/* MÓDULO VETOR
Esse modulo visa guardar os vértices em um vetor que contém os vértices, que será manipulado através de void*. */

/// @brief Cria um vetor para armazenar os vértices.
/// @param tamanho É o número de vértices que existirão no programa, tamanho do vetor.
/// @return Retorna o vetor de vértices criado.
Vetor cria_vetor (int tamanho);

/// @brief Insere um vértice no vetor.
/// @param vetor É o ponteiro para o vetor de vértices.
/// @param v É um ponteiro que aponta para o vértice que será inserido no vetor.
void insere_vertice_vetor (Vetor vetor, Vertice v);

/// @brief Função que procura através do id único de cada vértice, o desejado.
/// @param vetor É o ponteiro para o vetor de vértices.
/// @param id É o id do vértice desejado.
/// @return Retorna o vértice desejado.
Vertice busca_vetor (Vetor vetor, int id);

/// @brief Libera toda a memória alocada pelo vetor de vértices, disponibilizando-a para uso.
/// @param vetor É o ponteiro para saber qual vetor terá a sua memória liberada.
void libera_vetor (Vetor vetor);

#endif
