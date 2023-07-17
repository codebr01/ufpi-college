#include <stdio.h>
float nota,idade,nota3,nota2,nota1,soma_idade3,soma_idade2,soma_idade1,cont,porc3,porc2,porc1;
char pergunta;
int main(){
    printf("NOTAS PARA O FILME LA LA LAND....\n");
    printf("[ 3 ] - EXECELENTE \n[ 2 ] - BOM \n[ 1 ] - REGULAR \n[ 0 ] - PARA FINALIZAR\n");
    do{
        printf("Qual a sua nota? >> ");
        scanf("%f", &nota);
        if(nota != 0){
            if(nota == 3){
                cont += 1;
                nota3 += 1;
                printf("Qual a sua idade? >> ");
                scanf("%f",&idade);
                soma_idade3 += idade;
            }else{
                if(nota == 2){
                    cont += 1;
                    nota2 += 1;
                    printf("Qual a sua idade? >> ");
                    scanf("%f",&idade);
                    soma_idade2 += idade;
                }else{
                    if(nota == 1){
                        cont += 1;
                        nota1 += 1;
                        printf("Qual a sua idade? >> ");
                        scanf("%f",&idade);
                        soma_idade1 += idade;
                    }else{
                        if(nota < 3){
                            printf("Voce nao selecionou uma das opcoes...\n");
                        }
                    }
                }
            }
        setbuf(stdin,NULL);
        printf("\nVoce quer continuar no programa? [ s / n ]>> ");
        scanf("%c", &pergunta);
        }else{
            pergunta = 'n';
            printf("\nVOCE SAIU DO PROGRAMA....\n");
        }
    }while(pergunta != 'n');
    porc3 = (nota3 / cont) * 100;
    porc2 = (nota2 / cont) * 100;
    porc1 = (nota1 / cont) * 100;
    printf("%.1f%% deram nota EXCELENTE e a media das idades foi %.1f\n",porc3, soma_idade3 / nota3);
    printf("%.1f%% deram nota BOM e a media das idade foi %.1f\n",porc2, soma_idade2 / nota2);
    printf("%.1f%% deram nota REGULAR e a media das idade foi %.1f\n",porc1, soma_idade1 / nota1);
    return 0;
}
