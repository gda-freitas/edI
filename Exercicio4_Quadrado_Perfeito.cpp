/*---Gabriel A. Freitas--->
<-----Exercício EAD 4-----*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int quadrado(int num){
	for(int i = num;i>=0; i--){
		if(i*i == num){
			return 1;
		}
	}
	return 0;
}

main(int argc, char **argv){
	char *stringIn=NULL, *valor=NULL;
	int i=0, k=0, soma = 0, tam = 50;	
	valor = (char*)malloc(sizeof(char)*tam);
	stringIn = (char*)malloc(sizeof(char)*tam);
	
	printf("--------Quadrado Perfeito--------\n");
	printf("Digite os numeros de entrada(0 para encerrar): ");
	do{
		stringIn[i]=(int)getche();
		i++;
	}while(stringIn[i-1] != '0');
	
	for(int i=0; i<strlen(stringIn); i++){	
		valor[k] = stringIn[i];	
		if(stringIn[i]==' ' && i != 0){
			int aux = atoi(valor);
			k=0;
			soma += quadrado(aux);
		}else{
			k++;
		}
	}	
	printf("\nQuadrados Perfeitos Informados: %d", soma);
}
