//
// Created by Matheus on 01/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/vertice.h"
#include "../include/aresta.h"

typedef struct {
    Vertice i;
    Vertice j;
    char* ldir;
    char* lesq;
    double cmp;
    double vm;
    char* nome;
} StrAresta;

Aresta cria_aresta(Vertice i, Vertice j, char* ldir, char* lesq, double cmp, double vm, char* nome) {
    StrAresta* a = (StrAresta*)malloc(sizeof(StrAresta));
    a->i = i;
    a->j = j;
    a->ldir = (char*) malloc(strlen(ldir)+1);
    if (a->ldir == NULL) {
        printf("Erro na alocação de memória para o cpf do lado direito da aresta.");
        exit(1);
    }
    strcpy(a->ldir, ldir);

    a->lesq = (char*) malloc(strlen(lesq)+1);
    if (a->lesq== NULL) {
        printf("Erro na alocação de memória para o cpf do lado esquerdo da aresta.");
        exit(1);
    }
    strcpy(a->lesq, lesq);

    a->cmp = cmp;
    a->vm = vm;
    a->nome = (char*) malloc(strlen(nome)+1);
    if (a->nome== NULL) {
        printf("Erro na alocação de memória para o nome da aresta.");
        exit(1);
    }
    strcpy(a->nome, nome);

    return (Aresta) a;
}

void set_vertice_i_aresta (Aresta a, Vertice i) {
    ((StrAresta*)a)->i = i;
}

Vertice get_vertice_i_aresta (Aresta a) {
    return ((StrAresta*)a)->i;
}

void set_vertice_j_aresta (Aresta a, Vertice j) {
    ((StrAresta*)a)->j = j;
}

Vertice get_vertice_j_aresta (Aresta a) {
    return ((StrAresta*)a)->j;
}

void set_ldir_aresta (Aresta a, char* ldir) {
    ((StrAresta*)a)->ldir = ldir;
}

char* get_ldir_aresta (Aresta a) {
    return ((StrAresta*)a)->ldir;
}

void set_lesq_aresta (Aresta a, char* lesq) {
    ((StrAresta*)a)->lesq = lesq;
}

char* get_lesq_aresta (Aresta a) {
    return ((StrAresta*)a)->lesq;
}

void set_cmp_aresta (Aresta a, double cmp) {
    ((StrAresta*)a)->cmp = cmp;
}

double get_cmp_aresta (Aresta a) {
    return ((StrAresta*)a)->cmp;
}

void set_vm_aresta (Aresta a, double vm) {
    ((StrAresta*)a)->vm = vm;
}

double get_vm_aresta (Aresta a) {
    return ((StrAresta*)a)->vm;
}

void set_nome_aresta(Aresta a, char* nome) {
    ((StrAresta*)a)->nome = nome;
}

char* get_nome_aresta (Aresta a) {
    return ((StrAresta*)a)->nome;
}