//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char ori[8];
    char des[8];
    int n;
}Node;
void Verify_1(char str[]);
int str_int(char num[]);
int CanReach(Node a[],int x,char ori[],char des[],int n);
void Run(char *PathInput,char *PathRequest,char *Output);
int main() {

    Run("/home/jinm32/by/2013 new c/PathInput.txt",
        "/home/jinm32/by/2013 new c/PathRequest.txt",
        "/home/jinm32/by/2013 new c/output.txt");

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
void Verify_1(char str[]) {
    int len = strlen(str);
    for (int i = 1; i < len - 1; ++i) {
        str[i - 1] = str[i];
    }
    str[len - 2] = '\0';
}
int str_int(char num[]) {
    //直接忽略字符串最后的]
    int res = 0;
    for (int i = 0; i < strlen(num) - 1; ++i) {
        res = res * 10 + num[i] - '0';
    }
    return res;
}
int CanReach(Node a[],int x,char ori[],char des[],int n) {
    //printf("%s %s %d\n",ori,des,n);
    if (n == 1) {
        for (int i = 0; i < x; ++i) {
            if ((strcmp(a[i].ori, ori) == 0) && (strcmp(a[i].des, des) == 0))
                return 1;
        }
        return 0;
    } else {
        for (int i = 0; i < x; ++i) {
            if ((strcmp(a[i].ori, ori) == 0) && (strcmp(a[i].des, des) == 0))
                return 1;
        }

        for (int i = 0; i < x; ++i) {
            if (strcmp(a[i].ori, ori) == 0) {
                //printf("%s,%s,%d\n",a[i].des,des,n);
                if (CanReach(a, x, a[i].des, des, n - 1))
                    return 1;
            }
        }
        return 0;
    }
}
void Run(char *PathInput,char *PathRequest,char *Output) {
    FILE *in = fopen(PathInput, "r");
    FILE *req = fopen(PathRequest, "r");
    FILE *out = fopen(Output, "w");
    if (in == NULL) {
        printf("can not open file1\n");
        return;
    }
    if (req == NULL) {
        printf("can not open file2\n");
        return;
    }
    if (out == NULL) {
        printf("can not open file3\n");
        return;
    }
    int x;
    fscanf(in, "%d", &x);
    Node a[x];//放input数据
    for (int i = 0; i < x; ++i) {
        fscanf(in, "%s %s", a[i].ori, a[i].des);
        Verify_1(a[i].ori);
        a[i].des[strlen(a[i].des) - 1] = '\0';
        //printf("%s %s\n",a[i].ori,a[i].des);
    }

    int y;
    fscanf(req, "%d", &y);
    Node b[y];//放req数据
    for (int i = 0; i < y; ++i) {
        char num[8];
        fscanf(req, "%s %s %s", b[i].ori, b[i].des, num);
        Verify_1(b[i].ori);
        b[i].des[strlen(b[i].des) - 1] = '\0';
        b[i].n = str_int(num);
        //printf("%s %s %d\n",b[i].ori,b[i].des,b[i].n);
    }

    for (int i = 0; i < y; ++i) {
        if (CanReach(a, x, b[i].ori, b[i].des, b[i].n)) {
            fprintf(out, "%s %s %s\n", b[i].ori, b[i].des, "YES");
            //printf("%s %s %d\n", b[i].ori, b[i].des, b[i].n);
        } else {
            fprintf(out, "%s %s %s\n", b[i].ori, b[i].des, "NO");
        }

    }

    fclose(in);
    fclose(req);
    fclose(out);
}
