#pragma once
#include<iostream>
#include<stdlib.h>

class LinkedList {
private:
	typedef struct LNode {
		int data;
		struct LNode* next;
	}LNode,*LinkList;
	typedef struct doubleLNode {
		int data;
		struct doubleLNode* next, * prior;
	}dlnode, * dLinkList;//双向链表的节点
public:
	LinkedList()//初始化
	{
		LinkList h;
		if ((h = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			std::cout << "创建失败！";
		}
		h->next = NULL;
		std::cout << "创建成功！";
	}
	LinkedList(bool isCircular,bool isDouble)
	{
		if (isCircular == true && isDouble == false)
		{
			LinkList h;
			LNode* rear;
			if ((h = (LNode*)malloc(sizeof(LNode))) == NULL || (rear = (LNode*)malloc(sizeof(LNode))) == NULL)
			{
				std::cout << "创建失败！";
				return;
			}
			h->next = rear;
			rear->next = h;
			std::cout << "创建循环链表成功！";
		}
		if (isCircular == false && isDouble == true)
		{
			dLinkList h;
			if ((h = (dlnode*)malloc(sizeof(dlnode))) == NULL)
			{
				std::cout << "创建失败！";
				return;
			}
			h->next = NULL;
			h->prior = NULL;
			std::cout << "创建成功！";
		}
		if (isCircular == true && isDouble == true)
		{
			dLinkList h;
			dlnode* rear;
			if ((h = (dlnode*)malloc(sizeof(dlnode))) == NULL || (rear = (dlnode*)malloc(sizeof(dlnode))) == NULL)
			{
				std::cout << "创建失败！";
				return;
			}
			h->next = rear;
			h->prior = rear;
			rear->next = h;
			rear->prior = h;
			std::cout << "创建双向循环链表成功！";
		}
	}
	int getNum(LinkList head)//求长度
	{
		LNode* s;
		s = head;
		int j = -1;
		while (s != NULL&&s->next!=s)
		{
			j++;
			s=s->next;
		}
		return j;
	}
	int getNum(dLinkList head)
	{
		dlnode* s;
		s = head;
		int j = -1;
		while (s != NULL&&s->next!=s)
		{
			j++;
			s = s->next;
		}
		return j;
	}
	int getData(LinkList head, int i)//查找第i个节点
	{
		LNode* p;
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
			return;
		}
		return p->next->data;
	}
	int getData(dLinkList head, int i)
	{
		dlnode* p;
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
			return;
		}
		return p->next->data;
	}
	LNode* getLoc(LinkList head, int x)//定位数据为x的节点
	{
		LNode* p;
		p = head->next;
		int lengh = getNum(head);
		for (int j = 0; j <= lengh; j++)
		{
			if (p->data == x)
			{
				return p;
			}
		}
		std::cout << "can't find!";
	}
	dlnode* getLoc(dLinkList head, int x)//定位数据为x的节点
	{
		dlnode* p;
		p = head->next;
		int lengh = getNum(head);
		for (int j = 0; j <= lengh; j++)
		{
			if (p->data == x)
			{
				return p;
			}
		}
		std::cout << "can't find!";
	}
	void InsertAfter(LNode* p, int x)//在节点后插入
	{
		LNode* s;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	void InsertBefore(LinkList head,LNode* p, int x)//在节点前插入
	{
		LNode* q, * s;
		q = head;
		while (q->next != p)
			q = q->next;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p;
		q->next = s;
	}
	void InsertAtLoc(LinkList head, int i, int x)//在第i个节点前插入
	{
		LNode* p, * s;
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
		if ((s = (LNode*)malloc(sizeof(LNode))) == NULL)
			return;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	int Delete(LinkList head, int i)//删除第i个节点
	{
		LNode* s, * p;
		int j;
		p = head; j = -1;
		while (p->next != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}//寻找第i个节点
		if (p->next == NULL)
		{
			std::cout << "ERROR!";
			return false;
		}
		s = p->next;
		p->next = p->next->next;
		free(s);
		return true;
	}
	void merge(LNode* La, LNode* Lb)//合并两个循环链表，输入两个链表的尾结点
	{
		LNode* p;
		p = Lb->next;
		Lb->next = La->next;
		La->next = p->next;
		free(p);
	}
	int insert_dul(dLinkList head, int i, int x)//双向链表中插入数据
	{
		dlnode* p, * s;
		int j = -1;
		p = head;
		while (p != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}
		if (p == NULL)
		{
			std::cout << "ERROR!";
			return false;
		}
		if ((s = (dlnode*)malloc(sizeof(dlnode))) == NULL)
			return false;
		s->data = x;
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		return true;
	}
	int Delete_dul(dLinkList head, int i)//删除第i个节点
	{
		dlnode* p, * s;
		int j = -1;
		p = head;
		while (p != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}
		if (p == NULL)
		{
			std::cout << "ERROR!";
			return false;
		}
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return true;
	}
};