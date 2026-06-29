//
// Created by Matheus on 22/06/2026.
//

#ifndef GRAFO_H
#define GRAFO_H

#include <stdbool.h>

#include "../include/aresta.h"
#include "../include/lista.h"

typedef void* Grafo;

/// @brief Cria um grafo sem arestas com a quantidade de vértices indicada por um inteiro passado por parâmetro.
/// @param tamanho Número inteiro que indica quantos vértices terá o grafo criado.
/// @return O ponteiro que aponta para o grafo.
Grafo cria_grafo(int tamanho);

/// @brief Verifica se ambos, os vértices i e j, pertencem ao conjunto de vértices, caso eles façam parte,
/// é adicionado uma aresta direcionada que os conecta, no sentido (i,j), ou seja, inicia no i e termina no j.
/// Caso contrário ela só retorna antes de fazer o procedimento.
void insere_aresta(Vertice i, Vertice j, Grafo g);

/// Verifica se a aresta (i,j) pertence ao grafo, se sim, essa aresta é acessada, e é alterada a sua informação.
/// Altera a velocidade média com que os carros que trafegam por essa rua
/// Caso contrário a função só retorna antes de fazer o procedimento.
void define_velocidade_media(Vertice i, Vertice j, Grafo g, double velocidade);

/// Verifica se a aresta (i,j) pertence ao grafo, se sim, ela deixa de fazer parte do conjunto de arestas do grafo.
/// Caso contrário a função só retorna antes de fazer o procedimento.
void remove_aresta(Vertice i, Vertice j, Grafo g);

/// Recebe dois vértices e verifica se existe uma aresta do grafo que os conecta, se sim retorna "true".
/// @return "true", se a aresta existe. "false", se ela não existe.
bool eh_adjacente(Vertice i, Vertice j, Grafo g);

/// Dado um vértice, é retornado a lista de adjacência.
/// @return O ponteiro para a lista.
Lista adjacentes(Vertice v, Grafo g);

#endif
