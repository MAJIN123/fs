#include <stdio.h>
#include <math.h>


//判断是否为素数
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

//转换反序数
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

//判断整数m中是否包含为n的数符
int signcontain(long m,int n)
{
	int t=0;
	while(m>0)//从低到高依次判定是否包含数符n
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

	//2006年上级复试题
	//找出100到1000内的不含9的素数，存到result.txt文件中。
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
	//2007年上级复试题
	//把10到1000之间满足以下两个条件的数，存到result.txt文件中
	//1、是素数。
	//2、它的反数也是素数，如：123的反数是321。 
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