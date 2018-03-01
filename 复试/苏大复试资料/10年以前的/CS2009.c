#include <stdio.h>
#define MAX_NUM 20


//将一个字符数组转换成十进制数字
int transnum(char c[],int n)
{
	int t=0,i=0,k;//k为进制的权
	if(c[i]=='0')//如果是八进制数
	{
		k=8;
		i++;//数字的值不计算标识0
	}else
	{
		k=10;
	}
	for(;i<n&&c[i]!='\0';i++)
	{
		t=t*k+(c[i]-48);//字符0的ANSIC的值为48，将字符0~9转换成数字0~9的方法就是让字符的ansic值减48
	}
	return t;
}
//从大到小的排序比较算法
int cmpnumbts(const void * p1,const void * p2)
{
	return *(int *)p1>*(int *)p2?-1:1;
}

void main()
{

	//2009年苏大上机题目
	//（1）用IE浏览器从FTP上下载org.dat，并保存在D盘的根目录下。
	//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的十进制或八进制数字，数字之间用“,”分开，数字内部存在且仅存在空格。
	//（3）八进制数以起始位“0”作为标示与十进制数区分。
	//（4）顺序读取这些数字将他们转变为十进制数后按从大到小的顺序排序后，输出到D盘根目录下new.txt，每个数字一行。
	//eg：_235_,34__2,_043_1_,1_3   分别是：十进制235，十进制342.，八进制431，十进制13。_代表空格
	int f=1,i=0,j=0,num[MAX_NUM];//标识f=1为一个数字读取中f=0为一个数字的结束与新数字的开始，数组num用于保存所有经转换的十进制数字
	char ct[15],c;
	FILE * fp;
	memset(num,-1,sizeof(num));//从内存设置数组元素初始值为-1
	fp=fopen("d:\\org.dat","r");
	if(fp==NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		
		if(c==',')//读取完一个数字进行处理,最后会少处理一个数字需要单独再处理
		{
			f=0;
			ct[j]='\0';
			num[i]=transnum(ct,15);
			
		}else if(f==0)//新开始读取数字的第一个字符
		{
			f=1;
			i++;//i用于num数组的下标，也可用于数字个数的计数，新开始读取一个数字的时候i++
			j=0;
			memset(ct,'\0',sizeof(ct));//清空字符数组
			if(c!=' ')//剔除空格
			{
				ct[j]=c;
				j++;
			}
		}else//数字读取中,将读到的字符存储在字符数组中
		{
			if(c!=' ')//剔除空格
			{
				ct[j]=c;
				j++;
			}
		}
		c=fgetc(fp);
	}
	//单独再处理最后一个数字，因为最后一个数字后面没有逗号
	ct[j]='\0';
	num[i]=transnum(ct,15);
	fclose(fp);
	
	//数组排序从大到小
	//数组排序问题，利用qsort函数,qsort函数原型参数说明：
	//void qsort(void * base,size_t num,size_t width,int (_cdecl* compare)(const void *,const void *)
	//base:需要排序的目标数组开始地址
	//num:目标数组元素个数
	//width:目标数组中每一个元素的长度
	//compare:函数指针，指向比较函数
	//compare函数需要自己写，返回值类型为int当返回值>0时进行交换，注意函数原型中的参数为const void *
	qsort(num,MAX_NUM,sizeof(int),cmpnumbts);

	fp=fopen("D:\\new.txt","w+");
	if(fp==NULL)
	{
		printf("file save error.\n");
		exit(0);
	}
	for(i=0;i<MAX_NUM;i++)//输出所有元素到文件和屏幕
	{
		if(num[i]>-1)
		{
			printf("%d\n",num[i]);
			fprintf(fp,"%d\n",num[i]);
		}
	}
	fclose(fp);
}