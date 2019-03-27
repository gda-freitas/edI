#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv){	
	int n = 3, i=0, j=0;
	int **matriz=NULL;
	
	matriz = (int**) malloc(sizeof(int*)*n);
	
	for(i=0; i<n;i++){
		matriz[i]= (int*) malloc(sizeof(int)*n);
	}
	
	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			printf("%d\n", &matriz[i][j]);
		}
	}
}
