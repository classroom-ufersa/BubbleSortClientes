#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef CLIENTE_H
#define CLIENTE_H

/*Struct que armazena os dados do cliente
*/
typedef struct cliente{
    char nome[50];
    char endereco[50];
    int codigo;
}Cliente;

/*Função que preenche os dados do cliente com informações inseridas via teclado
*/
void preenche_cliente(Cliente *cliente);

#endif
