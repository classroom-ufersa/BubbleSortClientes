#include "cliente.h"

void preenche_cliente(Cliente *cliente)
{ // função que preenche o struct clientes
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome); // preenche o nome do cliente

    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", cliente->endereco); // preenche o endereço do cliente

    printf("Digite o codigo do cliente: ");

    while (scanf("%d", &cliente->codigo) != 1)
    {
        printf("Codigo invalido. Por favor, insira um numero inteiro: ");
        while (getchar() != '\n')
            ;
    }
}
