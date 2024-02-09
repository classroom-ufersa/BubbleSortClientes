#include "cliente.h"
#include <stdbool.h>
#include <string.h>

void bubble_sort(Cliente clientes[100], int num_clientes) {
  int i, j;
  Cliente temp;
  for (i = 0; i < num_clientes - 1; i++) {
    bool trocado = false; // sinaliza se aconteceu uma troca entre dois
                          // elementos no loop interno
    for (j = 0; j < num_clientes - i - 1; j++) {
      if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
        temp = clientes[j];
        clientes[j] = clientes[j + 1];
        clientes[j + 1] = temp;
        trocado = true;
      }
    }
    // se nenhuma troca foi realizada pelo loop interno,
    // o código realiza um break
    if (trocado == false) {
      break;
    }
  }
}
