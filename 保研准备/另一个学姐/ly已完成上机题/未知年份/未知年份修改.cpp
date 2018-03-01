#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include <windows.h>
#define COUNT 100000
struct data
{
	int num[4];

}data[COUNT];
struct data1
{
	int num[4];

}datacount[COUNT];
void run()
 {

	 FILE *fp;
	 int j=0,flag=1;
	 int n=0;
	 long i=0,k=0,m=0,x=0,y=0,count=0;
	 if((fp=fopen("e:\\1.bin","rb"))==NULL)
	 {
		 printf("cannot open file!\n");
		 exit(0);
	 }
	 printf("ghg");
	 for(i=0;i<COUNT;i++)
	 {
		fread(&data[i],sizeof(struct data),1,fp);
	 }
	 fclose(fp);
	for(i=0;i<COUNT;i++)
	{
		count=0;
		for(k=0;k<COUNT;k++)
		{
			    if(i==k)
				    continue;
				for(x=0,y=0;x<4;x++,y++)
				{
						if(data[k].num[y]>data[i].num[y])
						{
							count++;
							break;
						}
				}
				if(count==COUNT-1)
				{
							datacount[n].num[0]=data[i].num[0];
							datacount[n].num[1]=data[i].num[1];
							datacount[n].num[2]=data[i].num[2];
							datacount[n].num[3]=data[i].num[3];
							n++;
				}


		}

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\n",datacount[i].num[j]);
		}
		putchar(10);
	}
	printf("the num is : %d",n);
 }
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
