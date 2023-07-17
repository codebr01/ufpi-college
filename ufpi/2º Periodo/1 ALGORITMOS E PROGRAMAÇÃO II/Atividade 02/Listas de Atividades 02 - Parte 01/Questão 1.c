#include <stdio.h>
int main(){
    int i,aluno_nota,resp_aluno[11],cont = 1;
    for(i = 0; i < 11; i++){
        resp_aluno[i] = 0;
    }
    for(i = 0; i < 40; i++){
        scanf("%i", &aluno_nota);
        if(aluno_nota == -1){
            break;
        }
        if(aluno_nota == 0){
            resp_aluno[0] += cont;
        }
        if(aluno_nota == 1){
            resp_aluno[1] += cont;
        }
        if(aluno_nota == 2){
            resp_aluno[2] += cont;
        }
        if(aluno_nota == 3){
            resp_aluno[3] += cont;
        }
        if(aluno_nota == 4){
            resp_aluno[4] += cont;
        }
        if(aluno_nota == 5){
            resp_aluno[5] += cont;
        }
        if(aluno_nota == 6){
            resp_aluno[6] += cont;
        }
        if(aluno_nota == 7){
            resp_aluno[7] += cont;
        }
        if(aluno_nota == 8){
            resp_aluno[8] += cont;
        }
        if(aluno_nota == 9){
            resp_aluno[9] += cont;
        }
        if(aluno_nota == 10){
            resp_aluno[10] += cont;
        }
    }
    for(i = 0; i < 11; i++){
        printf("%i %i\n", i, resp_aluno[i]);
    }
    return 0;
}