#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
	int valor;
	Elemento *prox;
}Elemento;

typedef struct Fila{
	Elemento *inicio;
	Elemento *fim;
}Fila;

Fila *criaFila(){
	Fila *novaFila = (Fila*)malloc(sizeof(Fila));
	if(novaFila == NULL){
		printf("Erro na alocacao da fila.\n");
		exit(1);
	}
	novaFila->inicio = NULL;
	novaFila->fim = NULL;
	return novaFila;
}

int ehVazia(Fila *nodoFila){
	if(nodoFila->fim == NULL || nodoFila->inicio == NULL){
		return -1;
	}
	return 1;
}

void insereFila(Fila *nodoFila, int valor){
	Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
	if(novoElemento == NULL){
		printf("Erro na alocacao do novo elemento. \n");
		exit(1);
	}
	novoElemento->valor = valor;
	novoElemento->prox = NULL;	
	
	if(ehVazia(nodoFila) == -1){
		nodoFila->inicio = novoElemento;
		nodoFila->fim = novoElemento;
	}
	else{
		Elemento *auxElemento = nodoFila->fim;
		auxElemento->prox = novoElemento;
		nodoFila->fim = novoElemento;		
	}
}

int removeFila(Fila *nodoFila){
	if(ehVazia(nodoFila) == -1){
		printf("Fila Vazia. \n");
		exit(1);
	}
	Elemento *aux = nodoFila->inicio;
	int valor = aux->valor;
	nodoFila->inicio = aux->prox;
	free(aux);
	return valor;
}

void liberaFila(Fila *nodoFila){
	if(ehVazia(nodoFila) == -1){
		printf("Fila Vazia. \n");
		free(nodoFila);
		return;
	}	
	Elemento *aux2 = nodoFila->inicio;
	Elemento *aux;	
	while(aux2!=NULL){
		aux = aux2->prox;
		free(aux);
		aux2 = aux;
	}
	free(nodoFila);
}

int main(int argc, char **argv){
	
}
