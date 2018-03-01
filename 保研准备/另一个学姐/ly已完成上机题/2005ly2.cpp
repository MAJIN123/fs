//2005
//第3道  统计篇文章中各英文字母的个数，并排序。
#include<stdio.h>
#include<stdlib.h>
struct list
{
	char ch;
	int num;
};
void readfile(char *filename,struct list arr[],int count)
{

	FILE *fp;
	char c;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		exit(0);
	}
	for(int i=0;i<count;i++)
	{
		arr[i].num=0;
		arr[i].ch=i+97;
	}
	while((c=fgetc(fp))!=-1)
	{
		if(c>='a'&&c<='z')
		{
			//arr[c-'a'].ch=c;
			arr[c-'a'].num++;
		}
		if(c>='A'&&c<='Z')
		{
			//arr[c-'A'].ch=c+32;
			arr[c-'A'].num++;
		}
	}
	fclose(fp);
}
void sort(struct list arr[],int count)
{
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(arr[i].num>arr[j].num)
			{
				struct list temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void display(struct list arr[],int count)
{
	for(int i=0;i<count;i++)
	{
		printf("%c:%d\n",arr[i].ch,arr[i].num);
	}
}
int main()
{
	struct list arr[26];
	readfile("e:\\2005.txt",arr,26);
	printf("排序前：\n");
	display(arr,26);
	sort(arr,26);
	printf("排序后：\n");
	display(arr,26);
	return 0;
}