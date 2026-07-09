//
// Created by Matheus on 09/07/2026.
//

#ifndef FILA_DE_PRIORIDADE_H
#define FILA_DE_PRIORIDADE_H

#include <stdbool.h>

typedef void* FilaPrioridade;

/// @brief Cria uma fila de prioridade com uma capacidade máxima, sendo a quantidade de vértices.
/// @param capacidade Geralmente o número total de vértices do seu grafo.
FilaPrioridade cria_fila_prioridade(int capacidade);

/// @brief Retorna a quantidade atual de elementos na fila.
int tam_fila_prioridade(FilaPrioridade f);

/// @brief Verifica se a fila está vazia.
bool esta_vazia_fila_prioridade(FilaPrioridade f);

/// @brief Insere um vértice na fila associando-o a um peso (prioridade).
/// @param f O ponteiro para a fila de prioridade.
/// @param id_vertice O índice numérico do vértice.
/// @param prioridade O custo/distância inicial até ele.
void insere_fila_prioridade(FilaPrioridade f, int id_vertice, double prioridade);

/// @brief Remove e retorna o vértice que possui a MENOR prioridade (o mais perto/rápido).
/// @return O índice inteiro do vértice extraído.
int extrai_minimo(FilaPrioridade f);

/// @brief Atualiza a prioridade de um vértice para um valor MENOR do que o atual.
/// @param id_vertice O vértice que receberá o "desconto" na distância.
/// @param nova_prioridade O novo valor de custo (deve ser menor que o anterior).
void diminui_prioridade(FilaPrioridade f, int id_vertice, double nova_prioridade);

/// @brief Libera toda a memória alocada para a estrutura da fila.
void libera_fila_prioridade(FilaPrioridade f);

#endif