//链表的简单运用，多项式求和
#include<stdlib.h>
typedef struct poly
{
	int exp;//指数
	double coef;//系数
	struct poly* next;//指针域
}poly;

struct poly* add_poly(poly* Ah, poly* Bh)
{
	poly* qa, * qb, * s, * r, * Ch;
	double x;
	qa = Ah->next; qb = Bh->next;//指向第一个节点
	r = Ah; Ch = Ah;//链表Ah作为result
	while (qa != NULL && qb != NULL)//两链表均非空
	{
		if (qa->exp == qb->exp)
		{
			x = qa->coef + qb->coef;
			if (x != 0)
			{
				qa->coef = x;
				r->next = qa;
				r = qa;

				s = qb;
				qb = qb->next;
				free(s);
				qa = qa->next;
			}//相加后系数不为0
			else {
				s = qb; qb = qb->next; free(s);
				s = qa; qa = qa->next; free(s);
			}//相加后系数为0
		}
		else if (qa->exp < qb->exp)
		{
			r->next = qa; r = qa; qa = qa->next;
		}//Ah的指数小
		else
		{
			r->next = qb; r = qb; qb = qb->next;
		}//Bh的指数小
		if (qa == NULL)r->next = qb;
		else r->next = qa;
		return Ch;
	}
}