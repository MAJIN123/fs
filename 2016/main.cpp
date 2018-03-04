//0.请从服务器将两个数据文件input.txt和words.txt下载到本地电脑的D盘根文件夹。
//1.在D盘根文件夹的words.txt中存储了不超过30000条的英文单词，每个单词占一行。单词的最大长度为20，且单词内部没有空格，文件中无重复单词。图1是该文件的一个局部样例：
//2.在D盘根文件夹的input.txt中存储了一个“丢失”了空格和标点符号的英文文章。每行不超过128个字符，请编写程序把该文章中的前三行显示在屏幕上。（第一行和最后一行）
//3.编写程序将words.txt中的最后三行显示在屏幕上；（不做）
//4.编写程序利用words.txt中的单词作为词典，采用正向最大匹配切分单词算法对input.txt中的文本进行单词切分。切分时单词区分大小写，切分分割标记采用空格，并将切分后的结果写入到out.txt中。
//所谓正向最大匹配切分就是从左向右扫描待切分字符串，尽量取长词，该算法流程图参见图2。
//下面举一个简单例子：现有待切分字符串 “ABCDEFGHIJ”，设词典中最大单词长度为5。那么按照算法首先取出“ABCDE”判断是否是单词，如果是则切分到一个单词，否则舍弃最后一个字母接着判断，也就是判断“ABCD”是否是单词，依此类推，当只有一个字母时可以直接认定为是单词。在成功切分出一个单词后对待切分字符串余下的部分再次执行上述过程。
//5.编写程序实现步骤2、3描述的要求，并通过如下所示的主函数对进行验证，注意：除了指定添加的代码之外，不得修改main函数其余部分。对main函数每修改一处，总分扣3分，最多扣10分。
//6.本次考试考核C语言程序设计，因此不可以使用C++的STL的任何功能，如果需要添加下面样例之外的程序头文件，请举手得到监考老师批准。
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define SIZE 35512
void ReadFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("can not open file!\n");
        return;
    }
    char buff[SIZE];
    if (fgets(buff, 130, fp) == NULL) {
        printf("can not read firs line");
    }
    printf("first line: %s", buff);
    while (fgets(buff, 130, fp) != NULL);
    printf("last line: %s", buff);
    fclose(fp);
}
int ReadWords(char *filename,char words[][24]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("can not open file\n");
        return -1;
    }
    int i = 0;
    while (fgets(words[i], 24, fp) != NULL) {
        i++;
    }
    for (int j = 0; j < i - 1; ++j) {
        words[j][strlen(words[j]) - 1] = '\0';
    }
    fclose(fp);
    return i;
}

void split(char buff[],char words[][24],int count,FILE *fp) {
    char temp[21]={'\0'};
    int flag = 0;
    int start = 0;
    int end = strlen(buff)-1;
    while (start <= end) {
        for (int i = start; (i < (start + 20)) && buff[i] != '\0'; ++i) {
            temp[i - start] = buff[i];
            temp[i - start + 1] = '\0';
        }
        while (strlen(temp) > 1) {
            for (int j = 0; j < count; ++j) {
                if (strcmp(temp, words[j]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                fprintf(fp, "%s ", temp);
                start = start + strlen(temp);
                flag=0;
                break;
            } else {
                temp[strlen(temp) - 1] = '\0';
            }

        }
        if (strlen(temp) == 1) {
            fprintf(fp, "%s ", temp);
            start = start + strlen(temp);
        }
    }
    fprintf(fp, "\n");
}
void WriteFile(char *f1,char *f2,char words[][24],int count){
    FILE *fp1=fopen(f1,"r");
    FILE *fp2=fopen(f2,"w");
    if(fp1==NULL){
        printf("can not read file\n");
        return;
    }
    if(fp2==NULL){
        printf("can not write file\n");
        return;
    }
    char buff[SIZE];
    while(fgets(buff,130,fp1)!=NULL){
        if(buff[strlen(buff)-1]=='\n') {
            buff[strlen(buff) - 1] = '\0';
        }
        split(buff,words,count,fp2);
    }

    fclose(fp1);
    fclose(fp2);
}
int main() {
    char words[SIZE][24];
    clock_t start, finish;
    start = clock();

    ReadFile("/home/jinm32/by/2016/input.txt");

    int count=ReadWords("/home/jinm32/by/2016/words.txt",words);
    WriteFile("/home/jinm32/by/2016/input.txt","/home/jinm32/by/2016/output.txt",words,count);

    finish = clock();
    printf("\nTotal time:%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}