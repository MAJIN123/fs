#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate(int *,int,int);
void printPrime(int *,int);
int isPrime(int);
void printMiddle(int *,int);
void sort(int *, int);

void main(){
	FILE *fp;
	int i,k,number[2048];
/*	if((fp = fopen("D:\\data.txt","wb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < 25; i++){
		scanf("%d",&number[i]);
		fwrite(&number[i],sizeof(int),1,fp);
	}
	for(i = 25; i < 2048; i++){
		number[i] = 0;
		fwrite(&number[i],sizeof(int),1,fp);
	}
	fclose(fp);
*/
	if((fp = fopen("D:\\data.txt","rb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < 2048; i++){
		fread(&number[i],sizeof(int),1,fp);
		if(number[i] == 0)
			break;
		printf("%d\t", number[i]);
	}
	k = i;
	printf("\n");
	printf("The number is : %d\n", k);
	calculate(number,0,k-1);
	printPrime(number,k);
	printMiddle(number,k);
	fclose(fp);
}

void calculate(int *number,int m,int n){
	int i,max,min;
	max = min = number[m];
	for(i = m+1; i <= n; i++){
		if(number[i] > max)
			max = number[i];
		if(number[i] < min)
			min = number[i];
	}
	printf("max = %d\nmin = %d\n", max,min);
}

void printPrime(int *number,int n){
	int i = 0, maxPrime = 0;
	while(!isPrime(number[i])){
		i++;
	}
	maxPrime = number[i];
	for(; i < n; i++){
		if((isPrime(number[i])) && (number[i] > maxPrime))
			maxPrime = number[i];
	}
	printf("The maxPrime is : %d \n", maxPrime);
}

int isPrime(int n){
	int i,k = 0;
	k = (int)sqrt(n);
	for(i = 2; i <= k; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void printMiddle(int *number,int n){
	int i, head, end,max, min;
	sort(number,n);
	for(i = 0; i < n; i++){
		printf("%d\t",number[i]);
	}
	printf("\n");
	head = (n - (n % 3)) / 3;
	end = head * 2 - 1;
	max = number[end];
	min = number[head];
	printf("max = %d\nmin = %d", max, min);
}

void sort(int *number,int n){
	int i,j,temp;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n - i -1; j++){
			if(number[j] > number[j+1]){
				temp = number[j];
				number[j] = number[j+1];
				number[j+1] = temp;
			}
		}
	}
}