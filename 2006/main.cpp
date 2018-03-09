//2006年上级复试题
//找出100到1000内的不含9的素数，存到result.txt文件中。

//#include <iostream>
#include <stdio.h>
#include <math.h>
int Is_prime(int val) {
    if (val < 2)
        return 0;
    for (int i = 2; i < sqrt(val * 1.0); ++i) {
        if (val % i == 0)
            return 0;
    }
    return val;
}
int Have_Nine(int val) {
    if (val < 9) {
        return 0;
    }
    if (val == 9)
        return 1;
    while (9 <= val) {
        if (val % 10 == 9)
            return 1;
        val = val / 10;
    }
    return 0;
}
void WriteData(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    for (int i = 100; i < 1000; ++i) {
        if (Is_prime(i) && !Have_Nine(i)) {
            fprintf(fp, "%d\n", i);
        }
    }
    return;
}
int main() {
    WriteData("/home/jinm32/by/2006/result.txt");
    /*
    printf(" ： %d\n",Have_Nine(11));
    printf(" ： %d\n",Have_Nine(191));
    printf(" ： %d\n",Have_Nine(190));
    printf(" ： %d\n",Have_Nine(101));
    printf(" ： %d\n",Have_Nine(10001));
     */
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}