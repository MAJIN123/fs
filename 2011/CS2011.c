#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//判断是否为素数
int isprime(long n)
{
	int i,j;
	j=sqrt(n);
	for(i=2;i<=j;i++)
	{
		if(n%i==0)
		{
			break;
		}
	}
	if(i>j)
	{
		return 1;
	}else
	{
		return 0;
	}

}

//判断整数是否为2011年苏大复试所要求的素数类型
int isspeprime(int m)
{
	int i,j,k,l;//分别存储四位数字
	if(!isprime(m))//先判断该数是否为素数
	{
		return 0;
	}
	i=m/1000;//千
	j=(m/100)%10;//百
	k=(m%100)/10;//十
	l=m%10;//个
	if(!isprime(k*10+l))//十位数和个位数组成的数是素数
	{
		return 0;
	}
	if(!isprime(j*10+l))//百位数和个位数组成的数是素数
	{
		return 0;
	}
	if(!isprime(i*10+j))//千位数和百位数组成的数是素数
	{
		return 0;
	}
	if(!isprime(i*10+k))//千位数和十位数组成的数是素数
	{
		return 0;
	}
	return 1;
}

//判断一个字符是否为正常可能出现在一篇文章中的字符
//一个合理的解密算法是需要进行单词检测的，或者使用正则表达式进行简单的格式判定
int isnormalchar(char c)
{
	//只简单的考虑这几种情况

	if(!isprint(c))//不可打印的字符
	{
		return 0;
	}
	
	if(isalnum(c)||isspace(c)||c=='\''||c=='\"'||c=='!'||c==','||c=='.'||c==":"||c=="?")//判断是否是字母、数字、常用标点符号
	{
		return 1;
	}
	else
	{
		return 0;
	}


	/*
	if(c==' '||c=='\''||c=='\"'||c=='!'||c==','||c=='.'||c==":"||c=="?"||(c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
	{
		return 1;
	}else
	{
		return 0;
	}
	
	if((c>=32&&c<=126)||c==10)//常用字符，数字，字母
	{
		return 1;
	}else
	{
		return 0;
	}
	*/

}


void main()
{
	

	
	//2011年上机复试题
	//第二道： 
	//从ftp上下载一个文本info.txt，其中是一段关于计算机历史的英文文档（不过是加过密的，打开看全是乱码），
	//要求密钥cip1和cip2以及解密后的第一个句子。条件：
	//(1)cip1和cip2都是八位无符号整数；
	//(2)加密过程：每次从文本中读出八位字符，然后将该字符和密钥交替异或便是该位置的密文。
	//如第0个字节与cip1异或，第1个字节和cip2异或，第3个字节和cip1异或，。。。，如此循环至结束。
	//最后输出cip1和cip2以及第一段完整的英文句子。
	int cp1,cp2,flag,count=0;
	char c,ct,* cp,fname[]="D:\\info.txt";
	int i,j,k;
	FILE * fp;

	//生成一个用于测试的密文文档
	//cp="Good morning,dear professors.It's my great honor to have this chance to be here for this interview.First,I would like to briefly introduce myself.";
	//cp1=5;
	//cp2=19;
	//fp=fopen(fname,"w+");
	//i=1;
	//while(*cp!='\0')
	//{
	//	if(i%2!=0)
	//	{
	//		c=*cp^cp1;
	//	}else
	//	{
	//		c=*cp^cp2;
	//	}
	//	fputc(c,fp);
	//	i++;
	//	cp++;
	//}
	//fclose(fp);
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	for(i=1;i<256;i++)//八位的无符号数的取值范围，进行暴力破解测试
	{
		for(j=1;j<256;j++)
		{
			cp1=i;cp2=j;k=1;
			flag=1;//测试的密钥是否可用
			rewind(fp);//fp指针重新回到文件开头
			c=fgetc(fp);
			while(c!=EOF)
			{
				if(k%2!=0)//奇数字节用第一个密钥
				{
					ct=c^cp1;
				}else
				{
					ct=c^cp2;
				}
				if(!isnormalchar(ct))
				{
					flag=0;//密钥不对
					break;//结束本次解密测试
				}
				c=fgetc(fp);
				k++;
			}
			if(flag)
			{
				count++;//可能密钥组合计数
				printf("Possible secret keys %d:\n",count);
				printf("cp1=%d,cp2=%d\n",cp1,cp2);
				printf("The first sentence:\n");
				k=1;
				rewind(fp);//fp指针重新回到文件开头
				c=fgetc(fp);//输出使用该组密钥解密的第一个句子
				while(c!=EOF)
				{
					if(k%2!=0)//奇数字节用第一个密钥
					{
						ct=c^cp1;
					}else
					{
						ct=c^cp2;
					}
					if(ct=='.'||ct=='!')//句子之间的分割符
					{
						printf("%c",ct);
						break;
					}else
					{
						
						printf("%c",ct);
						c=fgetc(fp);
						k++;
					}
				}
				printf("\n");
			}
		
		}
	
	}
	fclose(fp);


	


	/*
	//2011年上机复试题
	//第一道：输出1000~9999中满足一下条件的所有数：
	//(1)该数是素数
	//(2)十位数和个位数组成的数是素数，百位数和个位数组成的数是素数
	//(3)千位数和百位数组成的数是素数，千位数和十位数组成的数是素数
	//比如1991，千位和十位组成的数就是19
	int i=1000;
	for(;i<10000;i++)
	{
		if(isspeprime(i))
		{
			printf("%d\t",i);
		}
	}
	*/

}