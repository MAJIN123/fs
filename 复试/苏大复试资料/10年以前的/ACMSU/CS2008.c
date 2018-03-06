#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 30


//判断字符数组中的单词是否是要排除的单词THE及其变形,或者已经包含该单词
int checkstr(char * words[],int m,char ct[],int n)
{
	char * cp;
	int i=0;
	//先判断是否是THE的变形
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


	//2008年苏大上机题目
	//（1）用IE从FTP上下载org.dat，并保存在D盘的根目录中。
	//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的英文单词，单词之间用空格分开，无其他符号。
	//（3）顺序读取这段文章的不同的单词（大小写敏感），同时在读取的过程中排除所有的单词THE以及变形，即这些单词不能出现在读取的结果中。
	//（4）将读取的所有单词的首字母转大写后，输出D根目录下new.txt，每个单词一行。
	//那段文字可以点右键打开方式中用记事本打开，内容是：
	//The constructor is used to initialize the object The destructor is
	//used to delete the Object the calling sequence of constructor is opposite to the calling sequence of destructor
	//正确结果应该是
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
	//注意有两个Object
	//因为第一次读取是大小写敏感的，后来又进行了首字母大写转化
	//08年和09年的题目非常相似，只是在信息的处理方式上有所不同
	int f=1,i=0,j=0;//标识f=1为一个单词读取中f=0为一个单词的结束与新单词的开始
	char ct[15],c, * words[MAX_NUM];
	char ffrom[]="D:\\org.dat";
	char fto[]="D:\\new.txt";
	FILE * fp;
	fp=fopen(ffrom,"r");
	//对于字符指针数组的初始化不知道有没有其他什么好的解决方案
	for(;i<MAX_NUM;i++)//初始化字符串数组都是"0"
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
		if(c==' ')//读取完一个单词进行处理,最后会少处理一个单词需要单独再处理
		{
			f=0;
			ct[j]='\0';
			if(!checkstr(words,MAX_NUM,ct,15))//判断该单词是否需要保存
			{
				words[i]=(char *)malloc(sizeof(char)*(strlen(ct)+1));//为字符指针创建内存空间
				strcpy(words[i],ct);
				i++;
			}		
		}else if(f==0)//新开始读取单词的第一个字符
		{
			f=1;
			j=0;
			memset(ct,'\0',sizeof(ct));//清空字符数组
			ct[j]=c;
			j++;
		
		}else//单词读取中,将读到的字符存储在字符数组中
		{
			ct[j]=c;
			j++;	
		}
		c=fgetc(fp);
	}
	//单独再处理最后一个单词
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
	//输出
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