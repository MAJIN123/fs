#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWords(char *, int);
int compare(char *);

void main(){
	FILE *fp;
	char array[1000],ch;
	int i = 0;
	if((fp = fopen("D:\\org.bat","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		ch = fgetc(fp);
		array[i++] = ch;
	}
	printWords(array,i);
	fclose(fp);
}

void printWords(char *p, int n){
	FILE *fp;
	char str[100][15];
	char temp[15];
	int i, j, m1 = 0, n1 = 0;
	if((fp = fopen("D:\\next.txt","w"))== NULL){
		printf("cannot open the file");
		exit(0);
	}
	*(p+n-1) = '\0';
	while((*p)== ' ')
		p++;
	while((*p)!='\0'){
		while((*p)!=' ' && (*p)!='\0'){
			str[m1][n1++] = *p;
			p++;
		}
		str[m1][n1]='\0';	
		while((*p) == ' ')
			p++;
		m1++;
		n1=0;
	}
	for(i = 0; i < m1; i++){
		if(!compare(str[i])){
			for(j = 0; j < i; j++){
				if(strcmp(str[j],str[i]) == 0){
					break;
				}
			}
			if(j == i){
				strcpy(temp,str[i]);
				if((temp[0])>='a' && (temp[0] <='z')){
					temp[0] -= 32;
				}
				printf("%s\n",temp);
				fprintf(fp,"%s\n",temp);
			}
		}
	}
	fclose(fp);
}

int compare(char *p){
	char *a1[8] = {"The","THe","ThE","THE","tHe","tHE","the","thE"};
	int i;
	for(i = 0; i < 8; i++){
		if((strcmp(p,a1[i])== 0))
			return 1;
	}
	return 0;
}
