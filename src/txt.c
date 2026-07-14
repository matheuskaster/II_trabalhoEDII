//
// Created by Matheus on 14/07/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/txt.h"
#include "../include/grafo.h"
#include "../include/mapa.h"
#include "../include/dijkstra.h"
#include "../include/lista.h"
#include "../include/aresta.h"

void reporta_coordenada_txt(FILE* file_txt, char* reg, char* cep, char face, int num, double x, double y) {
    fprintf(file_txt, "@o? %s: Endereco (CEP: %s, Face: %c, Num: %d) convertido para a coordenada (x: %.2f, y: %.2f)\n", reg, cep, face, num, x, y);
}

void reporta_qtd_componentes_txt(FILE* file_txt, int qtd, double vl) {
    fprintf(file_txt, "regs: Encontrados %d componentes conexos com velocidade media inferior a %.2f km/h.\n", qtd, vl);
}

void reporta_destino_inacessivel_txt(FILE* file_txt, char* reg1, char* reg2) {
    fprintf(file_txt, "p?: . O destino %s esta inacessivel a partir da origem %s.\n", reg2, reg1);
}

void reporta_descricao_caminho_txt(FILE* file_txt, Grafo g, CaminhoMinimo cm, char* tipo) {
    if (cm == NULL) return;

    int tamanho = get_tamanho_caminho(cm);
    double custo = get_custo_caminho(cm);

    fprintf(file_txt, "-> Trajeto %s (Custo total: %.2f):\n", tipo, custo);

    for (int i = 0; i < tamanho - 1; i++) {
        int u = get_vertice_caminho(cm, i);
        int v = get_vertice_caminho(cm, i + 1);

        Aresta a = acha_aresta_pelos_indices(g, u, v);

        if (a != NULL) {
            char* nome_rua = get_nome_aresta(a);

            fprintf(file_txt, "   %d. Siga pela via: %s (De cruzamento %d para %d)\n", (i + 1), nome_rua, u, v);
        } else {
            fprintf(file_txt, "   %d. Siga para o próximo cruzamento (%d para %d)\n", (i + 1), u, v);
        }
    }
    fprintf(file_txt, "   CHEGADA AO DESTINO.\n\n");
}