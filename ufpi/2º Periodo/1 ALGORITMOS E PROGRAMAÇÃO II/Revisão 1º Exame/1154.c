#include <stdio.h>

double leInteiros();

int main(){

    printf("%.2f\n", leInteiros());

    return 0;
}

double leInteiros(){
    int idade;
    float media,soma_idade,cont;
    soma_idade = 0;
    cont = 0;
    do{
      scanf("%i", &idade);
      if(idade > 0){
        cont += 1;
        soma_idade += idade;
      }
    }while(idade > 0);
    media = soma_idade / cont;

    return media;
}