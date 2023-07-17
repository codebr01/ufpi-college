#include <stdio.h>
#include <math.h>

typedef struct{
    float x1;
    float x2;
}Raiz;

Raiz calculaRaiz(float a, float b, float c);

int main(){
    float a,b,c;
    scanf("%f %f %f", &a, &b,&c);    
    calculaRaiz(a,b,c);
    return 0;
}

Raiz calculaRaiz(float a, float b, float c){
    Raiz r;
    float delta;
    delta = (b * b) - ((4 * a) * c);
    if(delta > 0 && a != 0){
        r.x1 = ((-1 * b) + (sqrt(delta))) / (2 * a);
        r.x2 = ((-1 * b) - (sqrt(delta))) / (2 * a);
        printf("R1 = %.5f\n", r.x1);
        printf("R2 = %.5f\n", r.x2);
    }else{
        printf("Impossivel calcular\n");
    }
    
    return r;
}
