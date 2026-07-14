//
// Created by Matheus on 14/07/2026.
//

#ifndef TXT_H
#define TXT_H
#include <stdio.h>

#include "grafo.h"
#include "dijkstra.h"

/// @brief Reporta a coordenada relativa ao endereço.
void reporta_coordenada_txt(FILE* file_txt, char* reg, char* cep, char face, int num, double x, double y);

/// @brief Reporta o número de componentes conexos.
void reporta_qtd_componentes_txt(FILE* file_txt, int qtd, double vl);

/// @brief Reporta caso o destino seja inacessível.
void reporta_destino_inacessivel_txt(FILE* file_txt, char* reg1, char* reg2);

/// @brief Reporta a descrição textual do trajeto.
void reporta_descricao_caminho_txt(FILE* file_txt, Grafo g, Mapa mapa, CaminhoMinimo cm, char* tipo);

#endif
