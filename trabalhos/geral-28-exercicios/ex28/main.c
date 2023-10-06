#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    float inicio, fim, duracao;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite a hora inicial do jogo: ");
    scanf("%f", &inicio);
    while(inicio > 24 || inicio < 0) {
        printf("Hora inv�lida\n\n");
        printf("Digite a hora inicial do jogo: ");
        scanf("%f", &inicio);
    }

    printf("Agora digite a hora final do jogo: ");
    scanf("%f", &fim);
    while(fim > 24 || fim < 0) {
        printf("Hora inv�lida\n\n");
        printf("Digite a hora inicial do jogo: ");
        scanf("%f", &fim);
    }

    if(fim > inicio) {
        duracao = fim - inicio;
        printf("A dura��o do jogo � %.2fh", duracao);
    } else if(inicio > fim) {
        duracao = fim + 24 - inicio;
        printf("A dura��o do jogo � %.2fh", duracao);
    }

    return 0;
}
