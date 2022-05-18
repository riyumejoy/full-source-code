//�ļ���:exp10-9.cpp
#include <stdio.h>
#include <malloc.h>
#define MAXE 20			//���Ա������Ԫ�ظ���
#define MAXR 10			//���������ȡֵ
typedef struct node
{
	int key;			//��¼�Ĺؼ���
    struct node *next;
} NodeType;

void CreateLink(NodeType *&p,int a[],int n)	//����β�巨����������
{
	NodeType *s,*t;
	for (int i=0;i<n;i++)
	{
		s=(NodeType *)malloc(sizeof(NodeType));
		s->key=a[i];
		if (i==0)
		{
			p=s;t=s;
		}
		else
		{
			t->next=s;t=s;
		}
	}
	t->next=NULL;
}
void DispLink(NodeType *p)	//���������
{
	while (p!=NULL)
	{
		printf("%4d",p->key);
		p=p->next;
	}
	printf("\n");
}
void DestroyLink(NodeType *p)	//���ٵ�����
{
	NodeType *pre=p,*q=pre->next;
	while (q!=NULL)
	{
		free(pre);
		pre=q;
		q=q->next;
	}
	free(pre);
}
int keyi(int s,int i)	//������ֵs���ӵ͵���λ��ȡ��iλ������
{
	for (int j=0;j<i;j++)
		s=s/10;
	return s%10;

}
void RadixSort(NodeType *&p,int r,int d) //ʵ�ֻ�������:pָ��������׽ڵ�,rΪ����,dΪ�ؼ���λ��
{
	NodeType *head[MAXR],*tail[MAXR],*t;	//��������ӵ���βָ��
	int i,j,k;
	for (i=0;i<d;i++)           		//�ӵ�λ����λѭ��
	{	
		for (j=0;j<r;j++) 				//��ʼ���������ס�βָ��
			head[j]=tail[j]=NULL;
		while (p!=NULL)          		//����ԭ������ÿ���ڵ�ѭ��
		{	
			k=keyi(p->key,i);   		//��p�ڵ�ؼ��ֵĵ�iλk
			if (head[k]==NULL)   		//��p�ڵ���䵽��k������
			{
				head[k]=p;
				tail[k]=p;
			}
          	else
			{
              	tail[k]->next=p;
				tail[k]=p;
			}
            p=p->next;             		//����ɨ����һ���ڵ�
		}
		p=NULL;
       	for (j=0;j<r;j++)        		//����ÿһ������ѭ��
        	if (head[j]!=NULL)         	//�����ռ�
			{	
				if (p==NULL)
				{
					p=head[j];
					t=tail[j];
				}
				else
				{
					t->next=head[j];
					t=tail[j];
				}
			}
		t->next=NULL;					//���һ���ڵ��next����NULL
		printf("��%dλ����:",i+1); DispLink(p);
	}
}

int main()
{
	int n=10;
	NodeType *p;
	int a[]={75,223,98,44,157,2,29,164,38,82};
	CreateLink(p,a,n);
	printf("   ����ǰ:"); DispLink(p);
	RadixSort(p,10,3);
	printf("   �����:"); DispLink(p);
	DestroyLink(p);
	return 1;
}
