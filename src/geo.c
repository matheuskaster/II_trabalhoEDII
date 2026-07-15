//
// Created by Matheus on 25/05/2026.
//

#include "../include/geo.h"
#include "../include/svg.h"
#include "../include/quadra.h"
#include <stdlib.h>
#include <string.h>

void geo (Gerenciador quadras, FILE* arq_geo, FILE* arq_svg, Cores cq) {

    if(arq_geo == NULL){
        printf("Arquivo .geo não encontrado. \n");
        exit(1);
    }

    char linha[256];
    char comando[3];

    abre_svg(arq_svg);

    while (fgets(linha, sizeof(linha), arq_geo) != NULL) {
        if (linha[0] == '\n' || linha[0] == '#'){
            continue;
        }

        sscanf(linha, "%s", comando);
        if (strcmp(comando, "q") == 0) {
            char cep[16];
            double x, y, w, h;
            sscanf (linha, "q %s %lf %lf %lf %lf", cep, &x, &y, &w, &h);
            Quadra q = cria_quadra(cep, x, y, w, h);
            desenha_quadra_svg(arq_svg, q, cq);

            char dados_quadra[1024];
            get_dados_completos_quadra(q, dados_quadra);
            Registro reg = cria_registro(cep, dados_quadra);

            insere_registro (quadras, reg);

            libera_registro(reg);
            libera_quadra(q);
        } else if (strcmp(comando, "cq") == 0) {
            char sw[16], cfill[16], cstrk[16];
            sscanf (linha, "cq %s %s %s", sw, cfill, cstrk);

            if (cq == NULL) {
                cq = cria_cores(sw, cfill, cstrk);
            } else {
                set_sw(cq, sw);
                set_cfill(cq, cfill);
                set_cstrk(cq, cstrk);
            }
        }
    }
    fecha_svg(arq_svg);
}