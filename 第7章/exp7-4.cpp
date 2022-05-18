//�ļ���:exp7-4.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{	ElemType data;
	int ltag,rtag;			//���ӵ��������
	struct node *lchild;	//����ָ��
	struct node *rchild;	//�Һ���ָ��
} TBTNode;
void CreateTBTree(TBTNode * &b,char *str)	//��str����������������Ķ�����b
{	TBTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ����
		case ')':top--;break;
		case ',':k=2; break;					//Ϊ�ҽ��
		default:p=(TBTNode *)malloc(sizeof(TBTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)					//pΪ�������ĸ����
					b=p;
				else							//�ѽ��������������
				{	switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DispTBTree(TBTNode *b)			//�������������Ķ�����b
{	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");
			DispTBTree(b->lchild);
			if (b->rchild!=NULL) printf(",");
			DispTBTree(b->rchild);
			printf(")");
		}
	}
}
TBTNode *pre;						//ȫ�ֱ���
void Thread(TBTNode *&p)			//��������������������CreateThread����
{	if (p!=NULL)
	{	Thread(p->lchild);			//������������
		if (p->lchild==NULL)		//��p������ָ��Ϊ��
		{	p->lchild=pre;			//������ǰ����ǰ������
			p->ltag=1;
		}
		else p->ltag=0;
		if (pre->rchild==NULL)		//��p������ָ��Ϊ��
		{	pre->rchild=p;			//����ǰ�����ĺ������
			pre->rtag=1;
		}
		else pre->rtag=0;
		pre=p;
		Thread(p->rchild);			//������������
	}
}
TBTNode *CreateThread(TBTNode *b)	//��������������������
{	TBTNode *root;
	root=(TBTNode *)malloc(sizeof(TBTNode));	//���������
	root->ltag=0;root->rtag=1;
	root->rchild=b;
	if (b==NULL)				//�ն�����
		root->lchild=root;
	else
	{	root->lchild=b;
		pre=root;				//pre�����p����ǰ�����,����������
		Thread(b);				//�����������������
		pre->rchild=root;		//�����,����ָ�����������
		pre->rtag=1;
		root->rchild=pre;		//�������������
	}
	return root;
}
void InOrder(TBTNode *tb)			//��ThInOrder�㷨����
{
	if (tb->lchild!=NULL && tb->ltag==0)	//������
		InOrder(tb->lchild);
	printf("%c ",tb->data);
	if (tb->rchild!=NULL && tb->rtag==0)	//���Һ���
		InOrder(tb->rchild);
}
void ThInOrder(TBTNode *tb)		//������������������������ݹ��㷨
{
	InOrder(tb->lchild);
}
void ThInOrder1(TBTNode *tb)	//��������������������ǵݹ��㷨
{	TBTNode *p=tb->lchild;		//ָ������
	while (p!=tb)
	{	while (p->ltag==0) p=p->lchild;		//������ʼ���
		printf("%c ",p->data);
		while (p->rtag==1 && p->rchild!=tb)	//�������������
		{	p=p->rchild;
			printf("%c ",p->data);
		}
		p=p->rchild;						//ת����p��������
	}
}
void DestroyTBTree1(TBTNode *tb)	//��DestroyTBTree�㷨����
{
	if (tb!=NULL)
	{
		if (tb->lchild!=NULL && tb->ltag==0)  //������  
			DestroyTBTree1(tb->lchild);
		if (tb->rchild!=NULL && tb->rtag==0)  //���Һ���  
			DestroyTBTree1(tb->rchild);
		free(tb);
	}
}
void DestroyTBTree(TBTNode *tb)	//�ͷ��������������������н��
{
	DestroyTBTree1(tb->lchild);
	free(tb);
}
int main()
{	TBTNode *b,*tb;
	CreateTBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 	
	printf("������:");DispTBTree(b);printf("\n");
	tb=CreateThread(b);
	printf("������������:\n");
	printf("    �ݹ��㷨:");ThInOrder(tb);printf("\n");
	printf("  �ǵݹ��㷨:");ThInOrder1(tb);printf("\n");
	DestroyTBTree(tb);
	return 1;
}
