#include <stdio.h>
#include <math.h>
int potencia(int x, int n);
int main(){
    int x,n;
    printf("Informe o numero: ");
    scanf("%i", &x);
    printf("Informe a potencia: ");
    scanf("%i", &n);
    int resultado = potencia(x,n);
    if(resultado < 0){
        printf("\n%i\n", resultado * -1);
    }else{
        if(resultado > 0){
            printf("\n%i\n", resultado);
        }
    }
    return 0;
}
int potencia(int x, int n){
    int resultado = pow(x,n);
    return resultado;
}
