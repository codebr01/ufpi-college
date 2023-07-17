#include <stdio.h>
int main(){
    char nome[20];
    int i;
    scanf("%s", nome);
    for(i = 0; i < 20; i++){
        if(nome[i] >= 97 && nome[i] <= 122){
            nome[i] = nome[i] - 32;
        }
    }
    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i + 1] == '\0'){
            printf("%c" , nome[i]);
            break;
        }
        printf("%c ", nome[i]);
    }
    return 0;
}