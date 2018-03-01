//2005年上级复试题
//第1道  把一个数表示成若干个素数的和
//第2道  一个递归程序，是关于如何选择机器人的最佳走步的
//第3道  统计篇文章中各英文字母的个数，并排序。
#include<stdio.h>
#include<math.h>
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
//========================================
//该函数用于把一个数表示成若干个素数的和
//参数是int型
//无返回值
//这种方法如果x本身就是素数，则会直接输出x
//========================================
void sumOfPrime1(int x)
{
	int sum=x;
	for(int i=x;i>1;i--) //从大往小找
	{
		if(isPrime(i)==1)//i是质数
		{
			if(sum-i>=2||sum-i==0)//sum-i大于等于2或者sum就等于i就采纳（一个>=2的数肯定还能被拆分成素数之和的）
			{
				sum=sum-i;
				printf("%5d\n",i);
				i=sum+1; //使得下一轮寻找直接从已减去i的sum开始，这能能提高效率

			}

		}
		if(sum==0)
			break;
	}
}
//================================================
//该函数用于把一个数表示成若干个素数的和
//参数是int型
//无返回值
//这种方法如果x本身就是素数且可拆分，则拆分再会输出
//=================================================
void sumOfPrime2(int x)
{
	int sum=x;
	if(x==2||x==3)
	{
		printf("%5d\n",x);
		return;
	}
	for(int i=x-1;i>1;i--) //从大往小找i的初值为x-1，则当x为素数时，不会直接输出x，还会再拆分的
	{
		if(isPrime(i)==1)//i是质数
		{
			if(sum-i>=2||sum-i==0)//sum-i大于等于2或者sum就等于i就采纳（一个>=2的数肯定还能被拆分成素数之和的）
			{
				sum=sum-i;
				printf("%5d\n",i);
				i=sum+1; //使得下一轮寻找直接从已减去i的sum开始，这能能提高效率

			}

		}
		if(sum==0)
			break;
	}
}
int main()
{
	int x;
    do
	{
		scanf("%d",&x);
		sumOfPrime2(x);
	}while(x!=1);

	return 0;
}