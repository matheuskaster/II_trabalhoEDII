//
// Created by Matheus on 08/07/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/mapa.h"

void setUp (void) {}
void tearDown (void) {}

void teste_criar_mapa(void) {
    Mapa m = cria_mapa(10);
    TEST_ASSERT_NOT_NULL(m);
    printf("Mapa criado com sucesso!\n");
    libera_mapa(m);
}

void teste_inserir_e_traduzir(void) {
    Mapa m = cria_mapa(5);

    insere_mapa(m, "v2", 0);
    insere_mapa(m, "v4", 1);
    insere_mapa(m, "v1", 3);
    insere_mapa(m, "v3", 4);


    ordena_mapa(m);

    TEST_ASSERT_EQUAL_INT(0, traduz_id(m, "v1"));
    TEST_ASSERT_EQUAL_INT(1, traduz_id(m, "v2"));
    TEST_ASSERT_EQUAL_INT(2, traduz_id(m, "v3"));
    TEST_ASSERT_EQUAL_INT(3, traduz_id(m, "v4"));


    printf("Traduções realizadas e validadas com sucesso!\n");
    libera_mapa(m);
}

void teste_traduzir_id_inexistente(void) {
    Mapa m = cria_mapa(5);
    insere_mapa(m, "cep1", 0);
    ordena_mapa(m);

    int resultado = traduz_id(m, "RuaFantasma");
    TEST_ASSERT_EQUAL_INT(-1, resultado);

    printf("Tratamento de ID inexistente validado!\n");
    libera_mapa(m);
}

int main () {
    UNITY_BEGIN();

    RUN_TEST(teste_criar_mapa);
    RUN_TEST(teste_inserir_e_traduzir);
    RUN_TEST(teste_traduzir_id_inexistente);

    return UNITY_END();
}