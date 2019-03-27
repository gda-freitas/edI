#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv){
	long long int *vetor = NULL;
	int tam = 10, i;
	vetor = (long long int*) malloc(sizeof(long long int)*tam);
	
	for(i=0; i<tam;i++){
		printf("%d\n", &vetor[i]);
	}
}

