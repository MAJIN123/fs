//2007年上级复试题
//把10到1000之间满足以下两个条件的数，存到result.txt文件中
//1、是素数。
//2、它的反数也是素数，如：123的反数是321。 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//====================================
//该函数用于判断一个数是否为素数
//参数是int型
//返回值为int型，1代表是素数，0代表不是
//====================================
int isPrime(int x)
{
	int num=sqrt(x*1.0);
	for(int i=2;i<=num;i++)
	{
		if(x%i==0)  //不是素数
			return 0;
	}
	return 1;//是素数
}
//====================================
//该函数用于求一个数的反数
//参数是int型
//返回值为int型，是传进去参数的反数
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
//该函数用于将一个数写入文件
//参数是文件指针和要写入文件的数
//无返回值
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