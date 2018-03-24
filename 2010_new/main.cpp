//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * //1）FTP上下载make.exe和org.dat，运行make.exe输入准考证后三位生成data.txt，文件为二进制编码
	//2）data.txt内存有2048个整数，其中前n个为非0数，后2048-n个数为0，将其读入数组，计算非零数的个数n
	//3）选出n个数中的最大数&最小数
	//4）选出n个数中最大素数
	//5）将n个数从大到小排序，并平均分成3段（若n非3的整数倍，则不考虑最后的1~2个数），选出中间段的最大数和最小数
 */
void ReadData(char *filename,int data[],int *count) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    while (fread(&data[*count], sizeof(int), 1, fp)) {
        if (data[*count] == 0)
            break;
        //printf("%d-",data[*count]);
        (*count)++;
    }

    fclose(fp);
}

int Is_prime(int val) {
    if (val < 2)
        return 0;
    for (int i = 2; i < sqrt(val * 1.0); ++i) {
        if (val % i == 0)
            return 0;
    }
    return 1;
}
void Max_Min(int data[],int count,int *max,int *min,int *max_prime) {
    if (count > 0) {
        *max = *min = data[0];
        for (int i = 1; i < count; ++i) {
            if (*max < data[i])
                *max = data[i];
            if (*min > data[i])
                *min = data[i];
            if (Is_prime(data[i]) && data[i] > *max_prime)
                *max_prime = data[i];
        }
    }
}

void Mid_Max_Min(int data[],int count,int *max,int *min) {
    for (int i = 0; i < count; ++i) {
        int x = i;
        for (int j = i + 1; j < count; ++j) {
            if (data[j] > data[x])
                x = j;
        }
        if (x != i) {
            int tmp = data[i];
            data[i] = data[x];
            data[x] = tmp;
        }
    }
    //012 345 6789
    *max = data[count / 3];
    *min = data[2 * count / 3 - 1];
}
int main() {
    int data[2014];
    int count = 0;
    int max = 0, min = 0, max_prime = 2;

    int Mid_max = 0, Mid_min = 0;
    ReadData("/home/jinm32/by/2010_new/data.txt", data, &count);
    Max_Min(data, count, &max, &min, &max_prime);
    Mid_Max_Min(data, count, &Mid_max, &Mid_min);

    //printf("%d,%d,%d",max,min,max_prime);


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}