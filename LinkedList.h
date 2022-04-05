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
	}dlnode, * dLinkList;//˫������Ľڵ�
public:
	LinkedList()//��ʼ��
	{
		LinkList h;
		if ((h = (LNode*)malloc(sizeof(LNode))) == NULL)
		{
			std::cout << "����ʧ�ܣ�";
		}
		h->next = NULL;
		std::cout << "�����ɹ���";
	}
	LinkedList(bool isCircular,bool isDouble)
	{
		if (isCircular == true && isDouble == false)
		{
			LinkList h;
			LNode* rear;
			if ((h = (LNode*)malloc(sizeof(LNode))) == NULL || (rear = (LNode*)malloc(sizeof(LNode))) == NULL)
			{
				std::cout << "����ʧ�ܣ�";
				return;
			}
			h->next = rear;
			rear->next = h;
			std::cout << "����ѭ������ɹ���";
		}
		if (isCircular == false && isDouble == true)
		{
			dLinkList h;
			if ((h = (dlnode*)malloc(sizeof(dlnode))) == NULL)
			{
				std::cout << "����ʧ�ܣ�";
				return;
			}
			h->next = NULL;
			h->prior = NULL;
			std::cout << "�����ɹ���";
		}
		if (isCircular == true && isDouble == true)
		{
			dLinkList h;
			dlnode* rear;
			if ((h = (dlnode*)malloc(sizeof(dlnode))) == NULL || (rear = (dlnode*)malloc(sizeof(dlnode))) == NULL)
			{
				std::cout << "����ʧ�ܣ�";
				return;
			}
			h->next = rear;
			h->prior = rear;
			rear->next = h;
			rear->prior = h;
			std::cout << "����˫��ѭ������ɹ���";
		}
	}
	int getNum(LinkList head)//�󳤶�
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
	int getData(LinkList head, int i)//���ҵ�i���ڵ�
	{
		LNode* p;
		int j = -1;
		p = head;
		while (p != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}//Ѱ�ҵ�i-1���ڵ�
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
		}//Ѱ�ҵ�i-1���ڵ�
		if (j != i - 1 || p->next == NULL)
		{
			std::cout << "ERROR!";
			return;
		}
		return p->next->data;
	}
	LNode* getLoc(LinkList head, int x)//��λ����Ϊx�Ľڵ�
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
	dlnode* getLoc(dLinkList head, int x)//��λ����Ϊx�Ľڵ�
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
	void InsertAfter(LNode* p, int x)//�ڽڵ�����
	{
		LNode* s;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	void InsertBefore(LinkList head,LNode* p, int x)//�ڽڵ�ǰ����
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
	void InsertAtLoc(LinkList head, int i, int x)//�ڵ�i���ڵ�ǰ����
	{
		LNode* p, * s;
		int j = -1;
		p = head;
		while (p != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}//Ѱ�ҵ�i-1���ڵ�
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
	int Delete(LinkList head, int i)//ɾ����i���ڵ�
	{
		LNode* s, * p;
		int j;
		p = head; j = -1;
		while (p->next != NULL && j < i - 1)
		{
			p = p->next;
			j++;
		}//Ѱ�ҵ�i���ڵ�
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
	void merge(LNode* La, LNode* Lb)//�ϲ�����ѭ�������������������β���
	{
		LNode* p;
		p = Lb->next;
		Lb->next = La->next;
		La->next = p->next;
		free(p);
	}
	int insert_dul(dLinkList head, int i, int x)//˫�������в�������
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
	int Delete_dul(dLinkList head, int i)//ɾ����i���ڵ�
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