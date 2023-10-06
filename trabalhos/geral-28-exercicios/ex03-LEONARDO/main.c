#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char a[50], b[50];
    float c, d, e;

    printf("Qual o nome da primeria pessoa?");
    scanf("%s", a);
    printf("Qual o nome da segunda pessoa?");
    scanf("%s", b);
    printf("Qual a idade da primeira pessoa?");
    scanf("%f", &c);
    printf("Qual a idade da segunda pessoa?");
    scanf("%f", &d);

    e = (c + d)/2;

    printf("A média da idade de %s e %s é: %.1f\n", a, b, e);

    return 0;
}
