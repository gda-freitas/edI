#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int val;
	nodo *proximo;
}typedef nodo;

nodo *insereInicio(int valor, nodo *indice){
	nodo *newIndice = NULL;
	newIndice = (nodo*)malloc(sizeof(nodo));
	
	if(newIndice == NULL){ //falha ao atribuir
		exit(1);
	}		
		
	newIndice -> val = valor;
	newIndice -> proximo=indice;
	
	return newIndice;	
}

nodo *insereMeio(int valor, nodo *indice){
	nodo *newIndice = NULL;
	nodo *anterior = NULL;
	nodo *aux = NULL;
	newIndice = (nodo*)malloc(sizeof(nodo));
	
	if(newIndice == NULL){
		exit(1);
	}		
		
	newIndice -> val = valor;
	newIndice -> proximo = NULL;
	
	if(indice == NULL){
		return newIndice;
	}	
	else{ 
		aux = indice;
		anterior = aux;
		while(aux!= NULL){
			if(newIndice->val<aux->val){
				anterior->proximo = newIndice;
				newIndice->proximo = aux;
				return indice;
			}
			anterior=aux;
			aux=aux->proximo;
		}
	}
}

nodo *insereFim(int valor, nodo *indice){
	nodo *newIndice = NULL;
	nodo *aux = NULL;
	newIndice = (nodo*)malloc(sizeof(nodo));
	
	if(newIndice == NULL){
		exit(1);
	}		
		
	newIndice -> val = valor;
	newIndice -> proximo = NULL;
	
	if(indice == NULL){
		return newIndice;
	}	
	else{ 
		aux = indice;
		while(aux->proximo != NULL){
			aux=aux->proximo;
		}
		aux->proximo=newIndice;
		return indice;
	}
}

void imprimeLista(nodo *idade){
	nodo *aux;
	for(aux=idade;aux!=NULL;aux=aux->proximo){
		printf("%d\n", aux->val);
	}
}

int main(int argc, char** argv){
	nodo *idade = NULL;
	idade = insereFim(1, idade);
	idade = insereFim(2, idade);
	idade = insereFim(4, idade);
	idade = insereFim(8, idade);
	idade = insereFim(16, idade);
	idade = insereInicio(0, idade);
	idade = insereMeio(5, idade);
	imprimeLista(idade);
}
