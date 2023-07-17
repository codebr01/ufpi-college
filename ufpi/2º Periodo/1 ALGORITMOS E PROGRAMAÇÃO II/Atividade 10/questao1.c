#include <stdio.h>
#include <stdlib.h>

typedef struct
{	
	int locacao;
	char *nomecarro;
}Carro;

typedef struct{
	int locacao2;
	char *nomecarro2;
}Carro2;

FILE  *fptr;

void salvarDados(Carro car[], char Arquivo[])
{
	int i;
	fptr = fopen(Arquivo, "w");
	
	if( fptr == NULL ){
        fprintf(stderr,"Erro na abertura de arquivo!\n");
        exit(1);
    }else{
    	for(i=0;i<1000;i++)
		{
			car[i].locacao = rand() % 1000;
			car[i].nomecarro = "Gol";
			fprintf(fptr, "%d %s \n", car[i].locacao, car[i].nomecarro);
		}
    fclose(fptr);
	}
	printf("Operacao concluida com sucesso! \n");
}

void restaurarDados(Carro2 car2[], char Arquivo[])
{
	int i=0;
	int teste;
	char teste2[1000];
	fptr = fopen(Arquivo, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Error na abertura do arquivo!");
		exit(1);
	}else
	{
		for(i=0;i<1000;i++){
			fscanf(fptr, "%d %[^\n]s", &teste, teste2);
			car2[i].locacao2 = teste;
			car2[i].nomecarro2 = teste2;		
		}
		fclose(fptr);
		printf("Operacao concluida com sucesso! \n");
	}
}

int main()
{
	
	Carro car[1000];
	Carro2 car2[1000];
	char Arquivo[10];
	int op;
	printf("Sistema de Backup de Dados \n");
	printf("Informe a operacao desejada (1-Salvar, 2-restaurar): ");
	scanf("%d", &op);
	printf("Informe o nome do arquivo de backup: ");
	scanf("%s", &Arquivo);
	
	if(op==1){
		salvarDados(car, Arquivo);
	}
	if(op==2)
	{
		restaurarDados(car2, Arquivo);
	}
	return 0;
}
