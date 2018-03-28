//#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node {
    int x;
    int y;
    double r;
    int count;//the number of points
    double dinaMiDu;
}Data;
double Distance(Data a,Data b);
void Cover_Points(Data *points,int num);
void Q4(Data *points,int num);
void ReadFile(char *intput,Data **points,int *cot);
int main() {
    Data *points;
    int count = 0;
    ReadFile("/home/jinm32/by/2017 new/data.bin", &points, &count);
    Cover_Points(points,count);
    Q4(points,count);
    free(points);
    return 0;
}
double Distance(Data a,Data b) {
    return sqrt(((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) * 1.0);
}

void Cover_Points(Data *points,int num) {
    //Q3
    int n;
    for (int i = 0; i < num - 1; ++i) {
        points[i].r = Distance(points[i], points[i + 1]);
        n = 0;
        for (int j = 0; j < num; ++j) {
            if (Distance(points[i], points[j]) <= points[i].r)
                n++;
        }
        points[i].count = n;
    }
    points[num - 1].r = Distance(points[num - 1], points[0]);
    n = 0;
    for (int i = 0; i < num; ++i) {
        if (Distance(points[i], points[num - 1]) <= points[num - 1].r)
            n++;
    }
    points[num - 1].count = n;
}

void Q4(Data *points,int num) {
    for (int i = 0; i < num; ++i) {
        points[i].dinaMiDu = (double) points[i].count / ((3.14 * points[i].r * points[i].r));
    }
    int flag;
    for (int i = 0; i < 5 && i < num; ++i) {
        flag = i;
        for (int j = i + 1; j < num; ++j) {
            if (points[j].dinaMiDu > points[flag].dinaMiDu)
                flag = j;
        }
        if (flag != i) {

            Data temp = points[flag];
            points[flag] = points[i];
            points[i] = temp;

        }
        printf("(%d,%d)(%5d)(%7.2f)\n", points[i].x, points[i].y, points[i].count, points[i].dinaMiDu);
    }
}


void ReadFile(char *intput,Data **points,int *cot) {
    //Q1 and Q2
    FILE *fp = fopen(intput, "rb");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }

    fseek(fp, 0, 0);
    fseek(fp, 0, 2);
    *cot = ftell(fp) / 8;
    *points = (Data *) malloc(sizeof(Data) * (*cot));

    fseek(fp, 0, 0);
    for (int i = 0; i < *cot; ++i) {
        fread(&(*points)[i], 8, 1, fp);
    }
    /*
    //Q3
    int num = *cot;
    int n;
    for (int i = 0; i < num - 1; ++i) {
        points[i].r = Distance(points[i], points[i + 1]);
        n = 0;
        for (int j = 0; j < num; ++j) {
            if (Distance(points[i], points[j]) <= points[i].r)
                n++;
        }
        points[i].count = n;
    }
    points[num - 1].r = Distance(points[num - 1], points[0]);
    n = 0;
    for (int i = 0; i < num; ++i) {
        if (Distance(points[i], points[num - 1]) <= points[num - 1].r)
            n++;
    }
    points[num - 1].count = n;




    //Q4
    for (int i = 0; i < num; ++i) {
        points[i].dinaMiDu = (double) points[i].count / ((3.14 * points[i].r * points[i].r));
    }
    int flag;
    for (int i = 0; i < 5 && i < num; ++i) {
        flag = i;
        for (int j = i + 1; j < num; ++j) {
            if (points[j].dinaMiDu > points[flag].dinaMiDu)
                flag = j;
        }
        if (flag != i) {
            Data temp = points[flag];
            points[flag] = points[i];
            points[i] = temp;
        }
        printf("(%d,%d)(%5d)(%7.2f)\n", points[i].x, points[i].y, points[i].count, points[i].dinaMiDu);

    }
     */

    fclose(fp);
}