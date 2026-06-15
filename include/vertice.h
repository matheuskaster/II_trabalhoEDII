//
// Created by Matheus on 01/06/2026.
//

#ifndef VERTICE_H
#define VERTICE_H

typedef void* Vertice;

/// @brief Cria um vértice com as coordenadas passados por parâmetro.
/// @param id É o identificador do vértice, único para cada vértice.
/// @param x É a coordenada no eixo 'x', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
/// @param y É a coordenada no eixo 'y', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
Vertice cria_vertice (int id, double x, double y);

/// @brief Define a string passada por parâmetro como o identificador o vértice.
/// @param id Número inteiro, identificador específico do vértice.
void set_id_vertice(Vertice v, int id);

/// @return Qual é o identificador específico do ponto passado por parâmetro.
int get_id_vertice(Vertice v);

/// @brief Altera o valor do 'x' do ponto.
/// @param x É a coordenada no eixo 'x', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
void set_x_vertice(Vertice v, double x);

/// @return Qual é a posição no eixo 'x' do vértice.
double get_x_vertice(Vertice v);

/// @brief Altera o valor do 'y' do ponto.
/// @param y É a coordenada no eixo 'y', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
void set_y_vertice(Vertice v, double y);

/// @return Qual é a posição no eixo 'y' do vértice.
double get_y_vertice(Vertice v);

/// @brief Libera toda a memória que estava reservada ao vértice, disponibilizando-a novamente para outro uso.
/// @param v É um ponteiro que aponta para o vértice que terá a sua memória liberada.
void libera_vertice (Vertice v);

#endif
