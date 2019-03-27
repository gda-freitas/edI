#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>

bool chkkaprekar(int n)
{
    if (n == 1)
       return true;
    //int sqr_n = n * n;
    int ctr_digits = 0;
    while (n)
    {
        ctr_digits++;
        n /= 10;
    }
    //sqr_n = n*n; 
    for (int i=1; i<ctr_digits; i++)
    {
         int eq_parts = pow(10, i);

         if (eq_parts == n)
            continue;
         int sum = n/eq_parts + n % eq_parts;
         if (sum*sum == n)
           return true;
    }
    return false;
}
int main(){
	if(chkkaprekar(2025)){
		printf("true porra" );
	}
}
