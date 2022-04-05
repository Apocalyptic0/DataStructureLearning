/*
#include<iostream>
#include<stdlib.h>

typedef struct Sqlist {
	int data;
	struct Sqlist* next;
}Sqlist;

int getLength(Sqlist* head)//求长度
{
	Sqlist* s;
	s = head;
	int j = -1;
	while (s != NULL && s->next != s)
	{
		j++;
		s = s->next;
	}
	return j;
}
int getData(Sqlist* head, int i)//查找第i个节点
{
	Sqlist* p;
	int j = -1;
	p = head;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}//寻找第i-1个节点
	if (j != i - 1 || p->next == NULL)
	{
		std::cout << "ERROR!";
		return false;
	}
	return p->next->data;
}
void InsertAtLoc(Sqlist* head, int i, int x)//在第i个节点前插入
{
	Sqlist* p, * s;
	int j = -1;
	p = head;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}//寻找第i-1个节点
	if (j != i - 1)
	{
		std::cout << "ERROR!";
		return;
	}
	if ((s = (Sqlist*)malloc(sizeof(Sqlist))) == NULL)
		return;
	s->data = x;
	s->next = p->next;
	p->next = s;
}

void merge(Sqlist *La, Sqlist *Lb, Sqlist* Lc)
{
	int i, j, k, a, b;
	int La_Length, Lb_Length;
	i = j = 0; k = -1;
	La_Length = getLength(La) - 1;
	Lb_Length = getLength(Lb) - 1;
	while (i <= La_Length && j <= Lb_Length)
	{
		a = getData(La, i);
		b = getData(Lb, j);
		if (a < b) {
			InsertAtLoc(Lc, ++k, a);
			++i;
		}
		else {
			InsertAtLoc(Lc, ++k, b);
			++j;
		}
	}//将La和Lb的元素插入Lc中
	while (i <= La_Length)
	{
		a = getData(La, i);
		InsertAtLoc(Lc, ++k, a);
		++i;
	}
	while (j <= Lb_Length)
	{
		b = getData(Lb, j);
		InsertAtLoc(Lc, ++k, b);
		++j;
	}
}

int main()
{
	Sqlist* La, * Lb, * Lc;
	La = (Sqlist*)malloc(sizeof(Sqlist));
	Lb = (Sqlist*)malloc(sizeof(Sqlist));
	Lc = (Sqlist*)malloc(sizeof(Sqlist));
	Lc->next = new Sqlist;
	Sqlist* s, * r;
	s = new Sqlist;
	La->next = s;
	s->data = 2;
	s->next = new Sqlist;
	s = s->next;
	s->data = 4;
	s->next = new Sqlist;
	s = s->next;
	s->data = 6;
	s->next = new Sqlist;
	s = s->next;
	s->data = 7;
	s->next = new Sqlist;
	s = s->next;
	s->data = 9;
	s->next = NULL;

	r = new Sqlist;
	Lb->next = r;
	r->data = 1;
	r->next = new Sqlist;
	r = r->next;
	r->data = 5;
	r->next = new Sqlist;
	r = r->next;
	r->data = 7;
	r->next = new Sqlist;
	r = r->next;
	r->data = 8;
	r->next = NULL;
	merge(La, Lb, Lc);

	Sqlist* p;
	int m = -1;
	int n ;
	int k = getLength(La) + getLength(Lb);
	p = Lc;
	while (p != NULL && m < k)
	{
		p = p->next;
		m++;
	}//寻找第k-1个节点
	p->next = NULL;

	n = getLength(Lc) - 1;

	for (int i = -1; i < n - 1; i++)
	{
		Lc = Lc->next;
		std::cout << Lc->data << " ";
	}
}*/