#include <stdio.h>
int main(){
    char palavra[30];
    int i;
    printf("Digite uma palavra: ");
    scanf("%[^\n]",palavra);
    for(i = 0; i < 30; i++){
        if((palavra[i] >= 97) && (palavra[i] <= 122)){
            palavra[i] = palavra[i] - 32;
        }
    }
    printf("\n%s\n", palavra);
    return 0;
}
