## Bubble Sort
O Bubble Sort é um algoritmo de ordenação simples e intuitivo. 
![Funcionamento do Bubble Sort](https://miro.medium.com/v2/resize:fit:1000/0*nh6F_qERbgD3xmV-.gif)

### Como Funciona
1. Percorre a lista de elementos.
2. Compara elementos adjacentes.
3. Se o elemento atual for maior que o próximo, troca-os de posição.
4. Repete os passos 1-3 até que a lista esteja completamente ordenada.

### Análise de complexidade
```
void bubble_sort(Cliente clientes[100], int num_clientes) {
  int i, j; // C1, 1 vez
  Cliente temp; // C2, 1 vez 

  for (i = 0; i < num_clientes - 1; i++) { // C3, n -1 vezes
    bool trocado = false; // C4, n -1
    for (j = 0; j < num_clientes - i - 1; j++) { // C5, n-1 vezes
      if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) { // C6, n^2 vezes
        temp = clientes[j]; // C7 n^2 vezes
        clientes[j] = clientes[j + 1]; // C8, n^2 vezes
        clientes[j + 1] = temp; // C9, n^2 vezes
        trocado = true; // C10, n^2 vezes
      }
    }
    if (trocado == false) { // C11, n-1 vezes
      break; // C12, n-1 vezes 
    }
  }
}
```
 a = C1 + C2
 b = (C3+C4+C5+C11+C12)*n-1
 c = (C6+C7+C8+C9+C10)*n^2
 a + (b*n-1) + (c*n^2)
 Tirando a constante: (b*n-1) + (c*n^2)
 Tira a de menor grau: (c*n^2)
 Tira o termo multiplicativo: n^2

### Vantagens e desvantagens
O bubble sort é vantajoso para pequenas listas ou para fins educacionais, é relativamente fácil de entender e implementar. É um algoritmo ineficiente para grandes conjuntos de dados, pois sua complexidade de tempo é O(n^2) no pior caso.

### Execução
```
gcc -c main.c
gcc -c cliente.c
gcc -c bubblesort.c
gcc -o main.exe bubblesort.o cliente.o main.o
```

## Componentes
- Jean Richardson 
- Francisco Adrian 
- Kauê Valentim 
- Juanny Thayssa