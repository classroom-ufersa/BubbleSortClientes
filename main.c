#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  FILE *arquivo;
  arquivo = fopen("clientes.txt", "w");

  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo!");
    return 1;
  }

  char clientes[100][50];
  int x = 1;
  char nome[50];
  int qtdClientes = 0;

  // Loop para adicionar clientes ao vetor clientes e ao arquivo
  while (x == 1) {

    printf("Informe um nome a ser cadastrado: ");
    scanf(" %[^\n]", nome);

    if (qtdClientes < 100) { // Testa se há espaço no vetor clientes
      strcpy(clientes[qtdClientes], nome); // Adiciona o nome ao vetor clientes
      fprintf(arquivo, "%s\n", nome); // Adiciona o nome ao arquivo clientes.txt
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
      for (int i = 0; i < qtdClientes; i++) {
        printf("%s \n", clientes[i]);
      }
    }
  }

  bubble_sort(clientes, qtdClientes);

  arquivo = fopen("clientes.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!");
    return 1;
  }

  for (int i = 0; i < qtdClientes; i++) {
    fprintf(arquivo, "%s \n", clientes[i]);
  }

  fclose(arquivo);
}
