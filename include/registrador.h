//
// Created by Matheus on 11/07/2026.
//

#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef void* Registradores;

/* MÓDULO REGISTRADOR
Gerencia os registradores (R0 a R10) que armazenam coordenadas geográficas 'x' e 'y'.
Fornece operações para gravar e recuperar rapidamente essas posições para uso.
*/

/// @brief Cria a estrutura que guardará os registradores.
/// @return Retorna a estrutura com os registradores criada.
Registradores cria_registradores();

/// @brief Armazena uma coordenada em um registrador específico.
/// @param r O ponteiro para os registradores.
/// @param id_reg String com o nome do registrador (ex: "R0", "R5", "R10").
/// @param x Coordenada no eixo 'x' no plano.
/// @param y Coordenada no eixo 'y' no plano.
void insere_registrador(Registradores r, char* id_reg, double x, double y);

/// @brief Recupera a coordenada armazenada em um registrador.
/// @param r O ponteiro para os registradores.
/// @param id_reg String com o nome do registrador (ex: "R0").
/// @param x Recebe, por referência na função, o valor do 'x', que estava no registrador.
/// @param y Recebe, por referência na função, o valor do 'y', que estava no registrador.
void busca_registrador (Registradores r, char* id_reg, double* x, double* y);

/// @brief Libera toda a memória que estava reservada para os registradores, disponibilizando-a novamente para uso.
/// @param r É o ponteiro para a estrutura terá a sua memória liberada.
void libera_registradores(Registradores r);

#endif
