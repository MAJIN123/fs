#include <stdio.h>
#include <stdlib.h>

void printDigit(char *,int);
int divert(char *);
void sort(int *, int);

void main(){
	FILE *fp;
	int i = 0;
	char a[30];
	
	if((fp = fopen("D:\\org1.bat","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	printDigit(a,i);
	
}
void printDigit(char *p, int n){
	FILE *fp;
	int i,m1 = 0,n1 = 0;
	char array[50][15];
	int digit[50];
	*(p + n -1) = '\0';
	printf("%s\n",p);
	if((fp = fopen("D:\\new.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while((*p) != '\0'){
		if((*p) == ','){
			array[m1][n1] = '\0';
			n1 = 0;
			m1++;
			p++;
		}
		else if((*p) != ' '){
			array[m1][n1] = *p;
			n1++;
			p++;
		}
		else
			p++;
	}
	array[m1][n1] = '\0';
	for(i = 0; i < m1+1; i++){
		digit[i] = divert(array[i]);
		printf("%s# %d#\n", array[i],digit[i]);
	}
	sort(digit,m1+1);
	for(i = 0; i < m1+1; i++){
		fprintf(fp,"%d\n",digit[i]);
	}
	fclose(fp);
}

int divert(char *p){
	int number = 0;
	char *temp;
	temp = p;
	if((*temp) == '0'){
		temp++;
		while((*temp) != '\0'){
			number = 8 * number + (*temp - '0');
			temp++;
		}		
	}
	else{
		while((*temp) != '\0'){
			number = 10 * number + (*temp - '0');
			temp++;
		}
	}
	return number;
}

void sort(int *a, int n){
	int i, j,temp;
	for(i = 0; i < n -1; i++){
		for(j = 0; j < n - i -1; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}