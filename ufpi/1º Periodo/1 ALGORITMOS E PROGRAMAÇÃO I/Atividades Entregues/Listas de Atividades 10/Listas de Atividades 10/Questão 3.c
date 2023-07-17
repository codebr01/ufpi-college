#include <stdio.h>
#include <math.h>
float calculoIMC(float h, float p);
int main(){
    float h,p;
    printf("Informe o peso: ");
    scanf("%f", &p);
    printf("Informe a altura: ");
    scanf("%f", &h);
    float IMC = calculoIMC(h,p);
    if(IMC > 25){
        printf("\nacima do peso\n");
    }else{
        printf("\nIMC = %.1f\n", IMC);
    }
    return 0;
}
float calculoIMC(float h, float p){
    float IMC = p / (pow(h,2));
    return IMC;
}

