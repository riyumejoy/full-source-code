//�����������㷨
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode *next;		//ָ���̽ڵ�
} LinkNode;		 			//������ڵ�����
void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ�ڵ�
	L->next=NULL;
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½ڵ�s
		s->data=a[i];
		s->next=L->next;			//���ڵ�s����ԭ��ʼ�ڵ�֮ǰ,ͷ�ڵ�֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
	r=L;						//rʼ��ָ��β�ڵ�,��ʼʱָ��ͷ�ڵ�
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½ڵ�s
		s->data=a[i];
		r->next=s;				//���ڵ�s����r�ڵ�֮��
		r=s;
	}
	r->next=NULL;				//β�ڵ�next����ΪNULL
}
void InitList(LinkNode *&L)		//��ʼ�����Ա�
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ�ڵ�
	L->next=NULL;				//��������Ϊ�ձ�
}
void DestroyList(LinkNode *&L)	//�������Ա�
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;					//pre��pͬ������һ���ڵ�					
		p=pre->next;
	}
	free(pre);					//��ʱpΪNULL,preָ��β�ڵ�,�ͷ���
}
bool ListEmpty(LinkNode *L)		//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next==NULL);
}
int ListLength(LinkNode *L)		//�����Ա�ĳ���
{	int i=0;
	LinkNode *p=L;				//pָ��ͷ�ڵ�,n��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);					//ѭ������,pָ��β�ڵ�,�����iΪ�ڵ����
}

void DispList(LinkNode *L)	//������Ա�
{	LinkNode *p=L->next;	//pָ���׽ڵ�
	while (p!=NULL)			//p��ΪNULL,���p�ڵ��data��
	{	printf("%c ",p->data);
		p=p->next;			//p������һ���ڵ�
	}
	printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e)	//�����Ա��е�i��Ԫ��ֵ
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L;				//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j<i && p!=NULL)		//�ҵ�i���ڵ�p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//�����ڵ�i�����ݽڵ�,����false
		return false;
	else						//���ڵ�i�����ݽڵ�,����true
	{	e=p->data;
		return true;
	}
}

int LocateElem(LinkNode *L,ElemType e)	//���ҵ�һ��ֵ��Ϊe��Ԫ�����
{	int i=1;
	LinkNode *p=L->next;			//pָ���׽ڵ�,i��Ϊ1(���׽ڵ�����Ϊ1)
	while (p!=NULL && p->data!=e)	//����dataֵΪe�Ľڵ�,�����Ϊi
	{	p=p->next;
		i++;
	}
	if (p==NULL)					//������ֵΪe�Ľڵ�,����0
		return(0);
	else							//����ֵΪe�Ľڵ�,�������߼����i
		return(i);
}

bool ListInsert(LinkNode *&L,int i,ElemType e)	//�����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L,*s;			//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1���ڵ�p
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1���ڵ�,����false
		return false;
	else						//�ҵ���i-1���ڵ�p,�����½ڵ㲢����true
	{	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;				//�����½ڵ�s,��data����Ϊe
		s->next=p->next;		//���ڵ�s���뵽�ڵ�p֮��
		p->next=s;
		return true;
	}
}

bool ListDelete(LinkNode *&L,int i,ElemType &e)	//ɾ����i��Ԫ��
{	int j=0;
	if (i<=0) return false;		//i���󷵻ؼ�
	LinkNode *p=L,*q;			//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j<i-1 && p!=NULL)	//���ҵ�i-1���ڵ�
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1���ڵ�,����false
		return false;
	else						//�ҵ���i-1���ڵ�p
	{	q=p->next;				//qָ���i���ڵ�
		if (q==NULL)			//�������ڵ�i���ڵ�,����false
			return false;
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��q�ڵ�
		free(q);				//�ͷ�q�ڵ�
		return true;			//����true��ʾ�ɹ�ɾ����i���ڵ�
	}
}
