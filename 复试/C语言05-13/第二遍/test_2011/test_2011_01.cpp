#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isCorrect(char*,int,int);
void printResult(char *,int,int);

void main(){
	FILE *fp;
	char a[500];
	int cip[10][2],i =0,j=0, k,cip1,cip2;
	if((fp = fopen("D:\\two\\infor.txt","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	k = i -1;
	a[i-1] = '\0';
	printf("%s\n",a);
	for(cip1 = 0; cip1 < 256 ; cip1++){
		if(!isCorrect(a,cip1,1))
			continue;
		for(cip2 = 0; cip2 < 256; cip2++){
			if(isCorrect(a,cip2,2)){
				cip[j][0] = cip1;
				cip[j][1] = cip2;
				j++;
			}
		}
	}
	printf("%d\n",j);
	for(i = 0; i < j; i++){
		printf("%d\t%d\n",cip[i][0],cip[i][1]);
		printResult(a,cip[i][0],cip[i][1]);
	}
}

int isCorrect(char *a,int cip, int n){
	int i,k;
	char ch;
	k = strlen(a);
	if(n == 1){
		for(i = 0; i < k; i += 2){
				ch = a[i];
				ch = ch ^ cip;
				if(isalpha(ch) || (ch == ' ') || (ch == ',') || (ch == '.')){
					continue;
				}
				else
					return 0;
		}
		return 1;
	}
	else{
		for(i = 1; i < k; i += 2){
				ch = a[i];
				ch = ch ^ cip;
				if(isalpha(ch) || (ch == ' ') || (ch == ',') || (ch == '.')){
					continue;
				}
				else
					return 0;
		}
		return 1;
	}
}

void printResult(char *a,int cip1,int cip2){
	int i = 0,j=0;
	char b[500];
	while(a[i] != '\0'){
		b[j++] = a[i] ^ cip1;
		if(a[i+1] != '\0'){
			b[j++] = a[i+1] ^ cip2;
		}
		else
			break;
		i += 2;
	}
	b[j] = '\0';
	printf("#%s#\n",b);
}