//
// Created by Matheus on 22/06/2026.
//

#include "../unity//unity.h"
#include "../include/vertice.h"

void setUp (void) {}
void tearDown (void) {}

void teste_criar_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    int id = get_id_vertice(v);
    double x = get_x_vertice(v);
    double y = get_y_vertice(v);

    printf("As informações do vértice são: id: %d, x: %.2lf, y: %.2lf", id, x, y);
    libera_vertice(v);
}
void teste_get_id_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    int id = get_id_vertice(v);
    printf("O novo id do vértice é: %d", id);
    libera_vertice(v);
}
void teste_get_x_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    double x = get_x_vertice(v);
    printf("O novo x do vértice é: %lf", x);
    libera_vertice(v);
}
void teste_get_y_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    double y = get_y_vertice(v);
    printf("O novo y do vértice é: %lf", y);
    libera_vertice(v);
}
void teste_set_id_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    set_id_vertice(v, 10);
    int id = get_id_vertice(v);
    printf("O novo id do vértice é: %d", id);
    libera_vertice(v);
}
void teste_set_x_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    set_id_vertice(v, 10);
    double x = get_x_vertice(v);
    printf("O novo x do vértice é: %lf", x);
    libera_vertice(v);
}
void teste_set_y_vertice (void) {
    Vertice v = cria_vertice(1, 2.0, 5.0);
    set_id_vertice(v, 10);
    double y = get_y_vertice(v);
    printf("O novo y do vértice é: %lf", y);
    libera_vertice(v);
}

int main () {
    UNITY_BEGIN();

    RUN_TEST (teste_criar_vertice);
    RUN_TEST(teste_set_id_vertice);
    RUN_TEST(teste_set_x_vertice);
    RUN_TEST(teste_set_y_vertice);
    RUN_TEST(teste_get_id_vertice);
    RUN_TEST(teste_get_x_vertice);
    RUN_TEST(teste_get_y_vertice);

    return UNITY_END();
}