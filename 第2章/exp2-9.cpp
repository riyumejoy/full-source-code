//�ļ���:exp2-9.cpp
#include <stdio.h>
#include <malloc.h>
#define MAX 100				//����ʽ�������
typedef struct
{
	double coef;			//ϵ��
	int exp;				//ָ��
} PolyArray;				//��Ŷ���ʽ����������
typedef struct pnode
{
	double coef;			//ϵ��
	int exp;				//ָ��
	struct pnode *next;
}  PolyNode;				//��������ʽ������������
void DispPoly(PolyNode *L)	//�������ʽ������
{
	bool first=true;		//firstΪtrue��ʾ�ǵ�һ��
	PolyNode *p=L->next;
	while (p!=NULL)
	{
		if (first)
			first=false;
		else if (p->coef>0)
			printf("+");
		if (p->exp==0)
			printf("%g",p->coef);
		else if (p->exp==1)
			printf("%gx",p->coef);
		else
			printf("%gx^%d",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}
void DestroyPoly(PolyNode *&L)	//���ٶ���ʽ������
{
	PolyNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}
void CreatePolyR(PolyNode *&L,PolyArray a[],int n) //β�巨����
{
	PolyNode *s,*r;int i;
	L=(PolyNode *)malloc(sizeof(PolyNode));	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));//�����½��
		s->coef=a[i].coef;
		s->exp=a[i].exp;
		r->next=s;				//�����s������r֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}
void Sort(PolyNode *&L)				//������ʽ������ָ���ݼ�����
{
	PolyNode *p=L->next,*pre,*q;
	if (p!=NULL)					//L��һ�������ϵ����ݽ��
	{
		q=p->next;					//q����p���ĺ�̽��
		p->next=NULL;				//����ֻ��һ�����ݽ��������
		p=q;
		while (p!=NULL)				//ɨ��ԭL�����µ����ݽ��
		{
			q=p->next;				//q����p���ĺ�̽��
			pre=L;
			while (pre->next!=NULL && pre->next->exp>p->exp)
				pre=pre->next;     //����������Ҳ�����p��ǰ�����pre
			p->next=pre->next;		//�����p���뵽���pre֮��
			pre->next=p;
			p=q;					//ɨ��ԭ���������µĽ��
		}
	}
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)  //ha��bh��ӵõ�hc
{
	PolyNode *pa=ha->next,*pb=hb->next,*s,*r;
	double c;
	hc=(PolyNode *)malloc(sizeof(PolyNode)); 
	r=hc;							//rָ��β��㣬��ʼʱָ��ͷ���
	while (pa!=NULL && pb!=NULL)	//pa��pb��û��ɨ����
	{
		if (pa->exp>pb->exp)		//��ָ���ϴ��pa��㸴�Ƶ�hc��
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));   
			s->exp=pa->exp;s->coef=pa->coef;
			r->next=s; r=s;
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)	//��ָ���ϴ��pb��㸴�Ƶ�hc��
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));   
			s->exp=pb->exp;s->coef=pb->coef;
			r->next=s; r=s;
			pb=pb->next;
		}
		else						//pa��pb����ָ�����ʱ
		{
			c=pa->coef+pb->coef;	//����������ϵ����c
			if (c!=0)				//��ϵ���Ͳ�Ϊ0ʱ�����½��
			{ 
				s=(PolyNode *)malloc(sizeof(PolyNode)); 
				s->exp=pa->exp;s->coef=c;	
				r->next=s; r=s;
			}
			pa=pa->next;			//pa��pb������һ�����
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;			//�������µĽ��
	while (pa!=NULL)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));
		s->exp=pa->exp;
		s->coef=pa->coef;
		r->next=s; r=s;
		pa=pa->next;
	}
	r->next=NULL;					//β���next����Ϊ��
}
int main()
{
	PolyNode *ha,*hb,*hc;
	PolyArray a[]={{1.2,0},{2.5,1},{3.2,3},{-2.5,5}};
	PolyArray b[]={{-1.2,0},{2.5,1},{3.2,3},{2.5,5},{5.4,10}};
	CreatePolyR(ha,a,4);
	CreatePolyR(hb,b,5);
	printf("ԭ����ʽA:   ");DispPoly(ha);
	printf("ԭ����ʽB:   ");DispPoly(hb);
	Sort(ha);
	Sort(hb);
	printf("�������ʽA: ");DispPoly(ha);
	printf("�������ʽB: ");DispPoly(hb);
	Add(ha,hb,hc);
	printf("����ʽ���:  ");DispPoly(hc);
	DestroyPoly(ha);
	DestroyPoly(hb);
	DestroyPoly(hc);
	return 1;
}

