#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "lista.h"
#include "lista.c"

struct avr
{
  char palavra[100];
  char cor;
  int valor;
  Avr *dir;
  Avr *esq;
  Lista *lista;
};

Avr *inicializa()
{
  return NULL;
}

Avr *criaNo(char *palavra, int linha)
{
  Avr *no;
  no = (Avr *)malloc(sizeof(Avr));
  strcpy(no->palavra,palavra);
  no->cor = 'R';
  no->lista = iniciaLista();
  no->dir = NULL;
  no->esq = NULL;

  return no;
}

int insereAvrRedBlack(Avr **raiz, char *palavra, int linha)
{

  int inseriu = 0;

  Avr *no;
  no = criaNo(palavra,linha);

  inseriu = insereNo(&(*raiz), no, linha);
  (*raiz)->cor = 'B';

  return inseriu;
}

int insereNo(Avr **raiz, Avr *no, int linha)
{
  int inseriu = 0;

  // inserindo no
  if ((*raiz) == NULL)
  {
    (*raiz) = no;
    (*raiz)->lista = insereLista((*raiz)->lista,linha);
    inseriu = 1;
  }
  else if (strcmp(no->palavra,(*raiz)->palavra) == -1)
  {
    insereNo(&((*raiz)->esq), no, linha);
  }
  else if (strcmp(no->palavra,(*raiz)->palavra) == 1)
  {
    insereNo(&((*raiz)->dir), no, linha);
  }
  else if(strcmp(no->palavra,(*raiz)->palavra) == 0){
    (*raiz)->lista = insereLista((*raiz)->lista,linha);
  }
  // verificando as cores
  if (cor((*raiz)->dir) == 'R' && cor((*raiz)->esq) == 'B')
  {
    rotacionaEsquerda(&(*raiz));
  }
  if (cor((*raiz)->esq) == 'R' && cor((*raiz)->esq->esq) == 'R')
  {
    rotacionaDireita(&(*raiz));
  }
  if (cor((*raiz)->esq) == 'R' && cor((*raiz)->dir) == 'R')
  {
    trocaCor(&(*raiz));
  }

  return inseriu;
}

void mostrarAvr(Avr *raiz)
{

  if (raiz != NULL)
  {
    mostrarAvr(raiz->esq);
    mostrarNo(raiz);
    mostrarAvr(raiz->dir);
  }
}

void mostrarNo(Avr *no)
{
  printf("-=-=-=-=-=-=-=-\n");
  printf("Palavra: %s\nCor: %c\n", no->palavra,no->cor);
  mostrarLinhas(no->lista);
}

void rotacionaEsquerda(Avr **no)
{

  Avr *aux;
  aux = (*no)->dir;

  // trocando cor
  aux->cor = (*no)->cor;
  (*no)->cor = 'R';

  // trocando ponteiros
  (*no)->dir = aux->esq;
  aux->esq = (*no);
  (*no) = aux;
}

void rotacionaDireita(Avr **no)
{

  Avr *aux;
  aux = (*no)->esq;

  // trocando cor
  aux->cor = (*no)->cor;
  (*no)->cor = 'R';

  // trocando ponteiros
  (*no)->esq = aux->dir;
  aux->dir = (*no);
  (*no) = aux;
}

void trocaCor(Avr **raiz)
{

  (*raiz)->dir->cor = 'B';
  (*raiz)->esq->cor = 'B';
  (*raiz)->cor = 'R';
}

char cor(Avr *no)
{
  char cor;
  cor = 'B';

  if (no != NULL)
  {
    cor = no->cor;
  }

  return cor;
}

Avr *balancear(Avr *H)
{

  if (cor(H->dir) == 'R')
  {
    rotacionaEsquerda(&H);
  }
  if (H->esq != NULL && cor(H->dir) == 'R' && cor(H->esq->esq) == 'R')
  {
    rotacionaDireita(&H);
  }
  if (cor(H->esq) == 'R' && cor(H->dir) == 'R')
  {
    trocaCor(&H);
  }

  return H;
}

Avr *move2DirRED(Avr *H)
{
  trocaCor(&H);

  if (cor(H->esq->esq) == 'R')
  {
    rotacionaDireita(&H);
    trocaCor(&H);
  }

  return H;
}

Avr *move2EsqRED(Avr *H)
{
  trocaCor(&H);

  if (cor(H->dir->esq) == 'R')
  {
    rotacionaDireita(&(H->dir));
    rotacionaEsquerda(&H);
    trocaCor(&H);
  }

  return H;
}

Avr *procuraMenor(Avr *atual)
{
  Avr *no1, *no2;
  no1 = atual;
  no2 = atual->esq;

  while (no2 != NULL)
  {
    no1 = no2;
    no2 = no2->esq;
  }

  return no1;
}

Avr *removerMenor(Avr *H)
{
  if (H->esq == NULL)
  {
    free(H);
    return NULL;
  }

  if (cor(H->esq) == 'B' && cor(H->esq->esq) == 'B')
  {
    H = move2EsqRED(H);
  }
  H->esq = removerMenor(H);

  return balancear(H);
}

Avr *remove_NO(Avr *H, char *palavra)
{

  if (strcmp(palavra,H->palavra) == -1)
  {
    if (cor(H->esq) == 'B' && cor(H->esq->esq) == 'B')
    {
      H = move2EsqRED(H);
    }
    H->esq = remove_NO(H->esq, palavra);
  }
  else
  {
    if (cor(H->esq) == 'R')
    {
      rotacionaDireita(&H);
    }
    if (strcmp(palavra,H->palavra) == 0 && (H->dir == NULL))
    {
      free(H);
      return NULL;
    }
    if (cor(H->dir) == 'B' && cor(H->dir->esq) == 'B')
    {
      H = move2DirRED(H);
    }
    if (strcmp(palavra,H->palavra) == 0)
    {
      Avr *x;
      x = procuraMenor(H->dir);
      H->dir = removerMenor(H->dir);
    }
    else
    {
      H->dir = remove_NO(H->dir, palavra);
    }
  }

  return balancear(H);
}

int remove_AvrLLRB(Avr *raiz, char *palavra)
{
  if (consulta_AvrLLRB(raiz, palavra) == 1)
  {
    Avr *h;
    h = raiz;
    raiz = remove_NO(h, palavra);
    if (raiz != NULL)
    {
      raiz->cor = 'B';
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

int consulta_AvrLLRB(Avr *raiz, char *palavra)
{
  int achou = 0;

  if (raiz != NULL)
  {
    printf("%s\n", raiz->palavra);
    if (strcmp(palavra,raiz->palavra) == 0)
    {
      achou = 1;
    }
    else if (strcmp(palavra,raiz->palavra) == -1)
    {
      achou = consulta_AvrLLRB(raiz->esq, palavra);
    }
    else
    {
      achou = consulta_AvrLLRB(raiz->dir, palavra);
    }
  }

  return achou;
}