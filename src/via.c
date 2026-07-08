//
// Created by Matheus on 25/05/2026.
//

#include "../include/via.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/grafo.h"
#include "../include/mapa.h"

void via (FILE* arq_via) {

    if(arq_via == NULL){
        printf("Arquivo .via não encontrado. \n");
        exit(1);
    }

    int contador = 0;

    int tamanho = 0;
    char linha[256];
    char comando[2];

    fgets(linha, sizeof(linha), arq_via);
    sscanf(linha, "%d", &tamanho);

    Grafo grafo = cria_grafo(tamanho);
    Mapa mapa = cria_mapa(tamanho);

    while (fgets(linha, sizeof(linha), arq_via) != NULL) {
        if (linha[0] == '\n' || linha[0] == '#'){
            continue;
        }
        sscanf(linha, "%s", comando);
        switch (comando[0]) {
            case 'v': {
                char* id = NULL;
                double x, y;
                sscanf(linha, "v %s %lf %lf", id, &x, &y);
                Vertice v = cria_vertice(id, x, y);
                insere_mapa(mapa, id, contador);
                insere_vertice_grafo(grafo, v, contador);
                contador++;
                break;
            }
            case 'e': {
                char *vertice_i = NULL, *vertice_j = NULL;
                char *ldir = NULL, *lesq = NULL, *nome = NULL;
                double cmp = 0, vm = 0;

                sscanf (linha, "e %s %s %s %s %lf %lf %s", vertice_i, vertice_j, ldir, lesq, &cmp, &vm, nome);
                break;
            }
            default: {
                printf("[ERRO] Comando lido do arquivo .via é invalido. \n");
                exit(1);
            }
        }
    }
    ordena_mapa(mapa);
}
