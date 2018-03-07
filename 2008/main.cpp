//2008年苏大上机题目
//（1）用IE从FTP上下载org.dat，并保存在D盘的根目录中。
//（2）此文件中按文本方式存放了一段其他文章，其中有若干长度小于15的英文单词，单词之间用空格分开，无其他符号。
//（3）顺序读取这段文章的不同的单词（大小写敏感），同时在读取的过程中排除所有的单词THE以及变形，即这些单词不能出现在读取的结果中。
//（4）将读取的所有单词的首字母转大写后，输出D根目录下new.txt，每个单词一行。
//那段文字可以点右键打开方式中用记事本打开，内容是：
//The constructor is used to initialize the object The destructor is
//used to delete the Object the calling sequence of constructor is opposite to the calling sequence of destructor
//正确结果应该是
//Constructor
//Is
//Used
//To
//Initialize
//Object
//Destructor
//Delete
//Object
//Calling
//Sequence
//Of
//Opposite
//注意有两个Object
//因为第一次读取是大小写敏感的，后来又进行了首字母大写转化
//#include <iostream>
#include<stdio.h>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}