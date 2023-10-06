#include <stdio.h>
#include <stdlib.h>

struct livro {
    char titulo [50];
    char autor [50];
    char data [15];
    char genero [50];
};

int main()
{
    struct livro liv;

    printf("Digite o nome do livro:");
    fgets(liv.titulo, 50, stdin);

    printf("Digite o nome do autor:");
    fgets(liv.autor, 50, stdin);

    printf("Digite a data de lancamento do livro:");
    fgets(liv.data, 15, stdin);

    printf("Digite o genero do livro:");
    fgets(liv.genero, 50, stdin);

    system("cls");

    printf("Nome: %s", liv.titulo);
    printf("Autor: %s", liv.autor);
    printf("Data de lancamento: %s", liv.data);
    printf("Genero: %s", liv.genero);

    return 0;
}
