#include <stdio.h>
#include <stdlib.h>

struct vector{
	long x;
	long y;
}vectorArray[20];

void main(){
	int calculateNumber(struct vector [],int);
	void print(struct vector[], int);
	FILE *fp;
	int i = 0, n,number;

	if((fp = fopen("D:\\org.bat", "rb")) == NULL){
		printf("cannot open this file\n");
		exit(0);
	}
	else{
		i=0;
		while(!feof(fp)){
			fread(&vectorArray[i].x, 4, 1, fp);
			fread(&vectorArray[i].y, 4, 1, fp);
			i++;
		}
	}
	fclose(fp);
	n = i - 1;//feof(fp)�������ص������һ�ζ����������ݣ��ʽ������1.
	printf("�ܹ��������ĸ���Ϊ��%d\n",n);	
	number = calculateNumber(vectorArray,n);
	printf("��Ч��ĸ���Ϊ�� %d\n",number);
	print(vectorArray,n);
}

int calculateNumber(struct vector *p, int n){
	int i,number = 0;
	for(i = 0; i < n; i++){
		if(((*p).x > 0) && ((*p).y > 0)){
			number++;
		}
		p++;
	}
	return number;
}
void print(struct vector *p,int n){
	int i;
	for(i = 0; i < n; i++){
		printf("�� %d ��������ǣ�%ld ��%ld��\n", i+1,(*p).x, (*p).y);
		p++;
	}
}