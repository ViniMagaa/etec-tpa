#include <stdio.h>
#include <locale.h>


int main()
{
    int a = 0, b = 0, c = 0;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite o lado do quadrado para calcular sua área: ");
    scanf("%d", &a);

    int lado = a * a;
    printf("A área do quadrado com o lado %d é: %d\n\n", a, lado);

    //TRIÂNGULO
    a = 0;
    printf("Digite a altura do triângulo retângulo: ");
    scanf("%d", &a);
    printf("Digite a base do triângulo retângulo: ");
    scanf("%d", &b);

    int areatriangulo = b * a / 2;
    printf("A área do triangulo com a base %d e a altura %d é: %d\n\n", b, a, areatriangulo);

    //TRAPEZIO
    printf("Digite a base 1 do trapézio: ");
    scanf("%d", &a);
    printf("Digite a base 2 do trapézio: ");
    scanf("%d", &b);
    printf("Digite a altura do trapézio: ");
    scanf("%d", &c);

    int areatrapezio = (a + b) * c / 2;
    printf("A área do trapézio com a base 1: %d, base 2: %d e a altura: %d é igual a %d", a, b, c, areatrapezio);

    return 0;
}
