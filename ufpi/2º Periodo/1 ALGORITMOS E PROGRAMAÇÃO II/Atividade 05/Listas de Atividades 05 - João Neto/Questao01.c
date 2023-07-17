#include <stdio.h>

void cubo(int *nPtr);

int main(){
    
    int resp = 1;
    int *nPrt;

    while(resp != 0){
        scanf("%i", &resp);
        if(resp != 0){
            nPrt = &resp;
            cubo(nPrt);
        }else{
            resp = 0;
        }
    }
    return 0;
}

void cubo(int *nPtr){
    printf("%i\n", *nPtr * *nPtr * *nPtr);
}