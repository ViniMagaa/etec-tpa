#include <stdio.h>
#include<math.h>

int main()
{
    float R, A;

    printf("Insira o raio do circulo");
    scanf("%f", &R);

    printf("Essa � a �rea do circulo que voc� quer %f",pow(R,2)*3.14159);

    return 0;
}
