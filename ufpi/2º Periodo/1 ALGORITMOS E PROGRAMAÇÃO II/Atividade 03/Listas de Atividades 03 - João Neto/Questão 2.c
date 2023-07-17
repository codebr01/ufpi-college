#include <stdio.h>
#include <math.h>
float calcula(float a1, float b1, float a2,float b2);
int main(){
    float x1,y1,x2,y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    printf("%.2f\n", calcula(x1,y1,x2,y2));
    return 0;
}
float calcula(float a1, float b1, float a2, float b2){
    float distancia = sqrt(pow((a2 - a1), 2) + pow((b2 - b1), 2));
    return distancia;
}