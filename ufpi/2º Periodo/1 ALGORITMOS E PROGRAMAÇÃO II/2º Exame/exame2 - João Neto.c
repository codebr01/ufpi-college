#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct{
    int codigo;
    char descricao[30];
    float preco;
}Cadastro;

void cadastrar();
void visualizar();
void remover_registro(Cadastro *c);
void ordenar();
void selecao(Cadastro *array, int n);

int tamanho = 0;

int main(){// 2 pontos
	FILE *f = fopen("dados.txt", "rb");
	Cadastro c;
    if(f==(NULL)){
        f = fopen("dados.txt", "wb");
    }
	int resp = 8;
	printf("1-cadastrar\n2-visualizar\n3-remover registro\n4-ordenar por descrição\n5-finalizar.\n");
	while(resp != 5){
		printf("Informe o módulo desejado:");
		scanf("%i", &resp);
		setbuf(stdin,NULL);

		if(resp == 1){//cadastrar 2 pontos
			cadastrar();
		}else{
			if(resp == 2){//visualizar 2 pontos
				visualizar();
			}else{
				if(resp == 3){//remover registro
					remover_registro(&c);
				}else{
					if(resp == 4){//ordenar por descrição
						ordenar();
					}else{
						if(resp == 5){//finalizar
							return 0;
						}
					}
				}
			}
		}
	}

	return 0;
}

void cadastrar(){
	int cod;
    FILE *f = fopen("dados.txt","rb+");
    if(f == NULL){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    Cadastro aux;
    printf("Informe o codigo do produto: ");
    scanf("%i", &cod);
    while(!feof(f)){
        fread(&aux, sizeof(Cadastro), 1, f);
        if (aux.codigo == 0){
            continue;
        }
        else if(aux.codigo == cod){
            printf("Codigo do produto ja foi cadastrado!\n");
            fclose(f);
        }
    }
    aux.codigo = cod;
    printf("Informe a descricao do produto: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", aux.descricao);
    printf("Informe o preco do produto: ");
    scanf("%f", &aux.preco);
    fseek(f, aux.codigo * sizeof(Cadastro), SEEK_SET);
    fwrite(&aux, sizeof(Cadastro), 1, f);
    tamanho++;
    fclose(f);
    printf("\n");

}

void visualizar(){
	FILE *f = fopen("dados.txt", "rb");
    if(f==(NULL)){
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }
    Cadastro aux;
    while(!feof(f)){
        fread(&aux, sizeof(Cadastro), 1, f);
        if (aux.codigo == 0){
            continue;
        }
        fscanf(f,"%i %s %f", &aux.codigo, aux.descricao, &aux.preco);
        printf("%i, %s, %.2f.\n", aux.codigo, aux.descricao, aux.preco);
    }
    fclose(f);
    printf("\n");
}

void remover_registro(Cadastro *c){
	int codigo, i,cod;
	FILE *g;
    printf("\nDigite o codigo a ser retirado: ");
    scanf("%i", &codigo);

    g = fopen("dados.txt", "r");

    if(c == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }else{
        for(;!feof;){
            if(fscanf(g,"%i", c->codigo) == codigo){
                c->codigo = NULL;
            }
        }
		
    }
    fclose(g);
    printf("\n");
}

void ordenar(){
    FILE *f = fopen("dados.bin", "rb");
    Cadastro array[MAX] = {};
    
    fread(array, sizeof(Cadastro), MAX, f);
    selecao(array, MAX);

    int i;
    for(i=MAX-1; i>0; i--){
        if (array[i].codigo == 0){
            break;
        }
        printf("%d, %s, %.2f.\n",  array[i].codigo, array[i].descricao, array[i].preco);
    }
    fclose(f);
}
void selecao(Cadastro *array, int n){
    int i, j, min;
    for (i=0; i<n-1; i++){
        min=i;
        for (j=i+1; j<n; j++){
            if (array[j].preco<array[min].preco){
                min=j;
            }
        }
        Cadastro aux=array[i];
        array[i]=array[min];
        array[min]=aux;
    }
}