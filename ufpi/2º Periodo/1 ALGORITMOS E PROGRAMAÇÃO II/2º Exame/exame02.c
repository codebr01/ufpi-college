#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct{
    int codigo;
    char descricao[30];
    float preco;
}Cadastro;
void cadastrar(){
	int cod;
    FILE *f=fopen("dados.txt","rb+");
    if(f==NULL){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    Cadastro aux;
    printf("codigo:\n");
    scanf("%d", &cod);
    while(!feof(f)){
        fread(&aux, sizeof(Cadastro), 1, f);
        if (aux.codigo == 0){
            continue;
        }
        else if(aux.codigo ==cod){
            printf("Codigo ja foi cadastrado!\n");
            fclose(f);
            return 0;
        }
    }
    aux.codigo = cod;
    printf("descricao:\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", aux.descricao);
    printf("preco:\n");
    scanf("%f", &aux.preco);
    // fprintf(f, "%d, %s, %.2f\n", aux.codigo, aux.descricao, aux.preco);
    fseek(f, aux.codigo * sizeof(Cadastro), SEEK_SET);
    fwrite(&aux, sizeof(Cadastro), 1, f);
    fclose(f);
}
void visualizar(){
    FILE *f = fopen("dados.txt", "rb");
    if(f==(NULL)){
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }
    Cadastro aux;
    // printf("codigo, descricao e preco:\n");
    while (!feof(f)){
        fread(&aux, sizeof(Cadastro), 1, f);
        if (aux.codigo == 0){
            continue;
        }
        fscanf(f,"%d %s %f", &aux.codigo, aux.descricao, &aux.preco);
        printf("%d, %s, %.2f.\n", aux.codigo, aux.descricao, aux.preco);
    }
    fclose(f);
}
void vregistro(){
    FILE *f = fopen("dados.txt", "rb");
    if(f==(NULL)){
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }
    // printf("Codigo:\n");
    int cod;
    scanf("%d", &cod);
    Cadastro aux;
    fseek(f, cod* sizeof(Cadastro), SEEK_SET);
    fread(&aux, sizeof(Cadastro), 1, f);
    if(cod!=aux.codigo){
        // printf("O cadastro desse codigo nao exite!\n");
        fclose(f);
        return 0;
    }
    else{
        printf("%d, %s ,%.2f.\n",  aux.codigo, aux.descricao, aux.preco);
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
int main(){
    int opcao;
    FILE *f = fopen("dados.txt", "rb");
    if(f==(NULL)){
        f = fopen("dados.txt", "wb");
    }
    printf("1-cadastrar\n2-visualizar\n3-visualizar um registro\n4-ordenar por preco\n5-finalizar.\n");
    do{
        printf("\nInforme o modulo desejado:\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            cadastrar();
            break;
        case 2:
            visualizar();
            break;
        case 3:
            vregistro();
            break;
       case 4:
           ordenar();
           break;
        
        default:
            break;
        }
    }while(opcao != 5);
    return 0;
}