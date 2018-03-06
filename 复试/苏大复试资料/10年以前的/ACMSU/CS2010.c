#include <stdio.h>
#include <math.h>
#define SU_LEN 2048


//从大到小的排序比较算法
int cmpnumbts(const void * p1,const void * p2)
{
	return *(int *)p1>*(int *)p2?-1:1;
}

//判断是否为素数
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


	//2010年上机复试题
	//1）FTP上下载make.exe和org.dat，运行make.exe输入准考证后三位生成data.txt，文件为二进制编码
	//2）data.txt内存有2048个整数，其中前n个为非0数，后2048-n个数为0，将其读入数组，计算非零数的个数n
	//3）选出n个数中的最大数&最小数
	//4）选出n个数中最大素数
	//5）将n个数从大到小排序，并平均分成3段（若n非3的整数倍，则不考虑最后的1~2个数），选出中间段的最大数和最小数
	int i,n,t,max,min,maxprime,nums[SU_LEN],maxmid,minmid,m;
	FILE * fp;
	char fname[]="D:\\data.txt";

//生成一个测试的文件
//	memset(nums,0,sizeof(nums));//数组元素初始化为0
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
	memset(nums,0,sizeof(nums));//数组元素初始化为0
	fread(nums,sizeof(int),SU_LEN,fp);//读出SU_LEN个整数存入数组
	fclose(fp);
	for(i=n=max=min=maxprime=0;i<SU_LEN;i++)
	{
		if(nums[i]>0)
		{
			if(min==0)//判断是否已经赋值非零最小值
			{
				min=nums[i];
			}
			if(max==0)
			{
				max=nums[i];
			}
			n++;//非零数计数
			if(nums[i]>max)//最大数
			{
				max=nums[i];
			}
			if(nums[i]<min)//最小数
			{
				min=nums[i];
			}
			if(isprime(nums[i]))//是否素数
			{
				if(nums[i]>maxprime)//最大素数
				{
					maxprime=nums[i];
				}
			}


		}
	}

	//数组排序从大到小
	qsort(nums,SU_LEN,sizeof(int),cmpnumbts);

	//对数组进行分段，先分析非零个数n是否为3的倍数，计算出3等分的每段元素个数，
	//由于已经对数组进行从大到小的排序则，前n个数组元素即为非零的n个元素，且每段分组的第一个元素是最大值，最后一个元素是最小值
	m=n;
	while(m%3!=0)//找出可以等分的总元素个数,即不考虑最后的1~2个数
	{
		m--;
	}
	m=m/3;//每段的元素个数
	maxmid=nums[m];//中间段的最大数
	minmid=nums[m*2-1];//中间段的最小数
	
	printf("Total number:%d\nThe Max number is:%d\nThe min number is:%d\nThe max prime number is:%d\nThe max number in middle section is:%d\nThe min number in middle section is:%d\n",n,max,min,maxprime,maxmid,minmid);
	

}