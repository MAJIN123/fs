//2014年上机复试题
//从网页上下载input.dat文件，里面是用二进制编写的，里面放了一堆int型的数，每个数占4个字节，每次读取两个，这两个数构成一个坐标。
//（1）规定处于第一象限的数是有效点，（即x>0,y>0的坐标），问这么多点中有效点有多少个？
//（2）现在用户从键盘输入一个坐标和一个数字K，设计算法输出K个离该坐标距离最近的点的坐标和每个坐标到该点的距离，写入到output.txt文件中。
/*
2,4,10
0---dis:28
1---dis:47
2---dis:60
3---dis:70
4---dis:76
5---dis:78
6---dis:89
7---dis:90
8---dis:92
9---dis:93
 */
//#include <iostream>
#include<stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
struct Point{
    int x;
    int y;
};
void WriteData(char *filename){
    srand(time(NULL));
    FILE*fp=fopen(filename,"wb");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    for(int i=0;i<1000;++i){
        int x=rand()%1000-500;
        fwrite(&x,4,1,fp);
    }
    fclose(fp);
}
int Dst(struct Point p1,int x,int y){
    return sqrt((p1.x-x)*(p1.x-x)+(p1.y-y)*(p1.y-y));
}
void sort(struct Point points[],int count,int x,int y,int k){
    for(int i=0;i<k;++i){
        for(int j=i+1;j<count;++j){
            if(Dst(points[j],x,y)<Dst(points[i],x,y)){
                struct Point tmp=points[j];
                points[j]=points[i];
                points[i]=tmp;
            }
        }
    }
}
void Run(char *filename, char *output){
    FILE *fp=fopen(filename,"rb");
    FILE *out=fopen(output,"w");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    if(out==NULL){
        printf("can not open file\n");
        return;
    }

    fseek(fp,0L,2);
    int count=ftell(fp)/8;//点的个数
    fseek(fp,0L,0);
    //printf("%d",i);
    struct Point points[count];
    fread(&points,sizeof(struct Point),count,fp);

    int r_count=0;
    for(int i=0;i<count;++i){
        if(points[i].x>0&&points[i].y>0)
            r_count++;
    }
    printf("有效点个数有：%d个\n",r_count);

    int x,y,k;
    printf("请输入点的坐标以及k，用逗号分隔\n");
    scanf("%d,%d,%d",&x,&y,&k);
    //printf("%d,%d,%d",x,y,k);
    sort(points,count,x,y,k);
    for(int i=0;i<k;++i){
        //printf("%d---dis:%d\n",i,Dst(points[i],x,y));
        fprintf(out,"第%d个点坐标:%d,%d，距离：%d\n",i+1,points[i].x,points[i].y,Dst(points[i],x,y));
    }

    fclose(fp);
    fclose(out);
}
int main() {

    //WriteData("/home/jinm32/by/2014/input.dat");
    Run("/home/jinm32/by/2014/input.dat","/home/jinm32/by/2014/output.txt");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}