/*---Gabriel A. Freitas--->
<-----Exercício EAD 3-----*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<bits/stdc++.h>

bool chkkaprekar(int n)
{
	int numWhile = n*n;
    int contador = 0;
	int numPart = 0, total = 0;	
    if (n == 1){
    	 return true;
	}
    while (numWhile)
    {
        contador++;
        numWhile /= 10;
    }
    for (int i=1; i<contador; i++)
    {
		numPart = pow(10, i);
		
		if (numPart == n){
			continue;
		}		
		int part1 = n/numPart;
		int part2 = n%numPart;
		
		total = part1 + part2;
		if (total*total == n){
			return true;
		}           
    }
    return false;
}
int main(){
	int numIn = 0;
	
	printf("---------Numero de Kaprekar---------\n\n");
	do{
		printf("Digite um numero inteiro positivo: ");
		scanf("%d", &numIn);
		if(numIn <= 0){
			printf("Numero Invalido!\n");
		}
	}while(numIn <= 0);
	
	if(chkkaprekar(numIn)){
		printf("1");
	}
	else{
		printf("0");
	}
}
