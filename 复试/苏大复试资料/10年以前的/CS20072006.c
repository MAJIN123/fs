#include <stdio.h>
#include <math.h>


//�ж��Ƿ�Ϊ����
int isprime(long n)
{
	int i,j;
	j=sqrt(n);
	for(i=2;i<=j;i++)
	{
		if(n%i==0)
		{
			break;
		}
	}
	if(i>j)
	{
		return 1;
	}else
	{
		return 0;
	}

}

//ת��������
long reversenum(long n)
{
	long m;
	for(m=0;n>0;)
	{
		m=m*10+n%10;
		n=n/10;
	}
	return m;
}

//�ж�����m���Ƿ����Ϊn������
int signcontain(long m,int n)
{
	int t=0;
	while(m>0)//�ӵ͵��������ж��Ƿ��������n
	{
		t=m%10;
		m=m/10;
		if(t==n)
		{
			return 1;
		}
	}
	return 0;
}

void main()
{

	//2006���ϼ�������
	//�ҳ�100��1000�ڵĲ���9���������浽result.txt�ļ��С�
	int i=100;
	char fsave[]="D:\\result.txt";
	FILE * fp;
	fp=fopen(fsave,"w+");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	for(;i<1000;i++)
	{
		if(isprime(i)&&(!signcontain(i,9)))
		{
			printf("%d\t",i);
			fprintf(fp,"%d\t",i);
		}
	}
	fclose(fp);





	/*
	//2007���ϼ�������
	//��10��1000֮�������������������������浽result.txt�ļ���
	//1����������
	//2�����ķ���Ҳ���������磺123�ķ�����321�� 
	int i=10;
	char fsave[]="D:\\result.txt";
	FILE * fp;
	fp=fopen(fsave,"w+");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	for(;i<1000;i++)
	{
		if(isprime(i)&&isprime(reversenum(i)))
		{
			printf("%d\t",i);
			fprintf(fp,"%d\t",i);

		}
	}
	fclose(fp);
	*/




}