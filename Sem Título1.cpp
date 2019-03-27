#include <stdio.h>

void swap(int *a,int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

main(int argc, char **argv){
	int a,b;
	a=2;
	b=3;
	printf(" %d,%d",a,b);
	swap(&a,&b);
	printf("\n %d,%d",a,b);
}


