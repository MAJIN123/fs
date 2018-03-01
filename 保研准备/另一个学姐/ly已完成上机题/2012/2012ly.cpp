//2012年苏大计算机上机编程题目：
	//从服务器上下载数据文件org.dat文件以二进制方式存放一系列整数，每个整数占4个字节。从第一个整数开始，第一个整数和第二个整数构成一个坐标点，依次类推，数据文件中保存了许多坐标点数据。
	//问题1：
	//规定处于第一象限的坐标点为有效点，请问数据文件中所有点的个数n为多少？有效点的个数k为多少？
	//问题2：
	//每个有效点与坐标原点构成一个的矩形，请问k个有效点与坐标原点构成的k个矩形的最小公共区域面积为多少？
	//问题3：
	//寻找有效点中符合下列条件的点：以该点为坐标原点，其他有效点仍然是有效点即处于第一象限（不包括坐标轴上的点）。输出这些点。
	//问题4：
	//对所有有效点进行分组，每个有效点有且只能属于一个分组，分组内的点符合下列规则：若对组内所有点的x坐标进行排序，点p1（x1，y1）在点p2（x2，y2）后面，即x1>x2那么y1>y2.请输出所有的分组。
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
	return i;//返回的是数组有效长度
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
int judge2(struct dot a,struct dot b)//a为原点
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
		    flags[i]=1;//设置分组标志为1表示已经分组
			count++;//组号加1
			printf("\nGroup %d:",count);//提示开始一个新的分组坐标的输出
			printf("(%d,%d)\t",arr[i].x,arr[i].y);//输出该分组中的第一个坐标
			t=i;//设置岗哨下标为i
			for(int j=i+1;j<count;j++)
			{
				if(flags[j])//如果坐标点已经有分组就结束本次的判定
				{
					continue;
				}
				if(arr[t].y<arr[j].y)//如果坐标点与该分组中最后一个坐标进行比较，判定是否可以划为本组
				{
					flags[j]=1;//可以划分到改组，设置该坐标的分组标志为1
					printf("(%d,%d)\t",arr[j].x,arr[j].y);//输出该点
					t=j;//下次比较的坐标设置为该点
				}
			}
		}
	}
}