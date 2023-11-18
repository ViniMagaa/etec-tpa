#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>

#define LIST_MOVIES_FILE_NAME "Lista-de-Filmes.txt"
#define SEATS_FILE_NAME "Assentos.txt"

#define MOVIES_LENGTH 10
#define MAX_SEAT_COLS 10
#define MAX_SEAT_ROWS 10

// Cores
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

typedef struct
{
  char title[50];
  char synopsis[200];
  char duration[5];
  double rating;
  int seats[MAX_SEAT_ROWS][MAX_SEAT_COLS];
} Movie;

Movie movies[MOVIES_LENGTH];
int userSeats[MAX_SEAT_ROWS * MAX_SEAT_COLS][2];
int userSeatsIndex = 0;

// Limpa o buffer do teclado
void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

  return;
}

// Exibe uma mensagem de erro e aguarda um caractere
void invalidOption()
{
  printf(RED BOLD "\nOpção inválida! Tente novamente.\n(Pressione qualquer tecla para continuar)\n" RESET);
  getch();
  system("cls");

  return;
}

// Escreve os filmes com suas informações no arquivo 'Lista-de-Filmes.txt'
void writeMovies()
{
  // Definindo os filmes
  strcpy(movies[0].title, "Shrek");
  strcpy(movies[0].synopsis, "Animação sobre um ogro que embarca em uma jornada para resgatar uma princesa e descobre o verdadeiro significado da amizade.");
  strcpy(movies[0].duration, "1h35m");
  movies[0].rating = 4.5;

  strcpy(movies[1].title, "Jogos Vorazes");
  strcpy(movies[1].synopsis, "Num futuro distópico, jovens são selecionados para lutar até a morte em um reality show transmitido para toda a nação.");
  strcpy(movies[1].duration, "2h22m");
  movies[1].rating = 3.5;

  strcpy(movies[2].title, "Homem de Ferro");
  strcpy(movies[2].synopsis, "Tony Stark, um industrialista bilionário, constrói uma armadura tecnológica para combater o mal como Homem de Ferro.");
  strcpy(movies[2].duration, "2h6m");
  movies[2].rating = 4.0;

  strcpy(movies[3].title, "Jogos Mortais");
  strcpy(movies[3].synopsis, "Um psicopata coloca suas vítimas em jogos mortais elaborados que testam sua capacidade de sobrevivência.");
  strcpy(movies[3].duration, "1h43m");
  movies[3].rating = 3.0;

  strcpy(movies[4].title, "Ratatouille");
  strcpy(movies[4].synopsis, "Um rato chamado Remy sonha em se tornar um grande chef e forma uma parceria incomum com Linguini, um jovem cozinheiro.");
  strcpy(movies[4].duration, "1h51m");
  movies[4].rating = 4.5;

  strcpy(movies[5].title, "Toy Story 4");
  strcpy(movies[5].synopsis, "Os brinquedos de Woody embarcam em uma aventura para salvar Forky, um brinquedo feito à mão, que não quer ser um brinquedo.");
  strcpy(movies[5].duration, "1h40m");
  movies[5].rating = 4.0;

  strcpy(movies[6].title, "Homem-Aranha");
  strcpy(movies[6].synopsis, "O adolescente Peter Parker adquire habilidades de aranha e assume a responsabilidade de proteger Nova York como o Homem-Aranha.");
  strcpy(movies[6].duration, "2h13m");
  movies[6].rating = 4.2;

  strcpy(movies[7].title, "Divertidamente");
  strcpy(movies[7].synopsis, "As emoções dentro da mente de uma jovem chamada Riley ajudam-na a lidar com as mudanças em sua vida.");
  strcpy(movies[7].duration, "1h35m");
  movies[7].rating = 4.4;

  strcpy(movies[8].title, "Deadpool");
  strcpy(movies[8].synopsis, "Um ex-militar com poderes regenerativos assume a identidade de Deadpool e busca vingança contra seus algozes.");
  strcpy(movies[8].duration, "1h49m");
  movies[8].rating = 4.8;

  strcpy(movies[9].title, "Vingadores");
  strcpy(movies[9].synopsis, "Os super-heróis da Marvel se reúnem para enfrentar uma ameaça intergaláctica liderada por Thanos.");
  strcpy(movies[9].duration, "2h29m");
  movies[9].rating = 4.7;

  // Abrir arquivo no modo o 'write'
  FILE *file = fopen(LIST_MOVIES_FILE_NAME, "wt");

  if (file)
  {
    for (int i = 0; i < MOVIES_LENGTH; i++)
    {
      fprintf(file, "Filme %d:\n", i + 1);
      fprintf(file, " Título: %s \n", movies[i].title);
      fprintf(file, " Sinopse: %s \n", movies[i].synopsis);
      fprintf(file, " Duração: %s \n", movies[i].duration);
      fprintf(file, " Classificação: %.1lf/5 \n\n", movies[i].rating);
      fprintf(file, " Sala do filme: %s\n ", movies[i].title);
      // Exibir indices das colunas A a J
      for (int i = 0; i < MAX_SEAT_COLS; i++)
      {
        char c = (char)65 + i; // 65 é o A na tabela ASCII
        fprintf(file, "  %c", c);
      }
      fprintf(file, "\n");

      for (int row = 0; row < MAX_SEAT_ROWS; row++)
      {
        // Escrever índices das linhas 0 a 9
        fprintf(file, "%d ", row);
        for (int col = 0; col < MAX_SEAT_COLS; col++)
        {
          char seat = (movies[i].seats[row][col] == 0) ? ' ' : 'X';
          fprintf(file, "[%c]", seat);
        }
        fprintf(file, "\n");
      }
      fprintf(file, "\n");
    }

    // Fechar arquivo
    fclose(file);
  }
  else
    printf("Erro ao abrir\n");

  return;
}

// Escreve os assentos de cada filme em cada linha do arquivo 'Assentos.txt'
void writeSeats(int isFirstTime)
{
  // Abrir arquivo no modo o 'write'
  FILE *file = fopen(SEATS_FILE_NAME, "wt");

  if (file)
  {
    for (int movieIndex = 0; movieIndex < MOVIES_LENGTH; movieIndex++)
    {
      for (int i = 0; i < MAX_SEAT_ROWS; i++)
      {
        for (int j = 0; j < MAX_SEAT_COLS; j++)
        {
          if (isFirstTime == 1)                 // Caso seja a primeira vez
            movies[movieIndex].seats[i][j] = 0; // Inicia todos os assentos em 0
          fprintf(file, "%d ", movies[movieIndex].seats[i][j]);
        }
      }
      fprintf(file, "\n");
    }

    // Fechar arquivo
    fclose(file);
  }
  else
    printf("Erro ao abrir\n");

  return;
}

// Lê e armazena os assentos do arquivo 'Assentos.txt'
void readSeats()
{
  // Abrir arquivo no modo o 'read'
  FILE *file = fopen(SEATS_FILE_NAME, "rt");

  if (file)
  {
    for (int movieIndex = 0; movieIndex < MOVIES_LENGTH; movieIndex++)
    {
      for (int i = 0; i < MAX_SEAT_ROWS; i++)
      {
        for (int j = 0; j < MAX_SEAT_COLS; j++)
        {
          fscanf(file, "%d ", &movies[movieIndex].seats[i][j]);
        }
      }
      fscanf(file, "\n");
    }

    // Fechar arquivo
    fclose(file);
  }
  else
  {
    // Caso não exista, ele chama a função para escrever assentos
    writeSeats(1); // Passa o parâmetro 1 para a primeira vez
  }

  return;
}

// Exibe a tela do filme
void showMovieScreen()
{
  int screenSize = MAX_SEAT_COLS * 3 + 4; // Cálculo para pegar toda a área
  for (int i = 0; i < 2; i++)             // Duas linhas de exibição
  {
    switch (i)
    {
    case 0:
      for (int j = 0; j < screenSize; j++)
      {
        printf("_");
      }
      break;

    case 1:
      for (int j = 0; j < screenSize - 3; j++) // Menos o tamanho dos caracteres que sobram de 'Tela'
      {
        if (j == 0)
        {
          printf("\n\\");
        }
        else if (j > 0 && j < screenSize - 4)
        {
          if (j == (screenSize - 4) / 2) // Calcula a metade para escrever a palavra no centro
          {
            printf("Tela");
          }
          else
          {
            printf(" ");
          }
        }
        else
        {
          printf("/\n\n");
        }
      }
      break;
    }
  }

  return;
}

// Mostra os assentos de maneira formatada na tela
void showSeats(int index)
{
  printf(CYAN "Sala do filme: %s\n\n " RESET, movies[index].title);
  // Exibir indices das colunas A a J
  for (int i = 0; i < MAX_SEAT_COLS; i++)
  {
    char c = (char)65 + i; // 65 é o A na tabela ASCII
    printf(MAGENTA "  %c" RESET, c);
  }
  printf("\n");

  for (int row = 0; row < MAX_SEAT_ROWS; row++)
  {
    // Exibir índices das linhas 0 a 9
    printf(MAGENTA "%d " RESET, row);
    for (int col = 0; col < MAX_SEAT_COLS; col++)
    {
      char seat = (movies[index].seats[row][col] == 0) ? ' ' : 'X';
      // Se há alguma pessoa reservada
      if (seat == 'X')
      {
        // Se não há assentos do usuário
        if (userSeatsIndex == 0)
        {
          printf(RED "[%c]" RESET, seat);
        }
        else
        {
          int seatOccupied = 0;
          for (int seatIndex = 0; seatIndex < userSeatsIndex; seatIndex++)
          {
            // Se os índices correspondem aos números da matriz 'userSeats'
            if (userSeats[seatIndex][0] == row && userSeats[seatIndex][1] == col + 65) // 65 é o A na tabela ASCII
            {
              printf(GREEN "[%c]" RESET, seat);
              seatOccupied = 1;
              break;
            }
          }
          if (seatOccupied == 0)
          {
            printf(RED "[%c]" RESET, seat);
          }
        }
      }
      else
      {
        // Se não há ninguém
        printf("[%c]", seat);
      }
    }
    // Ao final de cada linha exibe os números dela
    printf(MAGENTA " %d" RESET, row);
    printf("\n");
  }
  // Exibe a tela do filme
  showMovieScreen();

  return;
}

// Lê e processa o(s) assento(s) escolhidos pelo usuário
void readSeat(int index)
{
  int option;
  int row, col;
  char readCol;
  int isCorrect = 0;
  int isContinue = 0;
  do
  {
    do
    {
      system("cls");
      showSeats(index);
      printf(CYAN "Selecione seu assento (Linha + Coluna. EX: 1A)\n" RESET);

      clearBuffer();
      scanf("%d%c", &row, &readCol);
      col = (int)toupper(readCol); // Retorna o valor da letra maiúscula na tabela ASCII

      // Verifica se é válido
      if (row >= 0 && row < MAX_SEAT_ROWS && col >= 65 && col < (65 + MAX_SEAT_COLS))
      {
        // Altera o assento na posição escolhida para 1
        for (int i = 0; i < MAX_SEAT_ROWS; i++)
        {
          // Verificar linha
          if (i == row)
          {
            // Verificar coluna
            for (int j = 0; j < MAX_SEAT_COLS; j++)
            {
              if (65 + j == col) // 65 é o 'A' na tabela ASCII
              {
                // Verifica se já existe alguém no assento
                if (movies[index].seats[i][j] != 0)
                {
                  invalidOption();
                }
                else
                {
                  userSeats[userSeatsIndex][0] = row;
                  userSeats[userSeatsIndex][1] = col;
                  userSeatsIndex++;
                  movies[index].seats[i][j] = 1;
                  isCorrect = 1;
                }
              }
            }
          }
        }
      }
      else
      {
        invalidOption();
        isCorrect = 0;
      }
    } while (isCorrect == 0);

    do
    {
      system("cls");
      showSeats(index);
      printf(CYAN "Você quer reservar mais um assento?\n" RESET);
      printf(" [1] Sim, quero reservar mais pessoas\n");
      printf(" [2] Não, eu não vou adicionar\n");
      scanf("%d", &option);

      switch (option)
      {
      case 1:
        isContinue = 0;
        break;
      case 2:
        isContinue = 1;
        break;
      default:
        invalidOption();
        break;
      }
    } while (option < 1 || option > 2);

  } while (isContinue == 0);

  // Depois de adicionar, os assentos são salvos no arquivo de texto
  writeSeats(0); // Parâmetro 0 pois o arquivo já existe

  return;
}

// Exibe as informações de um filme
void showMovieInformation(int movieIndex)
{
  printf(CYAN "\nFilme selecionado:\n" RESET);
  printf(" Titulo: %s \n", movies[movieIndex].title);
  printf(" Sinopse: %s \n", movies[movieIndex].synopsis);
  printf(" Duração: %s \n", movies[movieIndex].duration);
  printf(" Classificação: %.1lf/5 \n\n", movies[movieIndex].rating);
  showSeats(movieIndex);
}

// Exibe uma mensagem desejando um bom filme juntamente algumas informações
void goodBye(int movieIndex)
{
  system("cls");
  printf(MAGENTA BOLD "\nBom Filme!\n" RESET);
  printf("Esperamos proporcionar a você uma experiência cinematográfica incrível.\n");

  showMovieInformation(movieIndex);
  printf(CYAN "\nSeu(s) assento(s):\n" RESET);
  for (int i = 0; i < userSeatsIndex; i++)
  {
    printf(" - %d%c\n", userSeats[i][0], (char)userSeats[i][1]);
  }

  printf(MAGENTA BOLD "Tenha uma ótima sessão!\n" RESET);
  printf("OBS: Para maiores informações sobre os filmes, acesse o arquivo '%s'\n\n", LIST_MOVIES_FILE_NAME);

  return;
}

int main()
{
  // Permitir acentuação
  setlocale(LC_ALL, "Portuguese");

  readSeats();
  writeMovies();

  int option, option2;

  // "CinemaC"
  printf(MAGENTA BOLD " ,-----.,--.                                  ,-----. \n");
  printf("'  .--./`--',--,--,  ,---. ,--,--,--. ,--,--.'  .--./ \n");
  printf("|  |    ,--.|      \\| .-. :|        |' ,-.  ||  |     \n");
  printf("'  '--'\\|  ||  ||  |\\   --.|  |  |  |\\ '-'  |'  '--'\\ \n");
  printf(" `-----'`--'`--''--' `----'`--`--`--' `--`--' `-----' \n\n");
  printf(CYAN "Bem Vindo ao CinemaC!\n" RESET);
  do
  {
    do
    {
      printf("Selecione o Filme que deseja assistir:\n");
      for (int i = 0; i < MOVIES_LENGTH; i++)
      {
        printf(" [%d] %s \n", i + 1, movies[i].title);
      }
      scanf("%d", &option);

      if (option < 1 || option > MOVIES_LENGTH)
      {
        invalidOption();
      }
    } while (option < 1 || option > MOVIES_LENGTH);

    showMovieInformation(option - 1);

    printf("Continuar?\n");
    printf(" [1] Sim, vou assistir esse filme\n");
    printf(" [2] Não, eu quero assistir outro filme\n");
    scanf("%d", &option2);

    if (option2 < 1 || option2 > 2)
    {
      invalidOption();
    }
    system("cls");
  } while (option2 != 1);

  readSeat(option - 1);

  goodBye(option - 1);

  return 0;
}
