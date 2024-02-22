#include "bubblesort.h"
#include "cliente.h"

int main(void) {
  Cliente *lista_clientes = NULL;
  FILE *arquivo;
  arquivo = fopen("clientes.txt", "a+");
  int arquivoVazio = fgetc(arquivo);
  if (arquivoVazio == EOF) {
      fprintf(arquivo, "Nome \t Endereço \t Código \n");
  }

  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo!");
    return 1;
  }

  int x = 1;
  int qtdClientes = 0;
  while (x == 1) {
    Cliente *temp = realloc(lista_clientes, (qtdClientes + 1) * sizeof(Cliente));
    if (temp == NULL) {
      printf("Erro ao alocar memória!");
      break;
    }
    lista_clientes = temp;

    preenche_cliente(&lista_clientes[qtdClientes]);
    qtdClientes++;

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

  for (int i = 0; i < qtdClientes; i++) {
    fprintf(arquivo, " %s \t %s \t %d \n", lista_clientes[i].nome,
            lista_clientes[i].endereco, lista_clientes[i].codigo);
  }
  fclose(arquivo);

  // Liberar memória alocada
  free(lista_clientes);

  return 0;
}
