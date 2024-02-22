# Bubble Sort
Este repositório tem como objetivo desenvolver um sistema simples de cadastro de clientes em linguagem C. O programa permite que o usuário insira informações sobre clientes, como nome, endereço e código, e armazene esses dados em um arquivo de texto. Os dados nesse arquivo de texto são ordenados alfabeticamente utilizando o algoritmo de ordenação Bubble Sort.

## Descrição
O Bubble Sort é um algoritmo de ordenação simples que percorre repetidamente a lista, compara elementos e os troca se estiverem na ordem errada. O processo é repetido até que a lista esteja ordenada. É um algoritmo relativamente fácil de entender e implementar, sendo vantajoso para pequenas listas ou para fins educacionais. O Bubble Sort tem uma complexidade de tempo de O(n^2), tornando-se ineficiente para grandes conjuntos de dados.

## Como Funciona
O Bubble Sort percorre a lista de elementos e compara os elementos adjacentes, se o elemento atual for maior que o próximo, troca-os de posição, no caso deste projeto a comparação é feita com strings. Ele repete esse processo até que todos os elementos sejam vereficados e nenhum elemento seja trocado de posição.

## Implementação
A implementação do algoritmo Bubble Sort neste repositório está disponível no arquivo [bubblesort.c]. Você pode encontrar exemplos de como usar essa implementação na documentação do código.

## Execução
Para compilar e executar o trabalho, siga as seguintes etapas:
1. Clone este repositório para o seu ambiente local usando o seguinte comando:
```
git clone https://github.com/classroom-ufersa/BubbleSortClientes
```

2. Navegue até o diretório clonado:
```
cd BubbleSortClientes
```

3. Compile os arquivos-fonte usando o gcc:
```
gcc -c main.c
```
```
gcc -c cliente.c
```
```
gcc -c bubblesort.c
```

4. Link os objetos compilados para criar o executável:
```
gcc -o main.exe bubblesort.o cliente.o main.o
```

5. Execute o programa:
```
./main.exe
```

## Referências
- [GeeksforGeeks - Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
- [Wikipedia - Bubble Sort](https://pt.wikipedia.org/wiki/Bubble_sort)