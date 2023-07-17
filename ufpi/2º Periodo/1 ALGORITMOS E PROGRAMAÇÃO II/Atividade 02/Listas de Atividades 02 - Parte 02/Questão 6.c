#include <stdio.h>
#define m 2
#define n 3
#define p 2
int main(){
    int A[m][n], B[n][p], C[m][p], i,multi = 0,j,o = 0,t = 0,k = 0,l = 0, rep = 1;
    printf("Coloque valores na matriz A:\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            scanf("%i", &A[i][j]);
            setbuf(stdin,NULL);
        }
    }
    printf("Coloque valores na matriz B:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            scanf("%i", &B[i][j]);
            setbuf(stdin,NULL);
        }
    }
    printf("\nMATRIZ A:\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMATRIZ B:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 2; j++){
            printf("%i ", B[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            C[i][j] = 0;
        }
    }
    printf("\n");
    rep = 1;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            for(rep = 1;rep < 4; rep++){
                multi = A[k][l] * B[o][t];
                C[i][j] += multi;
                l++;
                o++;
                multi = 0;
            }
            t++;
            l = 0;
            o = 0;
        }
        k++;
        o = 0;
        l = 0;
        t = 0;
    }
    printf("\nMATRIZ C:\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}