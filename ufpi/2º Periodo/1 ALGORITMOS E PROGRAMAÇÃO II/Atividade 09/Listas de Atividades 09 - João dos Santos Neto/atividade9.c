#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct{
    int chave;
    char nome[20];
} Registro;
typedef struct{
   Registro itens[1001];
   int tamanho;
} Tabela;

void criartabela(Tabela *t){
    int i, j;
    char nome[]="Gol";
    srand(time(NULL));
    for(i=0; i<1000; i++){
        t->itens[i].chave = rand()%1001;
        for(j=0; j<=3; j++){
            t->itens[i].nome[j] = nome[j];
        }
    }
}
void analisedesempenho(Tabela t){
    int num, i, j, ct, soma=0;
    float m=0;
    srand(time(NULL));
    for(i=0; i<100; i++){
        ct=0;
        srand(time(NULL));
        num= (rand()%1000);
        for(j=0; j< t.tamanho; j++){
            if(num == t.itens[i].chave){
                ct=1;
            }
            if(ct==1){
                break;
            }
        }
        soma+=j;
    }
    m=(soma/100);
    printf("A media de registros percorridos eh %.0f \n", m/2);
}
void count(Tabela t){
    int i, cont=0, codigo;
    printf("codigo para pesquisar:\n");
    scanf("%d", &codigo);
    for(i=0; i<t.tamanho; i++){
        if(t.itens[i].chave==codigo){
            cont++;
        }
    }
    if(cont<2){
        printf("O codigo %d se repete %d vez.\n", codigo, cont+1);
    }
    else{
        printf("O codigo %d se repete %d vezes.\n", codigo, cont);
    }
}
void remover(Tabela *t){
    int i, ct, chave;
    printf("chave a ser removida:\n");
    scanf("%d", &chave);
    for(i=0; i< t->tamanho; i++){
        if(t->itens[i].chave == chave){
            ct++;
            if(ct>1){
                (t->itens[i].chave = t->itens[t->tamanho-1].chave);
                --t->tamanho;
            }
        }
    }
	printf("%d registros com o codigo %d foram removidos\n", ct, chave);
    
    
}
int asknome(Tabela t, char nome[]){
    int i, aux;
    for(i=0; i<t.tamanho; i++){
        aux=strcmp(t.itens[i].nome, nome);
        if(aux==0){
            return t.itens[i].chave;
        }
    }
    return -10;
}
void insert(Tabela *t){
    int i, chave, aux, resp;
    char nome[20];
    printf("Inserir chave:\n");
    scanf("%d",&chave);
    printf("Inserir nome: \n");
    scanf("%s", &nome);
    aux=asknome(*t, nome);
    if(aux==-10){
        printf("Nao existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:\n");
    }
    else{
        printf("Existem registros desse veiculo. Digite 0 para cancelar e 1 para confirmar a insercao:\n");
    }
    scanf("%d", &resp);
    if(resp==1){
        ++ t->tamanho;
        t->itens[t->tamanho-1].chave=chave;
        for(i=0; i<20; i++){
            t->itens[t->tamanho-1].nome[i] = '\0';
        }
        for(i=0; i<= strlen(nome)-1; i++){
            t->itens[t->tamanho-1].nome[i]=nome[i];
        }
        printf("Insercao completa!\n");
    }
    else{
        printf("Insercao cancelada!\n");
    }
}
int main(){
    Tabela tabela;
    tabela.tamanho = 1000;
    int i;
    char nome[20];
	do{
		criartabela(&tabela);
	    analisedesempenho(tabela);
	    count(tabela);
	    remover(&tabela);
	
	    printf("Nome a ser pesquisado:\n");
	    scanf("%s", &nome);
	    if(asknome(tabela, nome)!= -10){
	       printf("A chave para esse veiculo eh: %d\n", asknome(tabela, nome));
	    }
	    else{
	       printf("Esse modelo nao esta registrado.\n");
	    }
	
	    insert(&tabela);
	    printf("-------------------------------------------------------------\n");
	}while(nome != '\0');
    
    return 0;
}
