#include <stdio.h>
int num, p, s, t, q, f;
int main(){
    printf("Informe um valor INTEIRO de cinco algarismos: ");
    scanf("%i", &num);
    p = num / 10000;
    printf("O primeiro numero e: %i\n", p);
    if(p % 2 == 1){
        printf("O numero %i e impar.\n", p);
    }else{
        printf("O numero %i e par.\n", p);
    }
    s = (num % 10000) / 1000;
    printf("\nO segundo numero e: %i\n", s);
    if(s % 2 == 1){
        printf("O numero %i e impar.\n", s);
    }else{
        printf("O numero %i e par.\n", s);
    }
    t = (num % 1000) / 100;
    printf("\nO terceiro numero e: %i\n", t);
    if(t % 2 == 1){
        printf("O numero %i e impar.\n", t);
    }else{
        printf("O numero %i e par.\n", t);
    }
    q = (num % 100) / 10;
    printf("\nO quarto numero e: %i\n", q);
    if(q % 2 == 1){
        printf("O numero %i e impar\n", q);
    }else{
        printf("O numero %i e par.\n", q);
    }
    f = num % 10;
    printf("\nO quinto numero e: %i\n", f);
    if(f % 2 == 1){
        printf("O numero %i e impar.\n", f);
    }else{
        printf("O numero %i e par.\n", f);
    }
    return 0;
}
