//�����������㷨
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;		 			//������������
void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;						//rʼ��ָ��β���,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		r->next=s;				//�����s����r���֮��
		r=s;
	}
	r->next=NULL;				//β���next����ΪNULL
}
void InitList(LinkNode *&L)		//��ʼ�����Ա�
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;				//��������Ϊ�ձ�
}
void DestroyList(LinkNode *&L)	//�������Ա�
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;					//pre��pͬ������һ�����					
		p=pre->next;
	}
	free(pre);					//��ʱpΪNULL,preָ��β���,�ͷ���
}
bool ListEmpty(LinkNode *L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==NULL);
}
int ListLength(LinkNode *L)		//�����Ա�ĳ���
{	int i=0;
	LinkNode *p=L;				//pָ��ͷ���,n��Ϊ0(��ͷ�������Ϊ0)
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);					//ѭ������,pָ��β���,�����iΪ������
}

void DispList(LinkNode *L)	//������Ա�
{	LinkNode *p=L->next;	//pָ���׽��
	while (p!=NULL)			//p��ΪNULL,���p����data��
	{	printf("%c ",p->data);
		p=p->next;			//p������һ�����
	}
	printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e)	//�����Ա��е�i��Ԫ��ֵ
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L;				//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i && p!=NULL)		//�ҵ�i�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//�����ڵ�i�����ݽ��,����false
		return false;
	else						//���ڵ�i�����ݽ��,����true
	{	e=p->data;
		return true;
	}
}

int LocateElem(LinkNode *L,ElemType e)	//���ҵ�һ��ֵ��Ϊe��Ԫ�����
{	int i=1;
	LinkNode *p=L->next;			//pָ���׽��,i��Ϊ1(���׽������Ϊ1)
	while (p!=NULL && p->data!=e)	//����dataֵΪe�Ľ��,�����Ϊi
	{	p=p->next;
		i++;
	}
	if (p==NULL)					//������ֵΪe�Ľ��,����0
		return(0);
	else							//����ֵΪe�Ľ��,�������߼����i
		return(i);
}

bool ListInsert(LinkNode *&L,int i,ElemType e)	//�����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L,*s;			//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p,�����½�㲢����true
	{	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;				//�����½��s,��data����Ϊe
		s->next=p->next;		//�����s���뵽���p֮��
		p->next=s;
		return true;
	}
}

bool ListDelete(LinkNode *&L,int i,ElemType &e)	//ɾ����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L,*q;			//pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1�����,����false
		return false;
	else						//�ҵ���i-1�����p
	{	q=p->next;				//qָ���i�����
		if (q==NULL)			//�������ڵ�i�����,����false
			return false;
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��q���
		free(q);				//�ͷ�q���
		return true;			//����true��ʾ�ɹ�ɾ����i�����
	}
}
