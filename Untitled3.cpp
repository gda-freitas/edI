#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

main(int argc, char **argv){
	char *stringIn=NULL, *valor=NULL;
	int *x = NULL, i=0, tam = 10, val = 0;
	
	valor = (char*)malloc(sizeof(char)*tam);
	stringIn = (char*)malloc(sizeof(char)*tam);
	x = (int*)malloc(sizeof(int)*tam);
	
	do{
		stringIn[i]=(int)getche();
		i++;
	}while(stringIn[i-1] != '0');
	printf("\n");

	//scanf("%[^\n]s", n);
	for(int i=0; i<strlen(stringIn); i++){				
		if(stringIn[i]==' '){
			printf("\n");
		}
		valor[i] = stringIn[i];
		printf("%c", valor[i]);
	}	
}
