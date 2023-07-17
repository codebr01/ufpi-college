#include <stdio.h>
#include <string.h>

int main()
{

    int n, i, k, j, iTamanho, achou;
    char idioma2[20];
    char idioma[20];

    scanf("%i", &n);

    for(i = 0; i < n; i++){

        scanf("%i", &k);

        for(j = 0; j < k; j++){
            scanf("%s", idioma);
            if(j == 0){
                strcpy(idioma2, idioma);
                iTamanho = strlen(idioma2);
            }
            if(j >= 1){
                if(strncmp(idioma2, idioma, iTamanho) == 0){
                    achou = 0;
                }else{
                    achou = 1;
                }
                strcpy(idioma2, idioma);
                iTamanho = strlen(idioma2);
            }
        }
        if(achou == 0){
            printf("%s\n", idioma);
        }else{
            printf("ingles\n");
        }
    }

    return 0;
}