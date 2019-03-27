/*---Gabriel A. Freitas--->
<-----Exercício EAD 1-----*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>

int main(int argc, char **argv){
	int x = 0, i = 0; 
	int k = 0,tam = 20;
	char *hex=NULL, *str=NULL, *aux1=NULL, *aux2=NULL;
	hex = (char*)malloc(sizeof(char)*tam);
	str = (char*)malloc(sizeof(char)*tam);
	aux1 = (char*)malloc(sizeof(char)*tam);
	aux2 = (char*)malloc(sizeof(char)*tam);
	
	printf("-----------Numero Espelho--------------\n\n");
	do{
		printf("Digite o valor em Hexadecimal: ");
		scanf("%s", hex);
		std::istringstream(hex) >> std::hex >> x; //Converte para decimal
		if(x <= 0){
			printf("Valor Invalido!\n");
		}
	}while(x<=0 || x>100000000);
	
	printf("Seu equivalente em Decimal: %d\n\n", x);
	
	itoa(x, str, 10); //Atribui a string para for
	
	for(i = 0; i<strlen(str); i++){
		aux1[i] = str[i];		
	}
	i=0;
	for(k = strlen(str)-1; k>=0; k--){
			aux2[i] = str[k];
			i++;
	}
	
	if(strcmp(aux1, aux2) == 0){
		printf("S");
	}
	if(strcmp(aux1, aux2) != 0){
		printf("N");	
	}
}
