#include <stdio.h>

float nota1, nota2, nota3 ,nota4 ,media;

int main(){
    printf("Digite o Primeiro numero: ");
    scanf("%f", &nota1);
    printf("Digite a Segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a Terceira nota: ");
    scanf("%f", &nota3);
    printf("Digite a Quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1*1 + nota2*2 + nota3*3 + nota4*4) / 10;

    printf("A media das notas foi: %.1f", media);
    return 0;
}
