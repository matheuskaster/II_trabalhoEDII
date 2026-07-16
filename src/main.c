//
// Created by Matheus on 25/05/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/grafo.h"
#include "../include/path_utils.h"
#include "../include/geo.h"
#include "../include/via.h"
#include "../include/qry.h"
#include "../include/hash.h"

#define PATH_LEN 250
#define FILE_NAME_LEN 100

int main(int argc, char *argv[]) {
    char dir_entrada[PATH_LEN] = "./";
    char dir_saida[PATH_LEN] = "";
    char arq_geo[FILE_NAME_LEN] = "";
    char arq_qry[FILE_NAME_LEN] = "";
    char arq_via[FILE_NAME_LEN] = "";
    Cores cq = cria_cores( "1.0px", "steelblue" , "MistyRose");

    FILE *file_geo = NULL;
    FILE *file_via = NULL;
    FILE *file_qry = NULL;
    FILE *file_svg_geo = NULL;
    FILE *file_svg_qry = NULL;
    FILE *file_txt = NULL;

    int i = 1;
    while (i < argc) {
        switch (argv[i][1]) {
            case 'e':
                if (i + 1 < argc) {
                    i++;
                    trataPath(dir_entrada, PATH_LEN, argv[i]);
                }
                break;
            case 'o':
                if (i + 1 < argc) {
                    i++;
                    trataPath(dir_saida, PATH_LEN, argv[i]);
                }
                break;
            case 'f':
                if (i + 1 < argc) {
                    i++;
                    trataNomeArquivo(arq_geo, FILE_NAME_LEN, argv[i]);
                }
                break;
            case 'q':
                if (i + 1 < argc) {
                    i++;
                    trataNomeArquivo(arq_qry, FILE_NAME_LEN, argv[i]);
                }
                break;
            case 'v':
                if (i + 1 < argc) {
                    i++;
                    trataNomeArquivo(arq_via, FILE_NAME_LEN, argv[i]);
                }
                break;
            default:
                printf("Argumento da função main inválido, encerrando o programa");
                return 1;
        }
        i++;
    }

    if (strlen(arq_geo) == 0 || strlen(dir_saida) == 0) {
        printf("Faltando -f ou -o, parâmetros que são obrigatórios. \n");
        return 1;
    }

    char* path_geo = monta_caminho_completo(dir_entrada, arq_geo);
    file_geo = fopen(path_geo, "r");
    if (!file_geo) {
        printf("[ERRO] não foi possível abrir o .geo: %s\n", path_geo);
        return 1;
    }
    free(path_geo);

    char* path_via = monta_caminho_completo(dir_entrada, arq_via);
    file_via = fopen(path_via, "r");
    if (!file_via) {
        printf("[ERRO] não foi possível abrir o .via: %s\n", path_via);
        return 1;
    }
    free(path_via);

    char* path_svg_geo = atualiza_extensao (dir_saida, arq_geo, ".svg");
    file_svg_geo = fopen(path_svg_geo, "w");
    if (!file_svg_geo) {
        fclose(file_geo);
        printf("[ERRO] não foi possível abrir o svg do .geo.\n");
        return 1;
    }
    free(path_svg_geo);

    char* path_dir_quadras = atualiza_extensao(dir_saida, arq_geo, ".geo.dir");
    char* path_bkt_quadras = atualiza_extensao(dir_saida, arq_geo, ".geo.bkt");
    Gerenciador hash_quadras = cria_hash(path_dir_quadras, path_bkt_quadras);
    free(path_dir_quadras);
    free(path_bkt_quadras);

    geo(hash_quadras, file_geo, file_svg_geo, cq);
    Grafo grafo = via(file_via);

    if (strlen(arq_qry) > 0) {

        char* path_qry = monta_caminho_completo(dir_entrada, arq_qry);
        file_qry = fopen(path_qry, "r");
        if (!file_qry) {
            printf("[ERRO] não foi possível abrir o .qry: %s\n", path_qry);
            return 1;
        }
        free(path_qry);

        char* path_svg_qry = atualiza_extensao(dir_saida, arq_qry, ".svg");
        char* path_txt_qry = atualiza_extensao(dir_saida, arq_qry, ".txt");

        file_svg_qry = fopen(path_svg_qry, "w");
        file_txt     = fopen(path_txt_qry, "w");

        free(path_txt_qry);

        if (file_svg_qry && file_txt) {
            qry(hash_quadras, grafo, file_qry, file_txt, file_svg_qry, cq);

            char* path_dump_quadras = atualiza_extensao(dir_saida, arq_geo, "geo.hfd");
            gera_dump(hash_quadras, path_dump_quadras);
            free(path_dump_quadras);
        }
        free(path_svg_qry);
    }

    fclose(file_geo);
    fclose(file_svg_geo);
    fclose(file_via);
    libera_cores(cq);
    if (file_qry)     fclose(file_qry);
    if (file_svg_qry) fclose(file_svg_qry);
    if (file_txt)     fclose(file_txt);
    if (hash_quadras) libera_hash(hash_quadras);

    return 0;
}