//2011年上机复试题
	//第一道：输出~9999中满足一下条件的所有数：
	//(1)该数是素数
	//(2)十位数和个位数组成的数是素数，百位数和个位数组成的数是素数
	//(3)千位数和百位数组成的数是素数，千位数和十位数组成的数是素数
#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
	if(x==0||x==1)//要注意要是没有这个if解决不了这两种情况，因为平时不会遇到所以一直没有注意！！！！！
		return 0;
	int i;
	int num=sqrt(x*1.0);
	for( i=2;i<=num;i++)
	{
		if(x%i==0)
		{
			break; //不是素数
		}
	}
	if(i>num)
	{
		return 1;//是素数
	}
	else
		return 0;//不是素数
}
int main()
{
	int count=0;
	printf("符合第一问的数有：\n");
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
	printf("符合第二问的数有：\n");
	for(int i=1000;i<=9999;i++)
	{
		int a=i%100;//十位和个位的组合
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
	printf("符合第三问的数有：\n");
	for(int i=1000;i<=9999;i++)
	{
		int a=i/100;//千位和百位的组合
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