#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "implementacoes_arquivo.c"


int menu()
{
  int r;
  FILE *file;

  printf("\n(1) - inserir\n(2) - remover\n(3) - mostrar\n(-1) - sair\nDigite a opcao: ");
  scanf("%i", &r);
  setbuf(stdin, NULL);

  return r;
}

int main()
{

  Avr *raiz;
  FILE *file;
  int inseriu, r, valor, i = 0, linha = 1;
  char c, palavra[50], palavra_remove[50];

  r = -2;
  raiz = inicializa();

  while (r != -1)
  {
    r = menu();
    setbuf(stdin, NULL);

    switch (r)
    {
    case 1:

      file = fopen("arquivo_de_texto.txt", "r");
      c = fgetc(file);
      while (c != EOF)
      {
        if (c == '\n')
        {
          palavra[i] = '\0';
          inseriu = insereAvrRedBlack(&raiz, palavra, linha);
          i = 0;
          linha++;
        }
        palavra[i] = c;
        i++;
        c = fgetc(file);
      }

      fclose(file);
      break;
    case 2:
      printf("Qual palavra deseja remover: ");
      scanf("%s", palavra_remove);

      if (remove_AvrLLRB(raiz, palavra_remove) == 1)
      {
        printf("\nPalavra removido!\n");
      }
      else
      {
        printf("\nPalavra nao encontrado!\n");
      }
      break;
    case 3:
      mostrarAvr(raiz);
      printf("-=-=-=-=-=-=-=-\n");
      break;
    }
  }

  return 0;
}