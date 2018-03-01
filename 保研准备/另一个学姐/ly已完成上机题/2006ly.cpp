//2006年上级复试题
//找出100到1000内的不含9的素数，存到result.txt文件中。
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//=========================================
//该函数用来判断一个数是否为质数
//参数为int型
//返回值是int型，0代表不是质数，1代表是质数
//=========================================
int isPrime(int x)
{
	int num=sqrt(x*1.0);
	for(int i=2;i<=num;i++)
	{
		if(x%i==0)   //x能被i整除，不是质数，返回0
			return 0;
	}
	return 1;
}
//=========================================
//该函数用来判断一个数x中是否含数n
//参数为int型
//返回值是int型，0代表不包含，1代表包含
//=========================================
int judge(int x,int n)
{
	while(x)
	{
		if(n==x%10)   //包含
			return 1;
		x=x/10;
	}
	return 0;   //不包含
}
//=========================================
//该函数用来将整型值x放到文件中
//参数为FILE *型、int型
//无返回值
//=========================================
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
		printf("打开文件失败！\n");
		exit(0);
	}
	for(int i=100;i<=1000;i++)
	{
		if(isPrime(i)==1&&judge(i,9)==0)//是不含9的素数，将它写入文件
		{
			writefile(fp,i);
		}
	}
	fclose(fp);
	return 0;
}