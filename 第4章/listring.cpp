//��������������㷨
#include <stdio.h>
#include <malloc.h>
typedef struct snode 
{	
	char data;
	struct snode *next;
} LinkStrNode;					//���������ڵ�����
void StrAssign(LinkStrNode *&s,char cstr[])	//�ַ�������cstr������s
{
	LinkStrNode *r,*p;
	s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	r=s;						//rʼ��ָ��β�ڵ�
	for (int i=0;cstr[i]!='\0';i++) 
	{	p=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		p->data=cstr[i];
		r->next=p;r=p;
	}
	r->next=NULL;
}
void DestroyStr(LinkStrNode *&s)	//���ٴ�
{	LinkStrNode *pre=s,*p=s->next;	//preָ��ڵ�p��ǰ���ڵ�
	while (p!=NULL)					//ɨ������s
	{	free(pre);					//�ͷ�pre�ڵ�
		pre=p;						//pre��pͬ������һ���ڵ�
		p=pre->next;
	}
	free(pre);						//ѭ������ʱ,pΪNULL,preָ��β�ڵ�,�ͷ���
}
void StrCopy(LinkStrNode *&s,LinkStrNode *t)	//��t���Ƹ���s
{
	LinkStrNode *p=t->next,*q,*r;
	s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	r=s;						//rʼ��ָ��β�ڵ�
	while (p!=NULL)				//��t�����нڵ㸴�Ƶ�s
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
}
bool StrEqual(LinkStrNode *s,LinkStrNode *t)	//�д����
{
	LinkStrNode *p=s->next,*q=t->next;
	while (p!=NULL && q!=NULL && p->data==q->data) 
	{	p=p->next;
		q=q->next;
	}
	if (p==NULL && q==NULL)
		return true;
	else
		return false;
}
int StrLength(LinkStrNode *s)	//�󴮳�
{
	int i=0;
	LinkStrNode *p=s->next;
	while (p!=NULL) 
	{	i++;
		p=p->next;
	}
	return i;
}
LinkStrNode *Concat(LinkStrNode *s,LinkStrNode *t)	//������
{
	LinkStrNode *str,*p=s->next,*q,*r;
	str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	r=str;
	while (p!=NULL)				//��s�����нڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	p=t->next;
	while (p!=NULL)				//��t�����нڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}
LinkStrNode *SubStr(LinkStrNode *s,int i,int j)	//���Ӵ�
{
	int k;
	LinkStrNode *str,*p=s->next,*q,*r;
	str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next=NULL;
	r=str;						//rָ���½������β�ڵ�
	if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
		return str;				//��������ȷʱ���ؿմ�
	for (k=0;k<i-1;k++)
		p=p->next;
	for (k=1;k<=j;k++) 			//��s�ĵ�i���ڵ㿪ʼ��j���ڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}
LinkStrNode *InsStr(LinkStrNode *s,int i,LinkStrNode *t)		//������
{
	int k;
	LinkStrNode *str,*p=s->next,*p1=t->next,*q,*r;
	str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next=NULL;
	r=str;								//rָ���½������β�ڵ�
	if (i<=0 || i>StrLength(s)+1)		//��������ȷʱ���ؿմ�
		return str;
	for (k=1;k<i;k++)					//��s��ǰi���ڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	while (p1!=NULL)					//��t�����нڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p1->data;
		r->next=q;r=q;
		p1=p1->next;
	}
	while (p!=NULL)						//���ڵ�p�����Ľڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}
LinkStrNode *DelStr(LinkStrNode *s,int i,int j)	//��ɾȥ
{
	int k;
	LinkStrNode *str,*p=s->next,*q,*r;
	str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next=NULL;
	r=str;						//rָ���½������β�ڵ�
	if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
		return str;				//��������ȷʱ���ؿմ�
	for (k=0;k<i-1;k++)			//��s��ǰi-1���ڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	for (k=0;k<j;k++)				//��p��next��j���ڵ�
		p=p->next;
	while (p!=NULL)					//���ڵ�p�����Ľڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}
LinkStrNode *RepStr(LinkStrNode *s,int i,int j,LinkStrNode *t)	//���滻
{
	int k;
	LinkStrNode *str,*p=s->next,*p1=t->next,*q,*r;
	str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next=NULL;
	r=str;							//rָ���½������β�ڵ�
	if (i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
		return str;		 			//��������ȷʱ���ؿմ�
	for (k=0;k<i-1;k++)  			//��s��ǰi-1���ڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;q->next=NULL;
		r->next=q;r=q;
		p=p->next;
	}
	for (k=0;k<j;k++)				//��p��next��j���ڵ�
		p=p->next;
	while (p1!=NULL)				//��t�����нڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p1->data;q->next=NULL;
		r->next=q;r=q;
		p1=p1->next;
	}
	while (p!=NULL)					//���ڵ�p�����Ľڵ㸴�Ƶ�str
	{	q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data=p->data;q->next=NULL;
		r->next=q;r=q;
		p=p->next;
	}
	r->next=NULL;
	return str;
}
void DispStr(LinkStrNode *s)	//�����
{
	LinkStrNode *p=s->next;
	while (p!=NULL)
	{	printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
