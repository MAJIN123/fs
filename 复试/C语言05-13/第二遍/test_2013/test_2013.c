#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char original[4];
	char destination[4];
}Flight;

typedef struct{
	Flight way;
	int hop;
}Request;

void divide(char*,Flight*);
void divide1(char *,Request *);
int isRelate(char*,char*,int,Flight *,int);

void main(){
	FILE *fp;
	Flight flight[10];
	Request request[10];
	int i = 0, k, num1,num2;
	char a[100];
	if((fp = fopen("D:\\two\\PathInput.txt","r")) == NULL){
		printf("cannot open the file.");
		exit(0);
	}
	num1 = fgetc(fp) - '0';
	printf("%d\n",num1);
	fgetc(fp);
	while(!feof(fp)){
		a[i++] =fgetc(fp);
	}
	k = i - 1;
	a[k] = '\0';
	printf("%s\n",a);
	fclose(fp);
	divide(a,flight);//对PathInput.txt进行分词处理。
	for(i = 0; i < num1; i++){
		printf("%s\t%s\n",flight[i].original,flight[i].destination);
	}
	if((fp = fopen("D:\\two\\PathRequest.txt","r")) == NULL){
		printf("cannot open the file.");
		exit(0);
	}
	num2 = fgetc(fp) - '0';
	printf("%d\n",num2);
	fgetc(fp);
	i = 0;//i从开始位置重新记录PathReuquest.txt的字符数据
	while(!feof(fp)){
		a[i++] =fgetc(fp);
	}
	k = i - 1;
	a[k] = '\0';
	printf("%s\n",a);
	fclose(fp);
	divide1(a,request);//对PathRequest.txt进行分词处理。
	for(i = 0; i < num2; i++){
		printf("%s\t%s\t%d\n",request[i].way.original,request[i].way.destination,request[i].hop);
	}
	for(i = 0; i < num2; i++){
		if(isRelate(request[i].way.original, request[i].way.destination, request[i].hop, flight,num1)){
			printf("[%s, %s, YES]\n",request[i].way.original, request[i].way.destination);
		}
		else{
			printf("[%s, %s, NO]\n",request[i].way.original, request[i].way.destination);
		}
	}
}

void divide(char *a, Flight * flight){
	int i = 0,j=0,t = 0;
	while(a[i] != '\n'){
		while(a[i] < 'A' || a[i] > 'Z'){
			if(a[i] == '\0')
				break;
			i++;
		}
		if(a[i] == '\0')
			break;
		while(a[i] >= 'A' && a[i] <= 'Z'){
			flight[j].original[t++] = a[i++];
		}
		flight[j].original[t] = '\0';
		t = 0;
		while(a[i] < 'A' || a[i] > 'Z')
			i++;
		while(a[i] >= 'A' && a[i] <= 'Z'){
			flight[j].destination[t++] = a[i++];
		}
		flight[j].destination[t] = '\0';
		t= 0;
		j++;
	}
}

void divide1(char *a, Request *request){
	int i = 0,j=0,t = 0;
	while(a[i] != '\n'){
		while(a[i] < 'A' || a[i] > 'Z'){
			if(a[i] == '\0')
				break;
			i++;
		}
		if(a[i] == '\0')
			break;
		while(a[i] >= 'A' && a[i] <= 'Z'){
			request[j].way.original[t++] = a[i++];
		}
		request[j].way.original[t] = '\0';
		t = 0;
		while(a[i] < 'A' || a[i] > 'Z'){
			i++;
		}
		while(a[i] >= 'A' && a[i] <= 'Z'){
			request[j].way.destination[t++] = a[i++];
		}
		request[j].way.destination[t] = '\0';
		t= 0;
		while(a[i] < '0' || a[i] > '9'){
			i++;
		}
		request[j].hop = a[i] - '0';
		j++;
	}
}

int isRelate(char *original,char *destination, int hop, Flight *flight,int n){
	char origin[4];
	int i;
	for(i = 0; i < n && hop > 0; i++){
		if(strcmp(flight[i].original,original) == 0){
			if(strcmp(flight[i].destination, destination) == 0){
				return 1;
			}
			else{
				strcpy(origin,flight[i].destination);//改变destination的值，用新的数组存进去
				if(isRelate(origin,destination,hop-1,flight,n))//递归调用isRelate函数
					return 1;
			}
		}
	}
	return 0;
}