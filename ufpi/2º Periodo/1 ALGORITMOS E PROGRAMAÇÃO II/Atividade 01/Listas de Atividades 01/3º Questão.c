#include <stdio.h>
int main(){
    char destino;
    int passagem;
    scanf("%c", &destino);
    if(destino == 'a'){
        scanf("%i", &passagem);
        if(passagem == 0){
            printf("R$ 500,00\n");
        }else{
            printf("R$ 900,00\n");
        }
    }
    if(destino == 'b'){
        scanf("%i", &passagem);
        if(passagem == 0){
            printf("R$ 350,00\n");
        }else{
            printf("R$ 650,00\n");
        }
    }
    if(destino == 'c'){
        scanf("%i", &passagem);
        if(passagem == 0){
            printf("R$ 350,00\n");
        }else{
            printf("R$ 600,00\n");
        }
    }
    if(destino == 'd'){
        scanf("%i", &passagem);
        if(passagem == 0){
            printf("R$ 300,00\n");
        }else{
            printf("R$ 550,00\n");
        }
    }
    return 0;
}