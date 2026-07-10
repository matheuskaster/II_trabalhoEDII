//
// Created by Matheus on 10/07/2026.
//

#ifndef COMPONENTES_H
#define COMPONENTES_H

#include "grafo.h"

typedef void* Componentes;

/* MÓDULO COMPONENTES (conexos)
Esse modulo visa montar um vetor de inteiros, com o mesmo tamanho do Vetor de vértices. O jeito que ele faz para "colorir"
o grafo é colocar o mesmo inteiro nas posições que são da mesma ilha. Ou seja, cada posição (índice) representa um vértice
no Vetor, de verdade, por isso quando dois índices do int* tem o mesmo número, esses dois vértices, estão conectados.
*/

/// @brief Executa a busca em profundidade, que depois de escolher um caminho, vai o mais profundo possível nesse caminho
/// e depois retorna para um caminho que não foi explorado.
Componentes calcula_componentes_conexos(Grafo g);

/// @brief Retorna a quantidade total de componentes, a quantidade de números diferentes é a quantidade de componentes.
int get_quantidade_componentes(Componentes cc);

/// @brief Retorna a "cor" do componente, a ilha que ele pertence, o número dele.
int get_vertice_componente(Componentes cc, int id_vertice_numerico);

/// @brief Libera toda a memória alocada para o cálculo dos componentes, disponibilizando-a novamente para uso.
void libera_componentes(Componentes cc);

#endif
