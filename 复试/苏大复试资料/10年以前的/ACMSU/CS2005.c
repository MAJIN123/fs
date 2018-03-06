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

//递归函数，把一个数表示成若干素数的和
//这种拆分方法很简单，效率很低，有待优化
void printsplitprime(long m)
{
	long n;
	if(m==3||m==2||m==5||m==7||m==9)
	{
		printf("%ld",m);
		return;
	}
	n=m/2;//为了控制所需素数的个数，每次寻找小于该数一半的最大素数
	while(!isprime(n))
	{
		n--;
	}
	printf("%ld+",n);
	printsplitprime(m-n);

}

//字符指针数组比较方法
int strpcmp(const void * p1,const void * p2)
{
	return **(char * *)p1-**(char * *)p2;
}


void main()
{

	//2005年上级复试题
	//第1道  把一个数表示成若干个素数的和
	//第2道  一个递归程序，是关于如何选择机器人的最佳走步的
	//第3道  统计篇文章中各英文字母的个数，并排序。
	//题目不是很难，但想在一个小时内把这它们全部调试出来也不容易啊!
	
	//第三道
	//该题目需要更详细的要求，现在只编写题目的两个核心功能1.字母计数2.排序
	FILE * fp;
	char fname[]="D:\\org.dat",c;
	int count=0,i;
	char * strs[5]={"Hello","Help","micy","C programe","test"};

	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		if((c>'A'&&c<'Z')||(c>'a'&&c<'z'))
		{
			count++;//如果是英文字母则计数
			//这里可以再做其他的事情
		}
		c=fgetc(fp);
	}
	fclose(fp);
	printf("Totle character:%d\n",count);
	
	//字符串排序
	qsort(strs,5,sizeof(char *),strpcmp);

	for(i=0;i<5;i++)
	{
		printf("%s\n",strs[i]);

	}

	//第二道，有待寻找更详细的题目要求


	/*
	//第一道：
	long m,n,t;
	int i;
	printf("please input the number:\n");
	scanf("%ld",&m);
	printf("%ld=",m);
	printsplitprime(m);
	*/
	
	
}