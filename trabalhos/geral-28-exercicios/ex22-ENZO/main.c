#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
      printf("digite um numero: ");
        scanf("%d", &num1);
      printf("digite o segundo numero: ");
        scanf("%d", &num2);
      printf("digite o terceiro numero: ");
        scanf("%d", &num3);

        if (num1 > num2 && num1 > num3){
            printf("o numero %d e o menor", num1);
        }
        else if (num2 < num1 && num2 < num3){
            printf("o numero %d e o menor", num2);
        }
        else if (num3 < num1 && num3 < num2){
            printf("o numero %d e o menor", num3);
        } else if (num1==num3 && num1==num2){
            printf("os numeros sao iguais");
        }
}

