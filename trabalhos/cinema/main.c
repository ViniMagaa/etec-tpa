#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>

#define LIST_MOVIES_FILE_NAME "Lista-de-Filmes.txt"
#define SEATS_FILE_NAME "Assentos.txt"

#define MOVIES_LENGTH 3
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
  int rating;
  int seats[MAX_SEAT_ROWS][MAX_SEAT_COLS];
} Movie;

Movie movies[MOVIES_LENGTH];
int userSeats[MAX_SEAT_ROWS * MAX_SEAT_COLS][2];
int userSeatsIndex = 0;

// Limpa o buffer do teclado
void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  return;
}

// Exibe uma mensagem de 'Erro: op��o inv�lida' e aguarda um caractere
void invalidOption()
{
  printf(RED BOLD "\nOp��o inv�lida! Tente novamente.\n(Pressione qualquer tecla para continuar)\n" RESET);
  getch();
  system("cls");

  return;
}

// Escreve os filmes com suas informa��es no arquivo 'Lista-de-Filmes.txt'
void writeMovies()
{
  // Definir os filmes
  strcpy(movies[0].title, "Cidade de Deus");
  strcpy(movies[0].synopsis, "A trajet�ria de dois amigos que crescem em uma favela do Rio de Janeiro e seguem caminhos distintos na vida do crime.");
  strcpy(movies[0].duration, "2h10m");
  movies[0].rating = 9;

  strcpy(movies[1].title, "Central do Brasil");
  strcpy(movies[1].synopsis, "Uma hist�ria emocionante sobre a amizade entre uma mulher idosa e um menino �rf�o em uma viagem pelo interior do Brasil.");
  strcpy(movies[1].duration, "1h53m");
  movies[1].rating = 8;

  strcpy(movies[2].title, "Tropa de Elite");
  strcpy(movies[2].synopsis, "Um capit�o do BOPE enfrenta desafios �ticos e morais ao tentar combater a criminalidade no Rio de Janeiro.");
  strcpy(movies[2].duration, "1h55m");
  movies[2].rating = 8;

  // Abrir arquivo no modo o 'write'
  FILE *file = fopen(LIST_MOVIES_FILE_NAME, "wt");

  if (file)
  {
    for (int i = 0; i < MOVIES_LENGTH; i++)
    {
      fprintf(file, "Filme %d:\n", i + 1);
      fprintf(file, " T�tulo: %s \n", movies[i].title);
      fprintf(file, " Sinopse: %s \n", movies[i].synopsis);
      fprintf(file, " Dura��o: %s \n", movies[i].duration);
      fprintf(file, " Classifica��o: %d/10 \n\n", movies[i].rating);
      fprintf(file, " Sala do filme: %s\n ", movies[i].title);
      // Exibir indices das colunas A a J
      for (int i = 0; i < MAX_SEAT_COLS; i++)
      {
        char c = (char)65 + i; // 65 � o A na tabela ASCII
        fprintf(file, "  %c", c);
      }
      fprintf(file, "\n");

      for (int row = 0; row < MAX_SEAT_ROWS; row++)
      {
        // Escrever �ndices das linhas 0 a 9
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

// L� e armazena os assentos do arquivo 'Assentos.txt'
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
    // Caso n�o exista, ele chama a fun��o para escrever assentos
    writeSeats(1); // Passa o par�metro 1 para a primeira vez
  }

  return;
}

// Exibe a tela do filme
void showMovieScreen()
{
  int screenSize = MAX_SEAT_COLS * 3 + 4; // C�lculo para pegar toda a �rea
  for (int i = 0; i < 2; i++)             // Duas linhas de exibi��o
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
  printf(CYAN "Sala do filme: %s\n " RESET, movies[index].title);
  // Exibir indices das colunas A a J
  for (int i = 0; i < MAX_SEAT_COLS; i++)
  {
    char c = (char)65 + i; // 65 � o A na tabela ASCII
    printf(MAGENTA "  %c" RESET, c);
  }
  printf("\n");

  for (int row = 0; row < MAX_SEAT_ROWS; row++)
  {
    // Exibir �ndices das linhas 0 a 9
    printf(MAGENTA "%d " RESET, row);
    for (int col = 0; col < MAX_SEAT_COLS; col++)
    {
      char seat = (movies[index].seats[row][col] == 0) ? ' ' : 'X';
      // Se h� alguma pessoa reservada
      if (seat == 'X')
      {
        // Se n�o h� assentos do usu�rio
        if (userSeatsIndex == 0)
        {
          printf(RED "[%c]" RESET, seat);
        }
        else
        {
          int seatOccupied = 0;
          for (int seatIndex = 0; seatIndex < userSeatsIndex; seatIndex++)
          {
            // Se os �ndices correspondem aos n�meros da matriz 'userSeats'
            if (userSeats[seatIndex][0] == row && userSeats[seatIndex][1] == col + 65) // 65 � o A na tabela ASCII
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
        // Se n�o h� ningu�m
        printf("[%c]", seat);
      }
    }
    // Ao final de cada linha exibe os n�meros dela
    printf(MAGENTA " %d" RESET, row);
    printf("\n");
  }
  // Exibe a tela do filme
  showMovieScreen();

  return;
}

// L� e processa o(s) assento(s) escolhidos pelo usu�rio
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
      col = (int)toupper(readCol); // Retorna o valor da letra mai�scula na tabela ASCII

      // Verifica se � v�lido
      if (row >= 0 && row < MAX_SEAT_ROWS && col >= 65 && col < (65 + MAX_SEAT_COLS))
      {
        // Altera o assento na posi��o escolhida para 1
        for (int i = 0; i < MAX_SEAT_ROWS; i++)
        {
          // Verificar linha
          if (i == row)
          {
            // Verificar coluna
            for (int j = 0; j < MAX_SEAT_COLS; j++)
            {
              if (65 + j == col) // 65 � o 'A' na tabela ASCII
              {
                // Verifica se j� existe algu�m no assento
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
      printf(CYAN "Voc� quer reservar mais um assento?\n" RESET);
      printf(" [1] Sim, quero reservar mais pessoas\n");
      printf(" [2] N�o, eu n�o vou adicionar\n");
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

  // Depois de adicionar, os assentos s�o salvos no arquivo de texto
  writeSeats(0); // Par�metro 0 pois o arquivo j� existe

  return;
}

// Exibe as informa��es de um filme
void showMovieInformation(int movieIndex)
{
  printf(CYAN "\nFilme selecionado:\n" RESET);
  printf(" Titulo: %s \n", movies[movieIndex].title);
  printf(" Sinopse: %s \n", movies[movieIndex].synopsis);
  printf(" Dura��o: %s \n", movies[movieIndex].duration);
  printf(" Classifica��o: %d/10 \n\n", movies[movieIndex].rating);
  showSeats(movieIndex);
}

// Exibe uma mensagem desejando um bom filme juntamente algumas informa��es
void goodBye(int movieIndex)
{
  system("cls");
  printf(MAGENTA BOLD "\nBom Filme!\n" RESET);
  printf("Esperamos proporcionar a voc� uma experi�ncia cinematogr�fica incr�vel.\n");

  showMovieInformation(movieIndex);
  printf(CYAN "\nSeus assentos:\n" RESET);
  for (int i = 0; i < userSeatsIndex; i++)
  {
    printf(" - %d%c\n", userSeats[i][0], (char)userSeats[i][1]);
  }

  printf(MAGENTA BOLD "\nTenha uma �tima sess�o!\n\n" RESET);

  return;
}

int main()
{
  // Permitir acentua��o
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
    printf(" [2] N�o, eu quero assistir outro filme\n");
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
