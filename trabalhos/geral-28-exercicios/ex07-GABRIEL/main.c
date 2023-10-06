#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

    char nome[100];
    float valorporhora, horastrabalhadas, pagamento;

    printf("Insira o nome do funcionário: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Insira o valor recebido por hora: ");
    scanf("%f", &valorporhora);

    printf("Insira a quantidade de horas trabalhadas: ");
    scanf("%f", &horastrabalhadas);

    pagamento = valorporhora * horastrabalhadas;

    printf("\n");
    printf("Funcionário: %s", nome);
    printf("Pagamento: R$ %.2f\n", pagamento);

    return 0;
}
