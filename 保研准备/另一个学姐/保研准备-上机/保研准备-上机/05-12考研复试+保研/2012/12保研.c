#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(struct node)

typedef struct node {
	int x;
	int y;
	int flag;
	struct node *next;
} node_t;

int main()
{
	FILE *fp1 = fopen("D:\\org.dat", "rb");
	int n=0, i=0, max, tmp[2];
	node_t *head = NULL, *p, *pre, temp;
	p = (node_t *)malloc(LEN);
	p->x = -9999;
	p->y = -9999;
	p->flag = 0;
	p->next = NULL;
	head = p;
	pre = p;

	while (fread(tmp, sizeof(int), 2, fp1) != 0) 
	{
		p = (node_t *)malloc(LEN);
		p->next = NULL;
		if (tmp[0] > 0 && tmp[1] > 0) 
		{
			p->x = tmp[0];
			p->y = tmp[1];
			p->flag = 0;
			n++;
		} 
		else 
		{
			continue;
		}
		pre->next = p;
		pre = p;
	}

	for (pre = head; pre != NULL; pre = pre->next) 
	{
		for (p = pre->next; p != NULL; p = p->next) 
		{
			if (pre->x > p->x && pre->y > p->y) 
			{
				temp.x = pre->x;
				temp.y = pre->y;
				pre->x = p->x;
				pre->y = p->y;
				p->x = temp.x;
				p->y = temp.y;
			}
		}
	}

	while (n != 0) 
	{
		pre = head;
		p = head->next;
		while (p != NULL) 
		{
			if (pre->x < p->x && pre->y < p->y) 
			{
				p->flag = 1;
				printf("%d %d\n", p->x, p->y);
				pre = p;
				p = p->next;
				n--;
				if (n == 0) 
				{
					i++;
					printf("%d\n", i);
					exit(0);
				}
				continue;
			}
			p = p->next;
		}
		pre = head;
		p = head->next;
		while (p != NULL) 
		{
			if (p->flag == 1) 
			{
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else 
			{
				pre = p;
				p = p->next;
			}
		}
		i++;
		printf("\n");
	}

	getchar();
	return 0;
}