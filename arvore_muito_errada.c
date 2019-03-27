#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	int info;
	struct arvore *esq;
	struct arvore *dir;
} tipoArvore;


//função criaArvore
tipoArvore *criaArvore(){
	return NULL;
}

int ehVazia(tipoArvore *tree){
	if(tree == NULL)
		return -1; //eh vazia
	else
		return 1; //não é vazia
}

void imprimeArvore(tipoArvore *tree){
	printf("<");
	if(ehVazia(tree) == 1){
		printf("%d ", tree->info);
		imprimeArvore(tree->esq);
		imprimeArvore(tree->dir);
	}
	printf(">");
}

void insereArvore(tipoArvore **tree, int valor){

	//nodo null
	if(*tree == NULL){
		*tree = malloc(sizeof(tipoArvore));
		(*tree)->info = valor;
		(*tree)->esq = NULL;
		(*tree)->dir = NULL;
	}else{
		//percorre a subarvore da esquerda
		if(valor < (*tree)->info)
			insereArvore(&(*tree)->esq, valor);
		//percorre a subarvore da direita
		else
			insereArvore(&(*tree)->dir, valor);
	}
}

int busca(tipoArvore *tree, int chave){
	if(ehVazia(tree) == -1)
		return 0; //se a árvore estiver vazia, retorna 0;
	if(tree->info == chave)
		return 1; //encontrou a chave;
	if(chave > tree->info)
		busca(tree->dir, chave);
	else
	   busca(tree->esq, chave);
	
}

void removeNodo(tipoArvore **root, tipoArvore *tree, tipoArvore *nodoPai, int chave){
	if(ehVazia(tree) == -1){
		printf("Elemento nao encontrado para remocao\n");
		return;
	}else if(tree->info != chave){
		if(tree->info > chave){
			removeNodo(&(*root), tree->esq, tree, chave);
		}			
		else{
			removeNodo(&(*root), tree->dir, tree, chave);
		}		
	}else{
		//verificar qual o tipo de nodo que está sendo removido
		//elemento folha, apenas remover.
		if(tree->esq == NULL && tree->dir == NULL){
			if(*root == tree){
				*root = NULL;	
			}			
			else if(nodoPai->dir == tree){
				nodoPai->dir = NULL;	
			}			
			else{
				nodoPai->esq = NULL;	
			}
			
		}
		else if(tree->esq == NULL && tree->dir != NULL){ //tem apenas subarvore da direita
			if(*root != tree){
				if(nodoPai->esq == tree)
					nodoPai->esq = tree->dir;
				else
					nodoPai->dir = tree->dir;				
			}else
				*root = tree->dir;
			
		}else if(tree->esq != NULL && tree->dir == NULL){ //tem apenas subarvore da esquerda
			if(*root != tree){
				if(nodoPai->esq == tree)
					nodoPai->esq = tree->esq;
				else
					nodoPai->dir = tree->esq;
			}else
				*root = tree->esq;				
		}else{ //tem subarvore na direita e esquera
			tipoArvore *nodoAux = tree->esq;
			tipoArvore *nodoAnt = tree;
			while(nodoAux->dir != NULL){
				nodoAnt = nodoAux;
				nodoAux = nodoAux->dir;
			}
			if(nodoAux->esq == NULL)
				nodoAnt->dir = NULL;
			else
				nodoAnt->dir = nodoAux->esq;
			if(*root == tree){
				if(nodoPai->esq == tree)
					nodoPai->esq = nodoAux;
				else
					nodoPai->dir = nodoAux;	
			}else
				*root = nodoAux;
			nodoAux->esq = tree->esq;
			nodoAux->dir = tree->dir;
		}
		free(tree);
	}
}

int main(int argc, char **argv){
	tipoArvore *tree = criaArvore();
	printf("\nArvore inicial\n");
	imprimeArvore(tree);
	insereArvore(&tree, 1);
	printf("\nArvore apos insercao do 1\n");
	imprimeArvore(tree);
	insereArvore(&tree, 2);
	printf("\nArvore apos insercao do 2\n");
	imprimeArvore(tree);
	insereArvore(&tree, 3);
	printf("\nArvore apos insercao do 3\n");
	imprimeArvore(tree);
	insereArvore(&tree, 5);
	printf("\nArvore apos insercao do 5\n");
	imprimeArvore(tree);
	insereArvore(&tree, 3);
	printf("\nArvore apos insercao do 3\n");
	imprimeArvore(tree);
	insereArvore(&tree, 7);
	printf("\nArvore apos insercao do 7\n");
	imprimeArvore(tree);
	insereArvore(&tree, 2);
	printf("\nArvore apos insercao do 2\n");
	imprimeArvore(tree);
	insereArvore(&tree, 4);
	printf("\nArvore apos insercao do 4\n");
	imprimeArvore(tree);

//	printf("\nbusca 2: %d\n", busca(tree, 2));
//	printf("\nbusca 5: %d\n", busca(tree, 5));
	removeNodo(&tree, tree, tree, 5);
	printf("\n Removido o 5\n ");
	imprimeArvore(tree);
	removeNodo(&tree, tree, tree, 2);
	printf("\nArvore apos remocao do 2\n");
	imprimeArvore(tree);
	return 0;

}
