#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int);

void main(){
	FILE *fp;
	int i, n = 0;
	if((fp = fopen("D:\\result.txt","ab")) == NULL){
		printf("cannot open the file!");
		exit(0);
	}
	for(i = 100; i < 1000; i++){
		if(isPrime(i)){
			fwrite(&i,sizeof(int),1,fp);
			n++;
			if(n % 10 == 0)
				printf("%d\t\n",i);
			else
				printf("%d\t",i);
		}
	}
	fclose(fp);
	if((fp = fopen("D:\\result.txt","rb")) == NULL){
		printf("cannot open the file!");
		exit(0);
	}
	while(!feof(fp)){
		fread(&i, sizeof(int),1,fp);
		printf("%d ",i);
	}
	fclose(fp);
}

int isPrime(int n){
	int i,k;
	int a1, a2, a3;
	a1 = n / 100;
	a2 = (n - a1 * 100) / 10;
	a3 = n - a1 * 100 - a2 * 10;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0)
			return 0;
	}
	if(i > k){
		if((a1 != 9) && (a2 != 9) && (a3 != 9) )
			return 1;
		else return 0;
	}
	return 0;
}