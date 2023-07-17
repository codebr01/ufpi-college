#include <stdio.h>
int main(){
    char palavra[20];
    int guardar_posicao[20];
    int i,j;
    for(i = 0; i < 20; i++){
        guardar_posicao[i] = 0;
    }
    printf("Informe uma palavra: ");
    scanf("%s", palavra);
    j = 0;
    for(i = 0; i < 20; i++){
        if(palavra[i] == 'r'){
            palavra[i] = 'l';
            guardar_posicao[j] = i + 1;
            j++;
        }
    }
    printf("\nCebolinha falaria: %s\n", palavra);
    printf("Houve troca nos caracteres: ");
    for(j = 0; j < 20; j++){
        printf("%i ", guardar_posicao[j]);
        if(guardar_posicao[j + 1] == 0){
            break;
        }
    }
    return 0;
}