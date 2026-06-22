//
// Created by Matheus on 22/06/2026.
//

#include "../unity//unity.h"
#include "../include/aresta.h"
#include "../include/vertice.h"

void setUp (void) {}
void tearDown (void) {}

void teste_modulo_aresta (void) {
    Vertice v1 = cria_vertice(1, 2.0, 5.0);
    Vertice v2 = cria_vertice(2, 3.0, 3.5);
    Aresta a = cria_aresta(v1, v2, "cep2","cep6", 700.0, 50.0, "Rua do Aço");

    Vertice v1a = get_vertice_i_aresta(a);
    Vertice v2a = get_vertice_j_aresta(a);

    printf("i = %d, %.1lf, %lf.\n", get_id_vertice(v1a), get_x_vertice(v1a), get_y_vertice(v1a));
    printf("j = %d, %.1lf, %lf.\n", get_id_vertice(v2a), get_x_vertice(v2a), get_y_vertice(v2a));
    printf("ldir = %s.\n", get_ldir_aresta(a));
    printf("lesq = %s.\n", get_lesq_aresta(a));
    printf("cmp = %.1lf.\n", get_cmp_aresta(a));
    printf("vm = %.1lf.\n", get_vm_aresta(a));
    printf("nome = %s.\n", get_nome_aresta(a));

    libera_aresta(a);
}

int main () {
    UNITY_BEGIN();

    RUN_TEST (teste_modulo_aresta);

    return UNITY_END();
}
