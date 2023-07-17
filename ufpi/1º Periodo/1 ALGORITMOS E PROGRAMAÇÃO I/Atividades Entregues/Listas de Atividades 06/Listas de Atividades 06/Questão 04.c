#include <stdio.h>
int main(){
    int num_par[10],num,i;
    i = 0;
    for(num = 2; num <= 20; num++){
        if(num % 2 == 0){
            num_par[i] = num;
            printf("Elemento %i - Valor %i\n", i, num);
            i++;
        }
    }
    return 0;
}
