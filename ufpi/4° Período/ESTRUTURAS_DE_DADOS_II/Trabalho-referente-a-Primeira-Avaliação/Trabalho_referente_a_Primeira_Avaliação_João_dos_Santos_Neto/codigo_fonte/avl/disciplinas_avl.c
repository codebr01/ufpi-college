#include "disciplinas_avl.h"
#include <stdio.h>
#include <stdlib.h>

struct disciplinas {
  int id;
  Disciplinas *left, *right;
  char name_of_discipline[100];
  int block;
  int workload;
  int altura;
};

Disciplinas *createNodeDiscipline(int bloco) {
  Disciplinas *node;
  node = (Disciplinas *)malloc(sizeof(Disciplinas));
  node->id = rand() % 1000;
  node->block = 1 + rand() % bloco;
  node->workload = rand() % 100;
  node->altura = alturaDisciplina(node);
  //printf("Digite o nome da disciplina: ");
  //scanf("%[^\n]s", node->name_of_discipline);
  return node;
}

void insertDisciplina(Disciplinas **root, int bloco){
  Disciplinas *node;
  node = createNodeDiscipline(bloco);
  insertTreeDiscipline(root, node);
}

void insertTreeDiscipline(Disciplinas **root, Disciplinas *node) {
  int fb;
  if ((*root) == NULL) {
    (*root) = node;
  } else if (node->id < (*root)->id) {
    insertTreeDiscipline(&((*root)->left), node);
  } else if (node->id > (*root)->id) {
    insertTreeDiscipline(&((*root)->right), node);
  }
  fb = fatorBalanceamentoDisciplina((*root));
  if(fb == 2){
    if(fatorBalanceamentoDisciplina((*root)->left) < 0){
      rotacaoEsquerdaDisciplina(&((*root)->left));    
    }
    rotacaoDireitaDisciplina(&(*root));
  }else if (fb == -2){
    if(fatorBalanceamentoDisciplina((*root)->right) > 0){
      rotacaoDireitaDisciplina(&((*root)->right));
    }
    rotacaoEsquerdaDisciplina(&(*root));
  }
  atualizarAlturaDisciplina((*root));
}

void printInOrdemDiscipline(Disciplinas *root) {
  if (root != NULL) {
    printInOrdemDiscipline(root->left);
    printf("\nCodigo da Disciplna: %d\nNome da Disciplina: \nBloco: %i\nCarga Horaria: %i\n\n",root->id,root->block,root->workload);
    printInOrdemDiscipline(root->right);
  }
}

void printDiscipline(Disciplinas *root, int cod_discipline){
  Disciplinas *find;
  find = searchNodeDiscipline(root,cod_discipline);
  if(find){
    printf("\nCodigo da Disciplna: %d\nNome da Disciplina: \nBloco: %i\nCarga Horaria: \n\n",find->id,find->block);
  }else{
    printf("\nCodigo da disciplina não existe!\n");
  }
}
Disciplinas *searchNodeDiscipline(Disciplinas *root, int cod){
  Disciplinas *find;
  find = NULL;
  if (root != NULL) {
    if (root->id == cod) {
      find = root;
    } else if (cod < root->id) {
      find = searchNodeDiscipline(root->left, cod);
    } else {
      find = searchNodeDiscipline(root->right, cod);
    }
  }
  return find;
}
void printDisciplinaInBlock(Disciplinas *root, int bloco){
  if (root != NULL) {
    printDisciplinaInBlock(root->left, bloco);
    if (root->block == bloco){
      printf("\n\nCodigo da Disciplna: %d\nNome da Disciplina: \nBloco: %i\nCarga "
           "Horaria: \n\n",
           root->id,root->block);
    }
    printDisciplinaInBlock(root->right, bloco);
  }
}

void printDisciplinaWorkload(Disciplinas *root, int workload){
  if (root != NULL) {
    printDisciplinaInBlock(root->left, workload);
    if (root->workload == workload){
      printf("\nCodigo da Disciplina: %i\nNome da Disciplina: \nBloco: %i\nCarga Horaria: %i\n\n",root->id,root->block, root->workload);
    }
    printDisciplinaInBlock(root->right, workload);
  }
}

int removeDiscipline(Disciplinas **root, int id){
  Disciplinas *aux,*filho,*maior;
  int removeu = 0,fb;
  if(*root != NULL){
    if(id == (*root)->id){
      removeu = 1;
      if(ehFolhaInt(*root) == 1){
        aux = *root;
        (*root) = NULL;
        free(aux);
      }
      else if(umFilhoInt(*root) == 1){
        filho = umFilho(*root);
        aux = (*root);
        (*root) = filho;
        free(aux);
      }
      else if(doisFilhoInt(*root) == 1){
        filho = buscaMaiorEsq((*root)->left);
        aux = (*root);
        filho->right = (*root)->right;
        (*root) = filho;
        free(aux);
      }
    }
    else if(id < (*root)->id){
      removeu = removeDiscipline(&((*root)->left),id);
    }else{
      removeu = removeDiscipline(&((*root)->right),id);
    }
    if((*root) != NULL){
      fb = fatorBalanceamentoDisciplina((*root));
      if(fb == 2){
        if(fatorBalanceamentoDisciplina((*root)->left) < 0){
          rotacaoEsquerdaDisciplina(&((*root)->left));    
        }
        rotacaoDireitaDisciplina(&(*root));
      }else if(fb == -2){
        if(fatorBalanceamentoDisciplina((*root)->right) > 0){
          rotacaoDireitaDisciplina(&((*root)->right));
        }
        rotacaoEsquerdaDisciplina(&(*root));
      }
      atualizarAlturaDisciplina((*root));
    }
  }
  return removeu;
}

Disciplinas* ehFolha(Disciplinas *no){
  Disciplinas *sim;
  sim = NULL;
  if(no->left == NULL && no->right == NULL){
    sim = no;
  }
  return sim;
}

int ehFolhaInt(Disciplinas *no){
  int sim;
  sim = 0;
  if(no->left == NULL && no->right == NULL){
    sim = 1;
  }
  return sim;
}

Disciplinas* umFilho(Disciplinas *no){
  Disciplinas *sim;
  sim = NULL;
  if((no->left != NULL && no->right == NULL) || (no->left == NULL && no->right != NULL)){
    if(no->left == NULL){
      sim = no->right;
    }else{
      sim = no->left;
    }
  }
  return sim;
}

int umFilhoInt(Disciplinas *no){
  int sim;
  sim = 0;
  if((no->left != NULL && no->right == NULL) || (no->left == NULL && no->right != NULL)){
    sim = 1;
  }
  return sim;
}

Disciplinas* doisFilho(Disciplinas *no){
  Disciplinas *sim;
  sim = NULL;
  if(no->left != NULL && no->right != NULL){
    sim = no;
  }
  return sim;
}

int doisFilhoInt(Disciplinas *no){
  int sim;
  sim = 0;
  if(no->left != NULL && no->right != NULL){
    sim = 1;
  }
  return sim;
}

Disciplinas* buscaMaiorEsq(Disciplinas *no){
  Disciplinas *maior;
  if(no->right == NULL){
    maior = no;
  }else{
    maior = buscaMaiorEsq(no->right);
  }
  return maior;
}

void removerTodasDisciplinas(Disciplinas **root){
  Disciplinas *aux;
  if(((*root)->left == NULL) && ((*root)->right == NULL)){
    aux = (*root);
    (*root) = NULL;
    free(aux);
  }else{
    removerTodasDisciplinas(&((*root)->left));
    removerTodasDisciplinas(&((*root)->right));
  }

}

int alturaDisciplina(Disciplinas *no){
  int he,hd,h;
  if(no != NULL){
    he = alturaDisciplina(no->left);
    hd = alturaDisciplina(no->right);
    if(he > hd){
      h = he + 1;
    }else{
      h = hd + 1;
    }
  }else{
    h = 0;
  }
  return h;
}

int fatorBalanceamentoDisciplina(Disciplinas *no){
  return alturaDisciplina(no->left) - alturaDisciplina(no->right);
}

void rotacaoEsquerdaDisciplina(Disciplinas **node){
  Disciplinas *aux,*q;
  q = (*node)->right;
  aux = q->left;
  q->left = (*node);
  (*node)->right = aux;
  (*node) = q;
}

void rotacaoDireitaDisciplina(Disciplinas **node){
  Disciplinas *aux,*q;
  q = (*node)->left;
  aux = q->right;
  q->right = (*node);
  (*node)->left = aux;
  (*node) = q;
}

void atualizarAlturaDisciplina(Disciplinas *node){
  node->altura = alturaDisciplina(node);
}

void deletarDisciplinas(Disciplinas **root){
  (*root) = NULL;
}
