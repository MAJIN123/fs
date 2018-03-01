//��������ӱ	
//ѧ��:1427407025
//������˼·������
//0.��ӷ����������������ļ�input.txt��words.txt���ص����ص��Ե�D�̸��ļ��С�
//1.��D�̸��ļ��е�words.txt�д洢�˲�����30000����Ӣ�ĵ��ʣ�ÿ������ռһ�С����ʵ���󳤶�Ϊ20���ҵ����ڲ�û�пո��ļ������ظ����ʡ�ͼ1�Ǹ��ļ���һ���ֲ�������
//2.��D�̸��ļ��е�input.txt�д洢��һ������ʧ���˿ո�ͱ����ŵ�Ӣ�����¡�ÿ�в�����128���ַ������д����Ѹ������е�ǰ������ʾ����Ļ�ϡ�����һ�к����һ�У�
//3.��д����words.txt�е����������ʾ����Ļ�ϣ���������
//4.��д��������words.txt�еĵ�����Ϊ�ʵ䣬�����������ƥ���зֵ����㷨��input.txt�е��ı����е����з֡��з�ʱ�������ִ�Сд���зַָ��ǲ��ÿո񣬲����зֺ�Ľ��д�뵽out.txt�С�
//��ν�������ƥ���з־��Ǵ�������ɨ����з��ַ���������ȡ���ʣ����㷨����ͼ�μ�ͼ2��
//�����һ�������ӣ����д��з��ַ��� ��ABCDEFGHIJ������ʵ�����󵥴ʳ���Ϊ5����ô�����㷨����ȡ����ABCDE���ж��Ƿ��ǵ��ʣ���������зֵ�һ�����ʣ������������һ����ĸ�����жϣ�Ҳ�����жϡ�ABCD���Ƿ��ǵ��ʣ��������ƣ���ֻ��һ����ĸʱ����ֱ���϶�Ϊ�ǵ��ʡ��ڳɹ��зֳ�һ�����ʺ�Դ��з��ַ������µĲ����ٴ�ִ���������̡�
//5.��д����ʵ�ֲ���2��3������Ҫ�󣬲�ͨ��������ʾ���������Խ�����֤��ע�⣺����ָ����ӵĴ���֮�⣬�����޸�main�������ಿ�֡���main����ÿ�޸�һ�����ֿܷ�3�֣�����10�֡�
//6.���ο��Կ���C���Գ�����ƣ���˲�����ʹ��C++��STL���κι��ܣ������Ҫ�����������֮��ĳ���ͷ�ļ�������ֵõ��࿼��ʦ��׼��
#include <time.h>
#include <stdio.h>
#include <string.h>
#define SIZE 30000
//=====================================
//�ú���������ʾ�ļ��ĵ�һ�к����һ��
//����Ϊchar��ָ�룬ָ���ļ���
//�޷���ֵ
//=====================================
void showFirstAndLastLine(char *filename)
{
	FILE *fp;
	char line[256];

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	if(fgets(line,130,fp)==NULL)    //���ļ���һ��
	{
		printf("Can not read the file!\n");
		return;
	}
	printf("First Line: %s",line);
	while(fgets(line,130,fp)!=NULL);//һֱ�����ļ�β
	printf("Last Line: %s\n",line);//��ӡ���һ��
	fclose(fp);//���ļ�
}
//==================================================
//�ú������ڽ������ļ����ݶ�ȡ����ά������
//����Ϊchar��ָ�룬ָ���ļ������Լ���ά�������е�ַ
//����ֵΪ�����ĵ��ʸ���
//==================================================
int ReadWords(char *filename,char words[][24])
{
	FILE *fp;
	int i=0;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return -1;
	}
	while(fgets(words[i],24,fp)!=NULL)//ѭ�������ļ�β
	{
		i++;
	}
	for(int j=0;j<i-1;j++) //��ÿ����������'\n'ȥ�����������һ������û�У�
	{
		words[j][strlen(words[j])-1]='\0';
	}
	fclose(fp);
	return i;//���ض����ĵ��ʸ���
}
//==========================================================
//�ú���������ʾ��ά��������lastlines��
//����Ϊ��ά�������е�ַ����ά������Ч���������Լ�lastlines
//�޷���ֵ
//==========================================================
void Display(char words[][24],int count,int lastlines)
{
	printf("���ʱ����%d��Ϊ��\n",lastlines);
	for(int i=count-lastlines;i<=count-1;i++)
	{
		printf("%s",words[i]);
		printf("\n");
	}
}
//======================================================================================
//�ú��������з�һ���ַ��������зֺõ��ַ��������ļ�
//����Ϊһλ����ָ�루ָ��Ҫ�зֵ��ַ��������ļ�ָ�룬�Լ���ά��������ָ�룬int�ͼ�������
//�޷���ֵ
//=======================================================================================
void split(char *arr,FILE *fp,char words[][24],int count)
{
	int start=0;
	int end=strlen(arr)-1;
	char temp[21]={'\0'};   //��󵥴ʳ�����20,�������ڴ���з��������ַ����鳤��Ϊ21�����һλ'\0'���㹻
	while(start<=end)       //��start<=end��ʱ��ִ��ѭ��
	{
		int i;
		for(i=start;(i<start+20)&&arr[i]!='\0';i++)  //��һ���в�������󳤶�20���Ӵ��ŵ�temp��
		{
			temp[i-start]=arr[i];
			temp[i-start+1]='\0';
		}
		loop1:
		if(strlen(temp)==1)                          //temp����Ϊ1����һ����һ�����ʣ�����д���ļ��������˵��ʺ�����Ͽո񣩣�����start��С����temp�ĳ���1���Ӷ�������һ��ѭ��
		{
			fprintf(fp,"%s ",temp);
			//printf("%s ",temp);
			start=start+strlen(temp);
		}
		else                                         //temp���Ȳ�Ϊ1����Ҫ��ʼ�ж���
		{
			int j;
			//int begin=0;
			//int stop;
			int flag=0;
			//while(strlen(temp)>strlen(words[begin]))//������whileѭ����word[begin]Ϊ��һ��������temp��ͬ�ĵ��ʵ��ʱ�Ȼ��ȫ�ǰ������ŵ�!!!!����
			//{
			//	begin++;
			//}
			//stop=begin;
			//while(strlen(temp)>=strlen(words[stop]))//������whileѭ����word[stop]Ϊ��һ�����ȴ���temp�ĵ���
			//{
			//	stop++;
			//}
			for(j=0;j<count;j++)                     //��temp�뵥�ʱ���ĵ������αȽϣ�����Ӧ�ÿ����Ż��������е�����
			{

				if(strcmp(temp,words[j])==0)//temp�ǵ���
				{
					flag=1;
					break;
				}
			}
			if(flag==1)//temp�ǵ��ʣ�����д���ļ��������˵��ʺ�����Ͽո񣩣�����start��С����temp�ĳ��ȣ��Ӷ�������һ��ѭ��
			{
				fprintf(fp,"%s ",temp);
				//printf("%s ",temp);
			    start=start+strlen(temp);
			}
			else//temp���ǵ��ʣ�ȥ��temp���ұ�һ�����ʣ������ж�temp�Ƿ�Ϊ1�����
			{
				temp[strlen(temp)-1]='\0';//ȥ��temp���ұ�һ������
				goto loop1;
			}
		}

	}
	fprintf(fp,"\n");
	//printf("\n");
}
//======================================================================================
//�ú��������з�һ���ַ��������зֺõ��ַ��������ļ���������û��goto���ģ�
//����Ϊһλ����ָ�루ָ��Ҫ�зֵ��ַ��������ļ�ָ�룬�Լ���ά��������ָ�룬int�ͼ�������
//�޷���ֵ
//=======================================================================================
void split1(char *arr,FILE *fp,char words[][24],int count)
{
	int start=0;
	int end=strlen(arr)-1;
	char temp[21]={'\0'};   //��󵥴ʳ�����20,�������ڴ���з��������ַ����鳤��Ϊ21�����һλ'\0'���㹻
	while(start<=end)       //��start<=end��ʱ��ִ��ѭ��
	{
		int i;
		for(i=start;(i<start+20)&&arr[i]!='\0';i++)  //��һ���в�������󳤶�20���Ӵ��ŵ�temp��
		{
			temp[i-start]=arr[i];
			temp[i-start+1]='\0';
		}
		//loop1:
		while(strlen(temp)!=1)
		{
			int j;
			//int begin=0;
			//int stop;
			int flag=0;
			//while(strlen(temp)>strlen(words[begin]))//������whileѭ����word[begin]Ϊ��һ��������temp��ͬ�ĵ��ʵ��ʱ�Ȼ��ȫ�ǰ������ŵ�!!!!����
			//{
			//	begin++;
			//}
			//stop=begin;
			//while(strlen(temp)>=strlen(words[stop]))//������whileѭ����word[stop]Ϊ��һ�����ȴ���temp�ĵ���
			//{
			//	stop++;
			//}
			for(j=0;j<count;j++)                     //��temp�뵥�ʱ���ĵ������αȽϣ�����Ӧ�ÿ����Ż��������е�����
			{

				if(strcmp(temp,words[j])==0)//temp�ǵ���
				{
					flag=1;
					break;
				}
			}
			if(flag==1)//temp�ǵ��ʣ�����д���ļ��������˵��ʺ�����Ͽո񣩣�����start��С����temp�ĳ��ȣ��Ӷ�������һ��ѭ��
			{
				fprintf(fp,"%s ",temp);
				//printf("%s ",temp);
			    start=start+strlen(temp);
				break;
			}
			else//temp���ǵ��ʣ�ȥ��temp���ұ�һ�����ʣ������ж�temp�Ƿ�Ϊ1�����
			{
				temp[strlen(temp)-1]='\0';//ȥ��temp���ұ�һ������
				//goto loop1;
			}
		}
		if(strlen(temp)==1)                          //temp����Ϊ1����һ����һ�����ʣ�����д���ļ��������˵��ʺ�����Ͽո񣩣�����start��С����temp�ĳ���1���Ӷ�������һ��ѭ��
		{
			fprintf(fp,"%s ",temp);
			//printf("%s ",temp);
			start=start+strlen(temp);
		}
	}
	fprintf(fp,"\n");
	//printf("\n");
}
//======================================================================================
//�ú�����������words.txt�еĵ�����Ϊ�ʵ䣬
//�����������ƥ���зֵ����㷨��input.txt�е��ı����е����з֡�
//�з�ʱ�������ִ�Сд���зַָ��ǲ��ÿո񣬲����зֺ�Ľ��д�뵽out.txt�С�
//����Ϊ�����ļ���������ļ������Լ���ά��������ָ�룬int�ͼ�������
//�޷���ֵ
//=======================================================================================
void WriteFile(char*filename1,char *filename2,char words[][24],int count)
{
	FILE *fp,*fp2;
	char line[256];           //��Ŵ��ļ��ж�ȡ��һ���ַ���
	fp=fopen(filename1,"r");  //���ļ�
	fp2=fopen(filename2,"w");//���ļ�
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		return;
	}
	if(fp2==NULL)
	{
		printf("Can not open the file to write!\n");
		return;
	}
	while(fgets(line,130,fp)!=NULL)//һֱ�����ļ�β
	{
		if(line[strlen(line)-1]=='\n')//��ÿһ������'\n'ȥ��������'\n'����Ϊ���ú���fgets��ԭ�򣨳������һ��û�У���ȥ���о�����ͦ�鷳�ġ�����
		{
			line[strlen(line)-1]='\0';
		}
		split1(line,fp2,words,count);//����split����������ȡ������һ���ַ����зֺ÷ŵ���һ���ļ���ȥ
	}
	fclose(fp);//���ļ�
	fclose(fp2);//���ļ�
}
int main()
{
	char words[SIZE][24];
	clock_t start, finish;
	start = clock();

	showFirstAndLastLine("d:\\input.txt");
//��input�ļ��ĵ�һ�к����һ����ʾ����Ļ��

	int count = ReadWords("d:\\words.txt", words);
	//��ȡӢ���ֵ䣬�����ص�������
	Display(words,count,3);
//�˴�������Ӵ����߼���ʵ����Ŀ�ĵ�3��Ҫ��
//���齫��Ҫ�Ĺ���ʵ��Ϊ����������ڴ�ֱ�ӻ��߼�ӵ���
	WriteFile("d:\\input.txt","d:\\out.txt",words,count);
	finish = clock();
	printf("Total time:%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);

    return 0;
}