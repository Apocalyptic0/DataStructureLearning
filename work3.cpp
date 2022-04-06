#define MAXNUM 40
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char stack[MAXNUM];
	int top;
}sqstack;

//��ʼ��ջ����	
int initStack(sqstack** s)
{
	if ((*s = (sqstack*)malloc(sizeof(sqstack))) == NULL)
		return FALSE;
	(*s)->top = -1;
	return TRUE;
}

int Push(sqstack* s, char x)
{
	if (s->top == MAXNUM - 1)
		return false;//ջ����
	s->top++;
	s->stack[s->top] = x;
	return true;
}
char Pop(sqstack* s)
{
	char x;
	if (s->top < 0)
		return NULL;//ջ�ѿ�
	x = s->stack[s->top];
	s->top--;
	return x;
}

char getTop(sqstack* s)//ȡջ��Ԫ��
{
	if (s->top < 0)
		return false;//ջ�ѿ�
	return s->stack[s->top];
}

//�Ƚ����㷨x1��x2�����ȼ�
char precede(char x1, char x2) {
	char result = '<';
	char string[2] = { x2,'\0' };
	if (((x1 == '+' || x1 == '-') && (strstr("+-)#", string) != NULL)) 
		|| ((x1 == '*' || x1 == '/') && (strstr("+-*/)#", string) != NULL)) 
		|| (x1 == ')' && (strstr("+-*/)#", string) != NULL)))
		return '>';
	else if (x1 == '(' && x2 == ')' || x1 == '#' && x2 == '#')
		return '=';
	else if (x1 == ')' && x2 == '(' || x1 == '#' && x2 == '(')
		return result;
	return result;
}

int main()
{
	sqstack* optr;
	sqstack* oprd;
	char s[80], c, y;
	int i = 0;
	int x1, x2;
	gets_s(s);
	initStack(&optr);
	initStack(&oprd);
	Push(optr, '#');
	c = s[i];
	while (c != '#' || getTop(optr) != '#')
	{
		if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')' && c != '#')
		{
			Push(oprd, c);
			c = s[++i];
			if (c == '/0')
				break;
		}
		else 
			switch (precede(getTop(optr), c))
			{
			case'<': {
				Push(optr, c);
				c = s[++i];
				break;
			}
			case'=': {
				Pop(optr);
				c = s[++i];
				break;
			}
			case'>': {
				y = Pop(optr);
				x2 = int(Pop(oprd)-'0');
				x1 = int(Pop(oprd)-'0');
				switch (y)
				{
				case'+':x1 += x2;
					break;
				case'-':x1 -= x2;
					break;
				case'*':x1 *= x2;
					break;
				case'/':x1 /= x2;
					break;
				}
				x1 += '0';
				Push(oprd, x1);
				break;
			}
			}
	}printf("%d", Pop(oprd)-'0');
}