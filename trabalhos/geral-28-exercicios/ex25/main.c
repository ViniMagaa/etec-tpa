#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int glicose;

    setlocale(LC_ALL, "Portuguese");
    printf("Insira a quantidade de glicose no seu sangue: \n");
    scanf("%d", &glicose);

    if(glicose >= 0 && glicose <= 100) {
        printf("O nível de glicose do seu sangue está normal.");
    }
    else if (glicose > 100 && glicose <= 140) {
        printf("O nível de glicose do seu sangue está elevado.");
    }
    else if (glicose >140) {
        printf("Você está com diabetes.");
    }
    else {
        printf("Quantidade de glicose inválida.");
    }
    return 0;
}
