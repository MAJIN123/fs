//#include <iostream>
//二进制数据文件1.bin中存放了100000个样本点，每个样本点由4个属性构成，属性均为整型。
// 定义：	如a点的k个属性不比b点的对应属性差（属性值越小越好），
//	 且a点至少有一个属性比b点的对应属性好，则称a点k-支配b点。
// 要求：	求出不被任何点k-支配的样本点的个数。
//	 在试卷上填写求出的样本点个数和所用时间（Elapsed Time）。
#include<stdio.h>
#include<time.h>
struct data{
    int num[4];
}data[100000];

void ReadFile(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    for (int i = 0; i < 100000; ++i) {
        fread(&data[i], sizeof(int), 4, fp);
    }

    fclose(fp);
}
int Is_Ctl(int k,struct data p,struct data q) {
    int count = 0;
    int flag = 0;
    for (int i = 0; i < 4; ++i) {
        if (p.num[i] <= q.num[i])
            count++;
        if (p.num[i] < q.num[i])
            flag = 1;
    }
    if (flag) {
        if (count >= k)
            return 1;
    }
    return 0;
}
int run(int k) {
    int res = 0;
    int flag = 0;
    for (int i = 0; i < 100000; ++i) {

        for (int j = 0; j < 100000; ++j) {
            if (j == i)
                continue;
            if (Is_Ctl(k, data[j], data[i])) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            res++;
        } else
            flag = 0;
    }
    return res;
}
int main() {
    clock_t start, finish;
    start = clock();

    ReadFile("/home/jinm32/by/2012_fu-new/1.bin");
    int k = 4;
    printf("不被任何点%d-支配的样本点的个数:%d", k, run(k));

    finish = clock();
    printf("\nElapsed Time :%lf\n", (double) (finish - start) / CLOCKS_PER_SEC);

    return 0;

}