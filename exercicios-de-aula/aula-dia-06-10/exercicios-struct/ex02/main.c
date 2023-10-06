#include <stdio.h>
#include <stdlib.h>

struct retangulo {
    float lado1;
    float lado2;
};

int main()
{
    float area, perim;
    struct retangulo ret;

    printf("Digite o valor do lado 1 do retangulo: ");
    scanf("%f", &ret.lado1);
    printf("Digite o valor do lado 2 do retangulo: ");
    scanf("%f", &ret.lado2);

    area = ret.lado1 * ret.lado2;
    perim = (2 * ret.lado1) + (2 * ret.lado2);

    printf("\nArea do retangulo: %.1f ", area);
    printf("\nPerimetro do retangulo: %.1f \n", perim);

    return 0;
}
