#include "cliente.h"


void preenche_cliente(Cliente *cliente) {
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);
    
    printf("Digite o endereço do cliente: ");
    scanf(" %[^\n]", cliente->endereco);
    
    printf("Digite o codigo do cliente: ");
    while (scanf("%d", &cliente->codigo) != 1) {
        printf("Codigo invalido. Por favor, insira um numero inteiro: ");
        while (getchar() != '\n');
    }
}
