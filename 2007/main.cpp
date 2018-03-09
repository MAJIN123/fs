//2007年上级复试题
//把10到1000之间满足以下两个条件的数，存到result.txt文件中
//1、是素数。
//2、它的反数也是素数，如：123的反数是321。



#include <stdio.h>
#include <math.h>
//#include <iostream>
int Is_Prime(int val) {
    if (val < 2)
        return 0;
    for (int i = 2; i < sqrt(val * 1.0); ++i) {
        if (val % i == 0)
            return 0;
    }
    return val;
}
int Reverse(int val) {
    int res = 0;
    while (val > 0) {
        res = res * 10 + val % 10;
        val = val / 10;
    }
    return res;
}
void WriteData(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    for (int i = 10; i < 1000; ++i) {
        if (Is_Prime(i) && Is_Prime(Reverse(i))) {
            fprintf(fp, "%d\n", i);
        }
    }
}
int main() {
    //printf("%d",Reverse(32100));
    WriteData("/home/jinm32/by/2007/result.txt");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}