/*
input.bin中有10000组数据，每组数据有4个属性，都为整型。
定义邻近点为拥有k个距离小于等于d的点的点，
d=根号下（(b1-a1)*(b1-a1)+(b2-a2)*(b2-a2)+(b3-a3)*(b3-a3)+(b4-a4)*(b4-a4)）;
现定义k=10，d=7500，显示出符合点的编号及其各个属性。
 */
#include <iostream>
using namespace std;
#include<math.h>
struct data{
    int num[4];
}data[10000];
void run(char * filename,int k,long int d){
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("can not open file\n");
        return;
    }
    for(int i=0;i<10000;i++){
        fread(&data[i],sizeof(struct data),1,fp);
    }
    fclose(fp);
    int count=0;
    for(int i=0;i<10000;++i){
        int b0=data[i].num[0];
        int  b1=data[i].num[1];
        int  b2=data[i].num[2];
        int  b3=data[i].num[3];
        count=0;
        for(int j=0;j<10000;j++){
            if(i==j)
                continue;
            int a0=data[j].num[0];
            int a1=data[j].num[1];
            int a2=data[j].num[2];
            int a3=data[j].num[3];
            double dis= sqrt(1.0*(long long)abs(((b0 - a0) * (b0 - a0)/100000000 + (b1 - a1) * (b1 - a1)/100000000 + (b2 - a2) * (b2 - a2)/100000000 + (b3 - a3) * (b3 - a3)/100000000)));
            //printf("%.2lf  ",dis);
            if(dis<=d/10000){
                //printf("第%d个：",i);
                //printf("%d,%d,%d,%d\n",b0,b1,b2,b3);
                count++;
                if(count>k){
                   // cout<<count<<endl;
                    break;
                }
            }
        }
        if(count<=k){
            printf("第%d个：",i);
            printf("%d,%d,%d,%d\n",b0,b1,b2,b3);

        }

    }
}
int main() {
    run("/home/jinm32/by/2014fu/1.bin",110,7500);
    return 0;
}