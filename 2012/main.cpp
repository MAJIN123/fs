#include <iostream>
#include<stdio.h>
#include <math.h>
using namespace std;
#define LEN 100
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
typedef struct{
    int x;
    int y;
    //int a;
    //int b;
}Point;

int isValpoint(Point p){
    if(p.x>0&&p.y>0)
        return 1;
    else
        return 0;
}

int ReadFile(char *filename,Point points[],int *count){
    Point tmp ;
    int tp[4];
    int num=0;
    FILE *fp=fopen(filename,"wb");
    if(!fp){
        printf("can not open file\n");
        exit(0);
    }
    while(!feof(fp)){

        if((fread(&tmp,sizeof(struct Point),1,fp))!=2){
            break;
        }

        num++;
        //tmp.x=tp[0];
        //tmp.y=tp[1];
        if(isValpoint(tmp)){
            points[*count]=tmp;
            (*count)++;
        }
    }
    fclose(fp);
    return num;
}
void Areas(Point points[],int n){
    int min_x=0,min_y=0;
    for(int i=0;i<n;++i){
        if(points[i].x<min_x)
            min_x=points[i].x;
        if(points[i].y>min_y)
            min_y=points[i].y;
    }
    printf("``````````");
}

int check(Point p1,Point p2){
    if(p1.x>p2.x&&p1.y>p2.y)
        return 1;
    else return 0;
}
void fun3(Point points[],int n){
    int flag=1;
    for(int i=0;i<n;++i){
        flag=1;
        for(int j=0;j<n;++j){
            if(i==j){
                continue;
            }
            if(check(points[j],points[i])){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("```````````");
        }
    }
}
int cmp(const void *p1,const void *p2){
    return ((Point *)p1)->x-((Point *)p2)->x;
}
void fun4(Point points[],int n){
    qsort(points,n,sizeof(Point),cmp);
    int flag[LEN];
    for(int i=0;i<LEN;++i){
        flag[i]=0;
    }
    int count=0;
    for(int i=0;i<n;++i){
        if(!flag[i]){
            flag[i]=1;
            count++;
            printf("count组");
            int tmp=i;
            for(int j=i+1;j<n;++j){
                if(flag[j]){
                    continue;
                }
                if(points[tmp].y<points[j].y){
                    flag[j]=1;
                    printf("``");
                    tmp=j;
                }
            }
        }
    }
}

int main() {
    int valcount=0;
    int *p=&valcount;
    Point points[LEN];
    char *filename="1.bin";
    int num=ReadFile(filename,points,p);
    printf("num:%d",valcount);

    return 0;
}

