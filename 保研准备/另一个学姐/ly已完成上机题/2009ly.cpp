//2009���մ��ϻ���Ŀ
	//��1����IE�������FTP������org.dat����������D�̵ĸ�Ŀ¼�¡�
	//��2�����ļ��а��ı���ʽ�����һ���������£����������ɳ���С��15��ʮ���ƻ�˽������֣�����֮���á�,���ֿ��������ڲ������ҽ����ڿո�
	//��3���˽���������ʼλ��0����Ϊ��ʾ��ʮ���������֡�
	//��4��˳���ȡ��Щ���ֽ�����ת��Ϊʮ�������󰴴Ӵ�С��˳������������D�̸�Ŀ¼��new.txt��ÿ������һ�С�

	//eg��_235_,34__2,_043_1_,1_3   �ֱ��ǣ�ʮ����235��ʮ����342.���˽���431��ʮ����13��_����ո�

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
	while((ch=fgetc(fp))!=-1) //һֱ�����ļ�ĩβ
	{
		if(ch>='0'&&ch<='9')
		{
			arr[i][j]=ch;
			arr[i][j+1]='\0';
			j++;
		}
		else if(ch==' ')//�ո�����ʲô������
		{

		}
		else if(ch==',') //���ŵ����
		{
			arr[i][j]='\0';
			j=0;
			i++;
		}
		else
		{

		}
	}
	arr[i][j]='\0';//���һ������û�У����ָ���
	fclose(fp);
	return i+1;//���ص������ָ���
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