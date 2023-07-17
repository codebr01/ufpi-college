#include <stdio.h>

double calculaArea(char operacao, double M[][12]);

int main(){
    double M[12][12];
    char O;
    scanf("%s", &O);
    if(O == 'S'){
        printf("%.1lf\n", calculaArea(O, M));
    }else{
        printf("%.1lf\n", calculaArea(O, M) / 66.0);
    }
    return 0;
}
double calculaArea(char operacao, double M[][12]){
    int l,c;
    double soma = 0;
    if(operacao == 'S'){
        for(l = 0; l < 12; l++){
            for(c = 0; c < 12; c++){
                scanf("%lf", &M[l][c]);
            }
        }
        for(l = 11; l >= 0; l--){
            for(c = 11; c > 11 - l; c--){
                soma += M[l][c];
            }
        }
    }else{
        if(operacao == 'M'){
            for(l = 0; l < 12; l++){
                for(c = 0; c < 12; c++){
                    scanf("%lf", &M[l][c]);
                }
            }
            for(l = 11; l >= 0; l--){
                for(c = 11; c > 11 - l; c--){
                    soma += M[l][c];
                }
            }
        }
    }
    return soma;
}
