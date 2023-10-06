#include <stdio.h>
#include <locale.h>

void exibirDados(char nome[], char sobre[], char dificuldade[], char popularidade[], char usado[], char salario[]);
void avaliar(void);
void feedback(void);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int option;
    char erro[] = "\n\n\nOp��o inválida! Tente novamente.\n\n\n";

    //declara��o das varaveis sobre as informa��es das linguagens
    char python[] = "Python";
    char pySobre[] = "O Python é uma linguagem de programa��o amplamente usada em aplicações da Web, desenvolvimento de software, ci�ncia de dados e machine learning (ML). Os desenvolvedores usam o Python porque � eficiente e f�cil de aprender e pode ser executada em muitas plataformas diferentes.";
    char pyDificuldade[] = "1 de 5 estrelas.";
    char pyPopularidade[] = "4.5 de 5 estrelas.";
    char pyUsado[] = "Essa linguagem é utilizada no Youtube, Instagram e Spotify.";
    char pySalario[] = "A m�dia salarial para Desenvolvedor Python no Brasil é de R$ 4.130,00.";

    char java[] = "Java";
    char javaSobre[] = "Java � uma linguagem de programa��o orientada a objetos desenvolvida na d�cada de 90 por uma equipe de programadores chefiada por James Gosling, na empresa Sun Microsystems, que em 2008 foi adquirido pela empresa Oracle Corporation.";
    char javaDificuldade[] = "3 de 5 estrelas.";
    char javaPopularidade[] = "5 de 5 estrelas.";
    char javaUsado[] = "Essa linguagem � utilizada no Gmail, Minecraft, maioria dos aplicativos Android e aplicativos de empresas.";
    char javaSalario[] = "A m�dia salarial para Desenvolvedor Java no Brasil é de R$ 3.745,00.";

    char c[] = "C";
    char cSobre[] = "C � uma linguagem de programa��o compilada de prop�sito geral, estruturada, imperativa, procedural, padronizada pela Organiza��o Internacional para Padroniza��o, criada em 1972 por Dennis Ritchie na empresa AT&T Bell Labs para desenvolvimento do sistema operacional Unix.";
    char cDificuldade[] = "3 de 5 estrelas.";
    char cPopularidade[] = "5 de 5 estrelas.";
    char cUsado[] = "Essa linguagem � utilizada em Sistemas Operacionais e Hardware.";
    char cSalario[] = "O sal�rio m�dio de um Desenvolvedor C no Brasil é de R$3.250.";

    char cmais[] = "C++";
    char cmaisSobre[] = "C++ � uma linguagem de programa��o compilada multi-paradigma e de uso geral. Desde os anos 1990 � uma das linguagens comerciais mais populares, sendo bastante usada tamb�m na academia por seu grande desempenho e base de utilizadores.";
    char cmaisDificuldade[] = "4 de 5 estrelas.";
    char cmaisPopularidade[] = "4.5 de 5 estrelas.";
    char cmaisUsado[] = "Essa linguagem � utilizada em Sistemas Operacionais, Hardware e navegadores.";
    char cmaisSalario[] = "O sal�rio m�dio nacional de Desenvolvedor C++ � de R$6.473 no Brasil.";

    char javascript[] = "JavaScript";
    char jsSobre[] = "JavaScript � uma linguagem de programa��o interpretada estruturada, de script em alto n�vel com tipagem din�mica fraca e multiparadigma. Juntamente com HTML e CSS, o JavaScript � uma das tr�s principais tecnologias da World Wide Web.";
    char jsDificuldade[] = "2 de 5 estrelas.";
    char jsPopularidade[] = "4 de 5 estrelas.";
    char jsUsado[] = "Essa linguagem � utilizada no Paypal e no front-end da maioria dos websites.";
    char jsSalario[] = "O sal�rio m�dio nacional de Desenvolvedor JavaScript � de R$4.500.";

    char csharp[] = "C#";
    char csharpSobre[] = "C# � uma linguagem de programa��o, multiparadigma, de tipagem forte, desenvolvida pela Microsoft como parte da plataforma .NET. A sua sintaxe orientada a objetos foi baseada no C++ mas inclui muitas influ�ncias de outras linguagens de programa��o, como Object Pascal e, principalmente, Java.";
    char csharpDificuldade[] = "3 de 5 estrelas.";
    char csharpPopularidade[] = "4.5 de 5 estrelas.";
    char csharpUsado[] = "Essa linguagem � utilizada por empresas e aplica��es do Windows.";
    char csharpSalario[] = "O sal�rio m�dio nacional de Desenvolvedor C# � de R$5.062.";

    char objectivec[] = "Objective-C";
    char objcSobre[] = "Objective-C, denominado frequentemente de ObjC ou mais raramente de Objective C ou Obj-C, � uma linguagem de programa��o reflexiva orientada a objecto que adiciona transmiss�o de mensagens no estilo Smalltalk para o C.";
    char objcDificuldade[] = "3 de 5 estrelas.";
    char objcPopularidade[] = "3 de 5 estrelas.";
    char objcUsado[] = "Essa linguagem � utilizada na maioria dos aplicativos iOS e boa parte do Mac OS X.";
    char objcSalario[] = "A m�dia salarial de Desenvolvedor de Objective-C � de R$ 6.090.";


    //menu principal
    do
    {
        system("cls");
        printf("Olá, seja bem vindo a um guia de linguagens de programação! \nSe voc� ainda não é um programador e não sabe qual das diversas linguagens escolher, este teste é para você!\n\n\n");
        printf("Vamos começar com as perguntas:\n\nPorque você quer aprender programação?\n");
        printf(" [1] Para me divertir\n");
        printf(" [2] Para ganhar dinheiro\n");
        printf(" [3] Estou apenas interessado\n");
        printf(" [4] Para aperfei�oar a mim mesmo\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            case 3:
            case 4:
            printf("\nVocê prefere aprender as coisas de que maneira?\n");
            printf(" (0) VOLTAR AO IN�CIO\n");
            printf(" [1] Da maneira mais fácil\n");
            printf(" [2] De uma maneira normal\n");
            printf(" [3] Da maneira mais difícil\n");
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                exibirDados(python, pySobre, pyDificuldade, pyPopularidade, pyUsado, pySalario);
                break;

                case 2:
                exibirDados(c, cSobre, cDificuldade, cPopularidade, cUsado, cSalario);
                break;

                case 3:
                exibirDados(cmais, cmaisSobre, cmaisDificuldade, cmaisPopularidade, cmaisUsado, cmaisSalario);
                break;

                default:
                printf(erro);
                break;
            }
            break;

            case 2:
            printf("\nPor qual meio?\n");
            printf(" (0) VOLTAR AO IN�CIO\n");
            printf(" [1] Através de um emprego\n");
            printf(" [2] Tenho uma ideia de startup\n");
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                printf("\nPara qual plataforma/setor?\n");
                printf(" (0) VOLTAR AO INÍCIO\n");
                printf(" [1] Games\n");
                printf(" [2] Mobile\n");
                printf(" [3] Web\n");
                printf(" [4] Trabalhar para Big Techs\n");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                    exibirDados(cmais, cmaisSobre, cmaisDificuldade, cmaisPopularidade, cmaisUsado, cmaisSalario);
                    break;

                    case 2:
                    printf("\nQual Sistema Operacional?\n");
                    printf(" (0) VOLTAR AO IN�CIO\n");
                    printf(" [1] iOS\n");
                    printf(" [2] Android\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                        case 1:
                        exibirDados(objectivec, objcSobre, objcDificuldade, objcPopularidade, objcUsado, objcSalario);
                        break;

                        case 2:
                        exibirDados(java, javaSobre, javaDificuldade, javaPopularidade, javaUsado, javaSalario);
                        break;

                        default:
                        printf(erro);
                        break;
                    }
                    break;

                    case 3:
                    printf("\nEm qual área?\n");
                    printf(" (0) VOLTAR AO IN�CIO\n");
                    printf(" [1] Front-end: parte visual de um site, aquilo que conseguimos interagir\n");
                    printf(" [2] Back-end: é o código que conecta a internet com o banco de dados, gerencia as conexões dos usuários e alimenta a aplicação web\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                        case 1:
                        exibirDados(javascript, jsSobre, jsDificuldade, jsPopularidade, jsUsado, jsSalario);
                        break;

                        case 2:
                        printf("\nGostaria de trabalhar para a Microsoft?\n");
                        printf(" (0) VOLTAR AO IN�CIO\n");
                        printf(" [1] Sim\n");
                        printf(" [2] N�o\n");
                        scanf("%d", &option);
                        switch (option)
                        {
                            case 1:
                            exibirDados(csharp, csharpSobre, csharpDificuldade, csharpPopularidade, csharpUsado, csharpSalario);
                            break;

                            case 2:
                            exibirDados(java, javaSobre, javaDificuldade, javaPopularidade, javaUsado, javaSalario);
                            break;

                            default:
                            printf(erro);
                            break;
                        }
                        break;

                        default:
                        printf(erro);
                        break;
                    }
                    break;

                    case 4:
                    printf("\nQual das Big Techs você gostaria de trabalhar?\n");
                    printf(" (0) VOLTAR AO IN�CIO\n");
                    printf(" [1] Facebook\n");
                    printf(" [2] Microsoft\n");
                    printf(" [3] Google\n");
                    printf(" [4] Apple\n");
                    scanf("%d", option);
                    switch(option)
                    {
                        case 1:
                        exibirDados(python, pySobre, pyDificuldade, pyPopularidade, pyUsado, pySalario);
                        break;

                        case 2:
                        exibirDados(csharp, csharpSobre, csharpDificuldade, csharpPopularidade, csharpUsado, csharpSalario);
                        break;

                        case 3:
                        exibirDados(python, pySobre, pyDificuldade, pyPopularidade, pyUsado, pySalario);
                        break;

                        case 4:
                        exibirDados(objectivec, objcSobre, objcDificuldade, objcPopularidade, objcUsado, objcSalario);
                        break;

                        default:
                        printf(erro);
                        break;
                    }
                    break;

                    default:
                    printf(erro);
                    break;
                }
                break;

                case 2:
                printf("\nPara qual plataforma/setor?\n");
                printf(" (0) VOLTAR AO IN�CIO\n");
                printf(" [1] Games\n");
                printf(" [2] Mobile\n");
                printf(" [3] Web\n");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                    exibirDados(cmais, cmaisSobre, cmaisDificuldade, cmaisPopularidade, cmaisUsado, cmaisSalario);
                    break;

                    case 2:
                    printf("\nQual Sistema Operacional?\n");
                    printf(" (0) VOLTAR AO IN�CIO\n");
                    printf(" [1] iOS\n");
                    printf(" [2] Android\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                        case 1:
                        exibirDados(objectivec, objcSobre, objcDificuldade, objcPopularidade, objcUsado, objcSalario);
                        break;

                        case 2:
                        exibirDados(java, javaSobre, javaDificuldade, javaPopularidade, javaUsado, javaSalario);
                        break;

                        default:
                        printf(erro);
                        break;
                    }
                    break;

                    case 3:
                    printf("\nEm qual área?\n");
                    printf(" (0) VOLTAR AO IN�CIO\n");
                    printf(" [1] Front-end: parte visual de um site, aquilo que conseguimos interagir\n");
                    printf(" [2] Back-end: é o código que conecta a internet com o banco de dados, gerencia as conexôes dos usuários e alimenta a aplicação web\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                        case 1:
                        exibirDados(javascript, jsSobre, jsDificuldade, jsPopularidade, jsUsado, jsSalario);
                        break;

                        case 2:
                        exibirDados(java, javaSobre, javaDificuldade, javaPopularidade, javaUsado, javaSalario);
                        break;

                        default:
                        printf(erro);
                        break;
                    }
                    break;

                    default:
                    printf(erro);
                    break;
                }
                break;

                default:
                printf(erro);
                break;
            }
            break;

            default:
            printf(erro);
            break;
        }
    } while(option == 0);

    return 0;
}

void exibirDados(char nome[], char sobre[], char dificuldade[], char popularidade[], char usado[], char salario[])
{
    int option, voltar;

    do  {
        system("cls");
        printf("A linguagem ideal para você � '%s'!\n", nome);
        printf("Escolha alguma opção para saber mais sobre ela:\n");
        printf(" [1] Sobre\n");
        printf(" [2] Dificuldade\n");
        printf(" [3] Popularidade\n");
        printf(" [4] Usado em...\n");
        printf(" [5] Salário médio de um programador da área\n");
        printf(" [6] SAIR\n");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
            printf("\n[SOBRE]\n%s", sobre);
            printf("\n\n(Digite '0' para voltar ao menu)\n");
            scanf("%d", &voltar);
            break;

            case 2:
            printf("\n[DIFICULDADE]\n%s", dificuldade);
            printf("\n\n(Digite '0' para voltar ao menu)\n");
            scanf("%d", &voltar);
            break;

            case 3:
            printf("\n[POPULARIDADE]\n%s", popularidade);
            printf("\n\n(Digite '0' para voltar ao menu)\n");
            scanf("%d", &voltar);
            break;

            case 4:
            printf("\n[USADO EM...]\n%s", usado);
            printf("\n\n(Digite '0' para voltar ao menu)\n");
            scanf("%d", &voltar);
            break;

            case 5:
            printf("\n[SAL�RIO M�DIO]\n%s", salario);
            printf("\n\n(Digite '0' para voltar ao menu)\n");
            scanf("%d", &voltar);
            break;

            case 6:
            avaliar();
            break;

            default:
            printf("\n[ERRO]");
            printf("\nDigite '0' para voltar ao menu.\n");
            scanf("%d", &voltar);
            break;
        }
    } while (voltar == 0);

    return;
}

void avaliar(void)
{
    int option;
    char erro[] = "\n\n\nOpção inválida! Tente novamente.\n\n\n";

    printf("\nO que você achou desse teste?\n");
    printf(" [1] Adorei!\n");
    printf(" [2] Gostei\n");
    printf(" [3] Não gostei, nem desgostei\n");
    printf(" [4] Já vi melhores...\n");
    scanf("%d", &option);
    switch(option){
        case 1:
        printf("Obrigado! Ainda bem que você adorou! :)\n");
        exit(0);
        break;
        case 2:
        printf("Valeu!\n");
        exit(0);
        break;
        case 3:
        feedback();
        break;
        case 4:
        feedback();
        break;
        default:
        printf(erro);
        break;
    }
}

void feedback(void)
{
    char feedback[500];

    printf("\n Ahhh... Tentamos nosso melhor. Então deixe o seu feedback:\n");
    scanf("%s", feedback);

    printf("Obrigado pelo feedback!");
    exit(0);
}
