#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    srand(time(NULL));
    int num;
    for(i = 0; i < 50000; i++){
        num = 1 + rand() % 10000;
        printf("%i\n", num);
    }

    return 0;
}