#include "curso_abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(){
  printf("\n1 - Imprimir Arvore de Cursos(In-Ordem)\n2 - Imprimir Curso\n3 - Imprimir todos os Cursos com mesmo numero de blocos\n4 - Imprimir Arvore de Disciplinas\n5 - Imprimir Disciplina\n6 - Imprimir Disciplinas de um bloco de determinado curso\n7 - Imprimir todas as Disciplinas com mesmo workload\n8 - Excluir uma Disciplina\n9 - Excluir um Curso\n10 - Excluir Arvore de Disciplinas de um Curso\n11 - Para inserir curso\nDigite -1 para sair\n\nDigite a opcao: ");
}


int main() {
  srand(time(NULL));
  time_t vTime[2];
  double tempo;
  Curso *tree = create();
  int idCurso,qtdBlocos,idDisciplina,workload,verificador;
  int i,op;

  op = 0;
  while(op != -1){
    menu();
    scanf("%i", &op);
    setbuf(stdin,NULL);
    switch(op){
    case 1:
      printInOrdem(tree);
      break;
    case 2:
      printf("Digite o ID do curso: ");
      scanf("%i", &idCurso);
      setbuf(stdin,NULL);
      searchCourse(tree,idCurso);
      break;
    case 3:
      printf("Digite a quantidade de blocos: ");
      scanf("%i", &qtdBlocos);
      setbuf(stdin,NULL);
      showBlocks(tree,qtdBlocos);
      break;
    case 4:
      printf("Digite o ID do curso: ");
      scanf("%i", &idCurso);
      setbuf(stdin,NULL);
      showCursoDisciplinaCod(tree,idCurso);
      break;
    case 5:
      printf("Digite o ID do curso e ID da disciplina: ");
      scanf("%i %i", &idCurso, &idDisciplina);
      setbuf(stdin,NULL);
      printCursoDisciplina(tree,idCurso,idDisciplina);
      break;
    case 6:
      printf("Digite o numero do bloco e ID do curso: ");
      scanf("%i %i", &qtdBlocos, &idCurso);
      setbuf(stdin,NULL);
      printAllDiscipline(tree,qtdBlocos,idCurso);
      break;
    case 7:
      printf("Digite ID do curso e a carga horaria da disciplina: ");
      scanf("%i %i", &idCurso, &workload);
      setbuf(stdin,NULL);
      printCursoDisciplinaWorkload(tree,idCurso,workload);
      break;
    case 8:
      printf("Digite ID do curso e o ID da disciplina: ");
      scanf("%i %i", &idCurso, &idDisciplina);
      setbuf(stdin,NULL);
      verificador = removerCursoDiscipline(&tree,idCurso,idDisciplina);
      if(verificador == 1){
        printf("\nDisciplina Removido!\n");
      }else{
        printf("\nDisciplina nao Removida\n");
      }
      break;
    case 9:
      printf("Digite ID do curso: ");
      scanf("%i", &idCurso);
      setbuf(stdin,NULL);
      verificador = removerCurso(&tree,idCurso);
      if(verificador == 1){
        printf("\nCurso Removido!\n");
      }
      if(verificador == 0){
        printf("\nCurso ainda possui disciplinas, exclua!\n");
      }
      break;
    case 10:
      printf("Digite ID do curso: ");
      scanf("%i", &idCurso);
      setbuf(stdin,NULL);
      removeAvrCursoDisciplina(&tree,idCurso);
      break;
    case 11:
      printf("Digite ID do curso a ser inserido: ");
      scanf("%i", &idCurso);
      setbuf(stdin,NULL);
      insertCourse(&tree,idCurso);
      break;
    default:
      break;
    }
  }

  return 0;
}