//2010���ϻ�������
	//1��FTP������make.exe��org.dat������make.exe����׼��֤����λ����data.txt���ļ�Ϊ�����Ʊ���
	//2��data.txt�ڴ���2048������������ǰn��Ϊ��0������2048-n����Ϊ0������������飬����������ĸ���n
	//3��ѡ��n�����е������&��С��
	//4��ѡ��n�������������
	//5����n�����Ӵ�С���򣬲�ƽ���ֳ�3�Σ���n��3�����������򲻿�������1~2��������ѡ���м�ε����������С��
//��Ϊû�ж������ļ��������Ҿ����ı��ļ�������������
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
		else if(i==0)//��������֮���ж���ո�
		{

		}
		else
		{
			nums[j]=change(temp);
			j++;
			i=0;
		}
	}
	nums[j]=change(temp);//����һ��ѭ���޷�ת�����һ�����֣�������һ�����ֺ���û�пո�����������ַ��ţ�
	fclose(fp);
}
int cal(int nums[])
{
	int i=0;
	while(nums[i]!=0&&i<COUNT) //��Ϊ������֮��Ĵ洢��Ԫ�к��п���Ҳ�洢�˲�����0��ֵ����Ҫ��֤iС�����鳤�ȷ��������
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
			return 0; //��������
		}
	}
	return 1;//������
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
	printf("\n�����\n");
	for(int i=0;i<COUNT;i++)
	{
		printf("%-5d",nums[i]);
	}
	flag=n/3;
	midmax=nums[flag];
	midmin=nums[2*flag-1];
	printf("ǰ%d�����е����ֵΪ%d����СֵΪ%d��\n",n,max,min);
	printf("ǰ%d�����е��������Ϊ%d��\n",n,maxprime);
	printf("�м�ε����ֵΪ%d����СֵΪ%d��\n",midmax,midmin);
	return 0;
}