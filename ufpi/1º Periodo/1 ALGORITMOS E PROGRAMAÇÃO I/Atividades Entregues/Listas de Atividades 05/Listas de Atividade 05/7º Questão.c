#include <stdio.h>
int t1,t2,t3,cont;
int main(){
    t1 = 1;
    t2 = 1;
    printf(" %i , %i ",t1 ,t2);
    for(cont = 3;cont <=20;cont += 1){
        t3 = t1 + t2;
        printf(", %i ",t3);
        t1 = t2;
        t2 = t3;
    }
    return 0;
}
