#include <stdio.h>

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
	int n=5;
    printf("Somatorio = %d", fib(n));
}
