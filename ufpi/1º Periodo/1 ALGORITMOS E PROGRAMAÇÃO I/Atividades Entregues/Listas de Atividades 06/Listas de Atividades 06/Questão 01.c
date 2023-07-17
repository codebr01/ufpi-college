#include <stdio.h>
int main(){
    char palavra[30];
    int i;
    printf("Digite uma palavra: ");
    scanf("%[^\n]", palavra);
    for(i = 0; i < 30; i++){
        if((palavra[i] == 'r') || (palavra[i] == 'R')){
            if(palavra[i] == 'r'){
                palavra[i] = 'l';
            }else{
                if(palavra[i] == 'R'){
                    palavra[i] = 'L';
                }
            }
        }
    }
    printf("\n%s\n", palavra);
    return 0;
}
