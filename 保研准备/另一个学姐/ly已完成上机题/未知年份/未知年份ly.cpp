#define _CRT_SECURE_NO_WARNINGS
#define COUNT 100000
#include <stdio.h>
#include <windows.h>
struct dot
{
	int attr[4];
	int flag;
}arr[COUNT];
void run(void);
int main()
{
	LARGE_INTEGER m_nFreq;
    LARGE_INTEGER m_nBeginTime;
    LARGE_INTEGER m_nEndTime;

    QueryPerformanceFrequency(&m_nFreq);
    QueryPerformanceCounter(&m_nBeginTime);

	run();

    QueryPerformanceCounter(&m_nEndTime);
	printf("\nElapsed Time = %lf sec\n", (double)(m_nEndTime.QuadPart-m_nBeginTime.QuadPart)/m_nFreq.QuadPart);
	return 0;
}
// ------------------------------���ϴ��벻�ý����κ��޸�------------------------------------

// --------------------------------------��������------------------------------------------
// ��֪��	�����������ļ�1.bin�д�����100000�������㣬ÿ����������4�����Թ��ɣ����Ծ�Ϊ���͡�
// ���壺	��a�����������Զ�����b���Ķ�Ӧ���Բ����ֵԽСԽ�ã���
//			��a��������һ�����Ա�b���Ķ�Ӧ���Ժã�����a��֧��b�㡣
// Ҫ����	���������κε�֧�����������ĸ�����
//			���Ծ�����д����������������������ʱ�䣨Elapsed Time����
// ---------------------------------------------------------------------------------------

// --------------------------------�Ӵ˴���ʼ���Ӵ���---------------------------------------

// run����Ϊ���㺯�����˺���ԭ�Ͳ��ܸġ�
void readfile(char *filename)
{
	FILE *fp;
	int i;
	fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	 for(i=0;i<COUNT;i++)
	 {
		fread(&arr[i],(sizeof(struct dot)-sizeof(int)),1,fp);
	//	printf("%d\n%d\n%d\n%d\n\n",arr[i].attr[0],arr[i].attr[1],arr[i].attr[2],arr[i].attr[3]);
	//	printf("%d ",data[i].num1);
	 }
	fclose(fp);
}
int compare(struct dot a,struct dot b)
{
	if(a.attr[0]<=b.attr[0]&&a.attr[1]<=b.attr[1]&&a.attr[2]<=b.attr[2]&&a.attr[3]<=b.attr[3])
	{
		if(a.attr[0]<b.attr[0]||a.attr[1]<b.attr[1]||a.attr[2]<b.attr[2]||a.attr[3]<b.attr[3])
			return 1; //a��֧��b��
	}
	if(a.attr[0]>=b.attr[0]&&a.attr[1]>=b.attr[1]&&a.attr[2]>=b.attr[2]&&a.attr[3]>=b.attr[3])
	{
		if(a.attr[0]>b.attr[0]||a.attr[1]>b.attr[1]||a.attr[2]>b.attr[2]||a.attr[3]>b.attr[3])
			return 2; //b��֧��a��
	}
	return 0;//���಻֧��
}
void run(void)
{
	int count=0;
	readfile("e:\\1.bin");
	for(int i=0;i<COUNT;i++)
	{
		arr[i].flag=0;
	}
	for(int i=0;i<COUNT-1;i++)
	{
		for(int j=i+1;j<COUNT;j++)
		{
			int result=compare(arr[i],arr[j]);
			if(result==1)//arr[i]֧��arr[j]
			{
				arr[j].flag=1;
			}
			else if(result==2)
			{
				arr[i].flag=1;
			}
			else
			{}
		}
	}
	for(int i=0;i<COUNT;i++)
	{
		if(arr[i].flag==0)
		{
			printf("%d\n%d\n%d\n%d\n\n",arr[i].attr[0],arr[i].attr[1],arr[i].attr[2],arr[i].attr[3]);
			//printf("%d\n",i);
			count++;
		}
	}
	printf("result:%d",count);
	return;
}
