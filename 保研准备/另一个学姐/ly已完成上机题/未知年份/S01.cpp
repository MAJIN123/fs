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
// ------------------------------���ϴ��벻�ý����κ��޸�------------------------------------

// --------------------------------------��������------------------------------------------
// ��֪��	�����������ļ�1.bin�д����100000�������㣬ÿ����������4�����Թ��ɣ����Ծ�Ϊ���͡�
// ���壺	��a����������Զ�����b��Ķ�Ӧ���Բ����ֵԽСԽ�ã���
//			��a��������һ�����Ա�b��Ķ�Ӧ���Ժã����a��֧��b�㡣
// Ҫ��	��������κε�֧���������ĸ�����
//			���Ծ�����д��������������������ʱ�䣨Elapsed Time����
// ---------------------------------------------------------------------------------------

// --------------------------------�Ӵ˴���ʼ��Ӵ���---------------------------------------

// run����Ϊ��㺯�����˺���ԭ�Ͳ��ܸġ�
void run(void)
{
	return;
}
