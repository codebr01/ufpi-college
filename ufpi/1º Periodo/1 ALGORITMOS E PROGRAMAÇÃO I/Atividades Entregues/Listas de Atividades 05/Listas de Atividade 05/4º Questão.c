#include <stdio.h>
#include <stdlib.h>
int numero, menor, maior, multi, cont;
char pergunta;
int main(){
    printf("Infome um numero: ");
    scanf("%i", &numero);
    cont = 1;
    maior = numero;
    menor = numero;
    multi = numero * 1;
    setbuf(stdin,NULL);
    printf("Voce quer informar outro numero? [s / n]");
    scanf("%c", &pergunta);
    while(pergunta != 'n'){
        printf("Informe outro numero: ");
        scanf("%i", &numero);
        setbuf(stdin,NULL);
        if(numero > maior){
            maior = numero;
        }else{
            if(numero < menor){
                menor = numero;
            }
        }
        multi *= numero;
        cont += 1;
        printf("Voce quer informar outro numero? [s / n]");
        scanf("%c", &pergunta);
    }
    printf("O maior numero: %i\n", maior);
    printf("\nO menor numero: %i\n",menor);
    printf("\nO produto: %i\n",multi);
    printf("\nVoce digitou %i vezes.\n", cont);
    return 0;
}
