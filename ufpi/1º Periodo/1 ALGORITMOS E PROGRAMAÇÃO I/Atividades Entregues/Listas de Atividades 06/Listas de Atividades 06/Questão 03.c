#include <stdio.h>
int main(){
    float peso[30], altura[30];
    int i;
    for(i = 0; i < 30; i++){
        printf("Digite o peso da %i pessoa: ", i+1);
        scanf("%f", &peso[i]);
        printf("Digite a altura da %i pessoa: ", i+1);
        scanf("%f", &altura[i]);
        printf("----------------------------------\n");
    }
    for(i = 0; i < 2; i++){
        printf("O IMC da %i eh %.2f\n", i + 1, peso[i] / (altura[i] * altura[i]));
        printf("-----------------------------------------\n");
    }
    return 0;
}
