#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

void main(){
	int i;
	FILE *fp;
	if((fp=fopen("D:\\two\\result.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 101; i < 1000; i += 2){
		if(isPrime(i)){
			fprintf(fp,"%d\n",i);
		}
	}
	fclose(fp);
}

int isPrime(int n){
	int i,k, a1, a2, a3;
	a1 = n / 100;
	a2 = (n - 100 * a1) / 10;
	a3 = (n - 100 * a1 - 10 * a2) % 10;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0){
			return 0;
		}
	}
	if((i > k) && (a1 != 9) && (a2 != 9) && (a3 != 9))
		return 1;
	else 
		return 0;
}