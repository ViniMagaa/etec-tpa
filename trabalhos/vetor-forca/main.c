#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int letraUsada(char letra, char arrayLetras[], int tamanho) {
    for(int i=0; i<tamanho; i++) {
        if(arrayLetras[i] == letra) {
            return 1; // Foi usada
        }
    }

    return 0; // Não foi usada
}

char *temas[6][10] = {
    {"INTERNET", "COMPUTADOR", "DESENVOLVEDOR", "PROGRAMA", "APLICATIVO", "CPU", "GABINETE", "FONTE", "SOFTWARE", "HARDWARE"},
    {"BRASIL", "ALEMANHA", "ESPANHA", "ARGENTINA", "INGLATERRA", "ANGOLA", "PORTUGAL", "TURQUIA", "NORUEGA", "HOLANDA"},
    {"BANANA", "HAMBURGUER", "PIZZA", "BOLACHA", "CHOCOLATE", "BOLO", "TORTA", "PICANHA", "COXINHA", "ALFACE"},
    {"MACACO", "GATO", "CACHORRO", "PAPAGAIO", "PEIXE", "ARANHA", "MULA", "CAMELO", "GUEPARDO", "CAPIVARA"},
    {"FUTEBOL", "BASQUETE", "HANDEBOL", "GOLFE", "BOXE", "ESGRIMA", "CORRIDA", "XADREZ", "RUGBY", "FUTSAL"},
    {"CADEIRA", "CAMA", "BOLA", "BALDE", "EXTINTOR", "LOUSA", "PANELA", "MOCHILA", "LIQUIDIFICADOR", "VASSOURA"}
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int jogarNovamente = 1;

    do
    {
        int option = 0;

        do
        {
            system("cls");
            printf(BLUE "  _____                   \n");
            printf(" |  ___|__  _ __ ___ __ _ \n");
            printf(" | |_ / _ \\| '__/ __/ _` |\n");
            printf(" |  _| (_) | | | (_| (_| |\n");
            printf(" |_|  \\___/|_|  \\___\\__,_|\n" RESET);

            printf("\nSelecione o tema:\n");
            printf(" [1] Informática\n");
            printf(" [2] País\n");
            printf(" [3] Alimento\n");
            printf(" [4] Animal\n");
            printf(" [5] Esporte\n");
            printf(" [6] Objeto\n");

            scanf("%d", &option);

            if(option<1 || option>6) {
                printf("[ERRO] Opção inválida. ");
                system("pause");
            }

        } while(option < 1 || option > 6);

        // Função srand para aleatorizar o programa
        srand(time(NULL));

        int nAleatorio = rand() % 10;
        char palavra[20];
        strcpy(palavra, temas[option-1][nAleatorio]);

        char palavraAdivinhada[strlen(palavra)];
        char letrasUsadas[26]; // 26 letras no alfabeto
        int tentativasRestantes = 6;
        int letrasRestantes = strlen(palavra);
        int quantidadeLetras = 0;

        for (int i = 0; i < letrasRestantes; i++) {
            palavraAdivinhada[i] = '_';
        }

        limparBuffer();

        do
        {
            system("cls");

            // Exibir a forca e a palavra
            exibirForca(tentativasRestantes, option);

            if(quantidadeLetras>0) {
                printf("Letras usadas: ");
                for(int i=0; i<quantidadeLetras; i++) {
                    printf("%c ", letrasUsadas[i]);
                }
            }

            printf("\n\n   Palavra: ");

            // Inicializa a palavra a ser adivinhada
            for (int i = 0; i < strlen(palavra); i++) {
                printf("%c ", palavraAdivinhada[i]);
            }

            // Ler a letra digitada
            char letra;
            printf("\n\nDigite uma letra: ");
            scanf("%c", &letra);
            letra = toupper(letra);
            int acertou = 0;

            if(letraUsada(letra, letrasUsadas, quantidadeLetras) != 1) {
                letrasUsadas[quantidadeLetras] = letra;
                quantidadeLetras++;

                for(int i=0; i<strlen(palavra); i++) {
                    if (palavra[i] == letra && palavraAdivinhada[i] != letra) {
                        palavraAdivinhada[i] = letra;
                        letrasRestantes--;
                        acertou = 1;
                    }
                }
                if(acertou == 0) {
                    tentativasRestantes--;
                }
            } else {
                printf("\n[ERRO] Letra já utilizada! Tente outra.\n");
                system("pause");
            }


            limparBuffer();
        } while(tentativasRestantes > 0 && letrasRestantes != 0);

        system("cls");

        // Exibir a forca e a palavra
        exibirForca(tentativasRestantes, option);
        printf("Letras usadas: ");
        for(int i=0; i<quantidadeLetras; i++) {
            printf("%c ", letrasUsadas[i]);
        }
        printf("\n\n   Palavra: ");
        for (int i = 0; i < strlen(palavra); i++) {
            printf("%c ", palavra[i]);
        }

        if(letrasRestantes == 0) {

            printf(GREEN"\n ____  ____                 ____      ____  _             _  ");
            printf("\n|_  _||_  _|               |_  _|    |_  _|(_)           | | ");
            printf("\n  \\ \\  / / .--.   __   _     \\ \\  /\\  / /  __   _ .--.   | | ");
            printf("\n   \\ \\/ // .'`\\ \\[  | | |     \\ \\/  \\/ /  [  | [ `.-. |  | | ");
            printf("\n   _|  |_| \\__. | | \\_/ |,     \\  /\\  /    | |  | | | |  |_| ");
            printf("\n  |______|'.__.'  '.__.'_/      \\/  \\/    [___][___||__] (_) \n"RESET);


        } else {

            printf(RED"\n ____  ____                 _____                           _  ");
            printf("\n|_  _||_  _|               |_   _|                         | | ");
            printf("\n  \\ \\  / / .--.   __   _     | |       .--.   .--.  .---.  | | ");
            printf("\n   \\ \\/ // .'`\\ \\[  | | |    | |   _ / .'`\\ \\( (`\\]/ /__\\\\ | | ");
            printf("\n   _|  |_| \\__. | | \\_/ |,  _| |__/ || \\__. | `'.'.| \\__., |_| ");
            printf("\n  |______|'.__.'  '.__.'_/ |________| '.__.' [\\__) )'.__.' (_) \n");

            printf("\n      __  ");
            printf("\n _  .' _| ");
            printf("\n(_) | |   ");
            printf("\n _  | |   ");
            printf("\n(_) | |_  ");
            printf("\n    `.__| \n"RESET);

        }

        printf("\nDigite 1 para jogar novamente ou 0 para sair.\n");
        scanf("%d", &jogarNovamente);
    } while(jogarNovamente == 1);

    return 0;
}

void exibirForca(int tentativa, int option)
{
    system("cls");

    printf(CYAN "Tema escolhido: " RESET);
    switch(option-1)
    {
        case 0:
            printf("Informática");
            break;
        case 1:
            printf("País");
            break;
        case 2:
            printf("Alimento");
            break;
        case 3:
            printf("Animal");
            break;
        case 4:
            printf("Esporte");
            break;
        case 5:
            printf("Objeto");
            break;
    }
    printf("\n");

    switch(tentativa)
    {
        case 6:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |       \n");
            printf("  |       \n");
            printf("  |       \n");
            printf("__|_______\n");
            break;

        case 5:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |       \n");
            printf("  |       \n");
            printf("__|_______\n");
            break;

        case 4:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |     | \n");
            printf("  |       \n");
            printf("__|_______\n");
            break;

        case 3:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |    /| \n");
            printf("  |       \n");
            printf("__|_______\n");
            break;

        case 2:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |    /|\\\n");
            printf("  |       \n");
            printf("__|_______\n");
            break;

        case 1:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |    /|\\\n");
            printf("  |    /  \n");
            printf("__|_______\n");
            break;

        case 0:
            printf("  _______ \n");
            printf("  |     | \n");
            printf("  |     O \n");
            printf("  |    /|\\\n");
            printf("  |    / \\\n");
            printf("__|_______\n");
            break;
    }
}
