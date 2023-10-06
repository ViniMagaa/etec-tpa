#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int idade, soma = 0, individuos = 0, media;

    printf("Digite a idade do primeiro indiv�duo: ");
    scanf("%d", &idade);

    //se a primeira idade for negativa
    if(idade < 0) {
        printf("\n\nIMPOSS�VEL CALCULAR\n\n");
        exit(0);
    } else {
        //se n�o, � adicionado ao valor da soma e ao indiv�duo
        soma = soma + idade;
        individuos++;
    }

    //enquanto a idade for negativa
    while(idade >= 0) {
        printf("Digite a idade do outro indiv�duo (valor negativo para encerrar: ");
        scanf("%d", &idade);

        if(idade >= 0) {
            soma = soma + idade;
            individuos++;
        }
    }

    //quando idades dor negativo
    soma = soma + (idade * -1); //transoforma o valor de idades para positivoe ent�o soma
    individuos++;

    // calculo da media
    media = soma / individuos;

    printf("A m�dia das idades dos %d indiv�duos � %d anos.", individuos, media);


    return 0;
}
