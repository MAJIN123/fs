//2009年苏大上机题目
	//（1）用IE浏览器从FTP上下载org.dat，并保存在D盘的根目录下。
	//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的十进制或八进制数字，数字之间用“,”分开，数字内部存在且仅存在空格。
	//（3）八进制数以起始位“0”作为标示与十进制数区分。
	//（4）顺序读取这些数字将他们转变为十进制数后按从大到小的顺序排序后，输出到D盘根目录下new.txt，每个数字一行。

	//eg：_235_,34__2,_043_1_,1_3   分别是：十进制235，十进制342.，八进制431，十进制13。_代表空格

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int readfile(char *filename,char arr[][15])
{
	FILE *fp;
	char ch;
	int i=0;
	int j=0;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=-1) //一直读到文件末尾
	{
		if(ch>='0'&&ch<='9')
		{
			arr[i][j]=ch;
			arr[i][j+1]='\0';
			j++;
		}
		else if(ch==' ')//空格的情况什么都不做
		{

		}
		else if(ch==',') //逗号的情况
		{
			arr[i][j]='\0';
			j=0;
			i++;
		}
		else
		{

		}
	}
	arr[i][j]='\0';//最后一个数字没有，做分隔符
	fclose(fp);
	return i+1;//返回的是数字个数
}
int changeOneNumber(char *arr)
{
	int i;
	int sum=0;
	if(arr[0]=='0')
	{
		i=1;
		while(arr[i]!='\0')
		{
			sum=sum*8+arr[i]-'0';
			i++;
		}
	}
	else
	{
		i=0;
		while(arr[i]!='\0')
		{
			sum=sum*10+arr[i]-'0';
			i++;
		}
	}
	return sum;
}
void change(char arr[][15],int num[],int count)
{
	for(int i=0;i<count;i++)
	{
		num[i]=changeOneNumber(arr[i]);
	}
}
void sort(int num[],int count)
{
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(num[i]<num[j])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
}
void writefile(char *filename,int num[],int count)
{
	FILE *fp;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("Can not open the file to write!\n");
		exit(0);
	}
	for(int i=0;i<count;i++)
	{
		fprintf(fp,"%d\n",num[i]);
	}
	fclose(fp);
}
int main()
{
	char arr[20][15];
	int num[20];
	int count=readfile("e:\\2009.dat",arr);
	change(arr,num,count);
	sort(num,count);
	writefile("e:\\2009.txt",num,count);
	return 0;
}