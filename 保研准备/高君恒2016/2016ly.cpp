//姓名：李颖	
//学号:1427407025
//具体解决思路描述：
//0.请从服务器将两个数据文件input.txt和words.txt下载到本地电脑的D盘根文件夹。
//1.在D盘根文件夹的words.txt中存储了不超过30000条的英文单词，每个单词占一行。单词的最大长度为20，且单词内部没有空格，文件中无重复单词。图1是该文件的一个局部样例：
//2.在D盘根文件夹的input.txt中存储了一个“丢失”了空格和标点符号的英文文章。每行不超过128个字符，请编写程序把该文章中的前三行显示在屏幕上。（第一行和最后一行）
//3.编写程序将words.txt中的最后三行显示在屏幕上；（不做）
//4.编写程序利用words.txt中的单词作为词典，采用正向最大匹配切分单词算法对input.txt中的文本进行单词切分。切分时单词区分大小写，切分分割标记采用空格，并将切分后的结果写入到out.txt中。
//所谓正向最大匹配切分就是从左向右扫描待切分字符串，尽量取长词，该算法流程图参见图2。
//下面举一个简单例子：现有待切分字符串 “ABCDEFGHIJ”，设词典中最大单词长度为5。那么按照算法首先取出“ABCDE”判断是否是单词，如果是则切分到一个单词，否则舍弃最后一个字母接着判断，也就是判断“ABCD”是否是单词，依此类推，当只有一个字母时可以直接认定为是单词。在成功切分出一个单词后对待切分字符串余下的部分再次执行上述过程。
//5.编写程序实现步骤2、3描述的要求，并通过如下所示的主函数对进行验证，注意：除了指定添加的代码之外，不得修改main函数其余部分。对main函数每修改一处，总分扣3分，最多扣10分。
//6.本次考试考核C语言程序设计，因此不可以使用C++的STL的任何功能，如果需要添加下面样例之外的程序头文件，请举手得到监考老师批准。
#include <time.h>
#include <stdio.h>
#include <string.h>
#define SIZE 30000
//=====================================
//该函数用于显示文件的第一行和最后一行
//参数为char型指针，指向文件名
//无返回值
//=====================================
void showFirstAndLastLine(char *filename)
{
	FILE *fp;
	char line[256];

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	if(fgets(line,130,fp)==NULL)    //读文件第一行
	{
		printf("Can not read the file!\n");
		return;
	}
	printf("First Line: %s",line);
	while(fgets(line,130,fp)!=NULL);//一直读到文件尾
	printf("Last Line: %s\n",line);//打印最后一行
	fclose(fp);//关文件
}
//==================================================
//该函数用于将单词文件内容读取到二维数组中
//参数为char型指针，指向文件名，以及二维数组首行地址
//返回值为读到的单词个数
//==================================================
int ReadWords(char *filename,char words[][24])
{
	FILE *fp;
	int i=0;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return -1;
	}
	while(fgets(words[i],24,fp)!=NULL)//循环读到文件尾
	{
		i++;
	}
	for(int j=0;j<i-1;j++) //把每个单词最后的'\n'去掉（除了最后一个单词没有）
	{
		words[j][strlen(words[j])-1]='\0';
	}
	fclose(fp);
	return i;//返回读到的单词个数
}
//==========================================================
//该函数用于显示二维数组的最后lastlines行
//参数为二维数组首行地址，二维数组有效的行数，以及lastlines
//无返回值
//==========================================================
void Display(char words[][24],int count,int lastlines)
{
	printf("单词表最后%d行为：\n",lastlines);
	for(int i=count-lastlines;i<=count-1;i++)
	{
		printf("%s",words[i]);
		printf("\n");
	}
}
//======================================================================================
//该函数用于切分一行字符串并将切分好的字符串放入文件
//参数为一位数组指针（指向要切分的字符串），文件指针，以及二维数组首行指针，int型计数变量
//无返回值
//=======================================================================================
void split(char *arr,FILE *fp,char words[][24],int count)
{
	int start=0;
	int end=strlen(arr)-1;
	char temp[21]={'\0'};   //最大单词长度是20,所以用于存放切分下来的字符数组长度为21（最后一位'\0'）足够
	while(start<=end)       //当start<=end的时候执行循环
	{
		int i;
		for(i=start;(i<start+20)&&arr[i]!='\0';i++)  //将一行中不超过最大长度20的子串放到temp中
		{
			temp[i-start]=arr[i];
			temp[i-start+1]='\0';
		}
		loop1:
		if(strlen(temp)==1)                          //temp长度为1则它一定是一个单词，把他写入文件（别忘了单词后面加上空格），并将start大小加上temp的长度1，从而进入下一轮循环
		{
			fprintf(fp,"%s ",temp);
			//printf("%s ",temp);
			start=start+strlen(temp);
		}
		else                                         //temp长度不为1，则要开始判断了
		{
			int j;
			//int begin=0;
			//int stop;
			int flag=0;
			//while(strlen(temp)>strlen(words[begin]))//经过该while循环后word[begin]为第一个长度与temp相同的单词单词表竟然不全是按长度排的!!!!生气
			//{
			//	begin++;
			//}
			//stop=begin;
			//while(strlen(temp)>=strlen(words[stop]))//经过该while循环后word[stop]为第一个长度大于temp的单词
			//{
			//	stop++;
			//}
			for(j=0;j<count;j++)                     //将temp与单词表里的单词依次比较（这里应该可以优化。。。有点慢）
			{

				if(strcmp(temp,words[j])==0)//temp是单词
				{
					flag=1;
					break;
				}
			}
			if(flag==1)//temp是单词，把他写入文件（别忘了单词后面加上空格），并将start大小加上temp的长度，从而进入下一轮循环
			{
				fprintf(fp,"%s ",temp);
				//printf("%s ",temp);
			    start=start+strlen(temp);
			}
			else//temp不是单词，去掉temp最右边一个单词，跳到判断temp是否为1的语句
			{
				temp[strlen(temp)-1]='\0';//去掉temp最右边一个单词
				goto loop1;
			}
		}

	}
	fprintf(fp,"\n");
	//printf("\n");
}
//======================================================================================
//该函数用于切分一行字符串并将切分好的字符串放入文件（想试试没有goto语句的）
//参数为一位数组指针（指向要切分的字符串），文件指针，以及二维数组首行指针，int型计数变量
//无返回值
//=======================================================================================
void split1(char *arr,FILE *fp,char words[][24],int count)
{
	int start=0;
	int end=strlen(arr)-1;
	char temp[21]={'\0'};   //最大单词长度是20,所以用于存放切分下来的字符数组长度为21（最后一位'\0'）足够
	while(start<=end)       //当start<=end的时候执行循环
	{
		int i;
		for(i=start;(i<start+20)&&arr[i]!='\0';i++)  //将一行中不超过最大长度20的子串放到temp中
		{
			temp[i-start]=arr[i];
			temp[i-start+1]='\0';
		}
		//loop1:
		while(strlen(temp)!=1)
		{
			int j;
			//int begin=0;
			//int stop;
			int flag=0;
			//while(strlen(temp)>strlen(words[begin]))//经过该while循环后word[begin]为第一个长度与temp相同的单词单词表竟然不全是按长度排的!!!!生气
			//{
			//	begin++;
			//}
			//stop=begin;
			//while(strlen(temp)>=strlen(words[stop]))//经过该while循环后word[stop]为第一个长度大于temp的单词
			//{
			//	stop++;
			//}
			for(j=0;j<count;j++)                     //将temp与单词表里的单词依次比较（这里应该可以优化。。。有点慢）
			{

				if(strcmp(temp,words[j])==0)//temp是单词
				{
					flag=1;
					break;
				}
			}
			if(flag==1)//temp是单词，把他写入文件（别忘了单词后面加上空格），并将start大小加上temp的长度，从而进入下一轮循环
			{
				fprintf(fp,"%s ",temp);
				//printf("%s ",temp);
			    start=start+strlen(temp);
				break;
			}
			else//temp不是单词，去掉temp最右边一个单词，跳到判断temp是否为1的语句
			{
				temp[strlen(temp)-1]='\0';//去掉temp最右边一个单词
				//goto loop1;
			}
		}
		if(strlen(temp)==1)                          //temp长度为1则它一定是一个单词，把他写入文件（别忘了单词后面加上空格），并将start大小加上temp的长度1，从而进入下一轮循环
		{
			fprintf(fp,"%s ",temp);
			//printf("%s ",temp);
			start=start+strlen(temp);
		}
	}
	fprintf(fp,"\n");
	//printf("\n");
}
//======================================================================================
//该函数用于利用words.txt中的单词作为词典，
//采用正向最大匹配切分单词算法对input.txt中的文本进行单词切分。
//切分时单词区分大小写，切分分割标记采用空格，并将切分后的结果写入到out.txt中。
//参数为输入文件名，输出文件名，以及二维数组首行指针，int型计数变量
//无返回值
//=======================================================================================
void WriteFile(char*filename1,char *filename2,char words[][24],int count)
{
	FILE *fp,*fp2;
	char line[256];           //存放从文件中读取的一行字符串
	fp=fopen(filename1,"r");  //打开文件
	fp2=fopen(filename2,"w");//打开文件
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	if(fp2==NULL)
	{
		printf("Can not open the file to write!\n");
		return;
	}
	while(fgets(line,130,fp)!=NULL)//一直读到文件尾
	{
		if(line[strlen(line)-1]=='\n')//把每一行最后的'\n'去掉！！有'\n'是因为所用函数fgets的原因（除了最后一行没有）不去掉感觉后面挺麻烦的。。。
		{
			line[strlen(line)-1]='\0';
		}
		split1(line,fp2,words,count);//调用split函数，将读取出来的一行字符串切分好放到另一个文件中去
	}
	fclose(fp);//关文件
	fclose(fp2);//关文件
}
int main()
{
	char words[SIZE][24];
	clock_t start, finish;
	start = clock();

	showFirstAndLastLine("d:\\input.txt");
//将input文件的第一行和最后一行显示在屏幕上

	int count = ReadWords("d:\\words.txt", words);
	//读取英文字典，并返回单词数量
	Display(words,count,3);
//此处可以添加处理逻辑以实现题目的第3点要求
//建议将需要的功能实现为多个函数后在此直接或者间接调用
	WriteFile("d:\\input.txt","d:\\out.txt",words,count);
	finish = clock();
	printf("Total time:%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);

    return 0;
}