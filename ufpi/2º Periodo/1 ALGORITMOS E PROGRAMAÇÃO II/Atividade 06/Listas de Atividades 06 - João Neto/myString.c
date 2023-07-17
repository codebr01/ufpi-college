#include <stdio.h>
#include "myString.h"

char *mystrcpy(char *s1, const char *s2){
	int i;
	
	for(i = 0;*(s2 + i) != '\0'; i++){
		*(s1 + i) = *(s2 + i);
	}

	*(s1 + i) = '\0';
	
    return s1;
}

char *mystrncpy(char *s1, const char *s2, size_t n){
	int i;
	
	for(i = 0; i < n; i++){
	    *(s1 + i) = *(s2 + i);
	}
	
    *(s1 + i) = '\0';
	
    return s1;		
}

char *mystrcat(char *s1, const char *s2){
	int cont = 0, i;
	
	while(s1[cont] != '\0'){
		cont++;
	}

	for(i = 0; *(s2 + i) != '\0'; i++){
		s1[cont + i] = s2[i];
	}
}

char *mystrncat(char *s1, const char *s2, size_t n){
	int cont = 0, i;
	
	while(s1[cont] != '\0'){
		cont++;
	}

	for(i = 0; i < n; i++){
		s1[cont + i] = s2[i];
	}
}

int *mystrcmp(const char *s1, const char *s2){
	int i = 0, r;

	for(i = 0; *(s1 + i) != '\0'; i++){
		
	    if (s1[i] == s2[i]){
            r = 0;
        }else{
            if(s1[i]>s2[i] || s1[i]<s2[i]){
                r = 1;
                break;
            }
        }
    }
	printf("%i\n", r);
}

int *mystrncmp(const char *s1, const char *s2, size_t n){
	int i = 0, r;

	for(i = 0; n < i; i++){
		
	    if (s1[i] == s2[i]){
            r = 0;
        }else{
            if(s1[i]>s2[i] || s1[i]<s2[i]){
                r = 1;
                break;
            }
        }
	}
    printf("%i\n", r);
}