#include <stdio.h>
int main(){
    int i,c = 0,numero[10],guardar,achei;
    for(i = 0; i < 10; i++){
        scanf("%i", &numero[i]);
        guardar = numero[i];
        setbuf(stdin,NULL);
        if(numero[i] >= 10 && numero[i] <= 100){
            if(i == 0){
                printf("\n%i\n\n", numero[i]);
            }else{
                for(c = 0; guardar != 0;c++){
                    setbuf(stdin,NULL);
                    if(guardar == numero[c]){
                        achei = 1;
                        guardar = 0;
                    }else{
                        achei = 0;
                    }
                    if(i == c){
                        if(guardar == numero[c]){
                            achei = 1;
                            guardar = 0;
                        }else{
                            achei = 0;
                        }
                    }
                }
            }
        }else{
            i--;
        }
        if(i != 0){
			if(achei == 0){
            	printf("\n%i\n\n", numero[i]);
        	}
    	}
    }
    return 0;
}
