//
// Created by Matheus on 08/07/2026.
//

#ifndef MAPA_H
#define MAPA_H

typedef void* Mapa;

/// @brief Cria a estrutura do mapa que vai realizar o mapeamento das strings dos vértices, para a posição delas, como inteiro.
/// @param tamanho O número total de vértices (para alocar o vetor interno).
/// @return O ponteiro para a estrutura do mapa criado.
Mapa cria_mapa(int tamanho);

/// @brief Associa o id em string a um índice numérico. Deve ser usada durante a leitura do .via.
/// @param m Ponteiro para o mapa.
/// @param id String contendo o identificador do vértice (ex: "v1").
/// @param indice O número inteiro sequencial associado a esse vértice (gerado pelo seu contador).
void insere_mapa(Mapa m, char* id, int indice);

/// @brief Ordena internamente o dicionário usando qsort para preparar para a busca rápida.
/// Deve ser chamada UMA ÚNICA VEZ, logo após o programa terminar de ler todos os vértices do .via.
/// @param m Ponteiro para o mapa que será ordenado pelo qsort.
void ordena_mapa(Mapa m);

/// @brief Faz a busca binária (bsearch) extremamente rápida e retorna o índice inteiro.
/// @return O índice (0, 1, 2...) ou -1 caso o nome não exista.
/// @param m Ponteiro para o mapa.
/// @param id String do id do vértice.
int traduz_id(Mapa m, char* id);

/// @brief Libera toda a memória alocada para o mapa, disponibilizando-a novamente para uso.
/// @param m Ponteiro para o mapa que terá a sua memória liberada.
void libera_mapa(Mapa m);

#endif