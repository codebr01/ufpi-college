#include <stdio.h>
#include <stdlib.h>

void maiusculo(char *sPtr);

int main(){

    int sair = 0;
    char linha[30], *sPtr;

    for(;;){
        gets(linha);
        if(linha[0] == '0'){
            break;
        }
        maiusculo(linha);
        printf("\n");
    }
    return 0;
}
void maiusculo(char *sPtr){
    int i;
    for(i = 0; sPtr[i] != '\0';i++){
        if(sPtr[i] >= 97 && sPtr[i] <= 122){
            printf("%c",sPtr[i]-32);
        }else{
            printf("%c",sPtr[i]);
        }
    }
}