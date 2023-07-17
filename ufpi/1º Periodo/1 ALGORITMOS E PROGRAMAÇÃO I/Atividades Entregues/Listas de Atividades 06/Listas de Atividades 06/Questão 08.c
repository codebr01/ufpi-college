#include <stdio.h>
int main(){
    char nome[30];
    int i;
    printf("Digite o nome: ");
    scanf("%[^\n]", nome);
    printf("\n");
    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i + 1] == '\0'){
            printf("%c", nome[i]);
        }else{
            printf("%c ", nome[i]);
        }
    }
    return 0;
}
