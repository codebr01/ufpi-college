#include <stdio.h>
int main(){
    int numeros[10],i,maior,menor;
    for(i = 0; i < 10; i++){
        scanf("%i", &numeros[i]);
    }
    for(i = 0; i < 10; i++){
        if(i == 0){
            maior = numeros[0];
            menor = numeros[0];
        }else{
            if(numeros[i] > maior){
                maior = numeros[i];
            }else{
                if(numeros[i] < menor){
                    menor = numeros[i];
                }
            }
        }
    }
    printf("-------------------------\n");
    for(i = 0; i < 10; i++){
        if(numeros[i] == menor){
            printf("%i\n", maior);
        }else{
            if(numeros[i] == maior){
                printf("%i\n", menor);
            }else{
                if(numeros[i] != menor && numeros != maior){
                    printf("%i\n", numeros[i]);
                }
            }
        }
    }
    return 0;
}
