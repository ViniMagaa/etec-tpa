#include <stdio.h>
#include <locale.h>

int main()
{
    int duracao, horas, minutos, segundos;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite a dura��o em segundos: ");
    scanf("%d", &duracao);

    horas = duracao / 3600;        // divide por 3600 para dar as horas
    duracao %= 3600;                // resto da divis�o por 3600
    minutos = duracao / 60;        // divide por 60 para dar os minutos
    segundos = duracao % 60;       // resto da divis�o por 60 para dar os segundos

    printf("A dura��o �: %02d:%02d:%02d\n", horas, minutos, segundos);

    return 0;
}
