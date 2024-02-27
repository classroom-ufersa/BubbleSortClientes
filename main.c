#include "bubblesort.h"
#include "cliente.h"

int main(void)
{

    Cliente *lista_clientes_atuais = NULL; 
    Cliente *lista_clientes_novos = NULL;  
    Cliente *lista_final = NULL;           

    FILE *arquivo;
    arquivo = fopen("clientes.txt", "a+");
    if (arquivo == NULL)
    { 
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    int qtdClientesAtuais = 0; 
    char linha[256];        

    while (fgets(linha, sizeof(linha), arquivo))
    { 
        lista_clientes_atuais = realloc(lista_clientes_atuais, (qtdClientesAtuais + 1) * sizeof(Cliente));
        if (lista_clientes_atuais == NULL)
        { 
            printf("Erro ao alocar memoria!");
            fclose(arquivo);
            return 1;
        }
        sscanf(linha, "%[^\t] \t %[^\t] \t %d", lista_clientes_atuais[qtdClientesAtuais].nome,
               lista_clientes_atuais[qtdClientesAtuais].endereco, &lista_clientes_atuais[qtdClientesAtuais].codigo);
        qtdClientesAtuais++; 
    }
    fclose(arquivo);                           

    if (qtdClientesAtuais > 0)
    {
        printf("Clientes carregados: %d\n", qtdClientesAtuais);
    }

    int cadastro = 1;         
    int qtdClientesNovos = 0;
    while (cadastro == 1)
    { 
        lista_clientes_novos = realloc(lista_clientes_novos, (qtdClientesNovos + 1) * sizeof(Cliente));
        if (lista_clientes_novos == NULL)
        {
            printf("Erro ao alocar memoria!");
            fclose(arquivo);
            return 1;
        }

        preenche_cliente(&lista_clientes_novos[qtdClientesNovos]); 
        qtdClientesNovos++;                                      

        printf("1 - Cadastrar outro cliente / 0 - Para encerrar o programa.\n"); 
        scanf("%d", &cadastro);
        if (cadastro == 0)
        {
            break;
        }
    }

    printf("Novos clientes cadastrados: %d\n", qtdClientesNovos); 

    int qtdClientesTotal = qtdClientesNovos + qtdClientesAtuais; 
    lista_final = malloc(qtdClientesTotal * sizeof(Cliente));  
    if (lista_final == NULL)
    {
        printf("Erro ao alocar memoria");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < qtdClientesAtuais; i++)
    { 
        lista_final[i] = lista_clientes_atuais[i];
    }

    for (int i = 0; i < qtdClientesNovos; i++)
    {
        lista_final[qtdClientesAtuais + i] = lista_clientes_novos[i];
    }

    bubble_sort(lista_final, qtdClientesTotal); 
    arquivo = fopen("clientes.txt", "w");       
    for (int i = 0; i < qtdClientesTotal; i++)
    { 
        fprintf(arquivo, "%s \t %s \t %d \n", lista_final[i].nome,
                lista_final[i].endereco, lista_final[i].codigo);
    }

    fclose(arquivo); 

    free(lista_clientes_atuais);
    free(lista_clientes_novos); 
    free(lista_final);          

    return 0;
}
