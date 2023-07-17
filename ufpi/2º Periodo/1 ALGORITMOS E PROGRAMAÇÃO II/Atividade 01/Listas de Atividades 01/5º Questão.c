#include <stdio.h>
void saidaDedados();
typedef struct{
    int h1, h2 , m1, m2;
}Idades;
Idades i;
int main(){
    scanf("%i %i %i %i", &i.h1, &i.h2, &i.m1, &i.m2);
    saidaDedados();
    return 0;
}
void saidaDedados(){
    int maiorh, maiorm, menorh, menorm;
    maiorh = maiorm = menorm = menorh = 0;
    if(i.h1 > i.h2){
        maiorh = i.h1;
        menorh = i.h2;
    }else{
        maiorh = i.h2;
        menorh = i.h1;
    }
    if(i.m1 > i.m2){
        maiorm = i.m1;
        menorm = i.m2;
    }else{
        maiorm = i.m2;
        menorm = i.m1;
    }
    printf("%i %i\n", maiorh + menorm, menorh * maiorm);
}