//�ı��ļ�input.txt������Ӣ�ĵ��ʺͷָ������ո񣬻س������У����ɡ���������˵����д����ͳ�Ʋ�ͬ���ʳ��ֵĴ�����Ƶ�ȣ���
//��ͳ�ƽ��������Ƶ�ȴӸߵ������򣬲�������Ƶ�ȴ���5�ĵ��ʼ���Ƶ��������ļ�output.txt�С��ļ���ʽ��ͼ1��ʾ��
//˵����
//(1)��������ķָ�������Ϊһ���ָ�����
//(2)���ʴ�Сд���С�
//(3)ÿ�����ʵĳ��Ȳ�����20���ַ���
//(4)���ʵ�����δ֪����ʹ�ö��徲̬������ķ�ʽ��ͳ�ƣ������۳�5�֡�
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
	char last;//�����һ���ַ�
	char temp[25]={'\0'};
	int i=0;//��������ʼ��
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
		else   //���ִ�����һ������ �����һ�����ʺ���û���κη���ĸ�ַ����Ͳ��ô������һ�������ˣ�����
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
	//����һ��������������һ�����ʺ���û���κη���ĸ�ַ���
	//fseek(fp,-1L,2);//���ļ���Ǵ�ĩβ������1���ֽ�
	//ch=fgetc(fp);
	if(last>='a'&&last<='z'||last>='A'&&last<='Z')//����������һ���ַ�����ĸ���ʾ���һ������û�в��뵽������
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
				if(p==qpre)            //�������Ҫ�����������ڵ������ڵ�
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
				else                 //Ҫ�����������ڵ㲻����
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
	printf("����ǰ��\n");
	display(head);
	sort(head);
	printf("�����\n");
	display(head);
	writefile("e:\\result.txt",head,5);
	return 0;
}

