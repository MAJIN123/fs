//2012���մ������ϻ������Ŀ��
	//�ӷ����������������ļ�org.dat�ļ��Զ����Ʒ�ʽ���һϵ��������ÿ������ռ4���ֽڡ��ӵ�һ��������ʼ����һ�������͵ڶ�����������һ������㣬�������ƣ������ļ��б����������������ݡ�
	//����1��
	//�涨���ڵ�һ���޵������Ϊ��Ч�㣬���������ļ������е�ĸ���nΪ���٣���Ч��ĸ���kΪ���٣�
	//����2��
	//ÿ����Ч��������ԭ�㹹��һ���ľ��Σ�����k����Ч��������ԭ�㹹�ɵ�k�����ε���С�����������Ϊ���٣�
	//����3��
	//Ѱ����Ч���з������������ĵ㣺�Ըõ�Ϊ����ԭ�㣬������Ч����Ȼ����Ч�㼴���ڵ�һ���ޣ��������������ϵĵ㣩�������Щ�㡣
	//����4��
	//��������Ч����з��飬ÿ����Ч������ֻ������һ�����飬�����ڵĵ�������й��������������е��x����������򣬵�p1��x1��y1���ڵ�p2��x2��y2�����棬��x1>x2��ôy1>y2.��������еķ��顣
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define LEN 20
struct dot
{
	int x;
	int y;
};
int judge(struct dot a)
{
	if(a.x>0&&a.y>0)
		return 1;
	else
		return 0;
}
int readfile(char *filename,struct dot arr[])
{
	FILE *fp;
	struct dot temp;
	int i=0;
	int total=0;
	fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return -1;
	}
	while(fread(&temp,sizeof(struct dot),1,fp)==1)
	{
		total++;
		if(judge(temp)==1)
		{
			arr[i]=temp;
			i++;
		}

	}
	printf("Total points:%d\nValidate points:%d\n",total,i);
	fclose(fp);
	return i;//���ص���������Ч����
}
int cal_mins(struct dot arr[],int count)
{
	int xmin=arr[0].x;
	int ymin=arr[0].y;
	for(int i=0;i<count;i++)
	{
		if(arr[i].x<xmin)
			xmin=arr[i].x;
		if(arr[i].y<ymin)
			ymin=arr[i].y;
	}
	return (xmin*ymin);
}
int judge2(struct dot a,struct dot b)//aΪԭ��
{
	if(b.x>a.x&&b.y>a.y)
		return 1;
	else
		return 0;
}
void fun3(struct dot arr[],int count)
{
	int flag;
	for(int i=0;i<count;i++)
	{
		flag=1;
		for(int j=0;j<count;j++)
		{
			if(i==j)
				continue;
			if(judge2(arr[i],arr[j])==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("(%d,%d)\n",arr[i].x,arr[i].y);
		}
	}
}
void sort(struct dot arr[],int count)
{
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(arr[i].x>arr[j].x)
			{
				struct dot temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void fun4(struct dot arr[],int count)
{
	int count=0;
	int t;
	sort(arr,count);
	int *flags=(int *)malloc(count*sizeof(int));
	memset(flags,0,sizeof(flags));
	for(int i=0;i<count;i++)
	{
		if(flags[i]==0)
		{
		    flags[i]=1;//���÷����־Ϊ1��ʾ�Ѿ�����
			count++;//��ż�1
			printf("\nGroup %d:",count);//��ʾ��ʼһ���µķ�����������
			printf("(%d,%d)\t",arr[i].x,arr[i].y);//����÷����еĵ�һ������
			t=i;//���ø����±�Ϊi
			for(int j=i+1;j<count;j++)
			{
				if(flags[j])//���������Ѿ��з���ͽ������ε��ж�
				{
					continue;
				}
				if(arr[t].y<arr[j].y)//����������÷��������һ��������бȽϣ��ж��Ƿ���Ի�Ϊ����
				{
					flags[j]=1;//���Ի��ֵ����飬���ø�����ķ����־Ϊ1
					printf("(%d,%d)\t",arr[j].x,arr[j].y);//����õ�
					t=j;//�´αȽϵ���������Ϊ�õ�
				}
			}
		}
	}
}