#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

    float distancia, combustivel, consumoMedio;

    printf("Insira a distância total percorrida em km: ");
    scanf("%f", &distancia);

    printf("Insira o total de combustível gasto em litros: ");
    scanf("%f", &combustivel);

    consumoMedio = distancia / combustivel;

    printf("Gasto médio de combustível: %.3f km/l\n", consumoMedio);

    return 0;
}
