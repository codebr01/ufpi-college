#include <stdio.h>
float nota3,nota2,nota1,media,media7,soma_turma1,soma_turma2;
int i;
int main(){
    for(i = 1;i <= 20; i += 1){
        printf("Informe a primeira nota: ");
        scanf("%f",&nota1);
        printf("Informe a segunda nota: ");
        scanf("%f",&nota2);
        printf("Informe a terceira nota: ");
        scanf("%f",&nota3);
        soma_turma1 = nota1 + nota2 + nota3;
        soma_turma2 += soma_turma1;
        media = (nota1 + nota2 + nota3) / 3;
        media7 = 0;
        if(media > 7){
            media7 += 1;
        }
        printf("media do aluno: %.2f\n", media);
        printf("-------------------------\n");
    }
    printf("A media da turma foi: %.2f\n",soma_turma2 / 60);
    printf("\n%.2f%% obtiveram media acima de 7.\n",(media7 / 20) * 100);
    return 0;
}
