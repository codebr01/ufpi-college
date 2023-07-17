#include <stdio.h>
char sexo;
int contm, contf;
int main(){
    printf("Infome o sexo [m / f] ou [ @ ] para terminar: ");
    scanf("%c", &sexo);
    contm = 0;
    contf = 0;
    setbuf(stdin,NULL);
    while(sexo != '@'){
        if(sexo == 'm'){
            contm += 1;
        }else{
            if(sexo == 'f'){
                contf += 1;
            }
        }
        printf("\nInfome o sexo [m / f] ou [ @ ] para terminar: ");
        scanf("%c", &sexo);
        setbuf(stdin,NULL);
    }
    printf("\nQuantidade masculina: %i\n", contm);
    printf("\nQuantidade feminina: %i\n", contf);
    return 0;
}
