#include "curso_abb.h"
#include "disciplinas_abb.h"
#include <stdio.h>
#include <stdlib.h>

struct curso {
  int id, blocos;
  char name_of_course[20];
  int num_of_week;
  Curso *left, *right;
  Disciplinas *disciplinas;
};

Curso *create() { return NULL; }

Curso *createNode(int id) {
  Curso *node = (Curso *)malloc(sizeof(Curso));
  node->id = id;
  node->blocos = 1 + rand() % 7;
  node->num_of_week = 15;
  //node->disciplinas = deletarDisciplinas();
  //printf("Digite o nome do curso: ");
  //scanf("%[^\n]s", node->name_of_course);
  //setbuf(stdin, NULL);
  node->left = NULL;
  node->right = NULL;
  for (int i = 0; i < 5; i++) {
    insertDisciplina(&node->disciplinas,node->blocos);
  }

  return node;
}

void insertCourse(Curso **root,int idCurso){
  Curso *node;
  node = createNode(idCurso);
  insertTree(root, node);
}

void insertTree(Curso **root, Curso *node){
  if ((*root) == NULL) {
    (*root) = node;
  } else if (node->id < (*root)->id) {
    insertTree(&((*root)->left), node);
  } else if (node->id > (*root)->id) {
    insertTree(&((*root)->right), node);
  }
}

void searchCourse(Curso *root, int id) {
  if (root != NULL) {
    if (root->id > id) {
      searchCourse(root->left, id);
    } else if (root->id < id) {
      searchCourse(root->right, id);
    } else if (root->id == id) {
      printf("\nCodigo Curso: %d\nNome do Curso: %s\nQuantidade de Blocos: "
             "%i\nNumero de Semanas: %i\n\n",
             root->id, root->name_of_course, root->blocos, root->num_of_week);
    }
  } else {
    printf("\nCurso inexistente!");
  }
}
void showBlocks(Curso *root, int qtdBlock) {
  if (root != NULL) {
    showBlocks(root->left, qtdBlock);
    if(root->blocos == qtdBlock) {
      printf("\nCodigo Curso: %d\nNome do Curso: %s\nQuantidade de Blocos: "
             "%i\nNumero de Semanas: %i\n\n",
             root->id, root->name_of_course, root->blocos, root->num_of_week);
    }
    showBlocks(root->right, qtdBlock);
  }
}

void printInOrdem(Curso *root) {
  if (root != NULL) {
    printInOrdem(root->left);
    printf("\nCodigo Curso: %d\nNome do Curso: %s\nQuantidade de Blocos: %i\nNumero de Semanas: %i\n\n",root->id, root->name_of_course, root->blocos, root->num_of_week);
    //printInOrdemDiscipline(root->disciplinas);
    printInOrdem(root->right);
  }
}

void showCursoDisciplinaCod(Curso *root, int cod) {
  Curso *find;
  find = searchNode(root, cod);
  if (find != NULL) {
    printInOrdemDiscipline(find->disciplinas);
  }
}

Curso *searchNode(Curso *root, int cod){
  Curso *find;
  find = NULL;
  if (root != NULL) {
    if (root->id == cod) {
      find = root;
    } else if (cod < root->id) {
      find = searchNode(root->left, cod);
    } else {
      find = searchNode(root->right, cod);
    }
  }
  return find;
}

void printCursoDisciplina(Curso *root, int cod_curso, int cod_discipline){

  Curso *find;
  find = searchNode(root, cod_curso);
  if(find){
    printDiscipline(find->disciplinas,cod_discipline);
  }else{
    printf("\nCodigo de curso não existe!\n");
  }
  
}
void printAllDiscipline(Curso *root, int block, int cod_curso){
  Curso *find_curso;
  find_curso = searchNode(root, cod_curso);
  if (find_curso != NULL) {
    printDisciplinaInBlock(find_curso->disciplinas,block);
  }else{
    printf("\nCodigo de curso não existe!\n");
  }
}

void printCursoDisciplinaWorkload(Curso *root, int cod_curso,int workload){
  Curso *find_curso;
  find_curso = searchNode(root, cod_curso);
  if (find_curso != NULL) {
    printDisciplinaWorkload(find_curso->disciplinas,workload);
  }else{
    printf("\nCodigo de curso não existe!\n");
  }
}

int removerCursoDiscipline(Curso **root, int idCurso, int idDisciplina){// procura o curso pelo idCurso e depois removeu a disciplina pelo idDisciplina
  int removeu;
  if(*root != NULL){
    if(idCurso == (*root)->id){
      removeu = removeDiscipline(&((*root)->disciplinas),idDisciplina);
    }else if(idCurso < (*root)->id){
      removeu = removerCursoDiscipline(&((*root)->left),idCurso,idDisciplina);
    }else{
      removeu = removerCursoDiscipline(&((*root)->right),idCurso,idDisciplina);
    }
  }
  return removeu;
}

int removerCurso(Curso **root, int idCurso){
  Curso *aux,*filho,*maior;
  int removeu = 0;
  if(*root != NULL){
    if(idCurso == (*root)->id){
      if((*root)->disciplinas == NULL){
        removeu = 1;
        if(ehFolhaIntCurso(*root) == 1){
          aux = *root;
          (*root) = NULL;
          free(aux);
        }
        else if(umFilhoIntCurso(*root) == 1){
          filho = umFilhoCurso(*root);
          aux = (*root);
          (*root) = filho;
          free(aux);
        }
        else if(doisFilhoIntCurso(*root) == 1){
          filho = buscaMaiorEsqCurso((*root)->left);
          aux = (*root);
          filho->right = (*root)->right;
          (*root) = filho;
          free(aux);
        }
      }
    }
    else if(idCurso < (*root)->id){
      removeu = removerCurso(&((*root)->left),idCurso);
    }else{
      removeu = removerCurso(&((*root)->right),idCurso);
    }
  }
  return removeu;
}


void removeAvrCursoDisciplina(Curso **root, int idCurso){
  Curso *find;
  find = searchNode((*root),idCurso);
  deletarDisciplinas(&((*find).disciplinas));
}

Curso* ehFolhaCurso(Curso *no){
  Curso *sim;
  sim = NULL;
  if(no->left == NULL && no->right == NULL){
    sim = no;
  }
  return sim;
}

int ehFolhaIntCurso(Curso *no){
  int sim;
  sim = 0;
  if(no->left == NULL && no->right == NULL){
    sim = 1;
  }
  return sim;
}

Curso* umFilhoCurso(Curso *no){
  Curso *sim;
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

int umFilhoIntCurso(Curso *no){
  int sim;
  sim = 0;
  if((no->left != NULL && no->right == NULL) || (no->left == NULL && no->right != NULL)){
    sim = 1;
  }
  return sim;
}

Curso* doisFilhoCurso(Curso *no){
  Curso *sim;
  sim = NULL;
  if(no->left != NULL && no->right != NULL){
    sim = no;
  }
  return sim;
}

int doisFilhoIntCurso(Curso *no){
  int sim;
  sim = 0;
  if(no->left != NULL && no->right != NULL){
    sim = 1;
  }
  return sim;
}

Curso* buscaMaiorEsqCurso(Curso *no){
  Curso *maior;
  if(no->right == NULL){
    maior = no;
  }else{
    maior = buscaMaiorEsqCurso(no->right);
  }
  return maior;
}