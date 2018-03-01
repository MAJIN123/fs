#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void run(void);

int main()
{
	LARGE_INTEGER m_nFreq;
    LARGE_INTEGER m_nBeginTime;
    LARGE_INTEGER m_nEndTime;

    QueryPerformanceFrequency(&m_nFreq);
    QueryPerformanceCounter(&m_nBeginTime);

	run();

    QueryPerformanceCounter(&m_nEndTime);
	printf("\nElapsed Time = %lf sec\n", (double)(m_nEndTime.QuadPart-m_nBeginTime.QuadPart)/m_nFreq.QuadPart);
	return 0;
}
// ------------------------------以上代码不得进行任何修改------------------------------------

// --------------------------------------考题如下------------------------------------------
// 已知：	二进制数据文件1.bin中存放了100000个样本点，每个样本点由4个属性构成，属性均为整型。
// 定义：	如a点的所有属性都不比b点的对应属性差（属性值越小越好），
//			且a点至少有一个属性比b点的对应属性好，则称a点支配b点。
// 要求：	求出不被任何点支配的样本点的个数。
//			在试卷上填写求出的样本点个数和所用时间（Elapsed Time）。
// ---------------------------------------------------------------------------------------

// --------------------------------从此处开始添加代码---------------------------------------

// run函数为起点函数。此函数原型不能改。
void run(void)
{
	return;
}
