//
// Created by Matheus on 22/06/2026.
//

#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

#include "../include/mapa.h"
#include "../include/vertice.h"
#include "../include/aresta.h"
#include "../include/lista.h"

typedef void* Grafo;

/// @brief Cria um grafo sem arestas com a quantidade de vértices indicada por um inteiro passado por parâmetro.
/// @param tamanho Número inteiro que indica quantos vértices terá o grafo criado.
/// @return O ponteiro que aponta para o grafo.
Grafo cria_grafo(int tamanho);

///@return O ponteiro para o mapa, que mapeia a posição dos vértices no vetor.
Mapa get_mapa_grafo(Grafo g);

/// @return Qual é a quantidade de vértices que o grafo possui.
int get_num_vertices(Grafo g);

/// @brief Função que adiciona o vértice, no vetor, que é parte da estrutura do grafo.
/// @param v É o ponteiro para o vértice que será adicionado ao grafo.
/// @param indice É a posição que o vértice será inserido no grafo.
void insere_vertice_grafo(Grafo g, Vertice v, int indice);

/// @brief Verifica se ambos, os vértices i e j, pertencem ao conjunto de vértices, caso eles façam parte,
/// é adicionado uma aresta direcionada que os conecta, no sentido (i,j), ou seja, inicia no i e termina no j.
/// Caso contrário ela só retorna antes de fazer o procedimento.
void insere_aresta_grafo(Grafo g, Aresta a, int indice_i);

/// Verifica se a aresta (i,j) pertence ao grafo, se sim, essa aresta é acessada, e é alterada a sua informação.
/// Altera a velocidade média com que os carros que trafegam por essa rua
/// Caso contrário a função só retorna antes de fazer o procedimento.
void define_velocidade_media(Grafo g, int indice_i, int indice_j, double velocidade);

/// Verifica se a aresta (i,j) pertence ao grafo, se sim, ela deixa de fazer parte do conjunto de arestas do grafo.
/// Caso contrário a função só retorna antes de fazer o procedimento.
void remove_aresta(Grafo g, int indice_i, int indice_j);

/// Recebe dois vértices e verifica se existe uma aresta do grafo que os conecta, se sim retorna "true".
/// @return "true", se a aresta existe. "false", se ela não existe.
bool eh_adjacente(Grafo g, int indice_i, int indice_j);

/// Dado um vértice, é retornado a lista de adjacência.
/// @return O ponteiro para a lista.
Lista adjacentes(Grafo g, int indice_vertice);

/// @brief Função que rebece o vértice de início e de fim de uma aresta.
/// @return Qual é a aresta que conecta esses vértices.
Aresta acha_aresta_pelos_indices(Grafo g, int u, int v);

/// @brief Libera toda a memória que estava reservada para o gravo, disponibilizando-a novamente para uso.
void libera_grafo(Grafo g);

#endif