#include <stdio.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Ponto;

float distancia(Ponto p1, Ponto p2);

int main() {
	Ponto ponto1;
	Ponto ponto2;

	printf("Informe os valores do ponto 1\n");
	printf("Valor x1: ");
	scanf("%f", &ponto1.x);
	printf("Valor y1: ");
	scanf("%f", &ponto1.y);

	printf("Informe os valores do ponto 2\n");
	printf("Valor x2: ");
	scanf("%f", &ponto2.x);
	printf("Valor y2: ");
	scanf("%f", &ponto2.y);

	printf("Distancia entre os dois pontos: %.2f \n", distancia(ponto1, ponto2));
	return 0;
}


float distancia(Ponto p1, Ponto p2) {
	return sqrt((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}
