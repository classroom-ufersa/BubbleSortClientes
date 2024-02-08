/*Struct que armazena os dados do cliente
*/
typedef struct cliente{
    char nome[50];
    char endereco[50];
    int codigo;
}Cliente;

/*Função que preenche os dados do cliente com informações inseridas via teclado
*/
Cliente * preenche_cliente(Cliente *cliente);
