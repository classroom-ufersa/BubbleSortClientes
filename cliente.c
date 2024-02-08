#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    char nome[50];
    char endereco[50];
    int codigo;
};

struct clientes * preenche_cliente(struct cliente *cliente){

    printf("Digite o nome do cliente (ou 0 para encerrar): ");
    scanf(" %[^\n]", cliente->nome);

    printf("Digite o endereço do cliente: ");
    scanf(" %[^\n]", cliente->endereco);

    printf("Digite o código do cliente: ");
    scanf("%d", &cliente->codigo);

    printf("---------------------------\n");

    return cliente;
}