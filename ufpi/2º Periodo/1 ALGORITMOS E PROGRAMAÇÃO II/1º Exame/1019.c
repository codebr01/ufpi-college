#include <stdio.h>

typedef struct{
    int hora;
    int minuto;
    int segundo;
}Tempo;

Tempo seg2tadTempo(int seg);

int main()
{

    int segundos;

    scanf("%i", &segundos);

    seg2tadTempo(segundos);
    
    return 0;
}

Tempo seg2tadTempo(int seg)
{
    Tempo t;

    t.hora = seg / 3600;
    t.minuto = (seg % 3600) / 60;
    t.segundo = ((seg % 3600) % 60);

    printf("%i:%i:%i\n",t.hora, t.minuto, t.segundo);

    return t;
}