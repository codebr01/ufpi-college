#include <stdio.h>
#define N 5
int main(){
    char nome[N][20];
    float medidas[N][3];
    int i = 0,altura = 0,peso = 1,ira = 2, posicao_altura = 0, posicao_peso = 0, posicao_ira = 0;
    float maior_altura = 0, maior_peso = 0, maior_ira = 0,menor_altura = 0, menor_peso = 0, menor_ira = 0, soma_altura = 0, soma_peso = 0, soma_ira = 0;
    scanf("%[^\n]s", nome[i]);
    setbuf(stdin,NULL);
    scanf("%f", &medidas[i][altura]);
    maior_altura = medidas[i][altura];
    menor_altura = medidas[i][altura];
    soma_altura += medidas[i][altura];
    posicao_altura = i;
    setbuf(stdin,NULL);
    scanf("%f", &medidas[i][peso]);
    maior_peso = medidas[i][peso];
    menor_peso = medidas[i][peso];
    soma_peso += medidas[i][peso];
    posicao_peso = i;
    setbuf(stdin,NULL);
    scanf("%f", &medidas[i][ira]);
    maior_ira = medidas[i][ira];
    menor_ira = medidas[i][ira];
    soma_ira += medidas[i][ira];
    posicao_ira = i;
    setbuf(stdin,NULL);
    i++;
    while(i < N){
        scanf("%[^\n]s", nome[i]);
        setbuf(stdin,NULL);
        scanf("%f", &medidas[i][altura]);
        soma_altura += medidas[i][altura];
        if(medidas[i][altura] > maior_altura){
            maior_altura = medidas[i][altura];
            posicao_altura = i;
        }else{
            menor_altura = medidas[i][altura];
        }
        scanf("%f", &medidas[i][peso]);
        setbuf(stdin,NULL);
        soma_peso += medidas[i][peso];
        if(medidas[i][peso] > maior_peso){
            maior_peso = medidas[i][peso];
            posicao_peso = i;
        }else{
            menor_peso = medidas[i][peso];
        }
        scanf("%f", &medidas[i][ira]);
        setbuf(stdin,NULL);
        soma_ira += medidas[i][ira];
        if(medidas[i][ira] > maior_ira){
            maior_ira = medidas[i][ira];
            posicao_ira = i;
        }else{
            menor_ira = medidas[i][ira];
        }
        i++;
    }
    printf("\n=== ALTURA ===\n");
    printf("Media Aritmetica: %.2f | Maior altura: %.2f | Menor altura: %.2f\n", soma_altura / N, maior_altura, menor_altura);
    printf("\n=== PESO ===\n");
    printf("Media Aritmetica: %.2f | Maior peso: %.2f | Menor peso: %.2f\n", soma_peso / N, maior_peso, menor_peso);
    printf("\n=== IRA ===\n");
    printf("Media Aritmetica: %.2f | Maior IRA: %.2f | Menor IRA: %.2f\n", soma_ira / N, maior_ira, menor_ira);
    printf("\nMaior altura: %s | Maior peso: %s | Maior IRA: %s\n", nome[posicao_altura], nome[posicao_peso], nome[posicao_ira]);
    return 0;
}
