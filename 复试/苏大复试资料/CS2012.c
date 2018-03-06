#include <stdio.h>
#include <math.h>
#define MAX_LEN 200


//�����������������
typedef struct {
	int x;
	int y;
}POINT;

//�ж�һ�����Ƿ�Ϊ��Ч��
int isvalpoint(POINT p)
{
	if(p.x>0&&p.y>0)
	{
		return 1;
	}else
	{
		return 0;
	}
}

//��һ��ĺ�����fpΪ�Զ����ƶ�ȡ��ʽ�򿪵��ļ�ָ�룬pointsΪ������Ч������飬pvc���ڱ�����Ч��ĸ���
void fun1(FILE * fp,POINT points[],int * pvc)
{
	POINT temp;
	int tp[2],count;

	printf("---------------fun1---------------\n");
	rewind(fp);//���ļ�ָ�����ã���ָֹ���Ѿ��ƶ���
	count=0;
	*pvc=0;
	while(!feof(fp))
	{
		if(fread(tp,4,2,fp)!=2)//ÿ�ζ�2�������������쳣���˳�
		{
			break;
		}
		temp.x=tp[0];
		temp.y=tp[1];
		count++;
		if(isvalpoint(temp))//�ж��Ƿ�Ϊ��Ч��
		{
			points[*pvc]=temp;
			(*pvc)++;
		}

	}

	printf("Total points:%d\nValidate points:%d\n",count,*pvc);

}

//�ڶ���ĺ�����pointsΪ������Ч������飬nΪ������Ч��ĸ���
void fun2(POINT points[],int n)
{
	int i,minx,miny;
	minx=points[0].x;
	miny=points[0].y;
	for(i=1;i<n;i++)
	{
		if(points[i].x<minx)
		{
			minx=points[i].x;
		}
		if(points[i].y<miny)
		{
			miny=points[i].y;
		}
	}
	printf("---------------fun2---------------\n");
	printf("Minimum public area:%d\n",minx*miny);

}

//���p1�Ƿ�����p2Ϊԭ��ĵ�һ����
int checkpointbypoint(POINT p1,POINT p2)
{
	if(p1.x>p2.x&&p1.y>p2.y)
	{
		return 1;
	}else
	{
		return 0;
	}
}


//������ĺ�����pointsΪ������Ч������飬nΪ������Ч��ĸ���
void fun3(POINT points[],int n)
{
	int i,j,flag=1;
	printf("---------------fun3---------------\nThe right points list:\n");
	for(i=0;i<n;i++)
	{
		flag=1;//��ʼΪ1��ʾ�õ�Ϊ���������ĵ�
		for(j=0;j<n;j++)
		{
			if(i==j)//��ͬ�㲻��Ҫ�Ƚ�
			{
				continue;
			}
			if(!checkpointbypoint(points[j],points[i]))//�������һ���㲻�ڸõ�ĵ�һ���ޣ�������Ըõ���ж�����ʶΪ0
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("(%d,%d)\t",points[i].x,points[i].y);
		}
	}
	printf("\n");
	
}

//����������鰴��x�����С��������
int cmp(const void * p1,const void * p2)
{
	return ((POINT *)p1)->x-((POINT *)p2)->x;
}

//������ĺ�����pointsΪ������Ч������飬nΪ������Ч��ĸ���
void fun4(POINT points[],int n)
{
	int i,j,t,count=0;
	int flags[MAX_LEN];//��־����
	memset(flags,0,sizeof(flags));//��־�����ʼ��Ϊ0��ʾpoints�ж�Ӧ�±���������δ����
	//��points�����������
	qsort(points,n,sizeof(POINT),cmp);
	printf("---------------fun4---------------");
	for(i=0;i<n;i++)//��ÿһ��������ÿһ����������ѭ����ȷ��ÿ���㶼���Լ��ķ���
	{
		if(!flags[i])//�������һ���������δ���з�����ô��������㻮��Ϊһ���µķ���
		{
			flags[i]=1;//���÷����־Ϊ1��ʾ�Ѿ�����
			count++;//��ż�1
			printf("\nGroup %d:",count);//��ʾ��ʼһ���µķ�����������
			printf("(%d,%d)\t",points[i].x,points[i].y);//����÷����еĵ�һ������
			t=i;//���ø����±�Ϊi
		
			for(j=i+1;j<n;j++)//����points�Ѿ�����x����������˴Ӹ���������һ������㿪ʼѭ�����ҿ��Ի�Ϊ����������
			{
				if(flags[j])//���������Ѿ��з���ͽ������ε��ж�
				{
					continue;
				}
				if(points[t].y<points[j].y)//����������÷��������һ��������бȽϣ��ж��Ƿ���Ի�Ϊ����
				{
					flags[j]=1;//���Ի��ֵ����飬���ø�����ķ����־Ϊ1
					printf("(%d,%d)\t",points[j].x,points[j].y);//����õ�
					t=j;//�´αȽϵ���������Ϊ�õ�
				}
			}
		}
	}
	printf("\n");
}


void main()
{
	

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
	//int test[]={1,3,20,4,79,34,12,25,-12,24,37,-19,-44,-6,25,6,22,4,-4,5};
	int valcount=0,* pvc;//valcount���ڱ�����Ч�������
	POINT points[MAX_LEN];//points���ڱ���������Ч��
	FILE * fp;
	char fname[]="D:\\org.dat";
	

	/*
	//���ɲ��������ļ�����test�����е�����д���ļ�
	fp=fopen(fname,"wb+");
	if(fp==NULL)
	{
		printf("file open error!\n");
		exit(0);
	}
	fwrite(test,4,20,fp);
	fclose(fp);
	*/
	
	fp=fopen(fname,"rb+");
	if(fp==NULL)
	{
		printf("file open error!\n");
		exit(0);
	}
	
	//�����һ��Ĵ�
	pvc=&valcount;
	fun1(fp,points,pvc);
	fclose(fp);
	
	//����ڶ���Ĵ�
	fun2(points,*pvc);
	
	//���������Ĵ�
	fun3(points,*pvc);
	
	//���������Ĵ�
	fun4(points,*pvc);

}