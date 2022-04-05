#pragma once
#include<iostream>
#define MAXNUM 100

class sqQueue {
private:
	typedef struct sqqueue {
		int queue[MAXNUM];
		int front;//��ͷָʾ��
		int rear;//��βָʾ��
	}sqqueue;

	//ѭ������
	typedef struct {
		int queue[MAXNUM];
		int front;
		int rear;
		int s;//�ж�front=rearʱ�ǿջ�����
	}qqueue;
public:
	int InitQueue(sqqueue** q)
	{
		if ((*q = (sqqueue*)malloc(sizeof(sqqueue))) == NULL)
			return false;
		(*q)->front = -1;
		(*q)->rear = -1;
		return true;
	}

	int InQueue(sqqueue* q, int x)
	{
		if ((q->rear > MAXNUM - 1))
			return false;//������
		q->rear++;
		q->queue[q->rear] = x;
		return true;
	}

	int OutQueue(sqqueue* q)
	{
		int x;
		if (q->rear == q->front)
			return NULL;//���п�
		x = q->queue[++q->front];
		return x;
	}

	int Empty(sqqueue* q)
	{
		if (q->rear == q->front)
			return true;
		return false;
	}

	int length(sqqueue* q)
	{
		return(q->rear - q->front);
	}

	//ѭ������
	int InitQueue(qqueue** q)
	{
		if ((*q = (qqueue*)malloc(sizeof(qqueue))) == NULL)
			return false;
		(*q)->front = MAXNUM;
		(*q)->rear = MAXNUM;
		(*q)->s = 0;
		return true;
	}

	int tInQueue(qqueue* q, int x)
	{
		if ((q->s == 1) && (q->front == q->rear))
			return false;//��
		q->rear++;
		if (q->rear == MAXNUM)q->rear = 0;
		q->queue[q->rear] = x;
		q->s = 1;
		return true;
	}

	int OutQueue(qqueue* q)
	{
		int x;
		if (q->s == 0)
			return NULL;
		q->front++;
		if (q->front == MAXNUM)
			q->front = 0;
		x = q->queue[q->front];
		if (q->front == q->rear)
			q->s = 0;
		return x;
	}
};