//线性链表转置
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct slnode {
	int data;
	struct slnode* next;
}slnode;//定义节点类型

int Initiate(slnode** h)
{
	if ((*h = (slnode*)malloc(sizeof(slnode))) == NULL)
		return FALSE;
	(*h)->next = NULL;
	return TRUE;
}//生成空线性链表

void insert(slnode* h, int x)
{
	slnode* s, * p;
	p = h;
	while (p->next != NULL)
		p = p->next;
	s = (slnode*)malloc(sizeof(slnode));
	s->data = x;
	s->next = NULL;
	p->next = s;
	p = s;
}//在表尾插入节点，形成单链表

void converse(slnode* head)
{
	slnode* p, * q;
	p = head->next;
	head->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}//反置单链表

int main()
{
	slnode* La, * p;
	int d, i;
	if (Initiate(&La) == FALSE)
	{
		printf("Error!");//链表初始化失败
		return FALSE;
	}
	for (i = 0; i < 4; i++)
	{
		scanf_s("%d", &d);
		insert(La, d);
	}
	p = La->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}//输出原单链表
	printf("\n");
	converse(La);//转置
	p = La->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}//输出原单链表
	return TRUE;
}