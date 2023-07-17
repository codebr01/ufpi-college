#include <stdio.h>
int menor3(int n1, int n2, int n3);
int main(){
    int n1,n2,n3;
    printf("Informe o primeiro numero: ");
    scanf("%i", &n1);
    printf("Informe o segundo numero: ");
    scanf("%i", &n2);
    printf("Informe o terceiro numero: ");
    scanf("%i", &n3);
    int menor = menor3(n1,n2,n3);
    if((n1 != n2) && (n1 != n3) && (n2 != n1) && (n2 != n3) && (n3 != n1) && (n3 != n2)){
        printf("\nMenor valor: %i\n", menor);
    }
    if((n1 != n2) && (n1 != n3) && (n2 == n3) && (n3 == n2)){
        printf("\nMenor valor: %i\n", menor);
    }
    if((n2 != n1) && (n2 != n3) && (n1 == n3) && (n3 == n1)){
        printf("\nMenor valor: %i\n", menor);
    }
    if((n3 != n1) && (n3 != n2) && (n1 == n2) && (n2 == n1)){
        printf("\nMenor valor: %i\n", menor);
    }
    if((n1 == n2) && (n1 == n3) && (n2 == n1) && (n2 == n3) && (n3 == n1) && (n3 == n2)){
        printf("\nNumeros Iguais\n");
    }
    return 0;
}
int menor3(int n1, int n2, int n3){
    int menor;
    if((n1 < n2) && (n1 < n3)){
        menor = n1;
    }
    if((n2 < n1) && (n2 < n3)){
        menor = n2;
    }
    if((n3 < n1) && (n3 < n2)){
        menor = n3;
    }
    if((n1 < n2) && (n1 < n3) && (n2 == n3) && (n3 == n2)){
        menor = n1;
    }
    if((n2 < n1) && (n2 < n3) && (n1 == n3) && (n3 == n1)){
        menor = n2;
    }
    if((n3 < n1) && (n3 < n2) && (n2 == n1) && (n1 == n2)){
        menor = n3;
    }
    return menor;
}

