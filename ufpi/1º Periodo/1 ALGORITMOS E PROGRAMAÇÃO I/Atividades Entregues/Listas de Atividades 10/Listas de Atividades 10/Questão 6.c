#include <stdio.h>
int primo(int n);
int main(){
    int n;
    printf("Informe um numero: ");
    scanf("%i", &n);
    primo(n);
    return 0;
}
int primo(int n){
    int i,k,div;
    for(i = 1; i <= n; i++){
        for(k = 1; k <= i; k++){
            if(i % k == 0){
                div ++;
            }
        }
        if(div == 2){
            printf("Numero %i eh primo\n", i);
        }else{
            printf("Numero %i nao eh primo\n", i);
        }
        div = 0;
    }
    return 0;
}
