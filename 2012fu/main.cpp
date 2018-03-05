//二进制数据文件1.bin中存放了100000个样本点，每个样本点由4个属性构成，属性均为整型。
// 定义：	如a点的k个属性不比b点的对应属性差（属性值越小越好），
//	 且a点至少有一个属性比b点的对应属性好，则称a点k-支配b点。
// 要求：	求出不被任何点k-支配的样本点的个数。
//	 在试卷上填写求出的样本点个数和所用时间（Elapsed Time）。
//#include <iostream>
#include <stdio.h>
#include <time.h>
struct data{
    int num[4];
}data[100000];

void ReadFile(char *filename){
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    for(int i=0;i<100000;++i){
        fread(&data[i],sizeof(struct data),1,fp);
        //printf("%d\n",data[i].num[1]);
    }
    fclose(fp);
    return;
}
//p1 ctl p2  ?
int ctl(struct data p1, struct data p2,int k){
    int f1=0,f2=0;
    for(int i=0;i<4;++i){
        if(p1.num[i]<=p2.num[i])
            f1++;
        if(p1.num[i]<p2.num[i])
            f2++;
    }
    if(f2&&f1>=k)
        return 1;
    else
        return 0;
    //4 ctl
    /*
    if(p1.num[0]<=p2.num[0]&&p1.num[1]<=p2.num[1]&&p1.num[2]<=p2.num[2]&&p1.num[3]<=p2.num[3]
       &&(p1.num[0]<p2.num[0]||p1.num[1]<p2.num[1]||p1.num[2]<p2.num[2]||p1.num[3]<p2.num[3]))
        return 1;
        */

}
int run(int k){
    int res=0;
    int flag=0;
    for(int i=0;i<100000;++i){
        flag=0;//默认没被支配
        for(int j=0;j<100000;++j){
            if(i==j)
                continue;
            if(ctl(data[j],data[i],k)){
                //i 被 j k支配
                flag=1;
                break;
            }
        }//end for j
        if(flag==1){
            //被支配
            //do nothing
        }
        else{
            res++;
        }
    }//end for i
    return res;    //317??
}
int main() {
    clock_t start, finish;
    start = clock();

    ReadFile("/home/jinm32/by/2012fu/1.bin");
    int k=3;
    printf("不被任何点%d-支配的样本点的个数:%d",k,run(k));

    finish = clock();
    printf("\nElapsed Time :%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);

    return 0;
}