#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Estrutura da lista
struct lista{
  int numero;
  struct lista *prox;              
};

typedef struct lista TipoLista;

TipoLista *insereLista(int valor, TipoLista *head){
  //alocacao e inicialização
  TipoLista *novoNodo = (TipoLista*) malloc(sizeof(TipoLista));
  if(novoNodo == NULL){
    printf("Erro na alocacao de novo nodo\n");
    exit(1);            
  } 
  novoNodo->numero = valor;
  novoNodo->prox = NULL;
  
  //Inserção na Lista
  if(head == NULL){
    return novoNodo;
  }else{
    //insereInicio
    if(valor < head->numero){
      novoNodo->prox = head;
      return novoNodo;         
    }else{
      TipoLista *aux = head->prox;
      TipoLista *anterior = head;
      
      while((valor>aux->numero) && (aux->prox != NULL)){
        anterior = aux;
        aux = aux->prox;              
      }
      //insereFinal
      if( (aux->prox == NULL) && (valor > aux->numero) ){
        aux->prox = novoNodo;
      }else{
        novoNodo->prox = aux;
        anterior->prox = novoNodo;      
      }                   
      return head;
    }
  }  
}

TipoLista *removeLista(int chave, TipoLista *head){

  if(head == NULL){
    printf("Lista Vazia\n");
    return head;
  }
  //removerInicio
  if(head->numero == chave){
    TipoLista *aux = head->prox;
    free(head);
    return aux;
  }else{
    TipoLista *aux = head->prox;
    TipoLista *anterior = head;
    while(aux != NULL){
       if(aux->numero == chave){
           TipoLista *aux_remove = aux;
           anterior->prox = aux->prox;
           free(aux_remove);
           return head;                      
       }
       anterior = aux;
       aux = aux->prox;       
    }
    printf("Elemento %d nao encontrado na lista\n", chave);      
  }

} 

int buscaLista(int chave, TipoLista *head){
    TipoLista *aux = head;
    while(aux != NULL){
      if(aux->numero == chave)
        return 1;
      aux = aux->prox;
    }
    printf("elemento nao encontrado\n");
    return 0;
}


void imprimeLista(TipoLista *head){
     TipoLista *aux = head;
     int idNodo = 0;
     while(aux != NULL){
       printf("id: %d\t numero: %d\n", idNodo, aux->numero);
       idNodo++;
       aux = aux->prox;     
     }     
}

TipoLista *liberaLista(TipoLista *head){
  TipoLista *aux = head;
  TipoLista *aux2;
  while(aux!= NULL){
    aux2 = aux;
    aux = aux->prox;
    free(aux2);
  }
  head = NULL;
  return head;
}

TipoLista *LimpaListaPar(TipoLista *head){
	if(head == NULL){
    	printf("Lista Vazia\n");
   		return head;
  	}
 
    TipoLista *aux = head;
    TipoLista *anterior = head;
    TipoLista *aux_remove;
    while(aux != NULL){
       if((aux->numero%2) == 0){
           aux_remove = aux;
           anterior->prox = aux->prox;
           aux = aux->prox;  
           free(aux_remove);
		                             
       }else{       	
       anterior = aux;
       aux = aux->prox;  
       }     
    }
    return head;  
}

int main(int argc, char **argv){
  TipoLista *head = NULL;  
  
  head = insereLista(3, head);
  head = insereLista(1, head);
  head = insereLista(2, head); 
  head = insereLista(8, head); 
  head = insereLista(0, head); 
  head = insereLista(5, head); 
  head = insereLista(10, head); 
  imprimeLista(head);

  head = removeLista(0, head);
  printf("\napos remocao 0\n");
  imprimeLista(head);

  //head = removeLista(3, head);
  //printf("\napos remocao 3\n");
  //imprimeLista(head);

  //head = removeLista(10, head);
  //printf("\napos remocao 10\n");
  //imprimeLista(head);
 /*
  if(buscaLista(3, head) == 1)
    printf("elemento 3 encontrado\n");
 
 if(buscaLista(9, head) == 1)
    printf("elemento 9 encontrado\n");
 */
 head = LimpaListaPar(head);
 printf("\nLista apos Limpar Pares\n");
 imprimeLista(head);
    
}
