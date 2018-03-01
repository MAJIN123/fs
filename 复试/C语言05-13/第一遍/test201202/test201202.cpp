#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long x;
	long y;
}Vector;

int judge(Vector *);
int calculateArea(Vector *, int);
void printPointers(Vector *, int);

void main(){
	FILE *fp;
	Vector vectorArray[20];
	int i = 0, n = 0, number = 0;
	int area;
	if((fp = fopen("D:\\org.bat","rb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	else{
		while(!feof(fp)){
			fread(&vectorArray[i].x,4,1,fp);
			fread(&vectorArray[i].y,4,1,fp);
			i++;
		}
		n = i - 1;
	}
	for(i = 0; i < n; i++){
		if((vectorArray[i].x > 0) && (vectorArray[i].y > 0))
			number++;
		printf("%d:\t(%d\t%d)\n", i+1, vectorArray[i].x, vectorArray[i].y);
	}
	area = calculateArea(vectorArray,n);
	
	printf("The number of all pointers is : %d\n", n);
	printf("The number of the effective pointers is : %d\n",number);
	printf("The common area is %d.\n", area);
	printPointers(vectorArray,n);
}

int calculateArea(Vector *vectorArray, int n){
	Vector *p = vectorArray;
	int min_x = (*p).x;
	int min_y = (*p).y;
	int i;
	p++;
	for(i = 1; i < n; i++,p++){
		if(((*p).x > 0) && ((*p).y > 0)){
			if((*p).x < min_x)
				min_x = (*p).x;
			if((*p).y < min_y)
				min_y = (*p).y;
		}
	}
	return min_x * min_y;
}

void printPointers(Vector *vectorArray, int n){
	Vector *p = vectorArray;
	Vector *q;
	int i, j, signal,number = 0;
	for(i = 0; i < n; i++, p++){
		if(judge(p)){
			q = vectorArray;
			signal = 0;
			for(j = 0; j < n; j++,q++){
				if(judge(q) && q != p){
					if(((*p).x > (*q).x) || ((*p).y >(*q).y)){
						signal = 1;
						break;
					}
				}
			}
			if(!signal){
				if(number == 0)
					printf("The flowing pointer is correct for this question:\n");
				number++;
				printf("(%ld  %ld)\n", (*p).x, (*p).y);
			}
		}
	}
	if(number == 0)
		printf("Do nont find the pointer!\n");
}

int judge(Vector *p){
	if(((*p).x > 0) && ((*p).y > 0))
		return 1;
	else
		return 0;
}
