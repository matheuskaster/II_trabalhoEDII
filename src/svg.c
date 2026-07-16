//
// Created by Matheus on 25/05/2026.
//

#include <stdio.h>
#include <string.h>
#include "../include/svg.h"
#include "../include/grafo.h"
#include "../include/vetor.h"

void abre_svg (FILE* arq_svg) {

    if (arq_svg == NULL) {
        printf("O aquivo não exite. \n");
        return;
    }
    fprintf(arq_svg,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(arq_svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"10000\" height=\"10000\">\n");
    fprintf(arq_svg,"<g>\n");
}

void desenha_quadra_svg (FILE* arq_svg, Quadra q, Cores cq) {
    fprintf(arq_svg, "<rect cep=\"%s\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" stroke-width=\"%s\" />\n", get_cep_quadra(q), get_cfill(cq), get_cstrk(cq), 0.6*get_h_quadra(q), 0.6*get_w_quadra(q), 0.6*get_y_quadra(q), 0.6*get_x_quadra(q), get_sw(cq));
    fprintf(arq_svg, "<text x=\"%lf\" y=\"%lf\" fill=\"black\" font-family=\"Arial\" font-size=\"10\" font-weight=\"bold\">%s</text>\n", (0.6 * get_x_quadra(q)) + 4.0, (0.6 * get_y_quadra(q)) + 24.0, get_cep_quadra(q));
}

void desenha_linha_registrador_svg(FILE* arq_svg, double x, double y, char* reg) {
    if (arq_svg == NULL || reg == NULL) return;
    fprintf(arq_svg, "\t<line x1=\"%.2f\" y1=\"%.2f\" x2=\"%.2f\" y2=\"7.20\" stroke=\"red\" stroke-width=\"1.5\" stroke-dasharray=\"3,3\" />\n", 0.6*x, 0.6*y, 0.6*x);
    fprintf(arq_svg, "\t<text x=\"%.2f\" y=\"6.00\" fill=\"red\" font-size=\"10\" font-family=\"sans-serif\" font-weight=\"bold\" text-anchor=\"middle\">%s</text>\n", 0.6*x, reg);
}

void desenha_aresta_svg(FILE* arq_svg, double xi, double yi, double xj, double yj) {
    if (arq_svg == NULL) return;
    fprintf(arq_svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"gray\" stroke-width=\"1.0\" />\n", 0.6*xi, 0.6*yi, 0.6*xj, 0.6*yj);
}

void desenha_bounding_box_svg(FILE* arq_svg, double x, double y, double w, double h, char* cb) {
    if (arq_svg == NULL || cb == NULL) return;
    fprintf(arq_svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"0.5\" stroke-width=\"1.5\" />\n", 0.6*x, 0.6*y, 0.6*w, 0.6*h, cb, cb);
}

void desenha_aresta_arvore_svg(FILE* arq_svg, double xi, double yi, double xj, double yj) {
    if (arq_svg == NULL) return;
    fprintf(arq_svg, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" stroke-width=\"4.0\" />\n", 0.6*xi, 0.6*yi, 0.6*xj, 0.6*yj);
}

void desenha_caminho_svg(FILE* arq_svg, Grafo g, CaminhoMinimo caminho, char* cc) {
    if (arq_svg == NULL || g == NULL || caminho == NULL || cc == NULL) return;
    int tamanho = get_tamanho_caminho(caminho);
    if (tamanho == 0) return;

    static int id_rota = 0;
    int id_atual = id_rota++;

    int indice = get_vertice_caminho(caminho, 0);
    Vertice v_origem = busca_vertice_vetor(g, indice);

    fprintf(arq_svg, "\t<path id=\"rota%d\" d=\"M %.2f %.2f ", id_atual, 0.6*get_x_vertice(v_origem), 0.6*get_y_vertice(v_origem));

    for (int i = 1; i < tamanho; i++) {
        int u = get_vertice_caminho(caminho, i);
        Vertice destino = busca_vertice_vetor(g, u);
        if (destino != NULL) {
            fprintf(arq_svg, "L %.2f %.2f ", 0.6*get_x_vertice(destino), 0.6*get_y_vertice(destino));
        }
    }

    fprintf(arq_svg, "\" stroke=\"%s\" fill=\"none\" stroke-width=\"2\"/>\n", cc);

    fprintf(arq_svg, "\t<circle r=\"6\" fill=\"%s\">\n\t\t<animateMotion dur=\"4s\" repeatCount=\"indefinite\">\n\t\t\t<mpath href=\"#rota%d\"/>\n\t\t</animateMotion>\n\t</circle>\n", cc, id_atual);
}

void desenha_placa_svg(FILE* arq_svg, double x, double y, char letra, char* cp) {
    if (arq_svg == NULL || cp == NULL) return;
    fprintf(arq_svg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"16\" height=\"16\" stroke=\"black\" fill=\"%s\" stroke-width=\"1\" />\n", x - 8.0, y - 8.0, cp);
    fprintf(arq_svg, "\t<text x=\"%lf\" y=\"%lf\" font-size=\"11\" font-weight=\"bold\" text-anchor=\"middle\" dominant-baseline=\"middle\" fill=\"white\" >%c</text>\n", x, y, letra);
}

void fecha_svg(FILE* arq_svg) {
    if (arq_svg == NULL) {
        printf("Não foi possível acessar o arquivo. \n");
        return;
    }
    fprintf(arq_svg, "</g>\n");
    fprintf(arq_svg,"</svg>\n");
}