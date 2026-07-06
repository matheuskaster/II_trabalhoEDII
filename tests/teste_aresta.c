//
// Created by Matheus on 22/06/2026.
//

#include "../unity//unity.h"
#include "../include/aresta.h"

void setUp (void) {}
void tearDown (void) {}

void teste_modulo_aresta (void) {
    Aresta a = cria_aresta("v1", "v2", "cep2","cep6", 700.0, 50.0, "Rua do Aço");
    set_lesq_aresta(a, "cep3");

    printf("i = %s.\n", get_vertice_i_aresta(a));
    printf("j = %s.\n", get_vertice_j_aresta(a));
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
