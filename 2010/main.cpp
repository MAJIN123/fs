//2010年上机复试题
//1）FTP上下载make.exe和org.dat，运行make.exe输入准考证后三位生成data.txt，文件为二进制编码
//2）data.txt内存有2048个整数，其中前n个为非0数，后2048-n个数为0，将其读入数组，计算非零数的个数n
//3）选出n个数中的最大数&最小数
//4）选出n个数中最大素数
//5）将n个数从大到小排序，并平均分成3段（若n非3的整数倍，则不考虑最后的1~2个数），选出中间段的最大数和最小数

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void CreatData(char *filename){
    FILE *fp=fopen(filename,"wb");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    srand(time(NULL));
    int n=rand()%2048;
    int a[2048];
    for(int i=0;i<n;++i){
        a[i]=rand()%5000;
    }
    for(int i=n;i<2048;++i){
        a[i]=0;
    }

    fwrite(a,4,2048,fp);
    fclose(fp);
}
int Readdata(char *filename,int a[]){
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("can not open file\n");
        exit(1);
    }

    int i=0;
    for(i;i<2048;++i){
        fread(&a[i],4,1,fp);
        if(a[i]==0)
            break;
    }
    return i;

}
int Is_prime(int a){
    if(a<2)
        return 0;

    for(int i=2;i<sqrt(a*1.0);++i) {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

void Max_Min(int a[],int count,int *max,int *min,int *prime){
    if(count<1)
        return;
    *max=*min=a[0];
    for(int i=1;i<count;++i){
        if(*max<a[i])
            *max=a[i];
        if(*min>a[i])
            *min=a[i];
        if(Is_prime(a[i])&&a[i]>*prime)
            *prime=a[i];
    }
}
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
int main() {
    //CreatData("/home/jinm32/by/2010/data.txt");
    int a[2048];
    int count=Readdata("/home/jinm32/by/2010/data.txt",a);
    int max=0,min=0,prime=2;
    Max_Min(a,count,&max,&min,&prime);
    printf("%d %d %d\n",max,min,prime);
    qsort(a,count,4,cmp);
    int num=count/3;
    //1 2 3 4 5 6 7 8 9 10 11 12
    printf("min:%d max:%d",a[num],a[num*2-1]);
    /*
    for(int i=0;i<count;++i)
        printf("%d  ",a[i]);
    printf("\n%d",count);
     */
    return 0;
}