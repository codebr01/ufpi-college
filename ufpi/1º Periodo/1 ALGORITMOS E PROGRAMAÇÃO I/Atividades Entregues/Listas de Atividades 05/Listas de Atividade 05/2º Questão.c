#include <stdio.h>
int i;
int main(){
    for(i = 1; i <= 100; i += 1){
        if(i % 5 == 0){
            printf("numero %i multiplo de 5\n",i);
        }
    }
    return 0;
}
