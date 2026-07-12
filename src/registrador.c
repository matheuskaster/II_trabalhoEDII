//
// Created by Matheus on 11/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/registrador.h"

#define NUM_REGISTRADORES 11

typedef struct {
    double x;
    double y;
} StrRegistrador;

typedef struct {
    StrRegistrador registros[NUM_REGISTRADORES];
} StrRegistradores;

static int extrai_indice(char* id_reg) {
    if (id_reg == NULL) return -1;

    int indice = atoi(&id_reg[1]);

    if (indice < 0 || indice >= NUM_REGISTRADORES) {
        return -1;
    }
    return indice;
}

Registradores cria_registradores() {
    StrRegistradores* registro = (StrRegistradores*) malloc(sizeof(StrRegistradores));

    if (registro == NULL) {
        printf("[ERRO] Falha ao alocar memoria para os registradores.\n");
        exit(1);
    }

    for (int i = 0; i < NUM_REGISTRADORES; i++) {
        registro->registros[i].x = 0.0;
        registro->registros[i].y = 0.0;
    }

    return registro;
}

void insere_registrador(Registradores r, char* id_reg, double x, double y) {
    StrRegistradores* registro = (StrRegistradores*) r;
    if (registro == NULL) return;

    int indice = extrai_indice(id_reg);
    if (indice == -1) return;

    registro->registros[indice].x = x;
    registro->registros[indice].y = y;
}

void busca_registrador(Registradores r, char* id_reg, double* x, double* y) {
    StrRegistradores* registro = (StrRegistradores*) r;
    if (registro == NULL) return;

    int indice = extrai_indice(id_reg);
    if (indice == -1) return;

    // Pega o valor do x e do y, por referência
    if (x != NULL) *x = registro->registros[indice].x;
    if (y != NULL) *y = registro->registros[indice].y;
}

void libera_registradores(Registradores r) {
    StrRegistradores* registro = (StrRegistradores*) r;
    if (registro != NULL) {
        free(registro);
    }
}