//2007���ϼ�������
//��10��1000֮�������������������������浽result.txt�ļ���
//1����������
//2�����ķ���Ҳ���������磺123�ķ�����321�� 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//====================================
//�ú��������ж�һ�����Ƿ�Ϊ����
//������int��
//����ֵΪint�ͣ�1������������0������
//====================================
int isPrime(int x)
{
	int num=sqrt(x*1.0);
	for(int i=2;i<=num;i++)
	{
		if(x%i==0)  //��������
			return 0;
	}
	return 1;//������
}
//====================================
//�ú���������һ�����ķ���
//������int��
//����ֵΪint�ͣ��Ǵ���ȥ�����ķ���
//====================================
int reverse(int x)
{
	int sum=0;
	while(x)
	{
		sum=sum*10+x%10;
		x=x/10;
	}
	return sum;
}
//====================================
//�ú������ڽ�һ����д���ļ�
//�������ļ�ָ���Ҫд���ļ�����
//�޷���ֵ
//====================================
void writefile(FILE *fp,int x)
{
	fprintf(fp,"%5d\n",x);
}
int main()
{
	FILE *fp;
	fp=fopen("e:\\result.txt","w");
	if(fp==NULL)
	{
		printf("Can not open the file to write!\n");
		exit(0);
	}
	for(int i=10;i<=1000;i++)
	{
		if(isPrime(i)==1&&isPrime(reverse(i))==1)
			writefile(fp,i);
	}
	fclose(fp);
	return 0;
}