#include <stdio.h>
#include <stdlib.h>

void printWords(char *);
void sort(int [][2],int);

void main(){
	FILE *fp;
	char a[100];
	int i = 0;

	if((fp = fopen("D:\\two\\article.txt","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	a[i-1] = '\0';
	printf("%s\n",a);
	printWords(a);
	fclose(fp);
}

void printWords(char *a){
	int character[52]={0}, i = 0,j =0, number;
	int character1[52][2];

	while(a[i] != '\0'){
		if(a[i] >= 'a' && a[i] <= 'z'){
			number = a[i] - 'a';
			character[number]++;
		}
		if(a[i] >= 'A' && a[i] <= 'Z'){
			number = a[i] - 'A' + 26;
			character[number]++;
		}
		i++;
	}
	for(i = 0; i < 52; i++){
		if(character[i] != 0){
			if(i < 26){
				character1[j][0] = i + 'a';
				character1[j][1] = character[i];
				j++;
			}
			else{
				character1[j][0] = i -26 + 'A';
				character1[j][1] = character[i];
				j++;
			}
		}
	}
	sort(character1,j);
	for(i = 0; i < j; i++){
		printf("%c\t:%d\n",character1[i][0],character1[i][1]);
	}
}

void sort(int a[][2],int n){
	int i, j, temp1,temp2;
	for(i = 0; i < n - 1; i ++){
		for(j = 0; j < n -i -1; j++){
			if(a[j][1] > a[j+1][1]){
				temp1 = a[j][0];
				a[j][0] = a[j+1][0];
				a[j+1][0] = temp1;
				temp2 = a[j][1];
				a[j][1] = a[j+1][1];
				a[j+1][1] = temp2;
			}
		}
	}
}