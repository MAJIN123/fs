#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
void printSplit(int);
int isPrime(int);
int maxPrime(int);
*/
void calculate(char *);
void sortArray(int [][2], int); 

void main(){
/*	int n;
	printf("Please input a number: \n");
	scanf("%d",&n);
	printf("The split number is flowing:\n");
	printSplit(n);
*/	
	FILE *fp;
	char content[100];
	if((fp = fopen("D:\\org1.bat","rb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	fgets(content,strlen(content),fp);
	printf("The content in the file is :\n");
	printf("%s\n",content);
	fclose(fp);
	calculate(content);
}

void calculate(char *p){
	int number[52] = {0};
	int number1[52][2] ={0};
	int i, j=0, k;
	while((*p) != '\0'){
		if(islower((*p))){
			k = (*p) - 'a';
			number[k]++;
		}
		if(isupper((*p))){
			k = (*p) -'A' + 26;
			number[k]++;
		}
		p++;
	}

	for(i = 0; i < 26; i++){
		if(number[i] != 0 ){
			number1[j][0] = i +'a';
			number1[j][1] = number[i];
			j++;
			printf("%c: %d\n",i+'a',number[i]);
		}
	}
	for(i = 26; i <52; i++){
		if(number[i] != 0){
			printf("%c: %d\n",i+'A'-26,number[i]);
			number1[j][0] = i +'A' - 26;
			number1[j][1] = number[i];
			j++;
		}
	}
	sortArray(number1, j);
}

void sortArray(int array[][2], int n){
	int i, j,k,temp1,temp2;
	for(i = 0; i < n - 1; i++){
		k = i;
		for(j = i + 1; j < n; j++){
			if(array[j][1] < array[k][1]){
				k = j;
			}
		}
		if(k != i){
			temp1 = array[i][0];
			temp2 = array[i][1];
			array[i][0] = array[k][0];
			array[i][1] = array[k][1];
			array[k][0] = temp1;
			array[k][1] = temp2;
		}
	}
	printf("The final sequence is following:\n");
	for(i = 0; i < n; i++){
		printf("%c : %d\n", array[i][0], array[i][1]);
	}
}

/*void printSplit(int n){
	int k,max;
	if(isPrime(n)){
		printf("%d ",n);
	}
	else{
		k = n / 2;
		max = maxPrime(k);
		printf("%d ",max);
		printSplit(n - max);
	}
}

int isPrime(int n){
	int i;
	for(i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int maxPrime(int n){
	int i = n;
	for(; i >= 2; i--){
		if(isPrime(i))
			return i;
	}
	return i;
}*/