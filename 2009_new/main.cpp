#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
//2009年苏大上机题目
//（1）用IE浏览器从FTP上下载org.dat，并保存在D盘的根目录下。
//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的十进制或八进制数字，数字之间用“,”分开，数字内部存在且仅存在空格。
//（3）八进制数以起始位“0”作为标示与十进制数区分。
//（4）顺序读取这些数字将他们转变为十进制数后按从大到小的顺序排序后，输出到D盘根目录下new.txt，每个数字一行。

//eg：_235_,34__2,_043_1_,1_3   分别是：十进制235，十进制342.，八进制431，十进制13。_代表空格
*/

typedef struct node {
    int num;
    struct node *next;
}Node;

void Sort(Node *head) {
    Node *p, *x, *cur;
    cur = head->next;
    while (cur) {
        x = cur;
        p = cur->next;
        while (p) {
            if (p->num > x->num)
                x = p;
            p = p->next;
        }

        int tmp = x->num;
        x->num = cur->num;
        cur->num = tmp;

        cur = cur->next;
    }
}
int str_int(char data[]) {
    int res = 0;
    int i = 0;
    while (data[i] == ' ' && i < strlen(data)) {
        //过滤空格
        i++;
    }
    if (data[i] == '0') {
        //八进制
        i++;
        for (i; i < strlen(data); ++i) {
            if (data[i] == ' ')
                continue;
            res = res * 8 + data[i] - '0';
        }
        return res;
    } else {
        //十进制
        for (i; i < strlen(data); ++i) {
            if (data[i] == ' ')
                continue;
            res = res * 10 + data[i] - '0';
        }
        return res;

    }


}
void Run(char *input,char *output) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    if (in == NULL || out == NULL) {
        printf("can  not open file\n");
        return;
    }
    char data[15];
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    while (fscanf(in, "%[^,],", data) != EOF) {
        //printf("%s\n",data);
        int val = str_int(data);
        Node *p = (Node *) malloc(sizeof(Node));
        if (p) {
            p->num = val;
            p->next = NULL;
        }
        p->next = head->next;
        head->next = p;


    }
    Sort(head);

    Node *p = head;
    while (p->next) {
        fprintf(out, "%d\n", p->next->num);

        p = p->next;
    }
    fclose(in);
    fclose(out);
}
int main() {
    Run("/home/jinm32/by/2009_new/input.txt", "/home/jinm32/by/2009_new/output.txt");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}