//��������ת��
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct slnode {
	int data;
	struct slnode* next;
}slnode;//����ڵ�����

int Initiate(slnode** h)
{
	if ((*h = (slnode*)malloc(sizeof(slnode))) == NULL)
		return FALSE;
	(*h)->next = NULL;
	return TRUE;
}//���ɿ���������

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
}//�ڱ�β����ڵ㣬�γɵ�����

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
}//���õ�����

int main()
{
	slnode* La, * p;
	int d, i;
	if (Initiate(&La) == FALSE)
	{
		printf("Error!");//�����ʼ��ʧ��
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
	}//���ԭ������
	printf("\n");
	converse(La);//ת��
	p = La->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}//���ԭ������
	return TRUE;
}