#include "bubblesort.h"
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Cliente lista_clientes[100];
  FILE *arquivo;
  arquivo = fopen("clientes.txt", "a+");

  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo!");
    return 1;
  }

  int x = 1;
  int qtdClientes = 0;
  while (x == 1) {
    if (qtdClientes < 100) {
      preenche_cliente(&lista_clientes[qtdClientes]);
      qtdClientes++;
    } else {
      printf("Não há espaço suficiente no vetor");
      break;
    }

    printf("1 - Cadastrar outro cliente / 0 - Para encerrar o programa.\n");
    scanf("%d", &x);
    if (x == 0) {
      x = 0;
      fclose(arquivo);
    }
  }

  bubble_sort(lista_clientes, qtdClientes);

  arquivo = fopen("clientes.txt", "a+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!");
    return 1;
  }

  fprintf(arquivo, "Nome \t Endereço \t Código \n");
  for (int i = 0; i < qtdClientes; i++) {
    fprintf(arquivo, " %s \t %s \t %d \n", lista_clientes[i].nome,
            lista_clientes[i].endereco, lista_clientes[i].codigo);
  }
  fclose(arquivo);

  return 0;
}
