//����ļ����ã�����ʽ���
#include<stdlib.h>
typedef struct poly
{
	int exp;//ָ��
	double coef;//ϵ��
	struct poly* next;//ָ����
}poly;

struct poly* add_poly(poly* Ah, poly* Bh)
{
	poly* qa, * qb, * s, * r, * Ch;
	double x;
	qa = Ah->next; qb = Bh->next;//ָ���һ���ڵ�
	r = Ah; Ch = Ah;//����Ah��Ϊresult
	while (qa != NULL && qb != NULL)//��������ǿ�
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
			}//��Ӻ�ϵ����Ϊ0
			else {
				s = qb; qb = qb->next; free(s);
				s = qa; qa = qa->next; free(s);
			}//��Ӻ�ϵ��Ϊ0
		}
		else if (qa->exp < qb->exp)
		{
			r->next = qa; r = qa; qa = qa->next;
		}//Ah��ָ��С
		else
		{
			r->next = qb; r = qb; qb = qb->next;
		}//Bh��ָ��С
		if (qa == NULL)r->next = qb;
		else r->next = qa;
		return Ch;
	}
}