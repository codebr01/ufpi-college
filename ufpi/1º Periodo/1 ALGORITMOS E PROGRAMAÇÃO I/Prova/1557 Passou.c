#include <stdio.h>
void preencheMatriz();
void imprimeMatriz();
int N;
int main(){
    for(;;){
        preencheMatriz();
        if(N == 0 || N > 15){
            break;
        }
        imprimeMatriz();
    }
    return 0;
}
void preencheMatriz(){
    scanf("%d", &N);
}
void imprimeMatriz(){
    long long int M[N][N],l,j,k,m,o,i;
        l = 1;
        for(i = 0; i < N; i++){
                k = l;
            for(j = 0; j < N; j++){
                M[i][j] = k;
                k += k;
            }l += l;
        }
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(N == 1)printf("%lld", M[i][j]);
                else if(N == 2){
                    if(j == 0)printf("%lld", M[i][j]);
                    else printf(" %lld", M[i][j]);
                }
                else if(N == 3 || N == 4){
                    if(j == 0)printf(" %lld", M[i][j]);
                    else printf("%3lld", M[i][j]);
                }
            else if(N == 5){
                if(j == 0)printf("%3lld", M[i][j]);
                else printf("%4lld", M[i][j]);
            }
            else if(N ==6 || N == 7){
                if(j == 0)printf("%4lld", M[i][j]);
                else printf("%5lld", M[i][j]);
            }
            else if(N == 8 || N == 9){
                if(j == 0)printf("%5lld", M[i][j]);
                else printf("%6lld", M[i][j]);
            }
            else if(N == 10){
                if(j == 0)printf("%6lld", M[i][j]);
                else printf("%7lld", M[i][j]);
            }
            else if(N == 11 || N == 12){
                if(j == 0)printf("%7lld", M[i][j]);
                else printf("%8lld", M[i][j]);
            }
            else if(N == 13 || N == 14){
                if(j == 0)printf("%8lld", M[i][j]);
                else printf("%9lld", M[i][j]);
            }
            else if(N == 15){
                if(j == 0)printf("%9lld", M[i][j]);
                else printf("%10lld", M[i][j]);
            }
            }printf("\n");
        }printf("\n");
}
