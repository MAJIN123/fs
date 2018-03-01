#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

//�ж������Ƿ�Ϊ2011���մ�����Ҫ�����������
int isspeprime(int m)
{
	int i,j,k,l;//�ֱ�洢��λ����
	if(!isprime(m))//���жϸ����Ƿ�Ϊ����
	{
		return 0;
	}
	i=m/1000;//ǧ
	j=(m/100)%10;//��
	k=(m%100)/10;//ʮ
	l=m%10;//��
	if(!isprime(k*10+l))//ʮλ���͸�λ����ɵ���������
	{
		return 0;
	}
	if(!isprime(j*10+l))//��λ���͸�λ����ɵ���������
	{
		return 0;
	}
	if(!isprime(i*10+j))//ǧλ���Ͱ�λ����ɵ���������
	{
		return 0;
	}
	if(!isprime(i*10+k))//ǧλ����ʮλ����ɵ���������
	{
		return 0;
	}
	return 1;
}

//�ж�һ���ַ��Ƿ�Ϊ�������ܳ�����һƪ�����е��ַ�
//һ������Ľ����㷨����Ҫ���е��ʼ��ģ�����ʹ��������ʽ���м򵥵ĸ�ʽ�ж�
int isnormalchar(char c)
{
	//ֻ�򵥵Ŀ����⼸�����

	if(!isprint(c))//���ɴ�ӡ���ַ�
	{
		return 0;
	}
	
	if(isalnum(c)||isspace(c)||c=='\''||c=='\"'||c=='!'||c==','||c=='.'||c==":"||c=="?")//�ж��Ƿ�����ĸ�����֡����ñ�����
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
	
	if((c>=32&&c<=126)||c==10)//�����ַ������֣���ĸ
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
	

	
	//2011���ϻ�������
	//�ڶ����� 
	//��ftp������һ���ı�info.txt��������һ�ι��ڼ������ʷ��Ӣ���ĵ��������Ǽӹ��ܵģ��򿪿�ȫ�����룩��
	//Ҫ����Կcip1��cip2�Լ����ܺ�ĵ�һ�����ӡ�������
	//(1)cip1��cip2���ǰ�λ�޷���������
	//(2)���ܹ��̣�ÿ�δ��ı��ж�����λ�ַ���Ȼ�󽫸��ַ�����Կ���������Ǹ�λ�õ����ġ�
	//���0���ֽ���cip1��򣬵�1���ֽں�cip2��򣬵�3���ֽں�cip1��򣬡����������ѭ����������
	//������cip1��cip2�Լ���һ��������Ӣ�ľ��ӡ�
	int cp1,cp2,flag,count=0;
	char c,ct,* cp,fname[]="D:\\info.txt";
	int i,j,k;
	FILE * fp;

	//����һ�����ڲ��Ե������ĵ�
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
	for(i=1;i<256;i++)//��λ���޷�������ȡֵ��Χ�����б����ƽ����
	{
		for(j=1;j<256;j++)
		{
			cp1=i;cp2=j;k=1;
			flag=1;//���Ե���Կ�Ƿ����
			rewind(fp);//fpָ�����»ص��ļ���ͷ
			c=fgetc(fp);
			while(c!=EOF)
			{
				if(k%2!=0)//�����ֽ��õ�һ����Կ
				{
					ct=c^cp1;
				}else
				{
					ct=c^cp2;
				}
				if(!isnormalchar(ct))
				{
					flag=0;//��Կ����
					break;//�������ν��ܲ���
				}
				c=fgetc(fp);
				k++;
			}
			if(flag)
			{
				count++;//������Կ��ϼ���
				printf("Possible secret keys %d:\n",count);
				printf("cp1=%d,cp2=%d\n",cp1,cp2);
				printf("The first sentence:\n");
				k=1;
				rewind(fp);//fpָ�����»ص��ļ���ͷ
				c=fgetc(fp);//���ʹ�ø�����Կ���ܵĵ�һ������
				while(c!=EOF)
				{
					if(k%2!=0)//�����ֽ��õ�һ����Կ
					{
						ct=c^cp1;
					}else
					{
						ct=c^cp2;
					}
					if(ct=='.'||ct=='!')//����֮��ķָ��
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
	//2011���ϻ�������
	//��һ�������1000~9999������һ����������������
	//(1)����������
	//(2)ʮλ���͸�λ����ɵ�������������λ���͸�λ����ɵ���������
	//(3)ǧλ���Ͱ�λ����ɵ�����������ǧλ����ʮλ����ɵ���������
	//����1991��ǧλ��ʮλ��ɵ�������19
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