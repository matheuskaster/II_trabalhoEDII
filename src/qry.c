//
// Created by Matheus on 25/05/2026.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/qry.h"
#include "../include/registrador.h"
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
            char reg[128];
            char cep[64];
            char face = '\0';
            int num;
            sscanf(linha, "@o? %s %s %c %d", reg, cep, &face, &num);
            o(quadras, r, reg, cep, face, num, file_svg, file_txt);
        }
        else if (strcmp(comando, "mvm") == 0) {
            double v = 0.0, x = 0.0, y = 0.0, w = 0.0, h = 0.0;
            sscanf(linha, "mvm %lf %lf %lf %lf %lf", &v, &x, &y, &w, &h);
            mvm(grafo, v, x, y, w, h);
        }
        else if (strcmp(comando, "regs") == 0) {
            double vl = 0.0;
            sscanf(linha, "regs %lf", &vl);
            regs(grafo, vl, file_svg, file_txt);
        }
        else if (strcmp(comando, "exp") == 0) {
            double vl = 0.0;
            sscanf(linha, "exp %lf", &vl);
            expande(grafo, vl, file_svg);
        }
        else if (strcmp(comando, "p?") == 0) {
            char reg1[4], reg2[4], cc[16], cr[16];
            sscanf(linha, "p? %s %s %s %s", reg1, reg2, cc, cr);
            p(grafo, r, reg1, reg2, cc, cr, file_svg, file_txt);
        }
    }
    int total;
    Registro* vetor_quadras = pega_todos_registros(quadras, &total);
    for (int i = 0; i < total; i++) {
        Registro registro = vetor_quadras[i];

        char* cep = get_chave_registro(registro);
        char* dados = get_dados_registro(registro);
        Quadra q = reconstroi_quadra(cep, dados);
        desenha_quadra_svg(file_svg, q, cq);

        libera_registro(registro);
        libera_quadra(q);
    }
    free(vetor_quadras);
    libera_registradores(r);
    libera_grafo(grafo);
    fecha_svg(file_svg);
}
