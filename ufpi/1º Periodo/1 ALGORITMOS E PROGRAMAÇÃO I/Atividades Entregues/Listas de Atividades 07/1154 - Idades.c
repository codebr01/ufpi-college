#include <stdio.h>
int main(){
    int idade;
    float media,soma_idade,numero_de_idades;
    soma_idade = 0;
    numero_de_idades = 0;
    do{
      scanf("%i", &idade);
      if(idade > 0){
        numero_de_idades = numero_de_idades + 1;
        soma_idade = soma_idade + idade;
      }
    }while(idade > 0);
    media = soma_idade / numero_de_idades;
    printf("%.2f\n", media);
    return 0;
}
