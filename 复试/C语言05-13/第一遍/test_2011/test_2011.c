#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPasscode(char *,int,int);
int isPermit(char);
void printSentence(char *,int,int);

void main(){
	FILE *fp;
	char information[300];
	int i = 0,j = 0, k,cip[256][2],cip1,cip2;
	if((fp = fopen("D:\\infor.txt","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		information[i++] = fgetc(fp);
	}
	k = i - 1;//feof()can calculate once again
	information[k] = '\0';
	for(cip1 = 0; cip1 < 256; cip1++){
		if(!isPasscode(information,cip1,1))
			continue;
		for(cip2 = 0; cip2 < 256; cip2++){
			if(!isPasscode(information,cip2,2))
				continue;
			else{
				cip[j][0] = cip1;
				cip[j][1] = cip2;
				j++;
			}
		}
	}
	for(i = 0; i < j; i++){
		printf("cip1 = %d\t cip2= %d\n",cip[i][0],cip[i][1]);
		printSentence(information,cip[i][0],cip[i][1]);
	}
	fclose(fp);
}

int isPasscode(char *information, int cip, int n){
	int i,k;
	char ch;
	k = strlen(information);
	if(n == 1){
		if(k % 2 == 0){
			for(i = 0; i < k; i += 2){
				ch = information[i] ^ cip;
				if(!isPermit(ch))
					return 0;
			}
		}
		else{
			for(i = 0; i < k - 1; i += 2){
				ch = information[i] ^ cip;
				if(!isPermit(ch))
					return 0;
			}
			ch = information[i-1] ^ cip;
			if(!isPermit(ch))
				return 0;
		}
	}
	else{
		if(k % 2 == 0){
			for(i = 1; i < k; i += 2){
				ch = information[i] ^ cip;
				if(!isPermit(ch))
					return 0;
			}
		}
		else{
			for(i = 1; i < k - 1; i += 2){
				ch = information[i] ^ cip;
				if(!isPermit(ch))
					return 0;
			}
		}
	}
	return 1;
}

int isPermit(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == '.') || (ch == ',') || (ch == ' ') || (ch == '!'))
		return 1;
	else
		return 0;
}

void printSentence(char *information,int cip1,int cip2){
	int i,n;
	char ch1,ch2;
	n = strlen(information);
	if(n % 2 == 0){
		for(i = 0; i < n; i += 2){
			ch1 = information[i];
			ch2 = information[i+1];
			information[i] = ch1 ^ cip1;
			information[i+1] = ch2 ^ cip2;
		}
	}
	else{
		for(i = 0; i < n - 1; i += 2){
			ch1 = information[i];
			ch2 = information[i+1];
			information[i] = ch1 ^ cip1;
			information[i+1] = ch2 ^ cip2;
		}
		information[n-1] = ch1 ^ cip1;
	}
	printf("%s\n",information);
}