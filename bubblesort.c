#include "cliente.h"

void bubble_sort(Cliente clientes[], int num_clientes) {//Algoritmo de ordenação bubblesort
  int i, j;
  Cliente temp;
  for (i = 0; i < num_clientes - 1; i++) {
    bool trocado = false;
    for (j = 0; j < num_clientes - i - 1; j++) {
      if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
        temp = clientes[j];
        clientes[j] = clientes[j + 1];
        clientes[j + 1] = temp;
        trocado = true;
      }
    }
    if (trocado == false) {
      break;
    }
  }
}
