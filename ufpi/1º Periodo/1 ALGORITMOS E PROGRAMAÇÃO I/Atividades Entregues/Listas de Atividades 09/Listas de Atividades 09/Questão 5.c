#include <stdio.h>
struct Data{
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;
};
int main(){
    struct Data d;
    int i,data1,data2;
    printf("Primeira Data ----------\n");
    printf("Infome o dia: ");
    scanf("%i", &d.dia1);
    printf("Informe o mes: ");
    scanf("%i", &d.mes1);
    printf("Informe o ano[ex: 2023,2021]: ");
    scanf("%i", &d.ano1);
    printf("Segunda Data ------------\n");
    printf("Infome o dia: ");
    scanf("%i", &d.dia2);
    printf("Informe o mes: ");
    scanf("%i", &d.mes2);
    printf("Informe o ano[ex: 2023,2021]: ");
    scanf("%i", &d.ano2);
    data1 = (d.ano1 * 365) + (d.mes1 * 31) + d.dia1;
    data2 = (d.ano2 * 365) + (d.mes2 * 31) + d.dia2;
    if(data1 > data2){
        if(data1 - data2 >= 41){
            printf("ultrapassa quarentena!\n");
        }
    }else{
        if(data2 > data1){
            if(data2 - data1 >= 41){
                printf("ultrapassa quarentena!\n");
            }
        }
    }
    return 0;
}
