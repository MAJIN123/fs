//0.请从服务器将两个数据文件input.txt和words.txt下载到本地电脑的D盘根文件夹。
//1.在D盘根文件夹的words.txt中存储了不超过30000条的英文单词，每个单词占一行。单>词的最大长度为20，且单词内部没有空格，文件中无重复单词。图1是该文件的一个局部样>例：
//2.在D盘根文件夹的input.txt中存储了一个“丢失”了空格和标点符号的英文文章。每行不
//超过128个字符，请编写程序把该文章中的前三行显示在屏幕上。（第一行和最后一行）
//3.编写程序将words.txt中的最后三行显示在屏幕上；（不做）
//4.编写程序利用words.txt中的单词作为词典，采用正向最大匹配切分单词算法对input.txt中的文本进行单词切分。切分时单词区分大小写，切分分割标记采用空格，并将切分后的
//结果写入到out.txt中。
//所谓正向最大匹配切分就是从左向右扫描待切分字符串，尽量取长词，该算法流程图参见
//图2。
//下面举一个简单例子：现有待切分字符串 “ABCDEFGHIJ”，设词典中最大单词长度为5。那
//么按照算法首先取出“ABCDE”判断是否是单词，如果是则切分到一个单词，否则舍弃最后一>个字母接着判断，也就是判断“ABCD”是否是单词，依此类推，当只有一个字母时可以直接认
//      定为是单词。在成功切分出一个单词后对待切分字符串余下的部分再次执行上述过程。
//5.编写程序实现步骤2、3描述的要求，并通过如下所示的主函数对进行验证，注意：除了
//指定添加的代码之外，不得修改main函数其余部分。对main函数每修改一处，总分扣3分，>最多扣10分。
//6.本次考试考核C语言程序设计，因此不可以使用C++的STL的任何功能，如果需要添加下>面样例之外的程序头文件，请举手得到监考老师批准。
//#include <iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
void Split(char line[],char words[][24],int count,FILE *fp);
void Read_Write(char *input,char *output,char words[][24],int count);
void ReadWords(char *filename,char words[][24],int *count);
void Qsort(char words[][24],int l,int r);
int main() {
    char words[30000][24];
    int count=0;

    clock_t start, finish;
    start = clock();

    ReadWords("/home/jinm32/by/2016 new/words.txt",words,&count);
    Qsort(words,0,count-1);
    Read_Write("/home/jinm32/by/2016 new/input.txt","/home/jinm32/by/2016 new/output.txt",words,count);
    finish = clock();
    printf("\nTotal time:%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);

    return 0;
}
void Split(char line[],char words[][24],int count,FILE *fp) {
    char temp[21] = {"\0"};
    int start = 0;
    int end = strlen(line) - 1;
    int flag = 0;

    while (start < end) {
        for (int i = start; i < 20 + start && line[i] != '\0'; ++i) {
            temp[i - start] = line[i];
            temp[i - start + 1] = '\n';
        }
        int a, b, mid;
        while (strlen(temp) > 0) {
            flag = 0;

            //二分查找，效率很高
            a = 0;
            b = count - 1;
            while (a <= b) {
                mid = a + ((b - a) >> 1);
                if (strcmp(words[mid], temp) > 0)
                    b = mid - 1;
                else {
                    if (strcmp(words[mid], temp) < 0)
                        a = mid + 1;
                    else {
                        //printf("yes  ");
                        flag = 1;
                        break;
                    }
                }
            }

            /*
             * 直接顺序查字典
            for (int i = 0; i < count; ++i) {
                if (strcmp(temp, words[i]) == 0) {
                    //找到了
                    flag = 1;
                    break;
                }
            }
            */
            if (flag || strlen(temp) == 1) {
                fprintf(fp, "%s ", temp);
                start = start + strlen(temp);
                break;
            } else {
                temp[strlen(temp) - 1] = '\0';
            }
        }

    }

    fprintf(fp, "\n");
}
void Read_Write(char *input,char *output,char words[][24],int count) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    if (in == NULL) {
        printf("can not open file\n");
        return;
    }
    if (out == NULL) {
        printf("can not open file\n");
        return;
    }

    char line[128];
    while (!feof(in)) {
        fscanf(in, "%s", line);
        Split(line, words, count, out);
    }

    fclose(in);
    fclose(out);
}
void ReadWords(char *filename,char words[][24],int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("can not open file\n");
        return;
    }
    while (!feof(fp)) {
        fscanf(fp, "%s", words[*count]);
        //printf("%s\n",words[*count]);
        (*count)++;
    }
    fclose(fp);
}
void Qsort(char words[][24],int l,int r) {
    int i, j;
    char index[24];
    if (l < r) {
        i = l;
        j = r;
        strcpy(index, words[i]);
        while (i < j) {
            while (i < j && strcmp(words[j], index) > 0)
                j--;
            if (i < j)
                strcpy(words[i++], words[j]);
            while (i < j && strcmp(index, words[i]) > 0)
                i++;
            if (i < j)
                strcpy(words[j--], words[i]);
        }
        strcpy(words[i], index);
        Qsort(words, l, i - 1);
        Qsort(words, i + 1, r);

    }
}

