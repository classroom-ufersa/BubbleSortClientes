#include <string.h>


void bubble_sort(char clientes[100][50], int num_clientes) {
    int i, j;
    char temp[50];
    for (i = 0; i < num_clientes - 1; i++) {
        for (j = 0; j < num_clientes - i - 1; j++) {
            if (strcmp(clientes[j], clientes[j + 1]) > 0) {
                strcpy(temp, clientes[j]);
                strcpy(clientes[j], clientes[j + 1]);
                strcpy(clientes[j + 1], temp);
            }
        }
    }
}
