//
// Created by Matheus on 25/05/2026.
//

#ifndef VIA_H
#define VIA_H
#include <stdio.h>
#include "grafo.h"

/* MODULO VIA
Esse modulo visa realizar a parte tudo o que precisa ser feito na leitura do arquivo .via. Recebe um arquivo com as
informacoes necessarias para a criacao de vertices e arestas, os vertices serao localizados em um vetor de vertices,
enquanto as arestas serão guardadas em um grafo.
*/

/// @param arq_via Ponteiro do tipo arquivo, para poder ler quais serão os vértices e arestas criados.
/// @return Retorna o ponteiro para o grafo criado e já preenchido pelas informações do arq_via.
Grafo via (FILE* arq_via);

#endif
