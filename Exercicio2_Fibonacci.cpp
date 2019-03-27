/*---Gabriel A. Freitas--->
<-----Exercício EAD 2-----*/
#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	
	if(n==0){
		return 0;		
	}
	if(n==1){	
		return 1;
	}
	if(n>1){
		n = (fib(n-1)+fib(n-2));		 
	}
	return n;
}

main(int argc, char **argv){
	int n = 0;
	printf("-----Sequencia de Fibonacci-----\n");
	do{
		printf("Digite um numero inteiro positivo até 40: ");
		scanf("%d", &n);
		if(n<1 || n>40){
			printf("Valor Invalido!\n");
		}
	}while(n<=0 || n>40);
	
    printf("Serie de Fibonacci para %d", n);
    
	for(int i=0; i<=n; i++){
		printf("\n %d", fib(i));
	}
}
