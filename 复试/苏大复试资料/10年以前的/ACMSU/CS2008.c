#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 30


//�ж��ַ������еĵ����Ƿ���Ҫ�ų��ĵ���THE�������,�����Ѿ������õ���
int checkstr(char * words[],int m,char ct[],int n)
{
	char * cp;
	int i=0;
	//���ж��Ƿ���THE�ı���
	cp=(char *)malloc(sizeof(char)*n);
	strcpy(cp,ct);
	strupr(cp);
	if(strcmp(cp,"THE")==0)
	{
		return 1;
	}
	
	for(;i<m;i++)
	{
		if(strcmp(words[i],ct)==0)
		{
			return 1;
		}
	}
	return 0;
}


void main()
{


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
	//08���09�����Ŀ�ǳ����ƣ�ֻ������Ϣ�Ĵ���ʽ��������ͬ
	int f=1,i=0,j=0;//��ʶf=1Ϊһ�����ʶ�ȡ��f=0Ϊһ�����ʵĽ������µ��ʵĿ�ʼ
	char ct[15],c, * words[MAX_NUM];
	char ffrom[]="D:\\org.dat";
	char fto[]="D:\\new.txt";
	FILE * fp;
	fp=fopen(ffrom,"r");
	//�����ַ�ָ������ĳ�ʼ����֪����û������ʲô�õĽ������
	for(;i<MAX_NUM;i++)//��ʼ���ַ������鶼��"0"
	{
		words[i]=(char *)malloc(2);
		strcpy(words[i],"0");
	}
	i=0;
	if(fp==NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		if(c==' ')//��ȡ��һ�����ʽ��д���,�����ٴ���һ��������Ҫ�����ٴ���
		{
			f=0;
			ct[j]='\0';
			if(!checkstr(words,MAX_NUM,ct,15))//�жϸõ����Ƿ���Ҫ����
			{
				words[i]=(char *)malloc(sizeof(char)*(strlen(ct)+1));//Ϊ�ַ�ָ�봴���ڴ�ռ�
				strcpy(words[i],ct);
				i++;
			}		
		}else if(f==0)//�¿�ʼ��ȡ���ʵĵ�һ���ַ�
		{
			f=1;
			j=0;
			memset(ct,'\0',sizeof(ct));//����ַ�����
			ct[j]=c;
			j++;
		
		}else//���ʶ�ȡ��,���������ַ��洢���ַ�������
		{
			ct[j]=c;
			j++;	
		}
		c=fgetc(fp);
	}
	//�����ٴ������һ������
	ct[j]='\0';
	if(!checkstr(words,MAX_NUM,ct,15))
	{
		words[i]=(char *)malloc(sizeof(char)*strlen(ct));
		strcpy(words[i],ct);
	}
	fclose(fp);

	fp=fopen(fto,"w+");
	if(fp==NULL)
	{
		printf("file save error.\n");
		exit(0);
	}
	//���
	for(i=0;i<MAX_NUM;i++)
	{
		if(strcmp(words[i],"0")==0)
		{
			break;
		}
		*words[i]=toupper(*words[i]);
		printf("%s\n",words[i]);
		fprintf(fp,"%s\n",words[i]);
	}
	fclose(fp);



}