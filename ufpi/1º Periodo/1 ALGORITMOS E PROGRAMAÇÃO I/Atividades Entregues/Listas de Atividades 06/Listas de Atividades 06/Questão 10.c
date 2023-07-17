#include <stdio.h>
int main(){
    double n[100];
    int i;
    i = 0;
    scanf("%lf", &n[0]);
    printf("N[%i] = %.4lf\n", i,n[0]);
    for(i = 0; i < 99; i++){
        n[i + 1] = n[i] / 2;
        printf("N[%i] = %.4lf\n", i + 1, n[i + 1]);
    }
    return 0;
}
