#include <stdio.h>
#include <locale.h>


int main()
{
    int a = 0, b = 0, c = 0;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite o lado do quadrado para calcular sua �rea: ");
    scanf("%d", &a);

    int lado = a * a;
    printf("A �rea do quadrado com o lado %d �: %d\n\n", a, lado);

    //TRI�NGULO
    a = 0;
    printf("Digite a altura do tri�ngulo ret�ngulo: ");
    scanf("%d", &a);
    printf("Digite a base do tri�ngulo ret�ngulo: ");
    scanf("%d", &b);

    int areatriangulo = b * a / 2;
    printf("A �rea do triangulo com a base %d e a altura %d �: %d\n\n", b, a, areatriangulo);

    //TRAPEZIO
    printf("Digite a base 1 do trap�zio: ");
    scanf("%d", &a);
    printf("Digite a base 2 do trap�zio: ");
    scanf("%d", &b);
    printf("Digite a altura do trap�zio: ");
    scanf("%d", &c);

    int areatrapezio = (a + b) * c / 2;
    printf("A �rea do trap�zio com a base 1: %d, base 2: %d e a altura: %d � igual a %d", a, b, c, areatrapezio);

    return 0;
}
