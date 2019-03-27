#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(int argc, char **argv){	
	srand((unsigned)time(NULL));
	
	int n=2, i=0, j=0, x=0, y=0;
	int *vetor_a=NULL, *vetor_b=NULL, *vetor_c=NULL;
	
	vetor_a = (int*) malloc(sizeof(int)*n*n);
	vetor_b = (int*) malloc(sizeof(int)*n*n);
	vetor_c = (int*) malloc(sizeof(int)*n*n);


	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			vetor_a[(i*n)+j] = rand()%5;			
		}
	}		
	
	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			vetor_b[(i*n)+j] = rand()%5;			
		}
	}	
	
	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			printf(" %d",vetor_a[(i*n)+j]);			
		}
		printf("\n");
	}
	
	printf("\n X \n\n");
	
	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			printf(" %d",vetor_b[(i*n)+j]);			
		}
		printf("\n");
	}
	
	printf("\n = \n\n");

	 for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
        for (x=0; x<n; x++) {
          vetor_c[(i*n)+j] = vetor_c[(i*n)+j] + (vetor_a[(i*n)+x]*vetor_b[(x*n)+j]); 

        }
      }    
    }
    
	for(i=0; i<n;i++){
		for(j=0; j<n;j++){			
			printf(" %d", vetor_c[(i*n)+j]);			
		}
		printf("\n");
	}	
	
	free(vetor_a);
	free(vetor_b);
	free(vetor_c);

}
