//
// Created by Matheus on 25/05/2026.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/qry.h"
#include "registrador.h"
#include "../include/hash.h"
#include "../include/grafo.h"
#include "../include/svg.h"
#include "../include/mobilidade.h"

void qry (Gerenciador quadras, Grafo grafo, FILE* file_qry, FILE* file_txt, FILE* file_svg, Cores cq) {

    Registradores r = cria_registradores();

    char linha[512];
    char comando[6];

    abre_svg(file_svg);

    while (fgets(linha, sizeof(linha), file_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }

        sscanf(linha, "%s", comando);

        if (strcmp(comando, "@o?") == 0) {
            char* reg = NULL;
            char cep[10];
            char face = '\0';
            int num;
            sscanf(linha, "%s %s %c %d", reg, cep, &face, &num);
            o(quadras, r, reg, cep, face, num, file_svg, file_txt);
        }
        else if (strcmp(comando, "mvm") == 0) {
            double v = 0.0, x = 0.0, y = 0.0, w = 0.0, h = 0.0;
            sscanf(linha, "%lf %lf %lf %lf %lf", &v, &x, &y, &w, &h);
            mvm(grafo, v, x, y, w, h);
        }
        else if (strcmp(comando, "regs") == 0) {
            double vl = 0.0;
            sscanf(linha, "%lf", &vl);
            regs(grafo, vl, file_svg, file_txt);
        }
        else if (strcmp(comando, "exp") == 0) {
            double vl = 0.0;
            sscanf(linha, "%lf", &vl);
            expande(grafo, vl, file_svg);
        }
        else if (strcmp(comando, "p?") == 0) {
            char *reg1 = NULL, *reg2 = NULL, *cc = NULL, *cr = NULL;
            sscanf(linha, "%s %s %s %s", reg1, reg2, cc, cr);
            p(grafo, reg1, reg2, cc, cr, file_svg, file_txt);
        }
    }
    int total;
    Registro* vetor_quadras = pega_todos_registros(quadras, &total);
    for (int i = 0; i < total; i++) {
        Registro r = vetor_quadras[i];

        char* cep = get_chave_registro(r);
        char* dados = get_dados_registro(r);
        Quadra q = reconstroi_quadra(cep, dados);
        desenha_quadra_svg(file_svg, q, cq);

        libera_registro(r);
        libera_quadra(q);
    }
    free(vetor_quadras);
    libera_registradores(r);
    fecha_svg(file_svg);
}
