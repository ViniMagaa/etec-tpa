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

// Limpa o buffer do teclado
void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe uma mensagem de 'Erro: opção inválida' e aguarda um caractere
void invalidOption()
{
  printf("\nOpção inválida! Tente novamente.\n");
  getch();
  system("cls");
}

// Escreve os filmes com suas informações no arquivo 'Lista-de-Filmes.txt'
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
      fprintf(file, " Classificação: %d/10 \n", movies[i].rating);
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
          if (isFirstTime == 1) // Caso seja a primeira vez
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
    // Caso não exista, ele chama a função 'writeSeats(1)'
    writeSeats(1); // Passa o parâmetro 1 para a primeira vez
  }
}

// Mostra os assentos de maneira formatada na tela
void showSeats(int index)
{
  printf(" Sala do filme: %s\n ", movies[index].title);
  // Exibir indices das colunas A a J
  for (int i = 0; i < MAX_SEAT_COLS; i++)
  {
    char c = (char)65 + i; // 65 é o A na tabela ASCII
    printf("  %c", c);
  }
  printf("\n");

  for (int row = 0; row < MAX_SEAT_ROWS; row++)
  {
    // Exibir índices das linhas 0 a 9
    printf("%d ", row);
    for (int col = 0; col < MAX_SEAT_COLS; col++)
    {
      char seat = (movies[index].seats[row][col] == 0) ? ' ' : 'X';
      printf("[%c]", seat);
    }
    printf("\n");
  }
  printf("\n");
}

// Lê e processa o(s) assento(s) escolhidos pelo usuário
void readSeat(int index)
{
  int option;
  int row, col;
  char readCol;
  int isCorrect = 0;
  do
  {
    do
    {
      system("cls");
      showSeats(index);
      printf("Selecione seu assento (Linha + Coluna. EX: 1A)\n");

      clearBuffer();
      scanf("%d%c", &row, &readCol);
      col = (int)toupper(readCol); // Retorna o valor da letra maiúscula na tabela ASCII

      // Verifica se é válido
      if (row >= 0 && row < MAX_SEAT_ROWS && col >= 65 && col < (65 + MAX_SEAT_COLS))
      {
        isCorrect = 1;
      }
      else
      {
        invalidOption();
        isCorrect = 0;
      }
    } while (isCorrect == 0);

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
            movies[index].seats[i][j] = 1;
          }
        }
      }
    }

    system("cls");
    showSeats(index);
    printf("Você quer reservar mais um assento?\n");
    printf(" [1] Não, eu não vou adicionar\n");
    printf(" [2] Sim, quero reservar mais pessoas\n");
    scanf("%d", &option);
    if (option < 1 || option > 2)
    {
      invalidOption();
    }
  } while (option != 1);

  // Depois de adicionar, os assentos são salvos no arquivo de texto
  writeSeats(0); // Parâmetro 0 pois o arquivo já existe
}

// Exibe as informações de um filme
void showMovieInformation(int movieIndex)
{
  printf("\nFilme selecionado:\n");
  printf(" Titulo: %s \n", movies[movieIndex].title);
  printf(" Sinopse: %s \n", movies[movieIndex].synopsis);
  printf(" Duração: %s \n", movies[movieIndex].duration);
  printf(" Classificação: %d/10 \n", movies[movieIndex].rating);
  showSeats(movieIndex);
}

int main()
{
  // Permitir acentuação
  setlocale(LC_ALL, "Portuguese");

  readSeats();
  writeMovies();

  int option, option2;

  printf("BEM VINDO AO CINEMA!\n");
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

    showMovieInformation(option-1);

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

  printf("\nBom Filme!\n");
  printf("Esperamos proporcionar a você uma experiência cinematográfica incrível. Tenha uma ótima sessão!\n\n");

  return 0;
}
