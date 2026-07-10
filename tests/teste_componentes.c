//
// Created by Matheus on 10/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/componentes.h"
#include "../include/grafo.h"

Grafo g;
Vertice v0, v1, v2, v3, v4;

// Arestas do Bairro A (0, 1, 2)
Aresta a01, a10;
Aresta a12, a21;

// Aresta que conecta os dois bairros (utilizada no teste em que tudo é o mesmo bairro)
Aresta a23, a32;

// Arestas do Bairro B (3, 4)
Aresta a34, a43;

void setUp(void) {
    g = cria_grafo(5); // Grafo com 5 vértices

    v0 = cria_vertice("v0", 0, 0);
    v1 = cria_vertice("v1", 0, 1);
    v2 = cria_vertice("v2", 1, 0);
    v3 = cria_vertice("v3", 1, 1);
    v4 = cria_vertice("v4", 2, 2);

    // Bairro A
    a01 = cria_aresta("v0", "v1", "dir", "esq", 10.0, 60, "Rua A");
    a10 = cria_aresta("v1", "v0", "dir", "esq", 10.0, 60, "Rua A");
    a12 = cria_aresta("v1", "v2", "dir", "esq", 10.0, 60, "Rua B");
    a21 = cria_aresta("v2", "v1", "dir", "esq", 10.0, 60, "Rua B");

    // A Ponte (liga 2 ao 3)
    a23 = cria_aresta("v2", "v3", "dir", "esq", 10.0, 60, "Ponte");
    a32 = cria_aresta("v3", "v2", "dir", "esq", 10.0, 60, "Ponte");

    // Bairro B
    a34 = cria_aresta("v3", "v4", "dir", "esq", 10.0, 60, "Rua C");
    a43 = cria_aresta("v4", "v3", "dir", "esq", 10.0, 60, "Rua C");

    insere_vertice_grafo(g, v0, 0);
    insere_vertice_grafo(g, v1, 1);
    insere_vertice_grafo(g, v2, 2);
    insere_vertice_grafo(g, v3, 3);
    insere_vertice_grafo(g, v4, 4);

    ordena_mapa(get_mapa_grafo(g));
}

void tearDown(void) {
    libera_grafo(g);
}

void teste_grafo_totalmente_conexo(void) {
    // TODAS as ruas, incluindo que conecta os bairros
    insere_aresta_grafo(g, a01, 0); insere_aresta_grafo(g, a10, 1);
    insere_aresta_grafo(g, a12, 1); insere_aresta_grafo(g, a21, 2);
    insere_aresta_grafo(g, a23, 2); insere_aresta_grafo(g, a32, 3); // Ponte inserida!
    insere_aresta_grafo(g, a34, 3); insere_aresta_grafo(g, a43, 4);

    Componentes cc = calcula_componentes_conexos(g);

    // Como todos estão interligados, deve haver apenas 1 componente (o componente 0)
    TEST_ASSERT_EQUAL_INT(1, get_quantidade_componentes(cc));

    // Todos os vértices devem pertencer ao mesmo componente (0)
    TEST_ASSERT_EQUAL_INT(0, get_vertice_componente(cc, 0));
    TEST_ASSERT_EQUAL_INT(0, get_vertice_componente(cc, 1));
    TEST_ASSERT_EQUAL_INT(0, get_vertice_componente(cc, 2));
    TEST_ASSERT_EQUAL_INT(0, get_vertice_componente(cc, 3));
    TEST_ASSERT_EQUAL_INT(0, get_vertice_componente(cc, 4));

    libera_componentes(cc);
}

void teste_grafo_desconexo_duas_ilhas(void) {
    // Somente ruas do Bairro A e do Bairro B
    insere_aresta_grafo(g, a01, 0); insere_aresta_grafo(g, a10, 1);
    insere_aresta_grafo(g, a12, 1); insere_aresta_grafo(g, a21, 2);

    insere_aresta_grafo(g, a34, 3); insere_aresta_grafo(g, a43, 4);

    Componentes cc = calcula_componentes_conexos(g);

    // Agora o mapa está quebrado em 2 ilhas, logo, 2 componentes!
    TEST_ASSERT_EQUAL_INT(2, get_quantidade_componentes(cc));

    // Vértices 0, 1 e 2 devem ter a mesma cor/componente (0)
    int cor_bairro_A = get_vertice_componente(cc, 0);
    TEST_ASSERT_EQUAL_INT(cor_bairro_A, get_vertice_componente(cc, 1));
    TEST_ASSERT_EQUAL_INT(cor_bairro_A, get_vertice_componente(cc, 2));

    // Vértices 3 e 4 devem ter a mesma cor, DIFERENTE do Bairro A, (1)
    int cor_bairro_B = get_vertice_componente(cc, 3);
    TEST_ASSERT_EQUAL_INT(cor_bairro_B, get_vertice_componente(cc, 4));

    // As ilhas precisam ter rotulagens diferentes!
    TEST_ASSERT_NOT_EQUAL(cor_bairro_A, cor_bairro_B);

    libera_componentes(cc);

    // Como a ponte não entrou no grafo neste teste, ela é liberada separadamente:
    libera_aresta(a23);
    libera_aresta(a32);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(teste_grafo_totalmente_conexo);
    RUN_TEST(teste_grafo_desconexo_duas_ilhas);
    return UNITY_END();
}