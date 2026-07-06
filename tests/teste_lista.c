//
// Created by Matheus on 29/06/2026.
//

#include "../unity/unity.h"
#include "../include/lista.h"
#include "../include/aresta.h"

void setUp (void) {}
void tearDown (void) {}

void teste_percorre_lista (void) {
    printf("-- TESTE PERCORRER LISTA --\n");
    Lista l = cria_lista();

    Vertice i1 = cria_vertice(1, 2.0, 5.0);
    Vertice j1 = cria_vertice(2, 3.0, 3.5);
    Aresta a1 = cria_aresta(i1, j1, "cep1","cep6", 700.0, 50.0, "Rua do Ferro");

    Vertice i2 = cria_vertice(2, 4.0, 10.0);
    Vertice j2 = cria_vertice(4, 6.0, 7);
    Aresta a2 = cria_aresta(i2, j2, "cep2","cep7", 700.0, 50.0, "Rua do Cobre");

    Vertice i3 = cria_vertice(3, 6.0, 15.0);
    Vertice j3 = cria_vertice(6, 9.0, 10.5);
    Aresta a3 = cria_aresta(i3, j3, "cep3","cep8", 700.0, 50.0, "Rua do Ouro");

    Vertice i4 = cria_vertice(4, 8.0, 20.0);
    Vertice j4 = cria_vertice(8, 12.0, 14);
    Aresta a4 = cria_aresta(i4, j4, "cep4","cep9", 700.0, 50.0, "Rua do Silíco");

    Vertice i5 = cria_vertice(5, 10.0, 25.0);
    Vertice j5 = cria_vertice(10, 15.0, 17.5);
    Aresta a5 = cria_aresta(i5, j5, "cep5","cep10", 700.0, 50.0, "Rua do Cobalto");

    insere_lista (l, a1);
    insere_lista (l, a2);
    insere_lista (l, a3);
    insere_lista (l, a4);
    insere_lista (l, a5);


    Aresta a = NULL;

    percorrer_do_inicio_lista (l);
    while (tem_proximo_lista(l)) {
        if (tem_proximo_lista(l)) {a = get_proximo_lista(l);}
        printf("%s\n", get_nome_aresta(a));
    }
    printf("\n");

    percorrer_do_inicio_lista (l);
    while (tem_proximo_lista(l)) {
        if (tem_proximo_lista(l)) {a = get_proximo_lista(l);}
        printf("%s\n", get_nome_aresta(a));
    }
    printf("\n");

    libera_lista(l);
    libera_vertice(i1);
    libera_vertice(j1);
    libera_vertice(i2);
    libera_vertice(j2);
    libera_vertice(i3);
    libera_vertice(j3);
    libera_vertice(i4);
    libera_vertice(j4);
    libera_vertice(i5);
    libera_vertice(j5);
}

void teste_remove_lista (void) {
    printf("-- TESTE REMOVER LISTA --\n");

    Lista l = cria_lista();

    Vertice i1 = cria_vertice(1, 2.0, 5.0);
    Vertice j1 = cria_vertice(2, 3.0, 3.5);
    Aresta a1 = cria_aresta(i1, j1, "cep1","cep6", 700.0, 50.0, "Rua do Ferro");

    Vertice i2 = cria_vertice(2, 4.0, 10.0);
    Vertice j2 = cria_vertice(4, 6.0, 7);
    Aresta a2 = cria_aresta(i2, j2, "cep2","cep7", 700.0, 50.0, "Rua do Cobre");

    Vertice i3 = cria_vertice(3, 6.0, 15.0);
    Vertice j3 = cria_vertice(6, 9.0, 10.5);
    Aresta a3 = cria_aresta(i3, j3, "cep3","cep8", 700.0, 50.0, "Rua do Ouro");

    Vertice i4 = cria_vertice(4, 8.0, 20.0);
    Vertice j4 = cria_vertice(8, 12.0, 14);
    Aresta a4 = cria_aresta(i4, j4, "cep4","cep9", 700.0, 50.0, "Rua do Silíco");

    Vertice i5 = cria_vertice(5, 10.0, 25.0);
    Vertice j5 = cria_vertice(10, 15.0, 17.5);
    Aresta a5 = cria_aresta(i5, j5, "cep5","cep10", 700.0, 50.0, "Rua do Cobalto");

    insere_lista (l, a1);
    insere_lista (l, a2);
    insere_lista (l, a3);
    insere_lista (l, a4);
    insere_lista (l, a5);

    Aresta a = remove_lista (l);
    printf("removendo aresta %s...\n", get_nome_aresta(a));
    libera_aresta(a);
    a = remove_lista (l);
    printf("removendo aresta %s...\n", get_nome_aresta(a));
    libera_aresta(a);
    a = remove_lista (l);
    printf("removendo aresta %s...\n", get_nome_aresta(a));
    libera_aresta(a);
    printf("\n --- O que sobrou na lista --- \n");

    percorrer_do_inicio_lista (l);
    while (tem_proximo_lista(l)) {
        if (tem_proximo_lista(l)) { a = get_proximo_lista(l);}
        printf("%s\n", get_nome_aresta(a));
    }

    libera_lista(l);

    libera_vertice(i1);
    libera_vertice(j1);
    libera_vertice(i2);
    libera_vertice(j2);
    libera_vertice(i3);
    libera_vertice(j3);
    libera_vertice(i4);
    libera_vertice(j4);
    libera_vertice(i5);
    libera_vertice(j5);
}

int main () {
    UNITY_BEGIN();

    RUN_TEST (teste_percorre_lista);
    RUN_TEST (teste_remove_lista);

    return UNITY_END();
}