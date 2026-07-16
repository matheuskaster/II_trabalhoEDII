//
// Created by Matheus on 25/05/2026.
//

#ifndef QRY_H
#define QRY_H
#include <stdio.h>
#include "quadra.h"
#include "hash.h"
#include "grafo.h"

/// @brief É uma função feita para poder ler o arquivo de entrada qry e chamar funções que irão executar os comandos.
/// @param quadras É o gerenciador que tem acesso e controle ao hashfile, referente às quadras, do programa.
/// @param grafo É o grafo com acesso às esquinas e ruas da cidade.
/// @param file_qry É o arquivo de entrada do tipo .qry.
/// @param file_txt É o arquivo de saída, com o relatório final, depois de ter sido processado pelo qry.
/// @param file_svg É o arquivo de saída, com as ilustrações, depois de ter sido processado pelo qry.
/// @param cq É o ponteiro que aponta para a estrutura que possue todas as cores das quadras.
void qry (Gerenciador quadras, Grafo grafo, FILE* file_qry, FILE* file_txt, FILE* file_svg, Cores cq);

#endif