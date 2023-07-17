#include <stdio.h>
int main(){
    int valor[10],i,j;
    for(i = 0; i < 10; i++){
        scanf("%i", &valor[i]);
    }
    printf("Elemento    Valor   Histograma\n");
    for(i = 0; i < 10; i++){
        printf("       %i    %i       ", i, valor[i]);
        for(j = 0; j < valor[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}