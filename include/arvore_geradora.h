//
// Created by Matheus on 10/07/2026.
//

// Vídeo utilizado para melhor compreensão:
// https://www.youtube.com/watch?v=5M7bOXrn54A

#ifndef ARVORE_GERADORA_H
#define ARVORE_GERADORA_H

#include "grafo.h"


typedef void* Arvore;

/* MÓDULO ÁRVORE GERADORA MÍNIMA
Módulo que calcula o melhor jeito de conectar todos os vértices do grafo, com o menor custo.
Escolhido o algoritmo de Prim, pois é mostrado no slide do professor que é parecido com o Dikstra, que era obrigatório.
Já que ambos utilizam pais, custos e visitados. Caso hajam ilhas desconexas, ele ignora e pega o subgrafo que permite
chegar em todos os vértices do grafo (cidade).
Vou simular um grafo não direcionado, fazendo ele duplamente direcionado.
Resumo: Esse algoritmo começa por um vértice arbitrário, e verifica quem é a aresta de menor peso saindo de um vértice
pertencente. Continua até conectar todos os vértices, sempre observando quem é a de menor peso, que mantém conectada e
que não forma um ciclo. Construindo o melhor subgrafo (árvore geradora mínima).
*/

/// @brief Executa o algoritmo de Prim para encontrar a árvore geradora mínima.
/// @param g O ponteiro para a árvore.
/// @return Os índices dos vértices, que conectados formam todas as arestas pertencentes.
Arvore calcula_arvore_geradora(Grafo g);

/// @brief Retorna a quantidade total de vértices na árvore.
/// @param a O ponteiro para a árvore.
/// @return O número de vértices.
int get_tamanho_arvore(Arvore a);

/// @brief Recupera quem é o "pai" de um vértice específico dentro da árvore geradora.
/// Como a árvore é devolvida em formato de mapa de pais, se o pai de B é A,
/// significa que a aresta (A, B) faz parte das ruas candidatas a ser alargada.
/// @param a O ponteiro para a árvore.
/// @param indice O índice no vétor de vértices
/// @return O índice do pai. (-1 se o vértice for a raiz).
int get_pai_vertice_arvore(Arvore a, int indice);

/// @brief Libera toda a memória que tinha sido reservada para a árvore, disponibilizando-a novamente para uso.
/// @param a O ponteiro para a árvore.
void libera_arvore_geradora(Arvore a);

#endif