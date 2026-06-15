//
// Created by Matheus on 01/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/vertice.h"

typedef struct {
    int id;
    double x;
    double y;
} StrVertice;

Vertice cria_vertice(int id, double x, double y) {
    StrVertice* v = (StrVertice*) malloc(sizeof(StrVertice));
    v->id = id;
    v->x = x;
    v->y = y;
    return (Vertice) v;
}

void set_id_vertice(Vertice v, int id) {
    ((StrVertice*)v)->id = id;
}

int get_id_vertice(Vertice v) {
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
    if (v) {
        free(v);
    }
}