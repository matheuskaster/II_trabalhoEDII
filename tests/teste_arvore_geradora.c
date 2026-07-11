//
// Testes da Árvore Geradora Mínima (Prim)
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/arvore_geradora.h"
#include "../include/grafo.h"

Grafo g;

Vertice v0;
Vertice v1;
Vertice v2;
Vertice v3;

Aresta a01; // Peso 10
Aresta a02; // Peso 5
Aresta a12; // Peso 15
Aresta a13; // Peso 20
Aresta a23; // Peso 30

void setUp(void) {
    g = cria_grafo(4);

    v0 = cria_vertice("id v0", 0, 0);
    v1 = cria_vertice("id v1", 0, 1);
    v2 = cria_vertice("id v2", 1, 1);
    v3 = cria_vertice("id v3", 1, 0);

    a01 = cria_aresta("id v0", "id v1", "cep dir-01", "cep esq-01", 10.0, 60, "Rua A");

    a02 = cria_aresta("id v0", "id v2", "cep dir-02", "cep esq-02", 5.0, 60, "Rua B");

    a12 = cria_aresta("id v1", "id v2", "cep dir-12", "cep esq-12", 15.0, 60, "Rua C");

    a13 = cria_aresta("id v1", "id v3", "cep dir-13", "cep esq-13", 20.0, 60, "Rua D");

    a23 = cria_aresta("id v2", "id v3", "cep dir-23", "cep esq-23", 30.0, 60, "Rua E");

    insere_vertice_grafo(g, v0, 0);
    insere_vertice_grafo(g, v1, 1);
    insere_vertice_grafo(g, v2, 2);
    insere_vertice_grafo(g, v3, 3);

    ordena_mapa(get_mapa_grafo(g));
}

void tearDown(void) {
    libera_grafo(g);
}

void teste_arvore_geradora_conecta_menor_custo(void) {
    insere_aresta_grafo(g, a01, 0);
    insere_aresta_grafo(g, a02, 0);
    insere_aresta_grafo(g, a12, 1);
    insere_aresta_grafo(g, a13, 1);
    insere_aresta_grafo(g, a23, 2);

    Arvore a = calcula_arvore_geradora(g);

    // Garante que a árvore processou todos os 4 vértices
    TEST_ASSERT_EQUAL_INT(4, get_tamanho_arvore(a));

    // Valida o mapa de pais construído pelo algoritmo de Prim
    // O vértice 0 é a raiz
    TEST_ASSERT_EQUAL_INT(-1, get_pai_vertice_arvore(a, 0));

    // O vértice 1 deve ter sido conectado pelo vértice 0 (Peso 10 é melhor que conectar pelo v2 com Peso 15)
    TEST_ASSERT_EQUAL_INT(0, get_pai_vertice_arvore(a, 1));

    // O vértice 2 deve ter sido conectado pelo vértice 0 (Peso 5)
    TEST_ASSERT_EQUAL_INT(0, get_pai_vertice_arvore(a, 2));

    // O vértice 3 deve ter sido conectado pelo vértice 1 (Peso 20 é melhor que conectar pelo v2 com Peso 30)
    TEST_ASSERT_EQUAL_INT(1, get_pai_vertice_arvore(a, 3));

    libera_arvore_geradora(a);
}

void teste_arvore_geradora_sem_arestas(void) {
    Arvore a = calcula_arvore_geradora(g);

    TEST_ASSERT_EQUAL_INT(4, get_tamanho_arvore(a));

    TEST_ASSERT_EQUAL_INT(-1, get_pai_vertice_arvore(a, 0));
    TEST_ASSERT_EQUAL_INT(-1, get_pai_vertice_arvore(a, 1));
    TEST_ASSERT_EQUAL_INT(-1, get_pai_vertice_arvore(a, 2));
    TEST_ASSERT_EQUAL_INT(-1, get_pai_vertice_arvore(a, 3));

    libera_arvore_geradora(a);

    // Não foram inseridas no grafo
    libera_aresta(a01);
    libera_aresta(a02);
    libera_aresta(a12);
    libera_aresta(a13);
    libera_aresta(a23);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(teste_arvore_geradora_conecta_menor_custo);
    RUN_TEST(teste_arvore_geradora_sem_arestas);

    return UNITY_END();
}