//���������㷨
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct DataNode
{	
	ElemType data;
	struct DataNode *next;
} DataNode;				//�������ݽڵ����Ͷ���
typedef struct
{	
	DataNode *front;
	DataNode *rear;
} LinkQuNode;			//�������Ͷ���
void InitQueue(LinkQuNode *&q)	//��ʼ������q
{	
	q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front=q->rear=NULL;
}
void DestroyQueue(LinkQuNode *&q)	//���ٶ���q
{
	DataNode *p=q->front,*r;//pָ���ͷ���ݽڵ�
	if (p!=NULL)			//�ͷ����ݽڵ�ռ�ÿռ�
	{	r=p->next;
		while (r!=NULL)
		{	free(p);
			p=r;r=p->next;
		}
	}
	free(p);
	free(q);				//�ͷ����ӽڵ�ռ�ÿռ�
}
bool QueueEmpty(LinkQuNode *q)	//�ж϶�q�Ƿ��
{
	return(q->rear==NULL);
}
void enQueue(LinkQuNode *&q,ElemType e)	//����
{	DataNode *p;
	p=(DataNode *)malloc(sizeof(DataNode));
	p->data=e;
	p->next=NULL;
	if (q->rear==NULL)		//������Ϊ��,���½ڵ��Ƕ��׽ڵ����Ƕ�β�ڵ�
		q->front=q->rear=p;
	else
	{	q->rear->next=p;	//��p�ڵ�������β,����rearָ����
		q->rear=p;
	}
}
bool deQueue(LinkQuNode *&q,ElemType &e)	//����
{	DataNode *t;
	if (q->rear==NULL)		//����Ϊ��
		return false;
	t=q->front;				//tָ���һ�����ݽڵ�
	if (q->front==q->rear)  //������ֻ��һ���ڵ�ʱ
		q->front=q->rear=NULL;
	else					//�������ж���ڵ�ʱ
		q->front=q->front->next;
	e=t->data;
	free(t);
	return true;
}
