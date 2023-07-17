#include <stdio.h>
typedef struct{
	char nome[45];
	float ira;
	int ano;
} Pessoa;
int main(){
	int i, num;
	double media = 0.0;
	printf("Informe a quantidade de alunos da turma: ");
	scanf("%i",&num);
	Pessoa pessoa[num];
	for(i=0;i<num;i++){
		setbuf(stdin, NULL);
		printf("Informe o nome do %i aluno: ", i + 1);
		scanf("%[^\n]s", pessoa[i].nome);
		printf("Informe o IRA do %i aluno: ", i + 1);
		scanf("%f", &pessoa[i].ira);
		printf("Informe o ano de graduacao do %i aluno: ", i + 1);
		scanf("%i", &pessoa[i].ano);
		media = media + pessoa[i].ira;
    }
	printf("\nMedia Da Turma: %.1lf\n", media/num);
	for(i=0;i<num;i++){
		if(pessoa[i].ano < 2022){
			printf("Nome do Academico: %s\nIra do Academico: %.1lf\n", pessoa[i].nome, pessoa[i].ira);

	    }
    }
	return 0;
}
