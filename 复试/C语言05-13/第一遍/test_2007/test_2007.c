#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);
int reverse(int);

void main(){
	FILE *fp;
	int i;
	if((fp = fopen("D:\\result.bat","wb"))==NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 10; i < 1000; i++){
		if(isPrime(i) && isPrime(reverse(i))){
			fwrite(&i, sizeof(int), 1, fp);
		}
	}
	fclose(fp);
	if((fp = fopen("D:\\result.bat","rb"))==NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		fread(&i,sizeof(int), 1, fp);
		printf("%d\t", i);
	}
	fclose(fp);
}

int isPrime(int n){
	int i, k;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int reverse(int n){
	int a,b,c;
	if(n / 100 != 0){
		a = n / 100;
		b = (n - a * 100) /10;
		c = n - a * 100 - b * 10;
		return c * 100 + b * 10 + a;
	}
	else{
		a = n/10;
		b = n % 10;
		return b * 10 + a;
	}
}