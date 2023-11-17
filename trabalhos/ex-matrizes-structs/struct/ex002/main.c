#include <stdio.h>
#include <stdlib.h>

struct Retangulo
{
    double lado1;
    double lado2;
};

int main()
{
    double area, perimetro;
    struct Retangulo retang;

    retang.lado1 = 10.1;
    retang.lado2 = 5.5;

    area = retang.lado1 * retang.lado2;
    perimetro = 2 * (retang.lado1 + retang.lado2);

    printf("Area: %.2lf \nPerimetro: %.2lf \n", area, perimetro);

    return 0;
}
