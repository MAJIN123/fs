#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printResult(int*,int);
void sort(int*,int);
int printPrime(int*, int);
int isPrime(int);

void main(){
	FILE *fp;
	int i,j =0,k =0,array[2048] = {0}, head,end;

/*	if((fp = fopen("D:\\two\\data.txt","wb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < 25; i++){
		scanf("%d",&number);
		fwrite(&number,sizeof(int),1,fp);
	}
	for(i = 25; i < 2048; i++){
		number = 0;
		fwrite(&number,sizeof(int),1,fp);
	}
*/
	if((fp = fopen("D:\\two\\data.txt","rb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		fread(&array[j++],sizeof(int),1,fp);
	}	
	for(i = 0; i < 2048; i++){
		if(array[i] != 0){
			k++;
			printf("%d\t",array[i]);
		}
	}
	printf("\n");
	printf("The number is %d. \n",k);
	printResult(array,k);
	for(i = 0; i < k; i++){
		printf("%d\t",array[i]);
	}
	printf("\n");
	head= (k - (k % 3)) / 3;
	end = head  * 2 - 1;
	printf("Max = %d\tMin = %d",array[head], array[end]);
	fclose(fp);
}

void printResult(int *array, int n){
	int max, min, maxPrime, i;
	max = min = array[0];
	for(i =1 ; i < n; i++){
		if(array[i] > max)
			max = array[i];
		if(array[i] < min)
			min = array[i];
	}
	printf("max = %d\tmin = %d\n",max, min);
	sort(array,n);
	maxPrime = printPrime(array,n);
	if(maxPrime == 0)
		printf("There is no prime in the array");
	else
		printf("The max prime is %d\n", maxPrime);
}

void sort(int *array, int n){
	int i, j,temp;
	for(i = 0; i < n -1 ; i++){
		for(j = 0; j < n - i -1; j++){
			if(array[j] < array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

int printPrime(int *array,int n){
	int i ;
	for(i =0; i < n; i++){
		if(isPrime(array[i]))
			return array[i];
	}
	return 0;
}

int isPrime(int n){
	int i ,k ;
	k = (int)sqrt(n);
	for(i =2; i <= k; i++){
		if(n % i ==0)
			return 0;
	}
	return 1;
}