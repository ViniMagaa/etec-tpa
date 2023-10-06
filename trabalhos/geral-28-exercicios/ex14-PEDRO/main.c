#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int nota1,nota2;
    float media;
    printf("Digite a nota 1: ");
    scanf("%d", &nota1);
    while(nota1 < 0 || nota1 > 10)
    {
        printf("Nota Inválida! Tente novamente.\n");
        printf("Digite a nota 1: ");
        scanf("%d",&nota1);

    }

    printf("Digite a nota 2: ");
    scanf("%d", &nota2);
    while(nota2 < 0 || nota2 > 10)
    {
        printf("Nota Inválida! Tente novamente.\n");
        printf("Digite a nota 2: ");
        scanf("%d",&nota2);

    }

    media =(nota1 + nota2)/2;
    printf("Sua média é: %f", media);

}

