#include <stdio.h>
int main(){
    int n[10],v,i;
    scanf("%i", &v);
    for(i = 0; i < 10; i++){
        printf("N[%i] = %i\n", i,v);
        v *= 2;
    }
    return 0;
}
