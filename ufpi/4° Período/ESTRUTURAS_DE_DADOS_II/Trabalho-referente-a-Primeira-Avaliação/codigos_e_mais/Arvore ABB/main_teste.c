#include "curso.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    time_t vTime[2];
    double tempo;
    Curso *tree = create();
    Curso *find;
    double somatorio = 0;
    int idCurso,qtdBlocos,idDisciplina,workload,verificador;
    int i,op;
    for(i = 0; i < 50000; i++){
      scanf("%i", &idCurso);
      //vTime[0] = clock();
      insertCourse(&tree,idCurso);
      // vTime[1] = clock();
      // tempo = (vTime[1] - vTime[0]) * 1000000;
      // somatorio += tempo;
    }
    // printf("%f\n",tempo / 50000);
    for(i = 0; i < 30; i++){
      vTime[0] = clock();
      find = searchNode(tree,1);
      vTime[1] = clock();
      tempo = (vTime[1] - vTime[0]);
      somatorio += tempo;
    }
    printf("%f\n",somatorio / 30);

  return 0;
}