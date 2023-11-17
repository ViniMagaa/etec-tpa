#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_CARACTERES 50

struct Livro
{
    char titulo[MAXIMO_CARACTERES];
    char autor[MAXIMO_CARACTERES];
    char genero[MAXIMO_CARACTERES];
    int nPaginas;
};

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int n;

    printf("Bem vindo a livraria!\n");
    printf("Digite quantos livros voce vai digitar: ");
    scanf("%d", &n);

    struct Livro livros[n];

    limparBuffer();

    for(int i = 0; i < n; i++)
    {
        system("cls");
        printf("Livro %d: \n", i+1);
        printf(" TItulo: ");
        fgets(livros[i].titulo, MAXIMO_CARACTERES, stdin);
        printf(" Autor: ");
        fgets(livros[i].autor, MAXIMO_CARACTERES, stdin);
        printf(" Genero: ");
        fgets(livros[i].genero, MAXIMO_CARACTERES, stdin);
        printf(" Nº de paginas: ");
        scanf("%d", &livros[i].nPaginas);

        limparBuffer();
    }

    system("cls");

    int opcao;
    do
    {
        system("cls");
        printf("Livros cadastrados: \n");
        for(int i = 0; i < n; i++)
        {
            printf(" [%d] %s", i+1, livros[i].titulo);
        }
        printf("Digite o indice do livro para obter mais informacoes ou 0 para sair\n");
        scanf("%d", &opcao);

        if(opcao != 0)
        {
            system("cls");
            printf("Livro %d: \n", opcao);
            printf(" Titulo: %s", livros[opcao-1].titulo);
            printf(" Autor: %s", livros[opcao-1].autor);
            printf(" Genero: %s", livros[opcao-1].genero);
            printf(" Numero de paginas: %d \n", livros[opcao-1].nPaginas);
            system("pause");
        }
    }
    while(opcao != 0);

    return 0;
}
