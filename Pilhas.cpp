#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int valor;
	struct elemento *prox;
}tipoElemento;

typedef struct pilha{
	struct elemento *topo;
}tipoPilha;

tipoPilha *criaPilha(){
	tipoPilha *nodoPilha = (tipoPilha*)malloc(sizeof(tipoPilha));
	if(nodoPilha == NULL){
		printf("Erro na alocacao da pilha.\n");
		exit(1);
	}
	nodoPilha->topo = NULL;
	return nodoPilha;
}

int ehVazia(tipoPilha *nodoPilha){
	if(nodoPilha->topo == NULL){
		return -1; //Pilha vazia
	}
	return 1; //Nao eh vazia
}

//Push
void inserePilha(tipoPilha *nodoPilha, int valor){
	tipoElemento *novoElemento = (tipoElemento*)malloc(sizeof(tipoElemento));
	if(novoElemento == NULL){	
		printf("Erro na alocacao do Ekemento.\n");
		exit(1);
	}
	novoElemento->valor = valor;
	novoElemento->prox = nodoPilha->topo;
	nodoPilha->topo = novoElemento;
}

//Pop
int removePilha(tipoPilha *nodoPilha){
	if(ehVazia(nodoPilha)==-1){
		printf("Pilha vazia\n");
		exit(1);
	}
	tipoElemento *aux = NULL;
	int valor = 0;
	aux = nodoPilha->topo;
	valor = aux->valor;
	nodoPilha->topo = aux->prox;
	free(aux);
	return valor;
}

void liberaPilha(tipoPilha *nodoPilha){
	tipoElemento *aux = NULL;
	tipoElemento *auxTopo = NULL;
	auxTopo = nodoPilha->topo;
	while(auxTopo != NULL){
		aux = auxTopo->prox;
		free(auxTopo);
		auxTopo = aux;
	}
	free(nodoPilha);
}

void imprimePilha(tipoPilha *pilha){
	tipoElemento *aux = NULL;
	if(pilha == NULL){
		printf("Pilha Vazia.");
		exit(1);
	}
	aux = pilha->topo;
	while(aux != NULL){
		printf("| %d |\n", aux->valor);
		aux=aux->prox;
	}
}

int main(int argc, char **argv){
	tipoPilha *Pilha = criaPilha();	
	printf("1 Etapa:\n");
	imprimePilha(Pilha);
	printf("\n2 Etapa:\n");
	inserePilha(Pilha, 3);
    imprimePilha(Pilha);
    printf("\n3 Etapa:\n");
	inserePilha(Pilha, 5);
    imprimePilha(Pilha);
    printf("\n4 Etapa:\n");
	inserePilha(Pilha, 7);
    imprimePilha(Pilha);
    printf("\n5 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n6 Etapa:\n");
	inserePilha(Pilha, 8);
    imprimePilha(Pilha);
    printf("\n7 Etapa:\n");
	inserePilha(Pilha, 9);
    imprimePilha(Pilha);
    printf("\n8 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n9 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n10 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n11 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n12 Etapa:\n");
	inserePilha(Pilha, 10);
    imprimePilha(Pilha);
    printf("\n13 Etapa:\n");
	removePilha(Pilha);
    imprimePilha(Pilha);
    printf("\n14 Etapa:\n");
	liberaPilha(Pilha);
}
