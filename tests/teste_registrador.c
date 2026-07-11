//
// Created by Matheus on 11/07/2026.
//


#include <stdio.h>
#include <stdlib.h>
#include "../unity/unity.h"
#include "../include/registrador.h"

Registradores regs;

void setUp(void) {
    regs = cria_registradores();
}

void tearDown(void) {
    libera_registradores(regs);
}

void teste_registrador_armazena_e_obtem_sucesso(void) {
    // Armazena coordenadas em posições válidas (limite inferior, meio e limite superior)
    insere_registrador(regs, "R0", 12.5, 34.2);
    insere_registrador(regs, "R5", -4.0, 8.8);
    insere_registrador(regs, "R10", 100.1, 200.2);

    double x, y;

    busca_registrador(regs, "R0", &x, &y);

    TEST_ASSERT_TRUE(x == 12.5);
    TEST_ASSERT_TRUE(y == 34.2);

    busca_registrador(regs, "R5", &x, &y);
    TEST_ASSERT_TRUE(x == -4.0);
    TEST_ASSERT_TRUE(y == 8.8);

    busca_registrador(regs, "R10", &x, &y);
    TEST_ASSERT_TRUE(x == 100.1);
    TEST_ASSERT_TRUE(y == 200.2);
}

void teste_registrador_sobrescreve_valor(void) {
    // Armazena um valor inicial no R3
    insere_registrador(regs, "R3", 10.0, 20.0);

    // Sobrescreve com novas coordenadas
    insere_registrador(regs, "R3", 50.5, 60.5);

    double x, y;
    busca_registrador(regs, "R3", &x, &y);

    // Garante que a função obtem_registro retornou os valores atualizados
    TEST_ASSERT_TRUE(x == 50.5);
    TEST_ASSERT_TRUE(y == 60.5);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(teste_registrador_armazena_e_obtem_sucesso);
    RUN_TEST(teste_registrador_sobrescreve_valor);

    return UNITY_END();
}