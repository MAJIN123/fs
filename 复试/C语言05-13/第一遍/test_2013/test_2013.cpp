#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char original[10];//The number plus one '\0' is four
	char destination[10];
}Flight;

typedef struct{
	Flight way;
	int hop;
}Flight1;

void inputflight(char*, Flight *);
void inputflight1(char*, Flight1 *);
int isRelate(Flight *,char *, char *,int);

void main(){
	FILE *fp;
	Flight flight[10];
	Flight1 flight1[10];
	char a[100],b[100];
	char result[3];
	int i = 0,j =0, number1, number2;
	char ch;

	if((fp=fopen("D:\\PathInput.txt","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	ch = fgetc(fp);
	number1 = ch - '0';
	printf("%d\n",number1);
	ch = fgetc(fp);
	while(!feof(fp)){
		a[i++] = fgetc(fp);
	}
	a[i-1] = '\0';
	inputflight(a,flight);
	for(i = 0; i < number1; i++){
		printf("[%s, %s]\n",flight[i].original,flight[i].destination);
	}
	fclose(fp);

	if((fp=fopen("D:\\PathRequest.txt","r")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	ch = fgetc(fp);
	number2 = ch - '0';
	printf("%d\n",number2);
	ch = fgetc(fp);//delete the '\n'
	while(!feof(fp)){
		b[j++] = fgetc(fp);
	}
	b[j-1] = '\0';
	inputflight1(b,flight1);
	for(i = 0; i < number2; i++){
		printf("[%s, %s, %d]\n",flight1[i].way.original,flight1[i].way.destination,flight1[i].hop);
	}
	fclose(fp);
	if((fp=fopen("D:\\Output.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	fclose(fp);
	printf("\n");

	if((fp = fopen("D:\\Output.txt","w")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < number2; i++){
		if(isRelate(flight, flight1[i].way.original, flight1[i].way.destination, flight1[i].hop)){
			strcpy(result,"YES");
			printf("[%s, %s, %s]\n",flight1[i].way.original,flight1[i].way.destination,result);
			fprintf(fp,"[%s, %s, %s]\n",flight1[i].way.original,flight1[i].way.destination,result);
		}
		else{
			strcpy(result,"NO");
			printf("[%s, %s, %s]\n",flight1[i].way.original,flight1[i].way.destination,result);
			fprintf(fp,"[%s, %s, %s]\n",flight1[i].way.original,flight1[i].way.destination,result);
		}
	}
	fclose(fp);
}

void inputflight(char *a, Flight *flight){
	int i = 0, j = 0,k =0;
	while(a[i] != '\0'){
		while(a[i] < 'A' || a[i] >'Z'){
			if(a[i] == '\0')
				break;
			i++;
		}
		if(a[i] == '\0')
			break;
		k = 0;
		while(a[i] >= 'A' && a[i] <= 'Z'){
			flight[j].original[k++] = a[i];
			i++;
		}
		flight[j].original[k] = '\0';
	
		while(a[i] < 'A' || a[i] >'Z')
			i++;
		k = 0;
		while(a[i] >= 'A' && a[i] <= 'Z'){
			flight[j].destination[k++] = a[i];
			i++;
		}
		flight[j].destination[k] = '\0';
		j++;
	}
}

void inputflight1(char*b, Flight1 *flight1){
	int i = 0, j = 0,k =0;	
	while(b[i] != '\0'){
		while(b[i] < 'A' || b[i] >'Z'){
			if(b[i] == '\0')
				break;
			i++;
		}
		if(b[i] == '\0')
			break;
		k = 0;
		while(b[i] >= 'A' && b[i] <= 'Z'){
			flight1[j].way.original[k++] = b[i];
			i++;
		}
		flight1[j].way.original[k] = '\0';
	
		while(b[i] < 'A' || b[i] >'Z')
			i++;
		k = 0;
		while(b[i] >= 'A' && b[i] <= 'Z'){
			flight1[j].way.destination[k++] = b[i];
			i++;
		}
		flight1[j].way.destination[k] = '\0';
		while(b[i] <'0' || b[i] >'9')
			i++;
		while(b[i] >= '0' && b[i] <='9'){
			flight1[j].hop = b[i] - '0';
			b++;
		}
		j++;
	}
}

int isRelate(Flight *flight, char *original, char* destination,int n){
	int j;
	char copyOriginal[4];
	strcpy(copyOriginal,original);
	if(strcmp(original,destination) == 0)
		return 1;
	else{
		for(j = 0; j < 6; j++){
			if(strcmp(flight[j].original,original) == 0){
				strcpy(copyOriginal,flight[j].destination);
				if(isRelate(flight,copyOriginal,destination,n-1) && (n > 0))
					return 1;
			}
		}
	}
	return 0;
}