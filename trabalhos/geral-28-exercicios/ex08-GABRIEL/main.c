#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

    float distancia, combustivel, consumoMedio;

    printf("Insira a dist�ncia total percorrida em km: ");
    scanf("%f", &distancia);

    printf("Insira o total de combust�vel gasto em litros: ");
    scanf("%f", &combustivel);

    consumoMedio = distancia / combustivel;

    printf("Gasto m�dio de combust�vel: %.3f km/l\n", consumoMedio);

    return 0;
}
