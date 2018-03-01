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
		else if(j==0)//解决 前几个都是空格 或者在两个单词之间有多个空格的情况
		{
		}
		else
		{
			arr[i][j]='\0';
			//i++;j=0;
			//假如新的单词是the及它的变形，就让i不执行i++，j恢复为0，这样下一个单词存储在原本是the的位置上，相当于去掉了the
			if(strcmp(arr[i],"THE")==0||strcmp(arr[i],"THe")==0||strcmp(arr[i],"ThE")==0||strcmp(arr[i],"The")==0||strcmp(arr[i],"tHE")==0||strcmp(arr[i],"tHe")==0||strcmp(arr[i],"thE")==0||strcmp(arr[i],"the")==0)
			{
				j=0;
				continue;//不continue继续执行下面的可能还会导致i++
			}
			int k;
			for(k=0;k<i;k++)
			{
				if(strcmp(arr[i],arr[k])==0)//有重复的单词就break
				{
					break;
				}
			}
			if(k<i)   //有重复单词执行跟遇到the一样的处理
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
	return i;//读取到多少单词
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
		strcpy(temp,strlwr(arr[i]));//先全部小写
		temp[0]-=32;//首字母大写
		fprintf(fp,"%s\n",temp);//写到文件里面去
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