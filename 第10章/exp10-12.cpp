//�ļ���:exp10-12.cpp
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXR 10
#define MaxSize 10
typedef struct node
{	char xm[10];	//����
	char xb;		//�Ա� m:�� f:Ů
	char bh[6];		//���
	struct node *next;
} StudNode;
typedef struct 
{	char xm[10];	//����
	char xb;		//�Ա� m:�� f:Ů
	char bh[6];		//���
} StudType;
void CreateLink(StudNode *&p,StudType A[],int n)	//����������
{	int i;
	StudNode *s,*t;
	p=NULL;
	for (i=0;i<n;i++)
	{	s=(StudNode *)malloc(sizeof(StudNode));
		strcpy(s->xm,A[i].xm);
		s->xb=A[i].xb;
		strcpy(s->bh,A[i].bh);
		if (p==NULL)
		{	p=s;
			t=s;
		}
		else
		{	t->next=s;
			t=s;
		}
	}
	t->next=NULL;
}
void DispLink(StudNode *p)		//���������
{	int i=0;
	while (p!=NULL)
	{	printf(" %s(%s,%c) ",p->xm,p->bh,p->xb);
		p=p->next;
		if ((i+1)%5==0) printf("\n");
		i++;
	}
	printf("\n");
}
void DestroyLink(StudNode *p)	//���ٵ�����
{
	StudNode *pre=p,*q=pre->next;
	while (q!=NULL)
	{
		free(pre);
		pre=q;
		q=q->next;
	}
	free(pre);
}
void RadixSort1(StudNode *&p,int r,int d)
//���Ա��������:ֻ�����һ��.pΪ��������������ָ��,rΪ����,dΪ�ؼ���λ��
{	StudNode *head[MAXR],*tail[MAXR],*t;//��������ӵ���βָ��
	int j,k;
	printf("���Ա��������\n");
	for (j=0;j<r;j++) 				//��ʼ���������ס�βָ��
		head[j]=tail[j]=NULL;
	while (p!=NULL)					//����ԭ������ÿ���ڵ�ѭ��
	{	if (p->xb=='f')				//�ҵ�k������
			k=0;
		else 
			k=1;
		if (head[k]==NULL)			//���з���,������β�巨����������
		{	head[k]=p;
			tail[k]=p;
		}
		else
		{	tail[k]->next=p;
			tail[k]=p;
		}
		p=p->next;					//ȡ��һ���������Ԫ��
	}
	p=NULL;
	for (j=0;j<r;j++)				//����ÿһ������ѭ��
		if (head[j]!=NULL)			//�����ռ�
		{	if (p==NULL)
			{	p=head[j];
				t=tail[j];
			}
			else
			{	t->next=head[j];
				t=tail[j];
			}
		}
	t->next=NULL;					//���һ���ڵ��next����NULL
	DispLink(p);
}
void RadixSort2(StudNode *&p,int r,int d)
//�԰�Ž�������:pΪ��������������ָ��,rΪ����,dΪ�ؼ���λ��
{	StudNode *head[MAXR],*tail[MAXR],*t;//��������ӵ���βָ��
	int i,j,k;
	printf("����Ž�������\n");
	for (i=3;i>=2;i--)				//�ӵ�λ����λ��d������
	{	for (j=0;j<r;j++)			//��ʼ���������ס�βָ��
			head[j]=tail[j]=NULL;
		while (p!=NULL)				//����ԭ������ÿ���ڵ�ѭ��
		{	k=p->bh[i]-'0';			//�ҵ�k������
			if (head[k]==NULL)		//���з���,������β�巨����������
			{	head[k]=p;
				tail[k]=p;
			}
			else
			{	tail[k]->next=p;
				tail[k]=p;
			}
			p=p->next;				//ȡ��һ���������Ԫ��
		}
		p=NULL;
		for (j=0;j<r;j++)			//����ÿһ������ѭ��
			if (head[j]!=NULL)		//�����ռ�
			{	if (p==NULL)
				{	p=head[j];
					t=tail[j];
				}
				else
				{	t->next=head[j];
					t=tail[j];
				}
			}
		t->next=NULL;				//���һ���ڵ��next����NULL
		printf(" ��%d��:\n",d-i+2);DispLink(p);
	}
}
void Sort(StudType A[],int n)		//����ź��Ա��������
{
	StudNode *p;
	CreateLink(p,A,n);
	printf("����ǰ:\n");DispLink(p);
	RadixSort1(p,2,1);				//���Ա��������
	RadixSort2(p,10,2);				//�԰�ŵĺ���λ��������
	printf("�����:\n");DispLink(p);
	DestroyLink(p);
}
int main()
{
	int n=10;
	StudType A[MaxSize]={{"����",'m',"1003"},{"���",'m',"1020"},
	{"���",'f',"1022"},{"��Ӣ",'f',"1003"},
	{"�Ź�",'m',"1021"},{"��ǿ",'m',"1002"},
	{"����",'f',"1002"},{"�»�",'m',"1001"},
	{"����",'f',"1021"},{"��ǿ",'m',"1022"}};
	Sort(A,n);
	return 1;
}
