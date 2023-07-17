#include <stdio.h>
int main(){
    int x,y,n,i,c;
    scanf("%i", &x);
    scanf("%i", &y);
    n = 0;
    i = 0;
    c = 0;
    for(x--;x > y;x--){
        if(x > 0){
            if(x % 2 == 1){
                i += x;
            }
        }else{
            if(x < 0){
                n = x * -1;
                if(n % 2 == 1){
                    c += n;
                }
            }
        }
    }
    printf("%i\n", i - c);
    return 0;
}
