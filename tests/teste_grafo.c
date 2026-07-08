//
// Created by Matheus on 06/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/grafo.h"
#include "../include/vertice.h"
#include "../include/aresta.h"

void setUp(void) {}
void tearDown(void) {}

void teste_criar_grafo(void) {
    Grafo g = cria_grafo(10);
    TEST_ASSERT_NOT_NULL(g);
    printf("Grafo criado (e módulos internos alocados) com sucesso!\n");
    libera_grafo(g);
}

void teste_inserir_vertice_e_aresta(void) {
    Grafo g = cria_grafo(2);

    Vertice v1 = cria_vertice("v1", 10.0, 10.0);
    Vertice v2 = cria_vertice("v2", 20.0, 20.0);

    insere_vertice_grafo(g, v1, 0);
    insere_vertice_grafo(g, v2, 1);

    Aresta rua = cria_aresta(v1, v2, "cepD", "cepE", 100.0, 60.0, "Rua Teste");

    insere_aresta_grafo(g, rua, 0);

    TEST_ASSERT_TRUE(eh_adjacente(g, 0, 1));

    TEST_ASSERT_FALSE(eh_adjacente(g, 1, 0));

    printf("Vértices e Arestas inseridos e validados corretamente!\n");

    // A função libera_grafo vai apagar o vetor, os vértices nele, as listas, e as arestas dentro das listas
    libera_grafo(g);
}

void teste_alterar_velocidade(void) {
    Grafo g = cria_grafo(2);

    Vertice v1 = cria_vertice("v1", 0.0, 0.0);
    Vertice v2 = cria_vertice("v2", 0.0, 0.0);
    insere_vertice_grafo(g, v1, 0);
    insere_vertice_grafo(g, v2, 1);

    Aresta rua = cria_aresta(v1, v2, "D", "E", 100.0, 40.0, "Rua Lenta");
    insere_aresta_grafo(g, rua, 0);

    define_velocidade_media(g, 0, 1, 80.0);

    // Dijkstra futuramente. Assumo que não deu segmentation fault.
    TEST_ASSERT_TRUE(true);

    libera_grafo(g);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(teste_criar_grafo);
    RUN_TEST(teste_inserir_vertice_e_aresta);
    RUN_TEST(teste_alterar_velocidade);

    return UNITY_END();
}