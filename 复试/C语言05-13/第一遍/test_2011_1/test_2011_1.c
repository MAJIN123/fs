#include <stdio.h>
#include <math.h>

int isPermit(int);
int isPrime(int);

void main(){
	int i;
	printf("%d",isPrime(2111));
	for(i = 1001; i < 9999; i += 2){
		if(isPermit(i))
			printf("%d\t",i);
	}
}

int isPermit(int n){
	int a1,a2,a3,a4;
	a1 = n / 1000;
	a2 = (n - a1 * 1000) / 100;
	a3 = (n - a1 * 1000 - a2 * 100) / 10;
	a4 = n - a1 * 1000 - a2 * 100 - a3 * 10;
	if(isPrime(n) && isPrime(a3 * 10 + a4) && isPrime(a2 * 10 + a4) && isPrime(a4 * 10 + a2) && isPrime(a4 * 10 + a3))
		return 1;
	else
		return 0;
}

int isPrime(int n){
	int i,k;
	k = (int) sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0){
			printf("%d",i);
			return 0;
		}
	}
	return 1;
}