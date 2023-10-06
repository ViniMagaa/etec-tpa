#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int option;
    do{
        printf("Qual área você gostaria de atuar?\n");
        printf("[1]Front-end");
        printf("[2]Back-end");
        printf("[3]Programação Web");
        printf("[4]Programação Mobile");
        printf("[5]Programação de jogos");

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
                    printf("PROGRAMAÇÃO WEB");
                    printf("");
                    break;
                case 4:
                    printf("PROGRAMAÇÃO MOBILE");
                    printf("");
                    break;
                case 5:
                    printf("PROGRAMAÇÃO DE JOGOS");
                    printf("");
                    break;
                default:
                    printf("opção invalida. Tente novamente")
        }
    }while (option!=3)
    return 0;
}
