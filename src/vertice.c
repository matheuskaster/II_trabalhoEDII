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
        printf("Erro na alocação de memória para o id do vértice");
        exit(1);
    }
    v->x = x;
    v->y = y;
    return (Vertice) v;
}

void set_id_vertice(Vertice v, char* id) {
    StrVertice* _v = ((StrVertice*)v);
    _v->id = (char*) malloc(strlen(id)+1);
    if (_v->id == NULL) {
        printf("Erro na alocação de memória para o id do vértice");
        exit(1);
    }
    strcpy(_v->id, id);
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