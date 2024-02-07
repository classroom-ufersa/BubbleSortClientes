#include <stdio.h>
#include <stdlib.h>

int main(void){

  FILE * clientes;
  clientes = fopen("clientes.txt","a");

  if(clientes == NULL){
    printf("erro ao criar o arquivo");
    return 1;
  }

int x = 1;
char nome[50];

  while (x == 1){
    
    // vai pedindo cliente e botando no negocio
    printf("Informe um nome a ser cadastrado");
    scanf(" %[^\n]", nome);

    fprintf(clientes, "%s \n", nome);    
    //scanf, se colocar que nao quer mais nada
    printf("1-para cadastras outro cliente / 0-para encerrar o programa.\n");
    scanf("%d", &x);

   // se o resultado for 0
    if (x==0){
        x = 0;
        fclose(clientes);
    }
    
  }
  
}