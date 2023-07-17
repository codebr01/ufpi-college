#include <stdio.h>
#include <string.h>

int main() {
	int tecla, i, j, k, zero, count;
	long long int num;
	char contrato[101];
	
	while(1){
		scanf("%d %s", &tecla, contrato);
		if(tecla == 0 && contrato[0] == '0') break;
		char cha[101];
		i = 0;
		j = 0;
		zero = 0;
		num = 0;
		count = 0;
		while(1){
			if(contrato[i] == '\0'){
				break;
			} else { 
                if(contrato[i] == tecla + 48){
				    i++;
			    } else {
				    cha[j] = contrato[i];
				    if(j == zero){
					    count++;
                    }
				    if(contrato[i] == '0')
					    zero++;
					    i++;
					    j++;
                }
			}
		}
		cha[j] = '\0';
		if(j == 0){
            printf("0\n"); 
        }else{ 
            if(j == zero){
                printf("%lld\n", num); 
            }else{
                if(count > 0){
			        for(k = count - 1; cha[k] != '\0'; k++){
				    printf("%d", cha[k] - 48);
			        }
			        printf("\n");
		        }else{
                    printf("%s\n", cha);
                }
            }
        }
	}
	
	return 0;
}