//2009年苏大上机题目
//（1）用IE浏览器从FTP上下载org.dat，并保存在D盘的根目录下。
//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的十进制或八进制数字，数字之间用“,”分开，数字内部存在且仅存在空格。
//（3）八进制数以起始位“0”作为标示与十进制数区分。
//（4）顺序读取这些数字将他们转变为十进制数后按从大到小的顺序排序后，输出到D盘根目录下new.txt，每个数字一行。
//eg：_235_,34__2,_043_1_,1_3   分别是：十进制235，十进制342.，八进制431，十进制13。_代表空格
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000
int str_int(char num[],int count){
    //str--十进制
    //-1 表示输入不规范
    if(count<1)
        return -1;
    int res;
    if(num[0]=='0'){
        //8进制
        if(count>2){
            res=num[1]-'0';
            for(int i=2;i<count;++i)
                res=res*8+num[i]-'0';
            return res;
        }
        else{
            return 0;
        }

    }
    else {
        res = num[0] - '0';
        for (int i = 1; i < count; ++i)
            res = res * 10 + num[i] - '0';
        return res;
    }
}
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

void ReadData(char *filename,char *outputfile){
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }

    int b[SIZE];//放转化的数字

    char ch=fgetc(fp);
    char num[24];
    int i=0;
    //_235_,34__2,_043_1_,1_3
    int count=0;
    while(ch!=EOF){
        i=0;
        do{
            if(ch==' '){
            }
            else{
                num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }while(ch!=','&&ch!=EOF);
        b[count]=str_int(num,i);
        count++;
        //printf("%d\n",str_int(num,i));
        ch=fgetc(fp);
    }
    fclose(fp);
    qsort(b,count,4,cmp);
    //for(int i=0;i<count;++i)
    //   printf("%d ",b[i]);
    /*
    FILE *out=fopen(outputfile,"w");
    if(out==NULL){
        printf("can not open file\n");
        return;
    }
    for(int i=0;i<count;++i)
        fputc(b[i],out);
    fclose(out);
    */

}
int main() {
    ReadData("/home/jinm32/by/2009/input.txt","/home/jinm32/by/2009/new.txt");
    //char a[]="321";
    //int x=str_int(a,3);
    //printf("%d",x-1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}