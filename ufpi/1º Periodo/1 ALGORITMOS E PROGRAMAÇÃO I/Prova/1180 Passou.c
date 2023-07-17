#include <stdio.h>
typedef struct {
    int menor;
    int posicao;
}Menor;
Menor buscaMenor(int X[], int n);
int main() {
    int n, i;
    scanf("%d", &n);
    int X[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }
    Menor menor = buscaMenor(X, n);
    printf("Menor valor: %d\n", menor.menor);
    printf("Posicao: %d\n", menor.posicao);
    return 0;
}
Menor buscaMenor(int X[], int n) {
    int i;
    Menor menor;
    menor.menor = X[0];
    menor.posicao = 0;
    for(i = 0; i < n; i++) {
        if(X[i] < menor.menor) {
            menor.menor = X[i];
            menor.posicao = i;
        }
    }
    return menor;
}
