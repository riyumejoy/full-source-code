//ѭ�������������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode		//���嵥����������
{
	ElemType data;
    struct LNode *next;
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n) //ͷ�巨����ѭ��������
{
	LinkNode *s;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
	s=L->next;	
	while (s->next!=NULL)			//����β���,��sָ����
		s=s->next;
	s->next=L;						//β���next��ָ��ͷ���

}
void CreateListR(LinkNode *&L,ElemType a[],int n) //β�巨����ѭ��������
{
	LinkNode *s,*r;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��
		s->data=a[i];
		r->next=s;			//�����s������r֮��
		r=s;
	}
	r->next=L;				//β���next��ָ��ͷ���
}
void InitList(LinkNode *&L)	//��ʼ�����Ա�
{
	L=(LinkNode *)malloc(sizeof(LinkNode));	//����ͷ���
	L->next=L;
}
void DestroyList(LinkNode *&L)	//�������Ա�
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{
		free(pre);
		pre=p;					//pre��pͬ������һ�����
		p=pre->next;
	}
	free(pre);					//��ʱp=L,preָ��β���,�ͷ���
}
bool ListEmpty(LinkNode *L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==L);
}
int ListLength(LinkNode *L)		//�����Ա�ĳ���
{
	LinkNode *p=L;int i=0;		//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);					//ѭ������,pָ��β���,�����nΪ������
}
void DispList(LinkNode *L)		//������Ա�
{
	LinkNode *p=L->next;
	while (p!=L)				//p��ΪL,���p����data��
	{
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)	//�����Ա��е�i��Ԫ��ֵ
{	int j=1;
	LinkNode *p=L->next;
	if (i<=0 || L->next==L)		//i������߿ձ��ؼ�
		return false;
	if (i==1)					//���1�����ֵ����Ϊ�����������
	{
		e=L->next->data;
		return true;
	}
	else						//i��Ϊ1ʱ
	{
		while (j<=i-1 && p!=L)	//�ҵ�i�����p
		{
			j++;
			p=p->next;
		}
		if (p==L)				//û���ҵ����ؼ�
			return false;
		else					//�ҵ�����ȡ����ֵ��������
		{				
			e=p->data;
			return true;
		}
	}
}

int LocateElem(LinkNode *L,ElemType e)  //���ҵ�һ��ֵ��Ϊe��Ԫ�����
{
	LinkNode *p=L->next;
	int i=1;
	while (p!=L && p->data!=e)	//���ҵ�һ��ֵ��Ϊe�Ľ��p
	{
		p=p->next;
		i++;					//i��Ӧ���p�����
	}
	if (p==L)
		return(0);				//û���ҵ�����0
	else
		return(i);				//�ҵ��˷��������
}
bool ListInsert(LinkNode *&L,int i,ElemType e)	//�����i��Ԫ��
{
	int j=1;
	LinkNode *p=L,*s;
	if (i<=0) return false;		//i���󷵻ؼ�
	if (p->next==L || i==1)		//ԭ������Ϊ�ձ��i=1��Ϊ�����������
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));	//�����½��s
		s->data=e;								
		s->next=p->next;		//�����s���뵽���p֮��
		p->next=s;
		return true;
	}
	else
	{
		p=L->next;
		while (j<=i-2 && p!=L)	//�ҵ�i-1�����p
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return false;
		else					//�ҵ���i-1�����p
		{
			s=(LinkNode *)malloc(sizeof(LinkNode));	//�����½��s
			s->data=e;								
			s->next=p->next;						//�����s���뵽���p֮��
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)	//ɾ����i��Ԫ��
{
	int j=1;
	LinkNode *p=L,*q;
	if (i<=0 || L->next==L) 
		return false;			//i������߿ձ��ؼ�
	if (i==1)					//i=1��Ϊ�����������
	{
		q=L->next;				//ɾ����1�����
		e=q->data;
		L->next=q->next;
		free(q);
		return true;
	}
	else						//i��Ϊ1ʱ
	{
		p=L->next;
		while (j<=i-2 && p!=L)	//�ҵ�i-1�����p
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return false;
		else					//�ҵ���i-1�����p
		{
			q=p->next;			//qָ��Ҫɾ���Ľ��
			e=q->data;
			p->next=q->next;	//�ӵ�������ɾ��q���
			free(q);			//�ͷ�q���
			return true;
		}
	}
}
