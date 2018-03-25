//#include <iostream>
#include<stdio.h>
#include<stdlib.h>
/*
 * //2012年苏大计算机上机编程题目：
//从服务器上下载数据文件org.dat文件以二进制方式存放一系列整数，每个整数占4个字节
。从第一个整数开始，第一个整数和第二个整数构成一个坐标点，依次类推，数据文件中保
存了许多坐标点数据。
//问题1：
//规定处于第一象限的坐标点为有效点，请问数据文件中所有点的个数n为多少？有效点的>个数k为多少？
//问题2：
//每个有效点与坐标原点构成一个的矩形，请问k个有效点与坐标原点构成的k个矩形的最小
公共区域面积为多少？
//问题3：
//寻找有效点中符合下列条件的点：以该点为坐标原点，其他有效点仍然是有效点即处于第
一象限（不包括坐标轴上的点）。输出这些点。
//问题4：
//对所有有效点进行分组，每个有效点有且只能属于一个分组，分组内的点符合下列规则：
若对组内所有点的x坐标进行排序，点p1（x1，y1）在点p2（x2，y2）后面，即x1>x2那么y1>y2.请输出所有的分组。
 */
typedef struct p{
    int a[2];
}Point;

typedef struct node{
    Point p;
    struct node *next;
}Node;
int Val_Point(Point p) {
    if (p.a[0] > 0 && p.a[1] > 0)
        return 1;
    return 0;
}
void Q1(char *filename,Node *head,int *count) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    Point point;
    while (!feof(fp)) {
        if (int x = fread(&point, sizeof(struct p), 1, fp) != 1) {
            //printf("%d\n",x);
            break;
        }
        if (Val_Point(point)) {
            Node *q = (Node *) malloc(sizeof(Node));
            if (q) {
                q->p = point;
                //(q->p).a[0]=point.a[0];
                //(q->p).a[1]=point.a[1];
                q->next = NULL;
            }
            q->next = head->next;
            head->next = q;
            (*count)++;
        }
    }

    fclose(fp);

}
int Areas(Node *head) {
    Node *p = head;
    int x = p->next->p.a[0], y = p->next->p.a[1];
    while (p->next) {
        if (x > p->next->p.a[0])
            x = p->next->p.a[0];
        if (y > p->next->p.a[1])
            y = p->next->p.a[1];
        p = p->next;
    }

    return x * y;
}

void WriteData() {
    int test[] = {1, 3, 20, 4, 79, 34, 12, 25, -12, 24, 37, -19, -44, -6, 25, 6, 22, 4, -4, 5, 6, 7, 8, 9, 11, 17, 2, 4,
                  1, 10};
    FILE *fp;
    char fname[] = "/home/jinm32/by/2012_new/org.dat";


    //生成测试数据文件，将test数组中的数据写入文件
    fp = fopen(fname, "wb+");
    if (fp == NULL) {
        printf("file open error!\n");
        exit(0);
    }
    fwrite(test, 4, 30, fp);
    fclose(fp);
}
void Display(Node *head) {
    Node *q = head;
    while (q->next) {
        printf("%d,%d\n", q->next->p.a[0], q->next->p.a[1]);
        q = q->next;
    }
}
void Q3(Node *head) {
    Node *q = head;
    Point x = q->next->p;
    Point y = q->next->p;
    while (q->next) {
        if (q->next->p.a[0] < x.a[0])
            x = q->next->p;
        if (q->next->p.a[1] < x.a[1])
            y = q->next->p;
        q = q->next;
    }
    if ((x.a[0] == y.a[0]) && (x.a[1] = y.a[1])) {
        printf("符合条件的点：%d %d\n", x.a[0], x.a[1]);
    } else {
        printf("Q3:没有符合条件的点\n");
    }
}
void Sort(Node *head) {
    Node *q = head->next;
    while (q) {
        Node *cur = q->next;
        Node *x = q;
        while (cur) {
            if ((cur->p.a[0]) < x->p.a[0]) {
                x = cur;
            }
            cur = cur->next;
        }
        if (x != q) {
            Point tmp = x->p;
            x->p = q->p;
            q->p = tmp;
        }

        q = q->next;
    }
}
void Q4(Node *head,int count) {
    int num = 0;

    int flag[count] = {0};
    flag[0] = 1;

    Node *p = head;
    Point cur;

    int i = 1;
    while (p->next) {

        if (!flag[i]) {
            flag[i] = 1;
            num++;
            printf("\n第%d组：", num);
            printf("(%d %d) ", p->next->p.a[0], p->next->p.a[1]);
            int tmp = i;
            Node *x = p->next->next;
            tmp++;
            cur = p->next->p;
            while (x) {
                if (!flag[tmp] && x->p.a[1] > cur.a[1]) {
                    printf("(%d %d)", x->p.a[0], x->p.a[1]);
                    flag[tmp] = 1;
                    cur = x->p;
                }
                x = x->next;
                tmp++;
            }

        }
        i++;
        p = p->next;
    }
}
int main() {

    //WriteData();
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    int count = 0;
    Q1("/home/jinm32/by/2012_new/org.dat", head, &count);
    //Display(head);
    int areas = Areas(head);
    printf("%d\n", areas);

    Q3(head);

    Sort(head);
    Display(head);
    Q4(head, count);

    return 0;
}