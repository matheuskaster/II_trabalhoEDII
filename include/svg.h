//
// Created by Matheus on 25/05/2026.
//

#ifndef SVG_H
#define SVG_H
#include <stdio.h>

#include "quadra.h"
#include "grafo.h"
#include "dijkstra.h"

/// @brief Escreve o cabeçalho do arquivo .svg, ou seja, é a declaração <?xml ...?> e a tag <svg ...> com seus atributos que definem o espaço e as regras para o desenho.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void abre_svg(FILE* arq_svg);

/// @brief Passa as características do retângulo para o svg poder o desenhar.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param q É um ponteiro que aponta para a quadra que será desenhada, no formato de um retângulo.
/// @param cq É o ponteiro que aponta para a estrutura que guarda as cores da quadra.
void desenha_quadra_svg(FILE* arq_svg, Quadra q, Cores cq);

/// @brief Desenha uma linha vertical pontilhada vermelha mostrando a posição do endereço e colocar o número do
/// registrador na outra extremidade da linha (topo da página).
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param x É a coordenada no eixo 'x' de onde será ilustrada a posição do endereço.
/// @param y É a coordenada no eixo 'y' de onde será ilustrada a posição do endereço.
/// @param reg É o char do registrador, para saber qual dos 11 que foi utilizado.
void desenha_linha_registrador_svg(FILE* arq_svg, double x, double y, char* reg);

/// @brief Desenha uma rua da cidade.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param xi Coordenada no eixo 'x' do início da aresta.
/// @param yi Coordenada no eixo 'y' do início da aresta.
/// @param xj Coordenada no eixo 'x' do fim da aresta.
/// @param yj Coordenada no eixo 'y' do fim da aresta.
void desenha_aresta_svg(FILE* arq_svg, double xi, double yi, double xj, double yj);

/// @brief Desenha a bounding box de um componente conexo.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param x Coordenada x da âncora da bounding box.
/// @param y Coordenada y da âncora da bounding box.
/// @param w Largura do bounding box.
/// @param h Altura do bounding box.
/// @param cb Cor da bounding box (50% de transparência).
void desenha_bounding_box_svg(FILE* arq_svg, double x, double y, double w, double h, char* cb);

/// @brief Pinta a rua selecionada pela árvore geradora mínima com linha grossa e vermelha.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param xi Coordenada no eixo 'x' do início da aresta.
/// @param yi Coordenada no eixo 'y' do início da aresta.
/// @param xj Coordenada no eixo 'x' do fim da aresta.
/// @param yj Coordenada no eixo 'y' do fim da aresta.
void desenha_aresta_arvore_svg(FILE* arq_svg, double xi, double yi, double xj, double yj);

/// @brief Desenha um percurso animado ao longo da lista de arestas com a cor indicada.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param caminho É a estrutura que contém a ordem dos vértices, para desenhar o trajeto.
/// @param cc Cor do caminho e do marcador animado.
void desenha_caminho_svg(FILE* arq_svg, Grafo g, CaminhoMinimo caminho, char* cc);

/// @brief Desenha uma placa marcando o início ou fim do trajeto.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo.
/// @param x Coordenada no eixo 'x' da onde vai se encontrar a placa.
/// @param y Coordenada no eixo 'y' da onde vai se encontrar a placa.
/// @param letra Letra da placa: I (início) ou F (fim).
/// @param cp Cor da placa.
void desenha_placa_svg(FILE* arq_svg, double x, double y, char letra, char* cp);

/// @brief Escreve o rodapé do arquivo .svg, ou seja, é a tag </svg> que fecha o arquivo svg, indicando a realização com sucesso.
/// @param arq_svg É um arquivo do tipo FILE* para acessar o arquivo, já inicializado.
void fecha_svg(FILE* arq_svg);

#endif