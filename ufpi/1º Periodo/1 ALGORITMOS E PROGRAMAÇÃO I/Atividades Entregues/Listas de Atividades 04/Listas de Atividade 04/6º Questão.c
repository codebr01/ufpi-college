#include <stdio.h>

int destino, passagem;

int main(){
    printf("Escolha uma das opcoes a seguir teclando o numero no seu teclado.\n\n");
    printf("============== Rodoviaria UFPI ==================\n");
    printf("[ 1 ] Destino: Regiao Norte\n");
    printf("[ 2 ] Destino: Regiao Nortedeste\n");
    printf("[ 3 ] Destino: Regiao Centro-Oeste\n");
    printf("[ 4 ] Destino: Regiao Sul\n");
    printf("\nEscolha seu destino: ");
    scanf("%i", &destino);
    switch(destino){
    case 1:
        printf("\nEscreva com seu teclado o tipo de passagem.\n");
        printf("\n[ 1 ] IDA\n");
        printf("[ 2 ] IDA E VOLTA\n");
        printf("\nEscolha a passagem: ");
        scanf("%i", &passagem);
        if(passagem == 1){
            printf("A passagem custa R$500,00\n");
        }else{
            if(passagem == 2){
                printf("A passagem custa R$900,00\n");
            }
        }
        break;
    case 2:
        printf("\nEscolha com seu teclado o tipo de passagem.\n");
        printf("\n[ 1 ] IDA\n");
        printf("[ 2 ] IDA E VOLTA\n");
        printf("\nEscolha a passagem: ");
        scanf("%i", &passagem);
        if(passagem == 1){
            printf("A passagem custa R$350,00\n");
        }else{
            if(passagem == 2){
                printf("A passagem custa R$650,00\n");
            }
        }
        break;
    case 3:
        printf("\nEscolha com seu teclado o tipo de passagem.\n");
        printf("\n[ 1 ] IDA\n");
        printf("[ 2 ] IDA E VOLTA\n");
        printf("\nEscolha a passagem: ");
        scanf("%i", &passagem);
        if(passagem == 1){
            printf("A passagem custa R$350,00\n");
        }else{
            if(passagem == 2){
                printf("A passagem custa R$600,00\n");
            }
        }
        break;
    case 4:
        printf("\nEscolha com seu teclado o tipo de passagem.\n");
        printf("\n[ 1 ] IDA\n");
        printf("[ 2 ] IDA E VOLTA\n");
        printf("\nEscolha a passagem: ");
        scanf("%i", &passagem);
        if(passagem == 1){
            printf("A passagem custa R$300,00\n");
        }else{
            if(passagem == 2){
                printf("A passagem custa R$550,00\n");
            }
        }
        break;
    default:
        printf("\nVoce nao selecionou nenhuma das opcoes.\n");
    }
    return 0;
}
