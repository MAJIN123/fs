//#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
 * 2014年上机复试题
从网页上下载input.dat文件，里面是用二进制编写的，里面放了一堆int型的数，每个数占4个字节，每次读取两个，这两个数构成一个坐标。
（1）规定处于第一象限的数是有效点，（即x>0,y>0的坐标），问这么多点中有效点有多少个？
（2）现在用户从键盘输入一个坐标和一个数字K，设计算法输出K个离该坐标距离最近的点的坐标和每个坐标到该点的距离，写入到output.txt文件中。
 */
typedef struct p{
    int x;
    int y;
}Point;

int Val_Points(Point *points,int count) {
    int res = 0;
    for (int i = 0; i < count; ++i) {
        if (points[i].x > 0 && points[i].y > 0)
            res++;
    }
    return res;
}

int Distance(Point a,Point b) {
    return (int) sqrt(((a.x - b.x) * (a.x - b.x) + (a.x - b.x) * (a.x - b.x)) * 1.0);
}
void  Run(char *input,char *output) {
    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "a+");
    if (in == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fseek(in, 0, 0);
    fseek(in, 0, 2);
    int count = ftell(in) / 8;//numbers of points
    Point *points = (Point *) malloc(sizeof(Point) * count);
    fseek(in, 0, 0);
    for (int i = 0; i < count; ++i) {
        fread(&points[i], sizeof(Point), 1, in);
    }
    int ValPoints = Val_Points(points, count);
    printf("The number of valable points:   %d\n", ValPoints);

    printf("please input you point(x,y)\n");
    Point p;
    scanf("%d,%d", &p.x, &p.y);
    printf("please input K\n");
    int k;
    scanf("%d", &k);

    fprintf(out, "  (x,y)=(%3d,%3d)  k=%d\n", p.x, p.y, k);

    int tmp;
    for (int i = 0; i < k; ++i) {
        int dis = Distance(points[i], p);
        tmp = i;
        for (int j = i + 1; j < count; ++j) {
            if (int x = Distance(points[j], p) < dis) {
                dis = x;
                tmp = j;
            }
        }
        if (tmp != i) {
            Point exchange = points[i];
            points[i] = points[tmp];
            points[tmp] = exchange;
        }
        fprintf(out, "%3d---(%4d,%4d)--%4d\n", i + 1, points[i].x, points[i].y, Distance(p, points[i]));
    }

    fclose(in);
    fclose(out);
}

int main(){
    Run("/home/jinm32/by/2014 new/input.dat","/home/jinm32/by/2014 new/output.dat");
    //printf("%d",SEEK_END);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}