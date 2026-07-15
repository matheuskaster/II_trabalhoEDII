//
// Created by Matheus on 14/07/2026.
//

#ifndef MOBILIDADE_H
#define MOBILIDADE_H

#include <stdio.h>
#include "../include/grafo.h"
#include "hash.h"
#include "registrador.h"

/* MÓDULO MOBILIDADE
Esse módulo foi criado com a intenção de deixar o módulo que cuida e controla as ações descritas no arquivo do qry
mais organizado. Ou seja, o qry faz so a leitura do que e o comando que o programa deseja executar, mas para deixar
ambos, tanto esse quanto o outro, mais compactos e legíveis. Aqui estará a implementação do que vai acontecer após
cada um dos comandos descritos no documento do projeto.
*/

/// @brief Armazena a posição geográfica do endereço cep/face/num, no registrador reg.
/// SVG: linha pontilhada vermelha mostrando a posição do endereço e o número do registrador na outra extremidade dela.
/// TXT: reporta a coordenada relativa ao endereço.
void o(Gerenciador quadras, Registradores r, char* reg, char* cep, char face, int num, FILE* file_svg, FILE* file_txt);

/// @brief Atualiza a velocidade média das arestas dentro da região (x,y,w,h) para v.
void mvm(Grafo g, double v, double x, double y, double w, double h);

/// @brief Considera como insuficiente os trechos com velocidade média inferior a vl. Calcula os componentes conexos.
/// TXT: reporta o número de componentes conexos.
/// SVG: Calcula as bounding boxes de cada componente conexo e desenha os respectivos retângulos com cores diferentes.
void regs(Grafo g, double vl, FILE* file_svg, FILE* file_txt);

/// @brief Calcula a árvore geradora mínima, seleciona apenas as arestas com velocidade média inferior a vl,
/// aumenta em 50% a velocidade média das arestas selecionadas.
/// SVG: pinta as arestas selecionadas com linha grossa e vermelha.
void expande(Grafo g, double vl, FILE* file_svg);

/// @brief Determina o melhor trajeto entre a origem (reg1) e o destino (reg2).
/// Desenha os percursos (mais curto, mais rápido) com as cores cc e cr, respectivamente.
/// TXT: descrição textual do percurso. Caso destino inacessível, reporta.
/// SVG: mostra os percursos pintados e animados. Marca os extremos do percurso com “placas” com as letras I e F.
void p(Grafo g, char* reg1, char* reg2, char* cc, char* cr, FILE* file_svg, FILE* file_txt);

#endif
