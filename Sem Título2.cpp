#include <stdio.h>

int fatorial(int n){
	if(n==1){
		return 1;
	}
	else{
		n = n*fatorial(n-1);
	}
	return n;
}

int somatorio(int n){
	if(n==0){
		return 0;
	}
	else{
		n += somatorio(n-1);
	}
	return n;
}

main(int argc, char **argv){
	int n=5;
    printf("Somatorio = %d", somatorio(n));
    printf("\nFatorial = %d", fatorial(n));

}
