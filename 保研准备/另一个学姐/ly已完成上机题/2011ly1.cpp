//2011���ϻ�������
	//��һ�������~9999������һ����������������
	//(1)����������
	//(2)ʮλ���͸�λ����ɵ�������������λ���͸�λ����ɵ���������
	//(3)ǧλ���Ͱ�λ����ɵ�����������ǧλ����ʮλ����ɵ���������
#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
	if(x==0||x==1)//Ҫע��Ҫ��û�����if��������������������Ϊƽʱ������������һֱû��ע�⣡��������
		return 0;
	int i;
	int num=sqrt(x*1.0);
	for( i=2;i<=num;i++)
	{
		if(x%i==0)
		{
			break; //��������
		}
	}
	if(i>num)
	{
		return 1;//������
	}
	else
		return 0;//��������
}
int main()
{
	int count=0;
	printf("���ϵ�һ�ʵ����У�\n");
	for(int i=1000;i<=9999;i++)
	{
		if(isPrime(i)==1)
		{
			printf("%5d",i);
			count++;
			if(count%10==0)
				printf("\n");

		}

	}
	count=0;
	printf("���ϵڶ��ʵ����У�\n");
	for(int i=1000;i<=9999;i++)
	{
		int a=i%100;//ʮλ�͸�λ�����
		int gewei=i%10;
		//int shiwei=i/10%10;
		int baiwei=i/100%10;
		int b=baiwei*10+gewei;
		if(isPrime(a)==1&&isPrime(b)==1)
		{
			printf("%5d",i);
			count++;
			if(count%10==0)
				printf("\n");
		}
	}
	count=0;
	printf("���ϵ����ʵ����У�\n");
	for(int i=1000;i<=9999;i++)
	{
		int a=i/100;//ǧλ�Ͱ�λ�����
		int shiwei=i/10%10;
		int qianwei=i/1000;
		int b=qianwei*10+shiwei;
		if(isPrime(a)==1&&isPrime(b)==1)
		{
			printf("%5d",i);
			count++;
			if(count%10==0)
				printf("\n");
		}
	}
	return 0;
}