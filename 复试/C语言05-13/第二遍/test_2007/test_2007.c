#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);
int divert(int);

void main(){
	int i;
	FILE *fp;
	if((fp = fopen("D:\\two\\result1.txt","w"))== NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 11; i < 1000; i += 2){
		if(isPrime(i) && isPrime(divert(i)))
			fprintf(fp,"%d\t",i);
	}
}

int isPrime(int n){
	int i,k;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int divert(int n){
	int a1,a2,a3;
	if(n < 100){
		a1 = n / 10;
		a2 = n % 10;
		return a2 * 10 + a1;
	}
	else{
		a1 = n / 100;
		a2 = (n - a1 * 100) / 10;
		a3 = n -a1 * 100 -a2 * 10;
		return a3 * 100 + a2 * 10 + a1;
	}
}