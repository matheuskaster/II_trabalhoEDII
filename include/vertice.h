//
// Created by Matheus on 01/06/2026.
//

#ifndef VERTICE_H
#define VERTICE_H

typedef void* Vertice;

/// @brief Cria um vértice com as coordenadas passados por parâmetro.
/// @param x É a coordenada no eixo 'x', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
/// @param y É a coordenada no eixo 'y', em que o vértice do segmento de rua se encontrará, no plano cartesiano.
Vertice cria_vertice (char* id, double x, double y);

/// @brief Define a string passada por parâmetro como o identificador o vértice.
/// @param id É o ponteiro para a string identificadora específico do vértice.
void set_id_vertice(Vertice v, char* id);

/// @return Qual é o identificador específico do ponto passado por parâmetro.
char* get_id_vertice(Vertice v);

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

#endif
