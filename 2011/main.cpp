//2011年上机复试题

//第一道：输出~9999中满足一下条件的所有数：
//(1)该数是素数
//(2)十位数和个位数组成的数是素数，百位数和个位数组成的数是素数
//(3)千位数和百位数组成的数是素数，千位数和十位数组成的数是素数

//第二道：
//从ftp上下载一个文本info.txt，其中是一段关于计算机历史的英文文档（不过是加过密的，打开看全是乱码），
//要求密钥cip1和cip2以及解密后的第一个句子。条件：
//(1)cip1和cip2都是八位无符号整数；
//(2)加密过程：每次从文本中读出八位字符，然后将该字符和密钥交替异或便是该位置的密文。
//如第个字节与cip1异或，第个字节和cip2异或，第个字节和cip1异或，。。。，如此循环至结束。
//最后输出cip1和cip2以及第一段完整的英文句子。

//#include <iostream>

#include <stdio.h>
#include <math.h>
int Is_prime(int a){
    if(a<2)
        return 0;

    for(int i=2;i<sqrt(a*1.0);++i) {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
void Question_1(){
//(1)该数是素数
//(2)十位数和个位数组成的数是素数，百位数和个位数组成的数是素数
//(3)千位数和百位数组成的数是素数，千位数和十位数组成的数是素数
    for(int i=1000;i<10000;++i){
        int num[4];
        num[3]=i/1000;//千
        num[2]=(i/100)%10;//百
        num[0]=i%10;//个
        num[1]=(i/10)%10;//十
        //printf("%d%d%d%d%d\n",num[3],num[2],num[1],num[0],i);
        int x=num[2]*10+num[0];//百 个
        int y=num[3]*10+num[1];
        //printf("%d  %d  %d\n",x,y,i);
        if(Is_prime(i)&&Is_prime(i%100)&&Is_prime(x)&&Is_prime(i/100)&&Is_prime(y)){
            printf("%d\n",i);
        }
    }
}
int main() {
    Question_1();
    return 0;
}