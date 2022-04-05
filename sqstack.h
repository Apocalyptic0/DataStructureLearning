#pragma once
#include<stdlib.h>

#define MAXNUM 100
class sqStack {
private:
	typedef struct sqstack {
		int stack[MAXNUM];
		int top;//栈顶指针
	}sqstack;

	typedef struct dupsqstack {
		int stack[MAXNUM];
		int lefttop;//左栈栈顶位置
		int righttop;//右栈栈顶位置
	}dupsqstack;

	char status;//确定是对左栈还是右栈操作

	typedef struct Stacknode {
		int data;
		struct Stacknode* next;
	}slStacktype;

public:
	int Initstack(sqstack** s)
	{
		if ((*s = (sqstack*)malloc(sizeof(sqstack))) == NULL)
			return false;
		(*s)->top = -1;
		return true;
	}
	int Push(sqstack* s, int x)
	{
		if (s->top == MAXNUM - 1)
			return false;//栈已满
		s->top++;
		s->stack[s->top] = x;
		return true;
	}
	int Pop(sqstack* s)
	{
		int x;
		if (s->top < 0)
			return false;//栈已空
		x = s->stack[s->top];
		s->top--;
		return x;
	}
	int getTop(sqstack* s)//取栈顶元素
	{
		if (s->top < 0)
			return false;//栈已空
		return s->stack[s->top];
	}
	int Empty(sqstack* s)
	{
		if (s->top < 0)
			return true;
		return false;
	}
	void setEmpty(sqstack* s)
	{
		s->top = -1;
	}

	//双向栈
	int InitDupStack(dupsqstack** s)
	{
		if ((*s = (dupsqstack*)malloc(sizeof(dupsqstack))) == NULL)
			return false;
		(*s)->lefttop = -1;
		(*s)->righttop = MAXNUM;
		return true;
	}
	int PushDupStack(dupsqstack* s, char status, int x)
	{
		if (s->lefttop + 1 == s->righttop)
			return false;//满栈
		if (status == 'L')
			s->stack[++s->lefttop] = x;
		else if (status == 'R')
			s->stack[--s->righttop] = x;
		else return false;//参数错误
		return true;
	}
	int PopDupStack(dupsqstack* s, char status)
	{
		if (status == 'L')
		{
			if (s->lefttop < 0)
				return false;
			else
				return(s->stack[s->lefttop--]);
		}
		else if (status == 'R')
		{
			if (s->righttop > MAXNUM - 1)
				return false;
			else
				return(s->stack[s->righttop++]);
		}
		else
			return false;
	}

	//单个链栈
	int PushLstack(slStacktype** top, int x)
	{
		slStacktype* p;
		if ((p = (slStacktype*)malloc(sizeof(slStacktype))) == NULL)
			return false;
		p->data = x;
		p->next = *top;
		*top = p;
		return true;
	}

	int PopLstack(slStacktype** top)
	{
		slStacktype* p;
		int x;
		if (*top == NULL)
			return NULL;
		p = *top;
		*top = (*top)->next;
		x = p->data;
		free(p);
		return x;
	}

	//多个链栈
	int PushDupLs(slStacktype* top[], int i, int x)
	{
		slStacktype* p;
		if ((p = (slStacktype*)malloc(sizeof(slStacktype))) == NULL)
			return false;
		p->data = x;
		p->next = top[i];
		p = top[i];
		return true;
	}

	int PopDupLs(slStacktype* top[], int i)
	{
		slStacktype* p;
		int x;
		if (top[i] == NULL)
			return NULL;//空栈
		p = top[i]; top[i] = (top[i])->next;
		x = p->data;
		free(p);
		return x;
	}
};

//栈的应用，十进制转其他进制