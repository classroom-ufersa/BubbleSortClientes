#include "cliente.h"


void preenche_cliente(Cliente *cliente) {
    printf("Digite o nome do cliente: ");
    scanf("%s", cliente->nome);
    
    printf("Digite o endereço do cliente: ");
    scanf("%s", cliente->endereco);
    
    printf("Digite o código do cliente: ");
    while (scanf("%d", &cliente->codigo) != 1) {
        printf("Código inválido. Por favor, insira um número inteiro: ");
        while (getchar() != '\n');
    }
}
