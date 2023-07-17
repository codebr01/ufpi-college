#include <stdio.h>

double calculaArea(char operacao, double M[][12]);

int main()
{
    double M[12][12];
    char O;
    scanf("%s", &O);
    if(O == 'S'){
        printf("%.1lf\n", calculaArea(O, M));
    }else{
        printf("%.1lf\n",calculaArea(O, M) / 30.0);
    }
    return 0;
}
double calculaArea(char operacao, double M[][12])
{
    double soma;
    int i,j;
    soma = 0;
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &M[i][j]);
        }
    }
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            if((j < i) && (j > 11 - i)){
                soma += M[i][j];
            }
        }
    }
    return soma;
}
