#include <stdio.h>
#include <math.h>

int isPrime(int);

void main(){
	int i,a1,a2,a3,a4;
	for(i = 1001; i < 10000; i += 2){
		if(isPrime(i)){
			a1 = i / 1000;
			a2 = (i - a1 * 1000) / 100;
			a3 = (i - a1 * 1000 - a2 * 100) / 10;
			a4 = i - a1 * 1000 - a2 * 100 - a3 * 10;
			if(isPrime(a3*10 + a4) && isPrime(a2*10 + a4) && isPrime(a4 * 10 + a2) && isPrime(a4 * 10 + a3)){
				printf("%d\t",i);
			}
		}
	}
}

int isPrime(int n){
	int i,k;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if((n % i) == 0)
			return 0;
	}
	return 1;
}