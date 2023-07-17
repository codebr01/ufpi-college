#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

typedef struct{
	int registro;
	char nome[20];
}Registro;

typedef struct{
	Registro reg[MAX + 1];
	int tamanho;
}Tabela;

int contador = 0;

int pesquisa_sequencial(Tabela *t, int chave);
int pesquisa_binaria(Tabela *t, int chave);
int repeticoes(Tabela *t, int n, int *chave_rep);
int func_search_name(Tabela *t, int n, int cod);
void preencher_tabela(Tabela *t);
void ordena(Tabela *t, int n);
void func_insert(Tabela *t, int key);
void func_remove(Tabela *t, int key);

int main(){
	srand(time(NULL));
	Tabela t;
	t.tamanho = 0;
	char resp;
	int chave,chave_rep,i,func_rep,find;
	resp = 'k';
	while(resp != 'X'){
		printf("-----------------------------------------\nDigite - X para sair.\nDigite - 2 para preencher a tabela.\nDigite - 3 para pesquisa sequencial.\nDigite - 4 para pesquisa binaria\nDigite - 5 para ver o numero de repeticoes de um registro\nDigite - 6 para remover um registro\nDigite - 7 para pesquisar um registro\nDigite - 8 para inserir um registro\n-----------------------------------------\nEscolha a alternativa: ");
		scanf("%c", &resp);
		setbuf(stdin,NULL);
		switch(resp){
			case('2'):
				preencher_tabela(&t);
				break;
			case('3'):
				for(i = 0; i < 100; i++){
					chave = rand() % 1000;
					pesquisa_sequencial(&t, chave);
				}printf("\nPesquisa sequencial: a media de registros percorridos por pesquisa eh %.2f\n\n", (float)contador / 100);
				contador = 0;
				break;
			case('4'):
				ordena(&t, MAX + 1);
				for(i = 0; i < 100; i++){// pesquisa binaria
					chave = 1 + rand() % 1000;
					pesquisa_binaria(&t, chave);
				}printf("\nPesquisa binaria: a media de registros percorridos por pesquisa eh %.2f\n\n", (float)contador / 100);
				contador = 0;
				for(i = 1; i < t.tamanho + 1; i++){
					printf("Nome: %s | Registro: %i\n", "Gol", t.reg[i].registro);
				}
				break;
			case('5'):
				printf("\nInforme o codigo entre 0 e 1000 a ser pesquisado: ");
				scanf("%i", &chave_rep);
				setbuf(stdin,NULL);
				func_rep = repeticoes(&t, MAX + 1, chave_rep);
				printf("\nO codigo %i se repete %i vez(es)\n", chave_rep, func_rep);
				break;
			case('6'):
				printf("Digite o registro a ser removido: ");
				scanf("%i", &chave);
				setbuf(stdin,NULL);
				func_remove(&t, chave);
				break;
			case('7'):
				printf("Digite o registro a ser pesquisado: ");
				scanf("%i", &chave);
				setbuf(stdin,NULL);
				find = func_search_name(&t,MAX + 1, chave);
				if(find != 0){
					printf("Veiculo encontrado! Indice: %i\n",find);
				}else{
					printf("Veiculo nao encontrado!\n");
				}
				break;
			case('8'):
				printf("Digite o registro a ser inserido: ");
				scanf("%i", &chave);
				setbuf(stdin,NULL);
				func_insert(&t, chave);
				for(i = 1; i <= MAX + 1; i++){
					printf("Nome: %s | Registro: %i\n", "Gol", t.reg[i].registro);
				}
				break;
		}
	}
	
	return 0;
}

void preencher_tabela(Tabela *t){
	int i;
	for(i = 0; i < MAX + 1; i++){
		if(t->tamanho == MAX){
			printf("Error: Tabela Cheia!\n\n");
		}else{
			t->tamanho++;
			t->reg[t->tamanho].registro = rand() % 1000;
			strcpy(t->reg[t->tamanho].nome, "Gol");
		}
	}
	for(i = 1; i < MAX + 1; i++){
		printf("Nome: %s | Registro: %i\n", t->reg[i].nome, t->reg[i].registro);
	}
	printf("\nTamanho da tabela: %i\n\n", t->tamanho);
}

int pesquisa_sequencial(Tabela *t, int chave){
	int i;
	t->reg[0].registro = chave;
	for(i = t->tamanho; t->reg[i].registro != chave; i--){
		contador++;
	}
	return i;
}

int pesquisa_binaria(Tabela *t, int chave){
	int i,esquerda,direita;
	esquerda = 1;
	direita = t->tamanho;
	do{
		i = (esquerda + direita) / 2;
		if(chave < t->reg[i].registro){
			direita = i - 1;
		}else{
			if(chave > t->reg[i].registro){
				esquerda = i + 1;
			}else{
				return i;
			}
		}
		contador++;
	}while(esquerda <= direita);
}

void ordena(Tabela *t, int n){
	int i, j, aux;
	for(i = 1; i < n - 1; i++){
		for(j = 2; j < n; j++){
			if(t->reg[j].registro < t->reg[j - 1].registro){
				aux = t->reg[j].registro;
				t->reg[j].registro = t->reg[j - 1].registro;
				t->reg[j - 1].registro = aux;
			}
		}
	}
}

int repeticoes(Tabela *t, int n, int *chave_rep){
	int i,cont = 0;
	for(i = 1; i < t->tamanho + 1; i++){
		if(chave_rep == t->reg[i].registro){
			cont++;
		}
	}
	return cont;
}

int func_search_name(Tabela *t, int n, int cod){
	int i,indice,find = 0,posicao;
	for(i = 1; i < n; i++){
		if(cod == t->reg[i].registro){
			find = 1;
			posicao = i;
			i = n;
		}
	}
	if(find = 1){
		return posicao;
	}else{
		return 0;
	}
}

void func_insert(Tabela *t, int key){
	int i,find,choice;
	find = func_search_name(&t,MAX + 1, key);
	if(find == 1){
		printf("Existem registros desse veículo. Digite 0 para cancelar e 1 para confirmar a insercao: ");
		scanf("%i", &choice);
		setbuf(stdin,NULL);
		if(choice == 1){
			for(i = 1; i < t->tamanho + 1; i++){
				if(t->reg[i].registro == 0){
					t->reg[i].registro = key;
					return i;
				}
			}
			if(i == 11){
				t->tamanho++;
				t->reg[t->tamanho].registro = key;
			}
		}else{
			return 0;
		}
	}else{
		printf("Não existem registros desse veículo. Digite 0 para cancelar e 1 para confirmar a insercao: ");
		scanf("%i", &choice);
		setbuf(stdin,NULL);
		if(choice == 1){
			for(i = 1; i < t->tamanho + 1; i++){
				if(t->reg[i].registro == 0){
					t->reg[i].registro = key;
					return i;
				}
			}
			if(i == 11){
				t->tamanho++;
				t->reg[t->tamanho].registro = key;
			}
		}else{
			return 0;
		}
	}
}

void func_remove(Tabela *t, int key){
	int i,limite,cont = 0;
	for(i = 1; i < t->tamanho + 1; i++){
		if(key == t->reg[i].registro){
			t->reg[i].registro = NULL;
			cont++;
		}
	}
	printf("%i registros com o código %i foram removidos\n", cont, key);
	cont = 0;
}
