#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void divide(char *, char [][15], int *);
int isThe(char *);
void printResult(char [][15],int);

void main(){
	FILE *fp;
	int i = 0,j=0;
	char a[500];
	char words[50][15];
	if((fp = fopen("D:\\two\\org.bat","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	a[i-1] = '\0';
	printf("#%s#",a);
	divide(a,words,&j);
	for(i = 0; i < j; i++){
		printf("%s\n",words[i]);
	}
	printResult(words,j);
}

void divide(char *a, char words[][15], int *p){
	int i = 0, j = 0, k = 0;
	while(a[i] != '\0'){
		while(!isalpha(a[i])){
			if(a[i] == '\0')
				break;
			i++;
		}
		if(a[i] == '\0')
			break;
		k = 0;
		while(isalpha(a[i]))
			words[j][k++] = a[i++];
		words[j][k] = '\0';
		j++;
	}
	*p = j;
}

void printResult(char words[][15], int n){
	FILE *fp;
	int i,j,signal;
	char temp[15];
	if((fp = fopen("D:\\two\\new.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < n; i++){
		signal = 0;
		for(j = 0; j < i; j++){
			if(j == i)
				continue;
			else{
				if(strcmp(words[i],words[j]) == 0){
					signal = 1;
					break;
				}
			}
		}
		if((signal == 0) && !isThe(words[i])){
			strcpy(temp,words[i]);
			if(islower(temp[0])){
				temp[0] -= 32;
			}
			fprintf(fp,"%s\n",temp);
		}
	}
	fclose(fp);
}

int isThe(char *p){
	int i,k;
	k = strlen(p);
	if(k != 3)
		return 0;
	else{
		for(i =0; i < 3; i++){
			if(islower(p[i])){
				p[i] -= 32;
			}
		}			
		if(strcmp(p,"THE") == 0)
			return 1;
		else 
			return 0;
	}
}