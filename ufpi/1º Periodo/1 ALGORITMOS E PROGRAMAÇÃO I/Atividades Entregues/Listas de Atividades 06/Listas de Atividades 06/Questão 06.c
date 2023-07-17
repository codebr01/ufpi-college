#include <stdio.h>
int main(){
	int conjunto[12],x,y,i;
	for(i = 0;i < 12; i++){
		printf("Digite o %i numero: ", i + 1);
		scanf("%i",&conjunto[i]);
	}
	printf("\nDigite um numero entre 0 e 11: ");
    scanf("%i",&x);
	printf("\nDigite mais um numero entre 0 e 11: ");
    scanf("%i",&y);
	printf("\nA soma: %i\n",conjunto[x] + conjunto[y]);
	return 0;
}
