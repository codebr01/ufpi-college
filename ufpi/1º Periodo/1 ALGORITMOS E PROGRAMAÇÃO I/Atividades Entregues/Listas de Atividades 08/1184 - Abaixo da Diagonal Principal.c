#include <stdio.h>
int main(){
    float m[12][12],soma,valor;
    int l,c;
    char opcao;
    soma = 0;
    scanf("%s", &opcao);
    if(opcao == 'S'){
        for(l = 0; l < 12; l++){
            for(c = 0; c < 12; c++){
                scanf("%f", &valor);
                m[l][c] = valor;
            }
        }
        for(l = 0; l < 12; l++){
            for(c = 0; c < 12; c++){
                if(c < l){
                    soma += m[l][c];
                }
            }
        }
        printf("%.1f\n", soma);
    }else{
        if(opcao == 'M'){
            for(l = 0; l < 12; l++){
                for(c = 0; c < 12; c++){
                    scanf("%f", &valor);
                    m[l][c] = valor;
                }
            }
            for(l = 0; l < 12; l++){
                for(c = 0; c < 12; c++){
                    if(c < l){
                        soma += m[l][c];
                    }
                }
            }
            printf("%.1f\n", soma / 66.0);
        }
    }
    return 0;
}
