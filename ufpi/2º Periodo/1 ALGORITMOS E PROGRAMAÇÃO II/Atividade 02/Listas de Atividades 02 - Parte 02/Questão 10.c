#include <stdio.h>
int main(){
    char oitavas[16];
    char quartas[8];
    char semi[4];
    char final[2];
    int i,j = 65, m, n,c = 0;
    for(i = 0; i < 16; i++){
        oitavas[i] = j;
        j++;
    }
    for(i = 0; i < 8; i++){
        scanf("%i %i", &m, &n);
        setbuf(stdin,NULL);
        if((m >= 0 && m <= 20) && (n >= 0 && n <= 20)){
            if(m > n){
                quartas[i] = oitavas[c];
            }else{
                quartas[i] = oitavas[c + 1];
            }
            c++;
            c++;
        }else{
            i--;
        }
    }
    c = 0;
    for(i = 0; i < 4; i++){
        scanf("%i %i", &m, &n);
        setbuf(stdin,NULL);
        if((m >= 0 && m <= 20) && (n >= 0 && n <= 20)){
            if(m > n){
                semi[i] = quartas[c];
            }else{
                semi[i] = quartas[c + 1];
            }
            c++;
            c++;
        }else{
            i--;
        }
    }
    c = 0;
    for(i = 0; i < 2; i++){
        scanf("%i %i", &m, &n);
        setbuf(stdin,NULL);
        if((m >= 0 && m <= 20) && (n >= 0 && n <= 20)){
            if(m > n){
                final[i] = semi[c];
            }else{
                final[i] = semi[c + 1];
            }
            c++;
            c++;
        }else{
            i--;
        }
    }
    c = 0;
    for(i = 0; i < 1; i++){
        scanf("%i %i", &m, &n);
        setbuf(stdin,NULL);
        if((m >= 0 && m <= 20) && (n >= 0 && n <= 20)){
            if(m > n){
                printf("%c\n", final[0]);
            }else{
                printf("%c\n", final[1]);
            }
        }else{
            i--;
        }
    }
    return 0;
}