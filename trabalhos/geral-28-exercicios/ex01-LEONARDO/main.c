#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    float P, C, L, R, A;

    printf("Digite o valor do metro quadrado: ");
    scanf("%f", &P);

    printf("Digite o comprimento do terreno: ");
    scanf("%f", &C);

    printf("Digite a largura do terreno: ");
    scanf("%f", &L);

    A = C * L;
    R = P * C * L;

    printf("O pre�o do terreno de �rea %.2f m� � de R$ %.2f\n", A, R);

    return 0;
}
