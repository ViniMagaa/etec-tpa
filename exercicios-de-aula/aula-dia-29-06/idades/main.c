#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int idade;

    printf("Digite sua idade:\n");
    scanf("%d", &idade);

    if (idade <= 2 && idade > 0){
        printf("Ta gastando com fralda \n");
    } else if (idade >= 18 && idade <= 100) {
        printf("Bora pagar boleto \n");
    } else if (idade < 18 && idade > 2) {
        printf  ("Aproveite. Uma hora acaba \n");
    } else if (idade < 0) {
        printf("[ERRO] Voce nao nasceu \n");
    } else {
        printf("[ERRO] Voce tem toda essa idade mesmo? \n");
    }

    return 0;
}
