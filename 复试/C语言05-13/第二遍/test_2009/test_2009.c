#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void divide(char *,char [][15],int *);
void sort(char [][15],int i);
int convert(char*);

void main(){
	FILE *fp;
	int i = 0,j = 0;
	char a[30];
	char digit[10][15];

	if((fp = fopen("D:\\two\\org1.bat","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	a[i-1] = '\0';
	divide(a,digit,&j);
	printf("#%s#\n",a);
	printf("%d\n",j);
	fclose(fp);
	for(i =0 ; i < j; i++){
		printf("#%s#\n",digit[i]);
	}
	sort(digit,j);
	if((fp = fopen("D:\\two\\new1.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i =0 ; i < j; i++){
		printf("#%s#\n",digit[i]);
		fprintf(fp,"%s\n",digit[i]);
	}
	fclose(fp);
}
void divide(char *a,char digit[][15],int *p){
	int i = 0,j =0, k =0;
	while(a[i] != '\0'){
		while(a[i] < '0' || a[i] > '9'){
			if(a[i] == '\0')
				break;
			i++;
		}
		if(a[i] == '\0')
			break;
		k = 0;
		while((a[i] >= '0' && a[i] <= '9') || (a[i] == ' ')){
			if(a[i] == ' '){
				i++;
				continue;
			}
			else{
				digit[j][k++] = a[i++];
			}
		}
		digit[j][k] = '\0';
		j++;
	}
	*p = j;
}

void sort(char digit[][15],int n){
	int i,j;
	char temp[15];
	for(i = 0; i < n -1; i ++){
		for(j = 0; j < n - i -1; j++){
			if(convert(digit[j]) > convert(digit[j+1])){
				strcpy(temp,digit[j]);
				strcpy(digit[j],digit[j+1]);
				strcpy(digit[j+1],temp);
			}
		}
	}	
}

int convert(char *a){
	int number = 0,i = 0;
	if(a[0] == '0'){
		i++;
		while(a[i]!='\0'){
			number = 8 * number + a[i++] - '0';
		}
	}
	else{
		while(a[i] !='\0'){
			number = 10 * number + a[i++] - '0';
		}
	}
	return number;
}
