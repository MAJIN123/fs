#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}Point;

int calculateArea(Point*,int);
void printPoints(Point*,int);
void sortPoints(Point*,int);
void printTeam(Point*,int);
int isAllDispate(int*,int);

void main(){
	FILE *fp;
	int i = 0,k,t=0, area = 0;
	Point p[40];
	Point effective[40];

/*	if((fp = fopen("D:\\two\\org11.dat","wb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	for(i = 0; i < 20; i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		fwrite(&p[i].x,4,1,fp);
		fwrite(&p[i].y,4,1,fp);
	}
	fclose(fp);*/
	if((fp = fopen("D:\\two\\org11.dat","rb")) == NULL){
		printf("cannot open the file");
		exit(0);
	}
	while(!feof(fp)){
		fread(&p[i].x,4,1,fp);
		fread(&p[i].y,4,1,fp);
		i++;
	}
	k = i -1;
	for(i =0 ; i < k; i++){
		if(p[i].x > 0 && p[i].y > 0){
			effective[t].x = p[i].x;
			effective[t].y = p[i].y;
			t++;
		}
		printf("%d\t%d\n",p[i].x,p[i].y);
	}
	printf("1.There are %d pointers.\n",k);
	printf("There are %d effective points.\n",t);
	area = calculateArea(effective,t);
	printf("2.The common area is %d.\n",area);
	printPoints(effective,t);
	sortPoints(effective,t);
	for(i = 0; i < t; i++)
		printf("%d\t%d\n",effective[i].x, effective[i].y);
	printTeam(effective,t);
	fclose(fp);
}

int calculateArea(Point *effective,int n){//Ѱ�ҵ���С��x����С��y����˼��ö�Ӧ�Ľ��
	int i, min1, min2, area = 0;
	min1 = effective[0].x;
	min2 = effective[0].y;

	for(i = 1; i < n; i++){
		if(effective[i].x < min1)
			min1 = effective[i].x;
		if(effective[i].y < min2)
			min2 = effective[i].y;
	}
	area = min1 * min2;
	return area;
}

void printPoints(Point *effective, int n){
	int i,j,signal = 0,t = 0;
	for(i = 0; i < n; i++){
		signal = 0;
		for(j = 0; j < n; j++){//�����зǱ���ĵ��x����y����С�ڵ��ڸõ��ʱ���򲻳�����
			if((effective[j].x <= effective[i].x || effective[j].y <= effective[i].y) && (j != i)){
				signal = 1;
				break;
			}
		}
		if(signal == 0){
			t++;
			printf("3. %d\t%d\n",effective[i].x,effective[i].y);
		}
	}
	if(t == 0){//��������ڷ��������ĵ㣬���������ĺ���
		printf("3.There is no point is correct!\n");
	}
}

void sortPoints(Point *effective,int n){//����x���������������������ڴ��ݵ���ָ�룬������Ӧ��Ԫ��Ҳ�ᷢ���仯
	int i, j;
	Point temp;
	for(i = 0; i < n -1; i++){
		for(j = 0; j < n - i -1 ; j++){
			if(effective[j].x > effective[j+1].x){
				temp.x = effective[j].x;
				temp.y = effective[j].y;
				effective[j].x = effective[j+1].x;
				effective[j].y = effective[j+1].y;
				effective[j+1].x = temp.x;
				effective[j+1].y = temp.y;
			}
		}
	}
}

void printTeam(Point *effective, int n){
	int a[40] = {0}, i=1,j, k = 0, temp;
	temp = effective[0].y;
	printf("---%d------\n",k+1);//��һ������
	a[0] = 1;
	printf("%d\t%d\n",effective[0].x, effective[0].y);
	while(!isAllDispate(a,n)){
		while(i < n){//����Ѱ�ұ�С��ĳ�Ա
			if(a[i] == 0){
				if(effective[i].y > temp){
					printf("%d\t%d\n",effective[i].x,effective[i].y);
					temp = effective[i].y;//�ı�Ƚϵ�tempֵ��Ҳ����y��ֵ��ǰһ����ԱΪ��׼�����бȽ�
					a[i] = 1;
				}
			}
			i++;
		}
		i = 0;
		for(j = 0; j < n; j++){//Ѱ�ҵ���һ���������ʼλ��
			if(a[j] == 0){
				k++;
				printf("---%d------\n",k+1);//�����С��ĵ�һ��Ԫ��
				temp = effective[j].y;//�޸�temp��ֵΪ��һ��Ԫ�ص�ֵ
				a[j] = 1;
				printf("%d\t%d\n",effective[j].x,effective[j].y);
				break;
			}
		}
	}
}

int isAllDispate(int *a,int n){//�ж������־�����ֵ��0 ~ n-1��֮���ֵ�Ƿ�ȫΪ1�����ȫΪ1�����ʾ��Աȫ�����������
	int i;
	for(i = 0; i < n; i++){
		if(a[i] == 0)
			return 0;
	}
	return 1;
}