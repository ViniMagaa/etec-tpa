#include<stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    float a, b, c, d, e;
	setlocale(LC_ALL, "Portuguese");

	printf("Qual � o altura do ret�ngulo? ");
	scanf("%f", &a);
	printf("Qual a largura do comprimento? ");
	scanf("%f", &b);

	c = a * b;
	d = 2 * a + 2 * b;
	e = sqrt(pow(a, 2) + pow(b, 2));

	printf("Essa � a �rea %.4f\n", c);
	printf("Esse � o perimetro %.4f\n", d);
	printf("Esse � o valor da diagonal do ret�ngulo %.4f\n", e);

	return 0;
}
