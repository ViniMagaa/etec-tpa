#include <stdio.h>
#include <string.h>

void limpar_entrada(){
    char c;
    while((c=getchar()) != '\n' && c != EOF){}
}

void ler_texto(char * buffer, int length){
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

int main() {
    int n, nmenores;
    double alturatotal, alturamedia, percentualmenores;

    printf("Quantas pessoas serao digitadas?");
    scanf("%d",&n);

    char nomes[n][50];
    int idade[n];
    double alturas[n];

    for(int i=0; i<n; i++) {
        printf("Dados de %da pessoas:\n", i + 1 );
        printf("Nome; ");
        limpar_entrada();
        ler_texto(nomes[i], 50);
        printf("Idade; ");
        scanf("%d", &idade[i]);
        printf("Altura; ");
        scanf("%lf", &alturas[i]);

        nmenores = 0;
        alturatotal = 0;
    }

    for (int i=0; i <n; i++) {
        if (idade[i] < 16) {
            nmenores++;   
        }
        alturatotal = alturatotal + alturas[i];
    }

    alturamedia = alturatotal /n;
    percentualmenores = ((double)nmenores / n ) * 100.0;

    printf("\nAltura media = %.2lf\n", alturamedia);
    printf("Pessoas com menos de 16 anos; %.1lf\n", percentualmenores);

    for(int i=0; i<n; i++) {
        if (idade[i] < 16) {
            printf("%s\n", nomes[i]);
        }
    }

   return 0;
}