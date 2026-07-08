//
// Created by Matheus on 01/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vertice.h"

typedef struct {
    char* id;
    double x;
    double y;
} StrVertice;

Vertice cria_vertice(char* id, double x, double y) {
    StrVertice* v = (StrVertice*) malloc(sizeof(StrVertice));

    v->id = (char*) malloc(strlen(id)+1);
    if (v->id == NULL) {
        printf("[ERRO] falha na alocação de memória para o id do vértice.");
        exit(1);
    }
    strcpy(v->id, id);

    v->x = x;
    v->y = y;
    return (Vertice) v;
}

void set_id_vertice(Vertice v, char* id) {
    strcpy (((StrVertice*)v)->id, id);
}

char* get_id_vertice(Vertice v) {
    return ((StrVertice*)v)->id;
}

void set_x_vertice(Vertice v, double x) {
    ((StrVertice*)v)->x = x;
}

double get_x_vertice(Vertice v) {
    return ((StrVertice*)v)->x;
}

void set_y_vertice(Vertice v, double y) {
    ((StrVertice*)v)->y = y;
}

double get_y_vertice(Vertice v) {
    return ((StrVertice*)v)->y;
}

void libera_vertice(Vertice v) {
    StrVertice* vertice = (StrVertice*) v;
    if (vertice != NULL) {
        if (vertice->id != NULL) {
            free(vertice->id);
        }
        free(vertice);
    }
}