#include "cliente.h"
#include <stdio.h>

void preenche_cliente(Cliente *cliente) {
  printf("Digite o nome do cliente (ou 0 para encerrar): ");
  scanf(" %[^\n]", cliente->nome);

  printf("Digite o endereço do cliente: ");
  scanf(" %[^\n]", cliente->endereco);

  printf("Digite o código do cliente: ");
  scanf("%d", &cliente->codigo);

  printf("---------------------------\n");
}
