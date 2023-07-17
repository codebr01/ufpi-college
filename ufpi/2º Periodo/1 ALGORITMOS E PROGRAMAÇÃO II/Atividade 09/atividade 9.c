#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

typedef struct{
	int codigo;
	char nome[20];
}Registro;

typedef struct{
	Registro reg[MAX + 1];
	int tamanho;
}Tabela;

int contador = 0,chave_rep;

int pesquisa_sequencial(Tabela *t, int chave);
int pesquisa_binaria(Tabela *t, int chave_bin);
int repeticoes(Tabela *t, int n);
int func_search_name(Tabela *t, int n, int cod);
void ordena(Tabela *t, int n);
void func_remove(Tabela *t, int n);
void func_insert(Tabela *t);

int main(){
	srand(time(NULL));
	int i,chave,func_rep,codigo;
	char nome[20];
	Tabela tab;
	tab.tamanho = 0;
	
	for(i = 0; i <= MAX ; i++){// preenchendo a tabela
		if(tab.tamanho >= MAX){
			printf("Error: Tabela Cheia!\n");
		}else{
			tab.tamanho++;
			tab.reg[tab.tamanho].codigo = rand() % 1000;
			strcpy(tab.reg[tab.tamanho].nome, "Gol");
		}
	}
	printf("\nTamanho da tabela: %i\n", tab.tamanho);
	for(i = 0; i < 100; i++){// pesquisa sequencial
		chave = 1 + rand() % 100;
		pesquisa_sequencial(&tab, chave);
	}printf("\nPesquisa sequencial: a media de registros percorridos por pesquisa eh %.2f\n\n", (float)contador / 100);
	contador = 0;
	ordena(&tab, MAX + 1);
	for(i = 0; i < 100; i++){// pesquisa binaria
		chave = 1 + rand() % 1000;
		pesquisa_binaria(&tab, chave);
	}printf("Pesquisa binaria: a media de registros percorridos por pesquisa eh %.2f\n", (float)contador / 100);
	contador = 0;
	func_rep = repeticoes(&tab, MAX + 1);
	printf("\nO codigo %i se repete %i vez(es)\n", chave_rep, func_rep);
	func_remove(&tab, MAX + 1);
	printf("Informe o nome e codigo: ");
	scanf("%s %i", nome, &codigo);
	func_search_name(&tab, MAX + 1,codigo);
	func_insert(&tab);
	for(i = 1; i <= tab.tamanho + 1; i++){
	    if(tab.reg[i].codigo > 0){
		    printf("NOME: %s | CODIGO: %i\n", tab.reg[i].nome, tab.reg[i].codigo);
	    }
	}
	return 0;
}

int pesquisa_sequencial(Tabela *t, int chave){
	int i;
	t->reg[0].codigo = chave;
	for(i = t->tamanho; t->reg[i].codigo != chave; i--){
		contador++;
	}
	return i;
}

int pesquisa_binaria(Tabela *t, int chave_bin){
	int i,esquerda,direita;
	esquerda = 1;
	direita = t->tamanho;
	do{
		i = (esquerda + direita) / 2;
		if(chave_bin < t->reg[i].codigo){
			direita = i - 1;
		}else{
			if(chave_bin > t->reg[i].codigo){
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
			if(t->reg[j].codigo < t->reg[j - 1].codigo){
				aux = t->reg[j].codigo;
				t->reg[j].codigo = t->reg[j - 1].codigo;
				t->reg[j - 1].codigo = aux;
			}
		}
	}
}

int repeticoes(Tabela *t, int n){
	int i,cont = 0;
	printf("\nInforme o codigo entre 0 e 1000 a ser pesquisado: ");
	scanf("%i", &chave_rep);
	setbuf(stdin,NULL);
	for(i = 1; i < n; i++){
		if(chave_rep == t->reg[i].codigo){
			cont++;
		}
	}
	return cont;
}

void func_remove(Tabela *t, int n){
	int codigo,i,cont = 0;
	printf("\nInforme o codigo a ser removido: ");
	scanf("%i", &codigo);
	printf("\n");
	for(i = 1; i < n; i++){
		if(codigo == t->reg[i].codigo){
			t->reg[i].codigo = NULL;
			printf("Conteudo do indice: %i | REMOVIDO\n", i);
			cont++;
		}
	}
	printf("%i registros com o codigo %i foram removidos\n\n", cont, codigo);
}

int func_search_name(Tabela *t, int n, int cod){
	int i,indice,find = 0;
	for(i = 1; i < n; i++){
		if(cod == t->reg[i].codigo){
			return i;
		}
	}
}

void func_insert(Tabela *t){
	int registro,indice,resp,p;
	char nome[20];
	printf("\nInfome o nome e codigo para insercao: ");
	scanf("%s %i", nome,&registro);
	setbuf(stdin,NULL);
	indice = func_search_name(t,t->tamanho + 1,registro);
	if(indice != 0){
		printf("\nExistem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao: ");
		scanf("%i", &resp);
		setbuf(stdin,NULL);
		if(resp == 1){
			t->tamanho++;
			p = t->tamanho;
			t->reg[p].codigo = registro;
			strcpy(t->reg[p].nome, nome);
		}
	}else{
		printf("\nNão existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao: ");
		scanf("%i", &resp);
		setbuf(stdin,NULL);
		if(resp == 1){
			t->tamanho++;
			p = t->tamanho;
			t->reg[p].codigo = registro;
			strcpy(t->reg[p].nome, nome);
		}
	}
	printf("\n");
	
}
