#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lancamento(int cara);
int main(){
    int guarda = 0;  
    printf("Cara repetiu %i vezes.\n", lancamento(guarda));
    return 0;
}
int lancamento(int cara){
    int i, o;
    srand(time(NULL));
    for(i = 0; i < 5; i++){
        o = rand() % 2;
        if(o == 0){
            printf("Coroa: %i\n", o);
        }else{
            if(o == 1){
                printf("Cara: %i\n", o);
                cara += 1;
            }
        }
    }
    return cara;
}
