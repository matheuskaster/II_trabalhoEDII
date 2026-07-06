//
// Created by Matheus on 01/06/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/vertice.h"
#include "../include/aresta.h"

typedef struct {
    char* i;
    char* j;
    char* ldir;
    char* lesq;
    double cmp;
    double vm;
    char* nome;
} StrAresta;

Aresta cria_aresta(char* i, char* j, char* ldir, char* lesq, double cmp, double vm, char* nome) {
    StrAresta* a = (StrAresta*)malloc(sizeof(StrAresta));
    a->i = (char*) malloc(strlen(i)+1);
    if (a->i == NULL) {
        printf("Erro na alocação de memória para o id do vértice de início da aresta.");
        exit(1);
    }
    strcpy(a->i, i);

    a->j = (char*) malloc(strlen(j)+1);
    if (a->j == NULL) {
        printf("Erro na alocação de memória para o id do vértice de fim da aresta.");
        exit(1);
    }
    strcpy(a->j, j);

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

void set_vertice_i_aresta (Aresta a, char* i) {
    strcpy (((StrAresta*)a)->i, i);
}

char* get_vertice_i_aresta (Aresta a) {
    return ((StrAresta*)a)->i;
}

void set_vertice_j_aresta (Aresta a, char* j) {
    strcpy (((StrAresta*)a)->j, j);
}

char* get_vertice_j_aresta (Aresta a) {
    return ((StrAresta*)a)->j;
}

void set_ldir_aresta (Aresta a, char* ldir) {
    strcpy (((StrAresta*)a)->ldir, ldir);
}

char* get_ldir_aresta (Aresta a) {
    return ((StrAresta*)a)->ldir;
}

void set_lesq_aresta (Aresta a, char* lesq) {
    strcpy (((StrAresta*)a)->lesq, lesq);
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
    strcpy (((StrAresta*)a)->nome, nome);
}

char* get_nome_aresta (Aresta a) {
    return ((StrAresta*)a)->nome;
}

void libera_aresta (Aresta a) {
    StrAresta* _a = (StrAresta*)a;
    if (_a) {
        free(_a->i);
        free(_a->j);
        free(_a->ldir);
        free(_a->lesq);
        free(_a->nome);
        free(_a);
    }
}