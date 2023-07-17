#include <stdio.h>
#include <string.h>
typedef struct{
	char nome[45];
	char codigo[45];
	float preco;
} Nomes;
int main(){
	int num, i;
	char np;
	float pp;
	char cdg[2];
	printf("Quantos Produtos: ");
	scanf("%d", &num);
	Nomes nome[num];
	for(i=0;i<num;i++){
		setbuf(stdin, NULL);
		printf("Nome: ");
		scanf("%s", nome[i].nome);
		printf("Codigo: ");
		scanf("%s", nome[i].codigo);
		printf("Valor R$: ");
		scanf("%f", &nome[i].preco);
		system("cls");
	}
	printf("Codigo: ");
	scanf("%s", cdg);
	for(i=0;i<num;i++){
	   if(strcmp(nome[i].codigo, cdg) == 0) {
			printf("\nNome: %s, Preco R$ %.1f\n", nome[i].nome, nome[i].preco);
	    }
    }
    return 0;
}
