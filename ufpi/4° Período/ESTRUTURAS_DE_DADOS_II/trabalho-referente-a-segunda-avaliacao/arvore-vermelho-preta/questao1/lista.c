#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
  int linha;
  Lista *prox;
};

Lista* iniciaLista(){
  return NULL;
}

Lista* insereLista(Lista *lista, int linha){

  Lista *aux,*new;
  new = (Lista*)malloc(sizeof(Lista));
  new->linha = linha;
  new->prox = NULL;
  aux = lista;  
  while (aux != NULL)
  {
    aux = aux->prox;
  }
  aux = new;
  return lista;
}

void mostrarLinhas(Lista *lista){
  Lista *aux;
  aux = lista;
  while(aux != NULL){
    printf("Linha: %i\n", aux->linha);
    aux = aux->prox;
  }
}
