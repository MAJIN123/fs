//2008���մ��ϻ���Ŀ
	//��1����IE��FTP������org.dat����������D�̵ĸ�Ŀ¼�С�
	//��2�����ļ��а��ı���ʽ�����һ���������£����������ɳ���С��15��Ӣ�ĵ��ʣ�����֮���ÿո�ֿ������������š�
	//��3��˳���ȡ������µĲ�ͬ�ĵ��ʣ���Сд���У���ͬʱ�ڶ�ȡ�Ĺ������ų����еĵ���THE�Լ����Σ�����Щ���ʲ��ܳ����ڶ�ȡ�Ľ���С�
	//��4������ȡ�����е��ʵ�����ĸת��д�����D��Ŀ¼��new.txt��ÿ������һ�С�
	//�Ƕ����ֿ��Ե��Ҽ��򿪷�ʽ���ü��±��򿪣������ǣ�
	//The constructor is used to initialize the object The destructor is
	//used to delete the Object the calling sequence of constructor is opposite to the calling sequence of destructor
	//��ȷ���Ӧ����
	//Constructor
	//Is
	//Used
	//To
	//Initialize 
	//Object
	//Destructor 
	//Delete
	//Object 
	//Calling
	//Sequence
	//Of
	//Opposite
	//ע��������Object
	//��Ϊ��һ�ζ�ȡ�Ǵ�Сд���еģ������ֽ���������ĸ��дת��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int readfile(char *filename,char arr[][15])
{
	FILE *fp;
	char ch;
	int i=0;
	int j=0;
	//int count=0;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=-1)
	{
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		{
			arr[i][j]=ch;
			arr[i][j+1]='\0';
			j++;
		}
		else if(j==0)//��� ǰ�������ǿո� ��������������֮���ж���ո�����
		{
		}
		else
		{
			arr[i][j]='\0';
			//i++;j=0;
			//�����µĵ�����the�����ı��Σ�����i��ִ��i++��j�ָ�Ϊ0��������һ�����ʴ洢��ԭ����the��λ���ϣ��൱��ȥ����the
			if(strcmp(arr[i],"THE")==0||strcmp(arr[i],"THe")==0||strcmp(arr[i],"ThE")==0||strcmp(arr[i],"The")==0||strcmp(arr[i],"tHE")==0||strcmp(arr[i],"tHe")==0||strcmp(arr[i],"thE")==0||strcmp(arr[i],"the")==0)
			{
				j=0;
				continue;//��continue����ִ������Ŀ��ܻ��ᵼ��i++
			}
			int k;
			for(k=0;k<i;k++)
			{
				if(strcmp(arr[i],arr[k])==0)//���ظ��ĵ��ʾ�break
				{
					break;
				}
			}
			if(k<i)   //���ظ�����ִ�и�����theһ���Ĵ���
				j=0;
			else
			{
				//printf("hhhhhh");
				//printf("%s",arr[i]);
				i++;
				j=0;
				
			}
		}
	}
	fclose(fp);
	return i;//��ȡ�����ٵ���
}
void writefile(char *filename,char arr[][15],int count)
{
	FILE *fp;
	fp=fopen(filename,"w");
	int k=0;
	if(fp==NULL)
	{
		printf("Can not open the file to write!\n");
		exit(0);
	}
	for(int i=0;i<count;i++)
	{
		char temp[15];
		strcpy(temp,strlwr(arr[i]));//��ȫ��Сд
		temp[0]-=32;//����ĸ��д
		fprintf(fp,"%s\n",temp);//д���ļ�����ȥ
	}
	fclose(fp);
}
int main()
{
	char arr[40][15];
	int count=readfile("e:\\2008.dat",arr);
	writefile("e:\\new.txt",arr,count);
	return 0;
}