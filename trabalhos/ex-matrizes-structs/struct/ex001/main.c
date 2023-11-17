#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
    char nome[50];
    int idade;
    double nota;
};

int main()
{
    struct Aluno Vinicius;;

    strcpy(Vinicius.nome, "Vinicius Gustavo Magalhaes dos Santos");
    Vinicius.idade = 15;
    Vinicius.nota = 9.5;

    printf("Informacoes do aluno Vinicius:\n");
    printf(" Nome completo: %s \n", Vinicius.nome);
    printf(" Idade: %d \n", Vinicius.idade);
    printf(" Nota: %.1lf \n", Vinicius.nota);

    return 0;
}
