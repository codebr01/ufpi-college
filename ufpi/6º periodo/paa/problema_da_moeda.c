//Trabalho: Algoritmo guloso para o problema da moeda
//Tarefa: Completar o código abaixo para resolver o problema da moeda.

//Aluno(a): João dos Santos Neto
//Data: 04/08/2024
//Disciplina: Projeto e Analise de Algoritmos
//Professor: Leonardo Pio Vasconcelos 

#include <stdio.h>
#include <stdlib.h>

void ordenar_moedas_decrescente(int* moedas){
    int i, j;
    int n = sizeof(moedas) / sizeof(moedas[0]) + 1;

    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(moedas[i] < moedas[j]){
                int aux = moedas[i];
                moedas[i] = moedas[j];
                moedas[j] = aux;
            }
        }
    }
}

int* troca_de_moedas(int valor, int* moedas, int n) {
    int i, m = 1;
    int* resultado = (int*) malloc(m * sizeof(int));

    for (i = 0; i < n; i++) {
        while (valor >= moedas[i]) {
            valor -= moedas[i];
            resultado[m - 1] = moedas[i];
            m += 1;
            resultado = (int*) realloc(resultado, m * sizeof(int));
        }
    }
    resultado[m - 1] = -1;

    return resultado;
}

int main() {
    int i, j;
    int moedas[] = {3, 20, 1}; 
    int valor = 30;
    
    ordenar_moedas_decrescente(moedas);

    int n = sizeof(moedas) / sizeof(moedas[0]);
    int* resultado = troca_de_moedas(valor, moedas, n);

    for (i = 0; resultado[i] != -1; i++) {
        printf("%i ", resultado[i]);
    }
    
    free(resultado);
    resultado = NULL;

    return 0;
}