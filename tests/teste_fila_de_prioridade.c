//
// Created by Matheus on 09/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/fila_de_prioridade.h"

void setUp(void) {}
void tearDown(void) {}

void teste_criar_e_liberar_fila(void) {
    FilaPrioridade f = cria_fila_prioridade(0);

    TEST_ASSERT_NOT_NULL(f);
    TEST_ASSERT_EQUAL_INT(0, tam_fila_prioridade(f));
    TEST_ASSERT_TRUE(esta_vazia_fila_prioridade(f));

    libera_fila_prioridade(f);
}

void teste_propriedade_min_heap(void) {
    FilaPrioridade f = cria_fila_prioridade(5);

    // vértices fora de ordem de peso
    insere_fila_prioridade(f, 0, 50.5);
    insere_fila_prioridade(f, 1, 10.2);
    insere_fila_prioridade(f, 2, 35.0);

    TEST_ASSERT_EQUAL_INT(3, tam_fila_prioridade(f));

    int menor = extrai_minimo(f);
    TEST_ASSERT_EQUAL_INT(1, menor);
    menor = extrai_minimo(f);
    TEST_ASSERT_EQUAL_INT(2, menor);
    menor = extrai_minimo(f);
    TEST_ASSERT_EQUAL_INT(0, menor);

    TEST_ASSERT_TRUE(esta_vazia_fila_prioridade(f));
    libera_fila_prioridade(f);
}

void teste_diminuir_prioridade(void) {
    FilaPrioridade f = cria_fila_prioridade(5);

    insere_fila_prioridade(f, 0, 100.0);
    insere_fila_prioridade(f, 1, 80.0);
    insere_fila_prioridade(f, 2, 50.0);


    diminui_prioridade(f, 0, 10.0);

    int menor = extrai_minimo(f);
    TEST_ASSERT_EQUAL_INT(0, menor);

    libera_fila_prioridade(f);
}

void teste_contem_e_busca_fila(void) {
    FilaPrioridade f = cria_fila_prioridade(5);

    TEST_ASSERT_FALSE(contem_fila_prioridade(f, 3));

    insere_fila_prioridade(f, 3, 25.5);
    TEST_ASSERT_TRUE(contem_fila_prioridade(f, 3));

    TEST_ASSERT_FALSE(contem_fila_prioridade(f, 2));

    int menor = extrai_minimo(f);
    TEST_ASSERT_EQUAL_INT(3, menor);
    TEST_ASSERT_FALSE(contem_fila_prioridade(f, 3));

    libera_fila_prioridade(f);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(teste_criar_e_liberar_fila);
    RUN_TEST(teste_propriedade_min_heap);
    RUN_TEST(teste_diminuir_prioridade);
    RUN_TEST(teste_contem_e_busca_fila);

    return UNITY_END();
}