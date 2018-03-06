#include <stdio.h>
#include <math.h>
#define SU_LEN 2048


//�Ӵ�С������Ƚ��㷨
int cmpnumbts(const void * p1,const void * p2)
{
	return *(int *)p1>*(int *)p2?-1:1;
}

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



void main()
{


	//2010���ϻ�������
	//1��FTP������make.exe��org.dat������make.exe����׼��֤����λ����data.txt���ļ�Ϊ�����Ʊ���
	//2��data.txt�ڴ���2048������������ǰn��Ϊ��0������2048-n����Ϊ0������������飬����������ĸ���n
	//3��ѡ��n�����е������&��С��
	//4��ѡ��n�������������
	//5����n�����Ӵ�С���򣬲�ƽ���ֳ�3�Σ���n��3�����������򲻿�������1~2��������ѡ���м�ε����������С��
	int i,n,t,max,min,maxprime,nums[SU_LEN],maxmid,minmid,m;
	FILE * fp;
	char fname[]="D:\\data.txt";

//����һ�����Ե��ļ�
//	memset(nums,0,sizeof(nums));//����Ԫ�س�ʼ��Ϊ0
//	for(i=0;i<500;i++)
//	{
//		nums[i]=i;
//	}
//	fp=fopen(fname,"wb+");
//	fwrite(nums,sizeof(int),SU_LEN,fp);
//	fclose(fp);


	fp=fopen(fname,"rb");
	if(fp==NULL)
	{
		printf("file open error.\n");
		exit(0);
	}
	memset(nums,0,sizeof(nums));//����Ԫ�س�ʼ��Ϊ0
	fread(nums,sizeof(int),SU_LEN,fp);//����SU_LEN��������������
	fclose(fp);
	for(i=n=max=min=maxprime=0;i<SU_LEN;i++)
	{
		if(nums[i]>0)
		{
			if(min==0)//�ж��Ƿ��Ѿ���ֵ������Сֵ
			{
				min=nums[i];
			}
			if(max==0)
			{
				max=nums[i];
			}
			n++;//����������
			if(nums[i]>max)//�����
			{
				max=nums[i];
			}
			if(nums[i]<min)//��С��
			{
				min=nums[i];
			}
			if(isprime(nums[i]))//�Ƿ�����
			{
				if(nums[i]>maxprime)//�������
				{
					maxprime=nums[i];
				}
			}


		}
	}

	//��������Ӵ�С
	qsort(nums,SU_LEN,sizeof(int),cmpnumbts);

	//��������зֶΣ��ȷ����������n�Ƿ�Ϊ3�ı����������3�ȷֵ�ÿ��Ԫ�ظ�����
	//�����Ѿ���������дӴ�С��������ǰn������Ԫ�ؼ�Ϊ�����n��Ԫ�أ���ÿ�η���ĵ�һ��Ԫ�������ֵ�����һ��Ԫ������Сֵ
	m=n;
	while(m%3!=0)//�ҳ����Եȷֵ���Ԫ�ظ���,������������1~2����
	{
		m--;
	}
	m=m/3;//ÿ�ε�Ԫ�ظ���
	maxmid=nums[m];//�м�ε������
	minmid=nums[m*2-1];//�м�ε���С��
	
	printf("Total number:%d\nThe Max number is:%d\nThe min number is:%d\nThe max prime number is:%d\nThe max number in middle section is:%d\nThe min number in middle section is:%d\n",n,max,min,maxprime,maxmid,minmid);
	

}