#include <stdio.h>
#include <math.h>


//�ж��Ƿ�Ϊ����
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

//�ݹ麯������һ������ʾ�����������ĺ�
//���ֲ�ַ����ܼ򵥣�Ч�ʺܵͣ��д��Ż�
void printsplitprime(long m)
{
	long n;
	if(m==3||m==2||m==5||m==7||m==9)
	{
		printf("%ld",m);
		return;
	}
	n=m/2;//Ϊ�˿������������ĸ�����ÿ��Ѱ��С�ڸ���һ����������
	while(!isprime(n))
	{
		n--;
	}
	printf("%ld+",n);
	printsplitprime(m-n);

}

//�ַ�ָ������ȽϷ���
int strpcmp(const void * p1,const void * p2)
{
	return **(char * *)p1-**(char * *)p2;
}


void main()
{

	//2005���ϼ�������
	//��1��  ��һ������ʾ�����ɸ������ĺ�
	//��2��  һ���ݹ�����ǹ������ѡ������˵�����߲���
	//��3��  ͳ��ƪ�����и�Ӣ����ĸ�ĸ�����������
	//��Ŀ���Ǻ��ѣ�������һ��Сʱ�ڰ�������ȫ�����Գ���Ҳ�����װ�!
	
	//������
	//����Ŀ��Ҫ����ϸ��Ҫ������ֻ��д��Ŀ���������Ĺ���1.��ĸ����2.����
	FILE * fp;
	char fname[]="D:\\org.dat",c;
	int count=0,i;
	char * strs[5]={"Hello","Help","micy","C programe","test"};

	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		if((c>'A'&&c<'Z')||(c>'a'&&c<'z'))
		{
			count++;//�����Ӣ����ĸ�����
			//���������������������
		}
		c=fgetc(fp);
	}
	fclose(fp);
	printf("Totle character:%d\n",count);
	
	//�ַ�������
	qsort(strs,5,sizeof(char *),strpcmp);

	for(i=0;i<5;i++)
	{
		printf("%s\n",strs[i]);

	}

	//�ڶ������д�Ѱ�Ҹ���ϸ����ĿҪ��


	/*
	//��һ����
	long m,n,t;
	int i;
	printf("please input the number:\n");
	scanf("%ld",&m);
	printf("%ld=",m);
	printsplitprime(m);
	*/
	
	
}