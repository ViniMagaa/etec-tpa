#include <stdio.h>
#include <string.h>
#include <conio.h>

#define LIST_MOVIES_FILE_NAME "Lista-de-Filmes.txt"
#define MOVIES_LENGTH 3

typedef struct
{
  char title[50];
  char synopsis[200];
  char duration[7];
  int rating;
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
  FILE *file = fopen(LIST_MOVIES_FILE_NAME, "w");

  if (file)
  {
    for (int i = 0; i < MOVIES_LENGTH; i++)
    {
      fprintf(file, "Filme %d:\n", i+1);
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

void readMovies()
{
  printf("oi");
}

int main()
{
  writeMovies();

  int option;

  do
  {
    printf("BEM VINDO AO CINEMA!\n");
    printf("Selecione o Filme que deseja assistir:\n");
    for (int i = 0; i < MOVIES_LENGTH; i++)
    {
      printf(" [%d] %s \n", i+1, movies[i].title);
    }
    scanf("%d", &option);

    if (option < 1 || option > MOVIES_LENGTH)
    {
      invalidOption();
    }
    else
      printf("AEEE Filme %d", option-1);
  } while (option < 1 || option > MOVIES_LENGTH);

  return 0;
}