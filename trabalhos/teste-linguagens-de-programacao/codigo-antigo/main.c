#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int option;
    do{
        printf("Qual �rea voc� gostaria de atuar?\n");
        printf("[1]Front-end");
        printf("[2]Back-end");
        printf("[3]Programa��o Web");
        printf("[4]Programa��o Mobile");
        printf("[5]Programa��o de jogos");

        switch(option){
                case 1:
                    printf("FRONT-END");
                    printf("");
                    break;
                case 2:
                    printf("BACK-END");
                    printf("");
                    break;
                case 3:
                    printf("PROGRAMA��O WEB");
                    printf("");
                    break;
                case 4:
                    printf("PROGRAMA��O MOBILE");
                    printf("");
                    break;
                case 5:
                    printf("PROGRAMA��O DE JOGOS");
                    printf("");
                    break;
                default:
                    printf("op��o invalida. Tente novamente")
        }
    }while (option!=3)
    return 0;
}
