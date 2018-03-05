#include <stdio.h>
#include <math.h>
#define MAX_LEN 200


//定义坐标点数据类型
typedef struct {
	int x;
	int y;
}POINT;

//判断一个点是否为有效点
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

//第一题的函数，fp为以二进制读取方式打开的文件指针，points为保存有效点的数组，pvc用于保存有效点的个数
void fun1(FILE * fp,POINT points[],int * pvc)
{
	POINT temp;
	int tp[2],count;

	printf("---------------fun1---------------\n");
	rewind(fp);//将文件指针重置，防止指针已经移动过
	count=0;
	*pvc=0;
	while(!feof(fp))
	{
		if(fread(tp,4,2,fp)!=2)//每次读2个整数，读数异常就退出
		{
			break;
		}
		temp.x=tp[0];
		temp.y=tp[1];
		count++;
		if(isvalpoint(temp))//判断是否为有效点
		{
			points[*pvc]=temp;
			(*pvc)++;
		}

	}

	printf("Total points:%d\nValidate points:%d\n",count,*pvc);

}

//第二题的函数，points为保存有效点的数组，n为保存有效点的个数
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

//检查p1是否在以p2为原点的第一象限
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


//第三题的函数，points为保存有效点的数组，n为保存有效点的个数
void fun3(POINT points[],int n)
{
	int i,j,flag=1;
	printf("---------------fun3---------------\nThe right points list:\n");
	for(i=0;i<n;i++)
	{
		flag=1;//初始为1表示该点为符合条件的点
		for(j=0;j<n;j++)
		{
			if(i==j)//相同点不需要比较
			{
				continue;
			}
			if(!checkpointbypoint(points[j],points[i]))//如果发现一个点不在该点的第一象限，则结束对该点的判定，标识为0
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

//将坐标点数组按照x坐标从小到大排序
int cmp(const void * p1,const void * p2)
{
	return ((POINT *)p1)->x-((POINT *)p2)->x;
}

//第四题的函数，points为保存有效点的数组，n为保存有效点的个数
void fun4(POINT points[],int n)
{
	int i,j,t,count=0;
	int flags[MAX_LEN];//标志数组
	memset(flags,0,sizeof(flags));//标志数组初始化为0表示points中对应下标的坐标点尚未分组
	//对points数组进行排序
	qsort(points,n,sizeof(POINT),cmp);
	printf("---------------fun4---------------");
	for(i=0;i<n;i++)//对每一个数组中每一个坐标点进行循环，确保每个点都有自己的分组
	{
		if(!flags[i])//如果发现一个坐标点尚未进行分组那么将该坐标点划分为一个新的分组
		{
			flags[i]=1;//设置分组标志为1表示已经分组
			count++;//组号加1
			printf("\nGroup %d:",count);//提示开始一个新的分组坐标的输出
			printf("(%d,%d)\t",points[i].x,points[i].y);//输出该分组中的第一个坐标
			t=i;//设置岗哨下标为i
		
			for(j=i+1;j<n;j++)//由于points已经按照x坐标排序，因此从该坐标点的下一个坐标点开始循环查找可以划为本组的坐标点
			{
				if(flags[j])//如果坐标点已经有分组就结束本次的判定
				{
					continue;
				}
				if(points[t].y<points[j].y)//如果坐标点与该分组中最后一个坐标进行比较，判定是否可以划为本组
				{
					flags[j]=1;//可以划分到改组，设置该坐标的分组标志为1
					printf("(%d,%d)\t",points[j].x,points[j].y);//输出该点
					t=j;//下次比较的坐标设置为该点
				}
			}
		}
	}
	printf("\n");
}


void main()
{
	

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
	//int test[]={1,3,20,4,79,34,12,25,-12,24,37,-19,-44,-6,25,6,22,4,-4,5};
	int valcount=0,* pvc;//valcount用于保存有效点的数量
	POINT points[MAX_LEN];//points用于保存所有有效点
	FILE * fp;
	char fname[]="D:\\org.dat";
	

	/*
	//生成测试数据文件，将test数组中的数据写入文件
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
	
	//输出第一题的答案
	pvc=&valcount;
	fun1(fp,points,pvc);
	fclose(fp);
	
	//输出第二题的答案
	fun2(points,*pvc);
	
	//输出第三题的答案
	fun3(points,*pvc);
	
	//输出第四题的答案
	fun4(points,*pvc);

}