#include <stdio.h>
#include <math.h>
typedef struct {
	float x;
	float y;
} Ponto;
int main() {
	Ponto ponto1;
	Ponto ponto2;
	float distancia;
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
	distancia = sqrt((pow((ponto2.x - ponto1.x), 2) + pow((ponto2.y - ponto1.y), 2)));
	printf("Distancia entre os dois pontos: %.2f \n", distancia);
	return 0;
}
