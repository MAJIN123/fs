/*
文本文件input.txt由若干英文单词和分隔符（空格，回车，换行）构成。根据如下说明编写程序统计不同单词出现的次数（频度）。
 将统计结果按出现频度从高到低排序，并将出现频度大于1的单词及其频度输出到文件output.txt中。文件格式如图1所示。
说明：
(1) 多个连续的分隔符被视为一个分隔符。
(2) 单词大小写敏感。
(3) 每个单词的长度不超过20个字符。
(4) 单词的数量未知。如使用定义静态大数组的方式来统计，将被扣除5分。
 */
//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node {
    char word[20];
    int count;
    struct node *next;
}Node,*Pnode;
int Is_ch(char ch) {
    if (ch > 64 && ch < 123)
        return 1;
    return 0;
}
void Insert(Pnode Linkedlist,char word[]) {
    //头节点
    Pnode p = Linkedlist;
    while (p->next) {
        if (strcmp(word, p->next->word) == 0) {
            p->next->count++;
            return;
        }
        p = p->next;
    }
    p->next = (Pnode) malloc(sizeof(Node));
    strcpy(p->next->word, word);
    p->next->count = 1;
    p->next->next = NULL;

}
Pnode ReadData(char *filename) {

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("can not open file\n");
        exit(1);
    }
    Pnode head = (Pnode) malloc(sizeof(Node));
    head->next = NULL;
    char ch = fgetc(fp);
    char word[20];
    int len = 0;
    while (ch != EOF) {
        if (!Is_ch(ch)) {
            if (len < 1) { ;
            } else {
                Insert(head, word);
                //printf("%s\n",word);
                len = 0;
            }
        } else {
            word[len] = ch;
            word[len + 1] = '\0';
            len++;
        }
        ch = fgetc(fp);
    }
    fclose(fp);
    return head;

}
void sort(Pnode head) {
    Pnode p, q;
    q = head;
    char temp[20];
    int x;
    while (q->next) {
        p = q->next;
        while (p->next) {
            if (p->next->count > q->next->count) {
                strcpy(temp, q->next->word);
                strcpy(q->next->word, p->next->word);
                strcpy(p->next->word, temp);

                x = q->next->count;
                q->next->count = p->next->count;
                p->next->count = x;

            }
            p = p->next;
        }
        q = q->next;
    }

}
void WriteFile(char *filename,Pnode head) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("can not open file\n");
        exit(1);
    }
    Pnode p = head;
    while (p->next) {
        if (p->next->count < 2) {
            fclose(fp);
            return;
        }
        fprintf(fp, "%s:%d\n", p->next->word, p->next->count);
        p = p->next;
    }
    fclose(fp);
}
int main() {
    Pnode head = ReadData("/home/jinm32/by/2016fu/input.txt");
    sort(head);
    WriteFile("/home/jinm32/by/2016fu/output.txt", head);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}