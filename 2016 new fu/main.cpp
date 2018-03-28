#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
文本文件input.txt由若干英文单词和分隔符（空格，回车，换行）构成。根据如下说明编>写程序统计不同单词出现的次数（频度）。
将统计结果按出现频度从高到低排序，并将出现频度大于1的单词及其频度输出到文件output.txt中。文件格式如图1所示。
说明：
(1) 多个连续的分隔符被视为一个分隔符。
(2) 单词大小写敏感。
(3) 每个单词的长度不超过20个字符。
(4) 单词的数量未知。如使用定义静态大数组的方式来统计，将被扣除5分。
*/
typedef struct node{
    char word[24];
    int count;
    struct node *next;
}Node;

void Insert(Node *head,Node *p);
void Insert(Node *head,Node *p);
void sort(Node *head);
void ReadFile(char *filename,Node *head);
void WriteFile(char *filename,Node *head);
void Display(Node *head);
int main() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    ReadFile("/home/jinm32/by/2016 new fu/input.txt", head);
    sort(head);
    //Display(head);
    WriteFile("/home/jinm32/by/2016 new fu/output.txt", head);
    return 0;
}
void Insert(Node *head,Node *p) {
    Node *q = head;
    while (q->next) {
        if (strcmp(q->next->word, p->word) == 0) {
            q->next->count++;
            return;
        }
        q = q->next;
    }
    q->next = p;
}
void sort(Node *head) {
    Node *p = head->next;
    Node *q, *x;
    Node temp;

    while (p) {
        x = p;
        q = p->next;
        while (q) {
            if (q->count > x->count)
                x = q;
            q = q->next;
        }
        if (x != p) {
            strcpy(temp.word, x->word);
            temp.count = x->count;

            strcpy(x->word, p->word);
            x->count = p->count;

            strcpy(p->word, temp.word);
            p->count = temp.count;
        }

        p = p->next;
    }
}
void ReadFile(char *filename,Node *head) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("can not ope file\n");
        return;
    }
    char temp[24];
    while (!feof(fp)) {
        fscanf(fp, "%s", temp);
        Node *p = (Node *) malloc(sizeof(Node));
        strcpy(p->word, temp);
        if (p) {
            p->next = NULL;
            p->count = 1;
            Insert(head, p);
        }
    }

    fclose(fp);
}
void WriteFile(char *filename,Node *head) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("can not open file");
        return;
    }
    Node *p = head;
    while (p->next) {
        fprintf(fp, "%s:%d\n", p->next->word, p->next->count);
        p = p->next;
    }

    fclose(fp);
}
void Display(Node *head) {
    Node *p = head;
    while (p->next) {
        printf("%d\n", p->next->count);
        p = p->next;
    }
}
