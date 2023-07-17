#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int locacao;
	char carro[20];
	float valor;
}Regis;

int op;
FILE *fptr;

void Formatar(Regis dad){
	int i;
	fptr = fopen("dados.bin", "wb");
	for(i=1; i<1000; i++){
		fwrite(&dad, sizeof( Regis ), 1, fptr );
	}
	fclose(fptr);
	printf("Arquivo formatado \n");
	printf("Voltando para o MENU...... \n");
	printf("Escolha outra Opcao: ");
	scanf("%d", &op);
}

void Escrever(Regis dad){
	
	fptr = fopen("dados.bin", "rb+");
	if(fptr == NULL){
		printf("Error ao localizar o arquivo desejado!!");
	}else{
		dad.locacao = 1;
		printf("Digite so a Locacao:");
		scanf("%d", &dad.locacao);
		while(dad.locacao != 0){
			printf("Digite o nome do carro e o seu valor: \nValor? ");
			fscanf(stdin, "%s%f", dad.carro, &dad.valor);
			fseek(fptr, ( dad.locacao - 1 ) * sizeof( Regis ), SEEK_SET);
			fwrite(&dad, sizeof( Regis), 1, fptr );
			printf("Locacao:");
			scanf("%d", &dad.locacao);
		}
	}
	printf("Informacao salva no arquivo!! \n");
	printf("Voltando para o MENU...... \n");
	printf("Escolha outra Opcao: ");
	scanf("%d", &op);
	
}

void Ler(Regis dad){
	
	fptr = fopen("dados.bin", "rb");
	if(fptr == NULL){
		printf("Error ao encontrar arquivo \n");
	}else{
		printf("\tLocacao\t\tNome\t\tValor \n");	
		 while ( !feof( fptr ) ) {
            fread( &dad, sizeof( Regis ), 1, fptr );
            if ( dad.locacao != 0 ) {
                printf("\t%d\t\t%s\t\t%2.f\n", dad.locacao, dad.carro, dad.valor);
            }
        }
        fclose( fptr );
	}
	printf("Arquivo Lido!! \n");
	printf("Se foi inserido mais de uma informacao no arquivo, porfavor reinicie o programa para as informacoes aparecerem nessa opcao\n");
	printf("Voltando para o MENU...... \n");
	printf("Escolha outra Opcao: ");
	scanf("%d", &op);
}

void Busca(Regis dad){
	
    fptr = fopen( "dados.bin", "rb" );
    if (  fptr == NULL ) {
        printf( "Error ao abrir o arquivo. \n" );
    }
    else {
      printf( "Buscar numero de locacao: \n");
        scanf( "%d", &dad.locacao);
       
            fseek(fptr, ( dad.locacao - 1 ) * sizeof( Regis ), SEEK_SET);
            fread( &dad, sizeof( Regis ), 1, fptr );
            printf( "\tLocacao\t\tNome\t\tValor \n" );
            printf( "\t%d\t\t%s\t\t%2.f\n", dad.locacao, dad.carro, dad.valor);            
        
    fclose( fptr );
    }
    printf("Busca completa!! \n");
	printf("Voltando para o MENU...... \n");
	printf("Escolha outra Opcao: ");
	scanf("%d", &op);
}

int main(){
	Regis dados[1000];
	Regis dad;
	printf(" Sistema de locacao baseado em arquivo \n");
	printf(" 1-Formatar \n 2-Escrever \n 3-Ler \n 4-Buscar \n 0-Finalizar\n ");		
	printf("Opcao: ");
	scanf("%d", &op);
	
	while(op!=0){
		switch(op){
			case 1:
				Formatar(dad);
				break;
			case 2:
				Escrever(dad);
				break;
			case 3:
				Ler(dad);
				break;
			case 4:
				Busca(dad);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Opcao Invalida");
		}
	}
	return 0;	
}
