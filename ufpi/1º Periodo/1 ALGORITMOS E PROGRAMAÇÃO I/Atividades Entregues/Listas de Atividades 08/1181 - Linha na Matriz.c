#include <stdio.h>
int main(){
    float m[12][12],soma,valor;
    int c,l,s;
    char opcao;
    scanf("%i", &s);
    scanf("%s", &opcao);
    soma = 0;
    if((l >= 0) && (l <= 11)){
        if(opcao == 'S'){
            for(l = 0; l < 12; l++){
                for(c = 0; c < 12; c++){
                    scanf("%f", &valor);
                    m[l][c] = valor;
                }
            }
            for(c = 0; c < 12; c++){
                soma += m[s][c];
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
                for(c = 0; c < 12; c++){
                    soma += m[s][c];
                }
                printf("%.1f\n", soma / 12.0);
            }
        }
    }
    return 0;
}
