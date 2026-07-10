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

    a14 = cria_aresta(v1, v4, "cep dir-14", "cep esq-14", 50.0, 40, "Rua do aço");
    a12 = cria_aresta(v1, v2, "cep dir-14", "cep esq-14", 50.0, 30, "Rua do cobre");
    a23 = cria_aresta(v2, v3, "cep dir-14", "cep esq-14", 50.0, 50, "Rua do rubi");
    a34 = cria_aresta(v3, v4, "cep dir-14", "cep esq-14", 50.0, 60, "Rua do ouro");

    insere_vertice_grafo(g, v1, 0);
    insere_vertice_grafo(g, v2, 1);
    insere_vertice_grafo(g, v3, 2);
    insere_vertice_grafo(g, v4, 3);
}

void tearDown(void) {
    libera_grafo(g);
}

void teste_dijkstra_encontra_menor_caminho(void) {

    // Caminho direto de v1(0) para v4(3) custa 100
    insere_aresta_grafo(g, a14, 100.0);
    // Caminho alternativo dando a volta (v1 -> v2 -> v3 -> v4) custa 45
    insere_aresta_grafo(g, a12, 10.0);
    insere_aresta_grafo(g, a23, 15.0);
    insere_aresta_grafo(g, a34, 20.0);

    // 3. Executando o Dijkstra (saindo de v1=0, querendo chegar em v4=3)
    CaminhoMinimo cm = calcula_caminho_dijkstra(g, 0, 3, DISTANCIA);

    // Garante que é possível chegar no destino
    TEST_ASSERT_TRUE(caminho_eh_alcancavel(cm));

    // Garante que o Dijkstra foi pelo caminho de 45 (e não pelo de 100)
    TEST_ASSERT_EQUAL_DOUBLE(45.0, caminho_get_custo(cm));

    // Garante que a rota passou por exatos 4 cruzamentos
    TEST_ASSERT_EQUAL_INT(4, get_tamanho_caminho(cm));

    // Garante que a ordem dos cruzamentos na rota está perfeita
    TEST_ASSERT_EQUAL_INT(0, get_vertice_caminho(cm, 0));
    TEST_ASSERT_EQUAL_INT(1, get_vertice_caminho(cm, 1));
    TEST_ASSERT_EQUAL_INT(2, get_vertice_caminho(cm, 2));
    TEST_ASSERT_EQUAL_INT(3, get_vertice_caminho(cm, 3));
}
void teste_dijkstra_destino_inalcancavel(void) {
    CaminhoMinimo cm = calcula_caminho_dijkstra(g, 0, 3);

    TEST_ASSERT_FALSE(caminho_eh_alcancavel(cm));
    TEST_ASSERT_EQUAL_INT(0, get_tamanho_caminho(cm));

    libera_caminho_minimo(cm);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(teste_dijkstra_encontra_menor_caminho);
    RUN_TEST(teste_dijkstra_destino_inalcancavel);
    return UNITY_END();
}
