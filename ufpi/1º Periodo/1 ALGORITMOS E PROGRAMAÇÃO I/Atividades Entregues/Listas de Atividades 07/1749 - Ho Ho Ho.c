#include <stdio.h>
int main(){
    int num;
    scanf("%i", &num);
    for(num;num > 0;num--){
        if(num != 1){
            printf("Ho ");
        }else{
            if(num == 1){
                printf("Ho!\n");
            }
        }
    }
    return 0;
}
