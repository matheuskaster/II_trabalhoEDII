//
// Created by Matheus on 09/07/2026.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdbool.h>
#include "../include/grafo.h"

typedef void* CaminhoMinimo;

/// @brief Calcula a rota mais rápida ou curta, a de menor peso, entre dois vértices.
/// @param g O ponteiro para o grafo.
/// @param id_origem O índice numérico do vértice de origem.
/// @param id_destino O índice numérico do vértice de destino.
/// @return O ponteiro para o caminho, já instanciado.
CaminhoMinimo calcula_caminho_dijkstra(Grafo g, int id_origem, int id_destino);

/// @brief Verifica se foi possível achar um caminho até o destino.
bool caminho_eh_alcancavel(CaminhoMinimo c);

/// @brief Retorna o custo/tempo total do trajeto.
double get_custo_caminho(CaminhoMinimo c);

/// @brief Retorna a quantidade de cruzamentos (vértices) que formam a rota.
int get_tamanho_caminho(CaminhoMinimo c);

/// @brief Retorna o id do vértice na rota.
char* get_vertice_caminho(CaminhoMinimo c, int indice);

/// @brief Libera a memória alocada para que retorna o menor caminho, disponibilizando-a novamente para uso.
void libera_caminho_minimo(CaminhoMinimo c);

#endif