 //------------------------------以上代码不得进行任何修改------------------------------------

// --------------------------------------考题如下------------------------------------------
// 已知：	二进制数据文件1.bin中存放了100000个样本点，每个样本点由4个属性构成，属性均为整型。
// 定义：	如a点的所有属性都不比b点的对应属性差（属性值越小越好），
//			且a点至少有一个属性比b点的对应属性好，则称a点支配b点。
// 要求：	求出不被任何点支配的样本点的个数。
//			在试卷上填写求出的样本点个数和所用时间（Elapsed Time）。
// ---------------------------------------------------------------------------------------

// --------------------------------从此处开始添加代码---------------------------------------

// run函数为起点函数。此函数原型不能改。
#include "stdio.h"
#include "stdlib.h"
struct data
{
	int num[4];
	
}data[100000];
struct data1
{
	int num[4];
	
}datacount[100000];
void run()
 {

	 FILE *fp;
	 int j=0,flag=1;
	 long i=0,k=0,m=0,x=0,y=0,count=0;
	 if((fp=fopen("1.bin","rb"))==NULL)
	 {
		 printf("cannot open file!\n");
		 exit(0);
	 }
	 printf("ghg");
	 for(i=0;i<100000;i++)
	 {
		fread(&data[i],sizeof(struct data),1,fp);
	//	printf("%d ",data[i].num1);
	 }
	 fclose(fp);
	for(i=0;i<100000;i++)
	 {
			
		for(j=0;j<4;j++)
			printf("%d ",data[i].num[j]);
			
		     putchar(10);
	 }
	 
	for(i=0;i<100000;i++)
	{
		printf("%d\n",i);


		for(k=0;k<100000;k++)
		{
			    //flag=1;
			    if(i==k)
				    continue;
		
				for(x=0,y=0;x<4;x++,y++)
				{
					if(data[k].num[y]>data[i].num[y])
					{
						//flag=2;
						goto L;
					}
				}
				//if(flag==1)
				//{
				for(x=0,y=0;x<4;x++,y++)
				{
						if(data[k].num[y]<data[i].num[y])
						{
							datacount[count].num[0]=data[i].num[0];
							datacount[count].num[1]=data[i].num[1];
							datacount[count].num[2]=data[i].num[2];
							datacount[count].num[3]=data[i].num[3];
							printf("%d %d %d %d \n",data[i].num[0],data[i].num[1],data[i].num[2],data[i].num[3]);
							count++;
							
							break;
						}
				}
				//}
	

		}


L:printf("%d\n",i);

	}
	count--;
	for(i=0;i<count;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",datacount[i].num[j]);
		}
		putchar(10);

	}

	printf("the num is : %d",count);
 }
void main()
 {
	 run();
 }