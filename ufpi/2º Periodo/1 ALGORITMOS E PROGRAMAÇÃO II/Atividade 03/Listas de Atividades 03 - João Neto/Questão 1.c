#include <stdio.h>
int valor(int copia);
int main(){
    int i,num;
    for(i = 0; i != 1;){
        scanf("%i", &num);
        if(num >= 1000 && num <= 9999){
            printf("%i\n", valor(num));
            i = 1;
        }
    }
    return 0;
}
int valor(int copia){
    int inverte,rep = 1,num2 = 0;
    while(rep <= 4){
        if(rep == 1){
            inverte = copia % 10;
            num2 += inverte * 1000;
            copia /= 10;
        }else{
            if(rep == 2){
                inverte = copia % 10;
                num2 += inverte * 100;
                copia /= 10;
            }else{
                if(rep == 3){
                    inverte = copia % 10;
                    num2 += inverte * 10;
                    copia /= 10;
                }else{
                    if(rep == 4){
                        inverte = copia % 10;
                        num2 += inverte;
                    }
                }
            }
        }
        rep++;
    }
    copia = num2;
    return copia;
}