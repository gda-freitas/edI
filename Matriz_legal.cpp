#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv){	
	int tam = 3, vetor[tam*tam], *matriz_a=NULL, matriz[tam][tam];
	matriz_a = (int*) malloc(sizeof(int)*tam*tam);

	int j, i;
	
	for(i=0; i<tam;i++){
		for(j=0; j<tam;j++){
			matriz_a[(i*tam)+j] = 0;
			
			printf("%d\n",&vetor[(i*tam)+j]);
			
			matriz[i][j] = 0;
		}
	}
}
