#include <stdio.h>
int menor2(int n1, int n2);
int menor;
int main(){
    int n1,n2;
    printf("Informe o primeiro numero: ");
    scanf("%i", &n1);
    printf("Informe o segundo numero: ");
    scanf("%i", &n2);
    int menor = menor2(n1,n2);
    if((n1 != n2) && (n2 != n1)){
        printf("\nMenor valor: %i\n", menor);
    }else{
        printf("\nNumeros Iguais\n");
    }
    return 0;
}
int menor2(int n1, int n2){
    int menor;
    if(n1 < n2){
        menor = n1;
    }else{
        menor = n2;
    }
    return menor;
}
