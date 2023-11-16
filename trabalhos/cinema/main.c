#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define LIST_MOVIES_FILE_NAME "Lista-de-Filmes.txt"
#define SEATS_FILE_NAME "Assentos.txt"

#define MOVIES_LENGTH 3
#define MAX_SEAT_COLS 10
#define MAX_SEAT_ROWS 10

typedef struct
{
  char title[50];
  char synopsis[200];
  char duration[7];
  int rating;
  int seats[MAX_SEAT_ROWS][MAX_SEAT_COLS];
} Movie;

Movie movies[MOVIES_LENGTH];

void invalidOption()
{
  printf("\nOpção inválida! Tente novamente.\n");
  getch();
  system("cls");
}

void writeMovies()
{
  // Definir os filmes
  strcpy(movies[0].title, "Cidade de Deus");
  strcpy(movies[0].synopsis, "A trajetória de dois amigos que crescem em uma favela do Rio de Janeiro e seguem caminhos distintos na vida do crime.");
  strcpy(movies[0].duration, "2h10m12");
  movies[0].rating = 9;

  strcpy(movies[1].title, "Central do Brasil");
  strcpy(movies[1].synopsis, "Uma história emocionante sobre a amizade entre uma mulher idosa e um menino órfão em uma viagem pelo interior do Brasil.");
  strcpy(movies[1].duration, "1h53m10");
  movies[1].rating = 8;

  strcpy(movies[2].title, "Tropa de Elite");
  strcpy(movies[2].synopsis, "Um capitão do BOPE enfrenta desafios éticos e morais ao tentar combater a criminalidade no Rio de Janeiro.");
  strcpy(movies[2].duration, "1h55m47");
  movies[2].rating = 8;

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
      fprintf(file, " Classificação: %d/10 \n\n", movies[i].rating);
    }

    // Fechar arquivo
    fclose(file);
  }
  else
    printf("Erro ao abrir\n");
}

void writeSeats(int movieIndex)
{
  // Abrir arquivo no modo o 'append' para adicionar abaixo
  FILE *file = fopen(SEATS_FILE_NAME, "a");

  if (file)
  {
    for (int i = 0; i < MAX_SEAT_ROWS; i++)
    {
      for (int j = 0; j < MAX_SEAT_COLS; j++)
      {
        movies[movieIndex].seats[i][j] = 0;
        fprintf(file, "%d ", movies[movieIndex].seats[i][j]);
      }
    }
    fprintf(file, "\n");

    // Fechar arquivo
    fclose(file);
  }
  else
    printf("Erro ao abrir\n");
}

void readSeats(int movieIndex)
{
  // Abrir arquivo no modo o 'read'
  FILE *file = fopen(SEATS_FILE_NAME, "rt");

  if (file)
  {
    for (int i = 0; i < MAX_SEAT_ROWS; i++)
    {
      for (int j = 0; j < MAX_SEAT_COLS; j++)
      {
        fscanf(file, "%d ", &movies[movieIndex].seats[i][j]);
      }
    }
    fscanf(file, "\n");

    // Fechar arquivo
    fclose(file);
  }
  else
  {
    for (int i = 0; i < MOVIES_LENGTH; i++)
    {
      writeSeats(i);
    }
  }
}

int main()
{
  // Permitir acentuação
  setlocale(LC_ALL, "Portuguese");

  for (int i = 0; i < MOVIES_LENGTH; i++)
    readSeats(i);
  writeMovies();

  int option;

  do
  {
    printf("BEM VINDO AO CINEMA!\n");
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

  printf("Filme %d \n\n", option - 1);
  for (int i = 0; i < MAX_SEAT_ROWS; i++)
  {
    for (int j = 0; j < MAX_SEAT_COLS; j++)
    {
      printf("%d ", movies[0].seats[i][j]);
    }
    printf("\n");
  }

  return 0;
}

/*
for (int i = 0; i < MOVIES_LENGTH; i++)
{
  fprintf(file, "Filme %d:\n ", i + 1);
  // Exibir indices das colunas A a J
  for (int j = 0; j < MAX_SEAT_COLS; j++)
  {
    char c = (char)65+j; // 65 é o A na tabela ASCII
    fprintf(file, "  %c", c);
  }
  fprintf(file, "\n");

  for (int row = 0; row < MAX_SEAT_ROWS; row++)
  {
    // Exibir índices das linhas 0 a 9
    fprintf(file, "%d ", row);
    for (int col = 0; col < MAX_SEAT_COLS; col++)
    {
      char seat = (seats[row][col] == 0) ? ' ' : 'X';
      fprintf(file, "[%c]", seat);
    }
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
}
*/