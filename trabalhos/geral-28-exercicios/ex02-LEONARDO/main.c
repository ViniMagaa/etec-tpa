#include<stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    float a, b, c, d, e;
	setlocale(LC_ALL, "Portuguese");

	printf("Qual é o altura do retângulo? ");
	scanf("%f", &a);
	printf("Qual a largura do comprimento? ");
	scanf("%f", &b);

	c = a * b;
	d = 2 * a + 2 * b;
	e = sqrt(pow(a, 2) + pow(b, 2));

	printf("Essa é a área %.4f\n", c);
	printf("Esse é o perimetro %.4f\n", d);
	printf("Esse é o valor da diagonal do retângulo %.4f\n", e);

	return 0;
}
