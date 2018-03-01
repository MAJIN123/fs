//2010年上机复试题
	//1）FTP上下载make.exe和org.dat，运行make.exe输入准考证后三位生成data.txt，文件为二进制编码
	//2）data.txt内存有2048个整数，其中前n个为非0数，后2048-n个数为0，将其读入数组，计算非零数的个数n
	//3）选出n个数中的最大数&最小数
	//4）选出n个数中最大素数
	//5）将n个数从大到小排序，并平均分成3段（若n非3的整数倍，则不考虑最后的1~2个数），选出中间段的最大数和最小数
//因为没有二进制文件，所以我就用文本文件来读啦嘤嘤嘤
#define COUNT 20
#include<stdio.h>
#include<math.h>
int change(char *num)
{
	int sum=0;
	int i;
	if(num[0]=='-')
	{
		i=1;
		while(num[i]!='\0')
		{
			sum=sum*10+num[i]-'0';
			i++;
		}
		return(-1)*sum;
	}
	else
	{
		i=0;
		while(num[i]!='\0')
		{
			sum=sum*10+num[i]-'0';
			i++;
		}
		return sum;
	}
}
void readfile(char *filename,int nums[])
{
	FILE *fp;
	char temp[10]={'\0'};
	int i=0,j=0;
	char ch;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
	{
		if(ch>='0'&&ch<='9'||ch=='-')
		{
			temp[i]=ch;
			temp[i+1]='\0';
			i++;
		}
		else if(i==0)//两个数字之间有多个空格
		{

		}
		else
		{
			nums[j]=change(temp);
			j++;
			i=0;
		}
	}
	nums[j]=change(temp);//上面一个循环无法转换最后一个数字（如果最后一个数字后面没有空格或其他非数字符号）
	fclose(fp);
}
int cal(int nums[])
{
	int i=0;
	while(nums[i]!=0&&i<COUNT) //因为在数组之后的存储单元中很有可能也存储了不等于0的值所以要保证i小于数组长度否则会出错的
	{
		i++;
	}
	return i;
}
void max_min(int nums[],int *max,int *min,int n)
{
	*max=nums[0];
	*min=nums[0];
	for(int i=1;i<n;i++)
	{
		if(nums[i]>*max)
		{
			*max=nums[i];
		}
		if(nums[i]<*min)
		{
			*min=nums[i];
		}
	}
}
int isPrime(int x)
{
	int num=sqrt(x*1.0);
	for(int i=2;i<=num;i++)
	{
		if(x%i==0)
		{
			return 0; //不是素数
		}
	}
	return 1;//是素数
}
int maxPrime(int nums[],int n)
{
	int max=2;
	for(int i=0;i<n;i++)
	{
		if((isPrime(nums[i])==1)&&nums[i]>max)
			max=nums[i];
	}
	return max;
}
void sort(int nums[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(nums[i]<nums[j])
			{
				int temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
			}
		}
	}
}
int main()
{
	int nums[COUNT];
	int n;
	int max,min;
	int maxprime;
	int midmax,midmin,flag;
	readfile("e:\\2010.txt",nums);
	for(int i=0;i<COUNT;i++)
	{
		printf("%-5d",nums[i]);
	}
	n=cal(nums);
	max_min(nums,&max,&min,n);
	maxprime=maxPrime(nums,n);
	sort(nums,n);
	printf("\n排序后：\n");
	for(int i=0;i<COUNT;i++)
	{
		printf("%-5d",nums[i]);
	}
	flag=n/3;
	midmax=nums[flag];
	midmin=nums[2*flag-1];
	printf("前%d个数中的最大值为%d，最小值为%d。\n",n,max,min);
	printf("前%d个数中的最大素数为%d。\n",n,maxprime);
	printf("中间段的最大值为%d，最小值为%d。\n",midmax,midmin);
	return 0;
}