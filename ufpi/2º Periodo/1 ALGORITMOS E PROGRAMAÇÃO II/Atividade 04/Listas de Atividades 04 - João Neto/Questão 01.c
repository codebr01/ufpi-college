#include <stdio.h>
typedef struct{
    char nome[20];
    float altura;
    float peso;
    float ira;
}Aluno;

int main(){
    Aluno a[5];
    float maior_peso = 0, maior_altura = 0, maior_ira = 0,soma_altura = 0, soma_peso = 0, soma_ira = 0;
    int i = 0,posicao_altura, posicao_peso, posicao_ira;
    scanf("%s %f %f %f", a[0].nome, &a[0].altura, &a[0].peso, &a[0].ira);
    soma_altura += a[0].altura;
    soma_peso += a[0].peso;
    soma_ira += a[0].ira;
	maior_altura = a[0].altura;
    posicao_altura = i;
    maior_peso = a[0].peso;
    posicao_peso = i;
    maior_ira = a[0].ira;
    posicao_ira = i;

    for(i = 1; i < 5; i++){
        scanf("%s %f %f %f", a[i].nome, &a[i].altura, &a[i].peso, &a[i].ira);
        setbuf(stdin,NULL);
        soma_altura += a[i].altura;
        soma_peso += a[i].peso;
        soma_ira += a[i].ira;
        if(a[i].altura > maior_altura){
            maior_altura = a[i].altura;
            posicao_altura = i;
        }
        if(a[i].peso > maior_peso){
            maior_peso = a[i].peso;
            posicao_peso = i;
        }
        if(a[i].ira > maior_ira){
            maior_ira = a[i].ira;
            posicao_ira = i;
        }
    }
    printf("\n\nMedia de peso: %.3f\nMedia de altura: %.3f\nMedia de IRA: %.3f\n\n", soma_peso / 5, soma_altura / 5, soma_ira / 5);
    printf("Maior peso: %s %.3f\nMaior altura: %s %.3f\nMaior IRA: %s %.3f\n", a[posicao_peso].nome,maior_peso, a[posicao_altura].nome,maior_altura, a[posicao_ira].nome,maior_ira);

    return 0;
}
