#include <stdio.h>
#include <math.h>
float calculaRaiz(float a,float b,float c);
int main(){
    float a, b, c;
    printf("Informe o coeficiente A: ");
    scanf("%f", &a);
    printf("Informe o coeficiente B: ");
    scanf("%f", &b);
    printf("Informe o coeficiente C: ");
    scanf("%f", &c);
    calculaRaiz(a,b,c);
    return 0;
}
float calculaRaiz(float a,float b,float c){
    float delta = (pow(b,2)) - (4 * a * c);
    float x1,x2;
    if(delta == 0){
        x1 = ((-1 * b) + (sqrt(delta))) / (2 * a);
        x2 = ((-1 * b) - (sqrt(delta))) / (2 * a);
        printf("Duas Raizes reais iguais, x': %.1f e x'': %.1f\n", x1,x2);
    }else{
        if(delta > 0){
            x1 = ((-1 * b) + (sqrt(delta))) / (2 * a);
            x2 = ((-1 * b) - (sqrt(delta))) / (2 * a);
            printf("Duas Raizes reais diferentes, x': %.1f e x'': %.1f\n", x1,x2);
        }else{
            if(delta < 0){
                printf("Raizes nao sao numeros reais.\n");
            }
        }
    }
    return 0;
}
