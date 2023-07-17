#include <stdio.h>
#include <math.h>
typedef struct{
    float x1,x2,y1,y2;
}Ponto;
Ponto distancia();
Ponto distancia(Ponto p){
    printf("Distancia: %.4f\n", sqrt(pow((p.x2 - p.x1), 2) + pow((p.y2 - p.y1), 2)));
    return p;
}
int main(){
    Ponto p;
    scanf("%f %f", &p.x1, &p.x2);
    scanf("%f %f", &p.y1, &p.y2);
    distancia(p);
    return 0;
}