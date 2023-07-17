#include <stdio.h>
#include <string.h>
typedef struct {
	char nome[45];
	float altura;
	double peso;
	char RG[15];
} Pessoa;
int main() {
	int n, cont;
	char rg[15];
	double imc;
	printf("Informe quantas pessoas: ");
	scanf("%i", &n);
	Pessoa pessoa[n];
	for(cont = 0; cont < n; cont++) {
		printf("Informe o nome da %i pessoa:", i + 1);
		setbuf(stdin, NULL);
		scanf("%[^\n]s", pessoa[cont].nome);
		printf("Informe a altura da %i pessoa: ", i + 1);
		scanf("%f", &pessoa[cont].altura);
		printf("Informe o peso da %i pessoa: ", i + 1);
		scanf("%lf", &pessoa[cont].peso);
		printf("Informe o RG da %i pessoa:", i + 1);
		scanf("%s", pessoa[cont].RG);
	}
	printf("Informe um RG:");
	scanf("%s", rg);
	for(cont = 0; cont < n; cont++) {
		if(strcmp(pessoa[cont].RG, rg) == 0) {
			imc = pessoa[cont].peso / (pessoa[cont].altura * pessoa[cont].altura);
			printf("Nome: %s, IMC = %.2lf\n", pessoa[cont].nome, imc);
			break;
		}
	}
	return 0;
}
