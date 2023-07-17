#include <stdio.h>
#include <stdlib.h>

int NUM_COMP, NUM_MOV;

void ordena_par(int *v, int n);
void ordena_impar(int *v, int n);
void troca(int *v1, int *v2);

int main(int argc, char **argv){
	int N,i,o,k = 0,l = 0;
	FILE *file,*file2;
	NUM_COMP = NUM_MOV = 0;

	file = fopen(argv[1], "r");
	fscanf(file,"%i", &N);
	
	int vetor[N], vetor_par[N], vetor_impar[N];
	for(i = 0;i < N; i++){
		fscanf(file,"%i", &vetor[i]);
	}
	fclose(file);
	for(i = 0; i < N; i++){
        if(vetor[i] % 2 == 0){
            vetor_par[k] = vetor[i];
            k++;
        }else{
            vetor_impar[l] = vetor[i];
            l++;
        }
	}
	ordena_par(&vetor_par, k);
    ordena_impar(&vetor_impar, l);
    
    file2 = fopen(argv[2], "w");
    for(o = 0; o < 1; o++){
    	for(i = 0; i < k; i++){
    		fprintf(file2,"%i\n", vetor_par[i]);
		}
		for(i = 0; i < l; i++){
    		fprintf(file2,"%i\n", vetor_impar[i]);
		}
	}
	
	fprintf(file2,"\n%i %i\n", NUM_COMP, NUM_MOV);
	
	fclose(file2);

    

	return 0;
}

void troca(int *v1, int *v2){
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

void ordena_par(int *v, int n){
    int i,j,aux;
    for(i = 0; i < n - 1; i++){
        for(j = 1; j < n - i; j++){
            NUM_COMP++;
            if(v[j] < v[j - 1]){
                NUM_MOV += 3;
                troca(&v[j], &v[j - 1]);
            }
        }
    }
}

void ordena_impar(int *v, int n){
    int i,j,aux;
    for(i = 0; i < n - 1; i++){
        NUM_COMP++;
        for(j = 1; j < n - i; j++){
            if(v[j] > v[j - 1]){
                NUM_MOV += 3;
                troca(&v[j], &v[j - 1]);
            }
        }
    }
}
