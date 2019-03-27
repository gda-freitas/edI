#include <stdio.h>
#include <limits.h>

void swap(int i, int j, int *vetor){
	int aux = 0;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void printvetor(int n, int cont, int troca, int* vetor){
	printf("\n\nVetor: ");
	for(int i=0; i<n; i++){
		printf("%d ", vetor[i]);
	}
	//printf("\nPermutacoes: %d, passos: %d \n",troca,cont);	
}

void bubblesort(int n, int* vetor){
	int cont=0, troca=0;
	for(int i=0; i<n; i++){
		for(int p=0; p<n-1; p++){
			 if(vetor[p] > vetor[p+1]){
			 	swap(p, p+1, vetor);
			 	troca++;
			 }
			 cont++;
		}		
	}	
	printvetor(n, cont, troca, vetor);	
}

void bubblesort_v1(int n, int* vetor){
	int cont=0, troca=0;
	for(int i=0; i<n; i++){
		for(int p=0; p<n-1-i; p++){
			 if(vetor[p] > vetor[p+1]){
			 	swap(p, p+1, vetor);
			 	troca++;
			 }
			cont++;	
		}		
	}	
	printvetor(n, cont, troca, vetor);	
}

void bubblesort_v2(int n, int* vetor){
	int cont=0, troca=0, x = 0;
	for(int i=0; i<n; i++){
		for(int p=0; p<n-1-i; p++){
			 if(vetor[p] > vetor[p+1]){
			 	swap(p, p+1, vetor);
			 	troca++;
			 	x=1;
			 }
			cont++;	
		}
		if(x==0){
			printvetor(n, cont, troca, vetor);	
			return;
		}
		x=0;
	}	
	printvetor(n, cont, troca, vetor);	
}

void selectionsort(int n, int *vetor){
	int menor = INT_MAX;	
	int posMenor = 0;
	for(int i=0; i<n; i++){
		for(int p=i; p<n; p++){
			 if(vetor[p]<menor){
			 	menor = vetor[p];
			 	posMenor = p;
			 }			
		}
		vetor[posMenor] = vetor[i];
		vetor[i] = menor;
		menor = INT_MAX;
	}
	printvetor(n, 0, 0, vetor);
}

int main(int argc, char** argv){
	int n = 5;
	int vetor[n] = {8, 2, 7, 3, 1};	
    //for(int i = 0; i<n; i++){
	//	vetor[i] = n-i;
	//}
	//bubblesort(n, vetor);	
	//bubblesort_v1(n, vetor);	
	//bubblesort_v2(n, vetor);
	selectionsort(n, vetor);
}


