#include <stdio.h>
#include <locale.h>

int main()
{
    int senha = 2002;
    int digitada;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite sua senha: ");
    scanf("%d",&digitada);
    while(digitada != senha) {
        printf("Senha Inválida! Tente novamente.\n\n");
        printf("Digite sua senha: ");
        scanf("%d",&digitada);

    }
    printf("Acesso Permitido");

    return 0;
}

