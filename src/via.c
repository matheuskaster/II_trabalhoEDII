//
// Created by Matheus on 25/05/2026.
//

#include "../include/via.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/vetor.h"

void via (FILE* arq_via) {

    if(arq_via == NULL){
        printf("Arquivo .via não encontrado. \n");
        exit(1);
    }

    char linha[256];
    char comando[2];

    while (fgets(linha, sizeof(linha), arq_via) != NULL) {
        if (linha[0] == '\n' || linha[0] == '#'){
            continue;
        }
        sscanf(linha, "%s", comando);
        switch (comando[0]) {
            case 'n': {
                int nv;
                sscanf (linha, "%d", &nv);
                cria_vetor(nv);
                break;
            }
            case 'v': {
                int id;
                double x, y;
                sscanf(linha, "v v%d %lf %lf", &id, &x, &y);
                cria_vertice(id, x, y);
                break;
            }
            case 'e': {
                int vertice_i, vertice_j;
                char *ldir = NULL, *lesq = NULL, *nome = NULL;
                double cmp = 0, vm = 0;

                sscanf (linha, "e v%d v%d %s %s %lf %lf %s", &vertice_i, &vertice_j, ldir, lesq, &cmp, &vm, nome);
                break;
            }
        }
    }
}
