#include <stdio.h>
#include<math.h>

int main()
{
    float R, A;

    printf("Insira o raio do circulo");
    scanf("%f", &R);

    printf("Essa é a área do circulo que você quer %f",pow(R,2)*3.14159);

    return 0;
}
