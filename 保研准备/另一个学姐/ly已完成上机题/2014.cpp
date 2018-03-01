//input.bin中有10000组数据，每组数据有4个属性，都为整型。
//定义邻近点为拥有k个距离小于等于d的点的点，d=根号下（(b1-a1)*(b1-a1)+(b2-a2)*(b2-a2)+(b3-a3)*(b3-a3)+(b4-a4)*(b4-a4)）;
//现定义k=10，d=7500，显示出符合点的编号及其各个属性。
//题目不太清楚也米有文件让我试试，就稍微写写思路吧


//思路 
#include<stdio.h>
#include<math.h>
//1、先声明结构体类型
#define LEN sizeof(struct dot)-sizeof(int)
#define COUNT 10000
#define d 7500
#define k 10
struct dot
{
int attr1;
int attr2;
int attr3;
int attr4;
int count;//改变量用于记邻近点的数
};
//2、用二进制方法（fread）打开文件，将10000组数据放到struct dot data[10000]结构体数组中(单独的一个函数)
void readfile(char* filename,struct dot data[])
{
	FILE *fp=fopen(filename,"rb");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	if(fread(data,LEN,COUNT,fp)!=COUNT)
	{
		printf("Can not read the data!\n");
		return;
	}
	fclose(fp);
}
//3、统计对于每一个点有多少个距离小于等于d的点的点
void cal (struct dot data[],int d1)
{
	for(int i=0;i<COUNT;i++)
	{
		data[i].count=0;
	}
	for(int i=0;i<COUNT-1;i++)  //感觉有点像选择排序
	{
		for(int j=i+1;j<COUNT;j++)
		{
			double l=sqrt(1.0*(data[i].attr1-data[j].attr1)*(data[i].attr1-data[j].attr1)+(data[i].attr2-data[j].attr2)*(data[i].attr2-data[j].attr2)+(data[i].attr3-data[j].attr3)*(data[i].attr3-data[j].attr3)+(data[i].attr4-data[j].attr4)*(data[i].attr4-data[j].attr4));
			if(l<=d1)
			{
				data[i].count++;
				data[j].count++;
			}
		}
	}
}
//4、main函数
int main()
{
	struct dot data[COUNT];
	readfile("d:\\input.bin",data);
	cal(data,d);
	for(int i=0;i<COUNT;i++)
    {
		if(data[i].count==k)
		{
			printf("该点：【%d %d %d %d】为邻近点\n",data[i].attr1,data[i].attr2,data[i].attr3,data[i].attr4);
		}
    }
	return 0;
}
