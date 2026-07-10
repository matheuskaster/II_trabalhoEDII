//
// Created by Matheus on 09/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/dijkstra.h"
#include "../include/grafo.h"

Grafo g;
Vertice v1;
Vertice v2;
Vertice v3;
Vertice v4;
Aresta a14;
Aresta a12;
Aresta a23;
Aresta a34;


void setUp(void) {
    g = cria_grafo(4);
    v1 = cria_vertice("id v1", 0, 0);
    v2 = cria_vertice("id v2", 0, 1);
    v3 = cria_vertice("id v3", 1, 1);
    v4 = cria_vertice("id v4", 1, 0);

    a14 = cria_aresta("id v1", "id v4", "cep dir-14", "cep esq-14", 30.0, 15, "Rua do aço");
    a12 = cria_aresta("id v1", "id v2", "cep dir-12", "cep esq-12", 20.0, 80, "Rua do cobre");
    a23 = cria_aresta("id v2", "id v3", "cep dir-23", "cep esq-23", 20.0, 80, "Rua do rubi");
    a34 = cria_aresta("id v3", "id v4", "cep dir-34", "cep esq-34", 20.0, 80, "Rua do ouro");

    insere_vertice_grafo(g, v1, 0);
    insere_vertice_grafo(g, v2, 1);
    insere_vertice_grafo(g, v3, 2);
    insere_vertice_grafo(g, v4, 3);

    ordena_mapa(get_mapa_grafo(g));
}

void tearDown(void) {
    libera_grafo(g);
}

void teste_dijkstra_encontra_menor_caminho(void) {

    insere_aresta_grafo(g, a14, 0);

    insere_aresta_grafo(g, a12, 0);
    insere_aresta_grafo(g, a23, 1);
    insere_aresta_grafo(g, a34, 2);

    CaminhoMinimo cm = calcula_caminho_dijkstra(g, 0, 3, DISTANCIA);

    // Garante que é possível chegar no destino
    TEST_ASSERT_TRUE(caminho_eh_alcancavel(cm));

    // Garante que o Dijkstra foi pelo caminho de 30 que é o de menor distância.
    TEST_ASSERT_TRUE(get_custo_caminho(cm) == 30.0);

    TEST_ASSERT_EQUAL_INT(2, get_tamanho_caminho(cm));

    // Garante que a ordem dos cruzamentos na rota está perfeita
    TEST_ASSERT_EQUAL_INT(0, get_vertice_caminho(cm, 0));
    TEST_ASSERT_EQUAL_INT(3, get_vertice_caminho(cm, 1));

    libera_caminho_minimo(cm);
}

void teste_dijkstra_caminho_mais_rapido(void) {

    insere_aresta_grafo(g, a14, 0);

    insere_aresta_grafo(g, a12, 0);
    insere_aresta_grafo(g, a23, 1);
    insere_aresta_grafo(g, a34, 2);

    CaminhoMinimo cm = calcula_caminho_dijkstra(g, 0, 3, TEMPO);

    TEST_ASSERT_TRUE(caminho_eh_alcancavel(cm));

    // Tempo da volta = (20/80) + (20/80) + (20/80) = 0.25 + 0.25 + 0.25 = 0.75
    // Tempo direto = (30/15) = 2.0.
    TEST_ASSERT_TRUE(get_custo_caminho(cm) == 0.75);
    // A rota da volta passa por 4 cruzamentos (v1, v2, v3, v4)
    TEST_ASSERT_EQUAL_INT(4, get_tamanho_caminho(cm));

    // Ordem: v1 -> v2 -> v3 -> v4
    TEST_ASSERT_EQUAL_INT(0, get_vertice_caminho(cm, 0));
    TEST_ASSERT_EQUAL_INT(1, get_vertice_caminho(cm, 1));
    TEST_ASSERT_EQUAL_INT(2, get_vertice_caminho(cm, 2));
    TEST_ASSERT_EQUAL_INT(3, get_vertice_caminho(cm, 3));

    libera_caminho_minimo(cm);
}

void teste_dijkstra_destino_inalcancavel(void) {
    CaminhoMinimo cm = calcula_caminho_dijkstra(g, 0, 3, DISTANCIA);

    TEST_ASSERT_FALSE(caminho_eh_alcancavel(cm));
    TEST_ASSERT_EQUAL_INT(0, get_tamanho_caminho(cm));

    libera_caminho_minimo(cm);

    // Não foram inseridas no grafo
    libera_aresta(a14);
    libera_aresta(a12);
    libera_aresta(a23);
    libera_aresta(a34);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(teste_dijkstra_encontra_menor_caminho);
    RUN_TEST(teste_dijkstra_caminho_mais_rapido);
    RUN_TEST(teste_dijkstra_destino_inalcancavel);
    return UNITY_END();
}
