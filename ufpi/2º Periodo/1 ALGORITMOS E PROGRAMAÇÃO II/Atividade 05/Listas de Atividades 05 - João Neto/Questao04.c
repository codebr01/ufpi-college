#include <stdio.h>

void somaComplexo( float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3);

int main(){
    float rz1,iz1,rz2,iz2,rz3,iz3;

    for(;;){
        scanf("%f %f %f %f", &rz1, &iz1, &rz2, &iz2);
        if(rz1 == 0 && iz1 == 0 && rz2 == 0 && iz2 == 0){
            break;
        }else{
            somaComplexo(rz1,iz1,rz2,iz2,&rz3,&iz3);
            printf("%.1f + %.1fi\n", rz3,iz3);
        }
    }
    
    return 0;
}
void somaComplexo( float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3){
    *rz3 = rz1 + rz2;
    *iz3 = iz1 + iz2;
}