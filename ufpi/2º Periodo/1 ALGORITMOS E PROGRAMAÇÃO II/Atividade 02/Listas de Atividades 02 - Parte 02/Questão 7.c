#include <stdio.h>
int main(){
    int valor = 2,i;
    printf("Elemento    Valor\n");
    for(i = 0; i < 10; i++){
        printf("       %i    %i\n", i, valor);
        valor += 2;
    }
    return 0;
}