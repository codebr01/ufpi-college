#include <stdio.h>
int main(){
    int l,c,i,j;
    scanf("%i %i", &l, &c);
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}