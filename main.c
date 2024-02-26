#include "bubblesort.h"
#include "cliente.h"

int main(void)
{

    Cliente *lista_clientes_atuais = NULL; // Lista que contem os clientes previamente cadastrados(caso exista algum)
    Cliente *lista_clientes_novos = NULL;  // Lista que armazena os clientes adicionados durante a execução
    Cliente *lista_final = NULL;           // Essa lista é a concatenação das duas listas anteriores

    FILE *arquivo;
    arquivo = fopen("clientes.txt", "a+"); // Função que abre ou cria o arquivo caso ele não exista
    if (arquivo == NULL)
    { // condição de erro caso o arquivo não seja aberto
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    int qtdClientesAtuais = 0; // variavel para a contagem de clientes
    char linha[256];           // Variavel para armazenar as linhas

    while (fgets(linha, sizeof(linha), arquivo))
    { // Funcionalidade que lê o arquivo e aloca memória dinamicamente
        lista_clientes_atuais = realloc(lista_clientes_atuais, (qtdClientesAtuais + 1) * sizeof(Cliente));
        if (lista_clientes_atuais == NULL)
        { // condição de erro caso a alocação de memória falhe
            printf("Erro ao alocar memoria!");
            fclose(arquivo);
            return 1;
        }
        sscanf(linha, "%[^\t] \t %[^\t] \t %d", lista_clientes_atuais[qtdClientesAtuais].nome,
               lista_clientes_atuais[qtdClientesAtuais].endereco, &lista_clientes_atuais[qtdClientesAtuais].codigo);
        qtdClientesAtuais++; // funcionalidade que lê o arquivo e trás as informações requisitadas
    }
    fclose(arquivo);                            // Fecha o arquivo

    if (qtdClientesAtuais > 0)
    {
        printf("Clientes carregados: %d\n", qtdClientesAtuais); // quantidade de clientes que foram carregados
    }

    int cadastro = 1;         // variavel que serve como condição de parada para os cadastros
    int qtdClientesNovos = 0; // variavel que armazena a quantidade de clientes cadastrados
    while (cadastro == 1)
    { // funcionalidade que aloca memória dinamicamente para os novos clientes cadastrados
        lista_clientes_novos = realloc(lista_clientes_novos, (qtdClientesNovos + 1) * sizeof(Cliente));
        if (lista_clientes_novos == NULL)
        {
            printf("Erro ao alocar memoria!");
            fclose(arquivo);
            return 1;
        }

        preenche_cliente(&lista_clientes_novos[qtdClientesNovos]); // Função que preenche os campos da struct clientes
        qtdClientesNovos++;                                        // quantidade de novos clientes

        printf("1 - Cadastrar outro cliente / 0 - Para encerrar o programa.\n"); // Menu de escolha
        scanf("%d", &cadastro);
        if (cadastro == 0)
        {
            break;
        }
    }

    printf("Novos clientes cadastrados: %d\n", qtdClientesNovos); // imprime a quantidade de novos clientes cadastrados

    int qtdClientesTotal = qtdClientesNovos + qtdClientesAtuais; // quantidade total de clientes cadastrados
    lista_final = malloc(qtdClientesTotal * sizeof(Cliente));    // alocação de memória para a lista final
    if (lista_final == NULL)
    {
        printf("Erro ao alocar memoria");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < qtdClientesAtuais; i++)
    { // concatenação das duas listas de clientes na lista final
        lista_final[i] = lista_clientes_atuais[i];
    }

    for (int i = 0; i < qtdClientesNovos; i++)
    {
        lista_final[qtdClientesAtuais + i] = lista_clientes_novos[i];
    }

    bubble_sort(lista_final, qtdClientesTotal); // Chamada do algoritmo bubblesort para ordenar a lista final
    arquivo = fopen("clientes.txt", "w");       // Abre o arquivo de texto e o reescreve ordenando os antigos e os atuais cadastrados
    for (int i = 0; i < qtdClientesTotal; i++)
    { // Percorre a lista final cadastrando todos os clientes no arquivo
        fprintf(arquivo, "%s \t %s \t %d \n", lista_final[i].nome,
                lista_final[i].endereco, lista_final[i].codigo);
    }

    fclose(arquivo); // Fecha o arquivo

    free(lista_clientes_atuais); // Libera memória
    free(lista_clientes_novos);  // Libera memória
    free(lista_final);           // Libera memória

    return 0;
}
