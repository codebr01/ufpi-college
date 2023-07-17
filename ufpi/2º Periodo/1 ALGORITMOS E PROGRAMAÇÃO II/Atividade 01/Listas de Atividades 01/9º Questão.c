#include <stdio.h>
int main(){
    int l,c,i,j;
    scanf("%i %i", &l, &c);
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if((i == 0 && (j == i || j != i)) || (j == 0 && (i == j || i != j)) || (i == l - 1 && (j == i || j != i)) || (j == c - 1 && (i == j || i != j))){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}