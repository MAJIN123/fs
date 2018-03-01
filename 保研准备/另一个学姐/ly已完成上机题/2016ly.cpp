//文本文件input.txt由若干英文单词和分隔符（空格，回车，换行）构成。根据如下说明编写程序统计不同单词出现的次数（频度）。
//将统计结果按出现频度从高到低排序，并将出现频度大于5的单词及其频度输出到文件output.txt中。文件格式如图1所示。
//说明：
//(1)多个连续的分隔符被视为一个分隔符。
//(2)单词大小写敏感。
//(3)每个单词的长度不超过20个字符。
//(4)单词的数量未知。如使用定义静态大数组的方式来统计，将被扣除5分。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct word)
struct word
{
	char spelling[25];
	int count;
	struct word *next;
};
struct word *create(void)
{
	struct word *p;
	p=(struct word *)malloc(LEN);
	if(p!=NULL)
	{
		p->next=NULL;
	}
	return p;
}
void insert(struct word *head,struct word *ptr)
{
	if(ptr==NULL)
		return;
	struct word *temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=ptr;
	ptr->next=NULL;
}
struct word *create_node(char *spelling)
{
	struct word *p;
	p=(struct word *)malloc(LEN);
	if(p!=NULL)
	{
		strcpy(p->spelling,spelling);
		p->count=1;
		p->next=NULL;
	}
	return p;
}
struct word * find(struct word *head,char *spelling)
{
	struct word *p;
	p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->spelling,spelling)==0)
			break;
		p=p->next;
	}
	return p;
}
struct word * readfile(char *filename)
{
	FILE *fp;
	struct word *head,*p;
	char ch;
	char last;//放最后一个字符
	char temp[25]={'\0'};
	int i=0;//别忘啦初始化
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Can not open the file to read!\n");
		exit(0);
	}
	head=create();
	while((ch=fgetc(fp))!=-1)
	{
		last=ch;
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
		{
			temp[i]=ch;
			temp[i+1]='\0';
			i++;
		}
		else if(i==0)
		{

		}
		else   //这种处理有一个问题 若最后一个单词后面没有任何非字母字符，就不好处理最后一个单词了！！！
		{
			temp[i]='\0';
			p=find(head,temp);
			if(p==NULL)
			{
				p=create_node(temp);
				insert(head,p);
			}
			else
			{
				p->count++;
			}
			i=0;
		}
	}
	//处理一种特殊情况（最后一个单词后面没有任何非字母字符）
	//fseek(fp,-1L,2);//将文件标记从末尾处后退1个字节
	//ch=fgetc(fp);
	if(last>='a'&&last<='z'||last>='A'&&last<='Z')//如果读的最后一个字符是字母则表示最后一个单词没有插入到链表中
	{
			p=find(head,temp);
			if(p==NULL)
			{
				p=create_node(temp);
				insert(head,p);
			}
			else
			{
				p->count++;
			}
	}
	fclose(fp);
	return head;
}
void sort(struct word *head)
{
	struct word *p,*q,*ppre,*qpre;
	ppre=head;
	p=head->next;
	while(p->next!=NULL)
	{
		qpre=p;
		q=p->next;
		while(q!=NULL)
		{
			if(p->count<q->count)
			{
				if(p==qpre)            //该情况是要交换的两个节点是相邻的
				{
					struct word *temp;
					p->next=q->next;
					ppre->next=q;
					q->next=p;
					temp=p;
					p=q;
					q=temp;
					qpre=p;
				}
				else                 //要交换的两个节点不相邻
				{
					struct word *temp;
					temp=p->next;
					p->next=q->next;
					q->next=temp;
					qpre->next=p;
					ppre->next=q;
					temp=p;
					p=q;
					q=temp;
				}
			}
			qpre=qpre->next;
			q=q->next;
		}
		ppre=ppre->next;
		p=p->next;
	}
}
void writefile(char *filename,struct word *head,int n)
{
	FILE *fp;
	struct word *p;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("Can not open the file to write!\n");
		exit(0);
	}
	p=head->next;
	while(p!=NULL)
	{
		if(p->count>n)
		{
			fprintf(fp,"%s,%4d\n",p->spelling,p->count);
		}
		p=p->next;
	}
	fclose(fp);
}
void display(struct word *head)
{
	struct word *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%s,%4d\n",p->spelling,p->count);
		p=p->next;
	}
}
int main()
{
	struct word *head=readfile("e:\\2016.txt");
	printf("排序前：\n");
	display(head);
	sort(head);
	printf("排序后：\n");
	display(head);
	writefile("e:\\result.txt",head,5);
	return 0;
}

