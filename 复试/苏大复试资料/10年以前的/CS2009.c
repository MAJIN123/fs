#include <stdio.h>
#define MAX_NUM 20


//��һ���ַ�����ת����ʮ��������
int transnum(char c[],int n)
{
	int t=0,i=0,k;//kΪ���Ƶ�Ȩ
	if(c[i]=='0')//����ǰ˽�����
	{
		k=8;
		i++;//���ֵ�ֵ�������ʶ0
	}else
	{
		k=10;
	}
	for(;i<n&&c[i]!='\0';i++)
	{
		t=t*k+(c[i]-48);//�ַ�0��ANSIC��ֵΪ48�����ַ�0~9ת��������0~9�ķ����������ַ���ansicֵ��48
	}
	return t;
}
//�Ӵ�С������Ƚ��㷨
int cmpnumbts(const void * p1,const void * p2)
{
	return *(int *)p1>*(int *)p2?-1:1;
}

void main()
{

	//2009���մ��ϻ���Ŀ
	//��1����IE�������FTP������org.dat����������D�̵ĸ�Ŀ¼�¡�
	//��2�����ļ��а��ı���ʽ�����һ���������£����������ɳ���С��15��ʮ���ƻ�˽������֣�����֮���á�,���ֿ��������ڲ������ҽ����ڿո�
	//��3���˽���������ʼλ��0����Ϊ��ʾ��ʮ���������֡�
	//��4��˳���ȡ��Щ���ֽ�����ת��Ϊʮ�������󰴴Ӵ�С��˳������������D�̸�Ŀ¼��new.txt��ÿ������һ�С�
	//eg��_235_,34__2,_043_1_,1_3   �ֱ��ǣ�ʮ����235��ʮ����342.���˽���431��ʮ����13��_����ո�
	int f=1,i=0,j=0,num[MAX_NUM];//��ʶf=1Ϊһ�����ֶ�ȡ��f=0Ϊһ�����ֵĽ����������ֵĿ�ʼ������num���ڱ������о�ת����ʮ��������
	char ct[15],c;
	FILE * fp;
	memset(num,-1,sizeof(num));//���ڴ���������Ԫ�س�ʼֵΪ-1
	fp=fopen("d:\\org.dat","r");
	if(fp==NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		
		if(c==',')//��ȡ��һ�����ֽ��д���,�����ٴ���һ��������Ҫ�����ٴ���
		{
			f=0;
			ct[j]='\0';
			num[i]=transnum(ct,15);
			
		}else if(f==0)//�¿�ʼ��ȡ���ֵĵ�һ���ַ�
		{
			f=1;
			i++;//i����num������±꣬Ҳ���������ָ����ļ������¿�ʼ��ȡһ�����ֵ�ʱ��i++
			j=0;
			memset(ct,'\0',sizeof(ct));//����ַ�����
			if(c!=' ')//�޳��ո�
			{
				ct[j]=c;
				j++;
			}
		}else//���ֶ�ȡ��,���������ַ��洢���ַ�������
		{
			if(c!=' ')//�޳��ո�
			{
				ct[j]=c;
				j++;
			}
		}
		c=fgetc(fp);
	}
	//�����ٴ������һ�����֣���Ϊ���һ�����ֺ���û�ж���
	ct[j]='\0';
	num[i]=transnum(ct,15);
	fclose(fp);
	
	//��������Ӵ�С
	//�����������⣬����qsort����,qsort����ԭ�Ͳ���˵����
	//void qsort(void * base,size_t num,size_t width,int (_cdecl* compare)(const void *,const void *)
	//base:��Ҫ�����Ŀ�����鿪ʼ��ַ
	//num:Ŀ������Ԫ�ظ���
	//width:Ŀ��������ÿһ��Ԫ�صĳ���
	//compare:����ָ�룬ָ��ȽϺ���
	//compare������Ҫ�Լ�д������ֵ����Ϊint������ֵ>0ʱ���н�����ע�⺯��ԭ���еĲ���Ϊconst void *
	qsort(num,MAX_NUM,sizeof(int),cmpnumbts);

	fp=fopen("D:\\new.txt","w+");
	if(fp==NULL)
	{
		printf("file save error.\n");
		exit(0);
	}
	for(i=0;i<MAX_NUM;i++)//�������Ԫ�ص��ļ�����Ļ
	{
		if(num[i]>-1)
		{
			printf("%d\n",num[i]);
			fprintf(fp,"%d\n",num[i]);
		}
	}
	fclose(fp);
}