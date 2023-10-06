#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
};
int main()
{
    struct aluno alu;

    printf("Escreva o nome do aluno:");
    fgets(alu.nome, 50, stdin);

    printf("Escreva a idade do aluno:");
    scanf("%d",&alu.idade);

    printf("Escreva a nota do aluno:");
    scanf("%f",&alu.nota);

    system("cls");

    printf("\nNome:%s\n", alu.nome);
    printf("Idade:%d\n", alu.idade);
    printf("\nNota:%.1f", alu.nota);


    return 0;
}
