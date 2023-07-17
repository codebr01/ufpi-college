#include <stdio.h>
#include <stdlib.h>
float media, num1, num2;
char opcao;
int main(){
    do{
        printf("Digite um numero: ");
        scanf("%f", &num1);
        printf("Digite outro numero: ");
        scanf("%f", &num2);
        setbuf(stdin,NULL);
        printf("---------------------------\n");
        printf("-----------Menu------------\n");
        printf("---------------------------\n");
        setbuf(stdin,NULL);
        printf("[  A  ] --  Maior numero \n");
        printf("[  B  ] --  Menor numero \n");
        printf("[  C  ] --  Media aritmetica \n");
        printf("[  D  ] --  FINALIZAR \n");
        printf(">>>>>> ");
        scanf("%c", &opcao);
        switch(opcao){
        setbuf(stdin,NULL);
        case 'a':
            if(num1 > num2){
                printf("O maior numero: %.0f\n", num1);
            }else{
                printf("O maior numero: %.0f\n", num2);
            }
            break;
        case 'b':
            if(num1 < num2){
                printf("O menor numero: %.0f\n", num1);
            }else{
                printf("O menor numero: %.0f\n", num2);
            }
            break;
        case 'c':
            media = (num1 + num2) / 2;
            printf("A media: %.1f\n", media);
            break;
        default:
            printf("Voce finalizou o programa.\n");
        }
    }while(opcao != 'd');
    return 0;
}
