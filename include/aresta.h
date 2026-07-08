//
// Created by Matheus on 01/06/2026.
//

#ifndef ARESTA_H
#define ARESTA_H

typedef void* Aresta;

/// @brief Cria uma aresta com os atributos passados por parâmetro.
/// @param i É uma string que contém o id do vértice onde está o início da aresta.
/// @param j É uma string que contém o id do vértice onde está o fim da aresta.
/// @param ldir String que informa o cep da quadra que está à direita da aresta.
/// @param lesq String que informa o cep da quadra que está à esquerda da aresta.
/// @param cmp Comprimento em metros do segmento de rua.
/// @param vm Velocidade média que os carros trafegam neste segmento de rua (m/s).
/// @param nome Nome da rua ao qual pertence o segmento.
Aresta cria_aresta(char* i, char* j, char* ldir, char* lesq, double cmp, double vm, char* nome);

/// @brief Define como o vértice de início da aresta.
/// @param i É o ponteiro para a string do id do vértice de início da aresta, composto pelas coordenadas 'x' e 'y'.
void set_vertice_i_aresta (Aresta a, char* i);

/// @return Qual é o id do vértice de início da aresta.
char* get_vertice_i_aresta (Aresta a);

/// @brief Define como o vértice de fim da aresta.
/// @param j É o ponteiro para a string do id do vértice de fim da aresta, composto pelas coordenadas 'x' e 'y'.
void set_vertice_j_aresta (Aresta a, char* j);

/// @return Qual é o id do vértice de fim da aresta.
char* get_vertice_j_aresta (Aresta a);

/// @brief Altera o valor que informa, através do cep, qual é a quadra que está localizada ao lado direito da rua.
/// @param ldir É o cep da quadra que está à direita da aresta.
void set_ldir_aresta (Aresta a, char* ldir);

/// @return Qual é o cep da quadra que está à direita da rua.
char* get_ldir_aresta (Aresta a);

/// @brief Altera o valor que informa, através do cep, qual é a quadra que está localizada ao lado esquerdo da rua.
/// @param lesq É o cep da quadra que está à esquerda da aresta.
void set_lesq_aresta (Aresta a, char* lesq);

/// @return Qual é o cep da quadra que está à esquerda da rua.
char* get_lesq_aresta (Aresta a);

/// @brief Altera qual é o comprimento de uma rua, em metros.
/// /// @param cmp É o comprimento da aresta.
void set_cmp_aresta (Aresta a, double cmp);

/// @return Qual é o comprimento da aresta.
double get_cmp_aresta (Aresta a);

/// @brief Altera qual é o valor da velocidade média, em metros por segundo, que os veículos demoram para percorrer essa quadra - da rua.
/// @param vm É a velocidade média da aresta.
void set_vm_aresta (Aresta a, double vm);

/// @return Qual é a velocidade média da aresta.
double get_vm_aresta (Aresta a);

/// @brief Define a string passada por parâmetro como o nome da aresta.
/// @param nome É o nome da aresta.
void set_nome_aresta(Aresta a, char* nome);

/// @return Qual é o nome da aresta.
char* get_nome_aresta (Aresta a);

/// @brief Libera toda a memória que estava reservada à aresta, disponibilizando-a novamente para outro uso.
/// @param a É um ponteiro que aponta para a aresta que terá a sua memória liberada.
void libera_aresta (Aresta a);


#endif
