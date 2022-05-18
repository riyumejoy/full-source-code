//�ļ���:exp3-9.cpp
#include <stdio.h>
#include <malloc.h>
#define N 3					//ͣ����������ͣ����
#define M 4					//�򳵳�������ͣ����
#define Price 2				//ÿ��λͣ������
typedef struct 
{
	int CarNo[N];			//���ƺ�
	int CarTime[N];			//����ʱ��
	int top;				//ջָ��
} SqStack;					//����˳��ջ����
typedef struct 
{
	int CarNo[M];			//���ƺ�
	int front,rear;			//���׺Ͷ�βָ��
} SqQueue;					//�������ζ�������

//����Ϊջ�������㷨
void InitStack(SqStack *&s)	 //��ʼ��ջ
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
bool StackEmpty(SqStack *s)	//�ж�ջ��
{
	return(s->top==-1);
}
bool StackFull(SqStack *s)	//�ж�ջ��
{
	return(s->top==N-1);
}
bool Push(SqStack *&s,int e1,int e2)  //��ջ
{
	if (s->top==N-1)
		return false;
	s->top++;
	s->CarNo[s->top]=e1;
	s->CarTime[s->top]=e2;
	return true;
}
bool Pop(SqStack *&s,int &e1,int &e2)  //��ջ
{
	if (s->top==-1)
		return false;
	e1=s->CarNo[s->top];
	e2=s->CarTime[s->top];
	s->top--;
	return true;
}
void DispStack(SqStack *s)	 //��ʾջ��Ԫ��
{
	for (int i=s->top;i>=0;i--)
		printf("%d ",s->CarNo[i]);
	printf("\n");
}

//����Ϊ���е������㷨
void InitQueue(SqQueue *&q)		//��ʼ����
{
	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
bool QueueEmpty(SqQueue *q)		//�ж϶ӿ�
{
	return(q->front==q->rear);
}
bool QueueFull(SqQueue *q)			//�ж϶���
{
	return ((q->rear+1)%M==q->front);
}
bool enQueue(SqQueue *&q,int e)		//����
{
	if ((q->rear+1)%M==q->front)	//����
		return false;
	q->rear=(q->rear+1)%M;
	q->CarNo[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,int &e)	//����
{
	if (q->front==q->rear)			//�ӿյ����
		return false;
	q->front=(q->front+1)%M;
	e=q->CarNo[q->front];
	return true;
}
void DispQueue(SqQueue *q)	 //��ʾ����Ԫ��
{
	int i=(q->front+1)%M;
	printf("%d ",q->CarNo[i]);
	while ((q->rear-i+M)%M>0) 
	{
		i=(i+1)%M;
		printf("%d ",q->CarNo[i]);
	} 
	printf("\n");
}
int main()
{
	int comm,i,j;
	int no,e1,time,e2;
	SqStack *St,*St1;
	SqQueue *Qu;
	InitStack(St);
	InitStack(St1);
	InitQueue(Qu);
	do
	{
		printf(">����ָ��(1:���� 2:�뿪 3:ͣ���� 4:�򳵳� 0:�˳�):");
		scanf("%d",&comm);
		switch(comm)
		{
		case 1:		//��������
			printf("  ���� ����ʱ��:");
			scanf("%d%d",&no,&time);
			if (!StackFull(St))			//ͣ��������
			{
				Push(St,no,time);
				printf("  ͣ����λ��:%d\n",St->top+1);
			}
			else						//ͣ������
			{
				if (!QueueFull(Qu))		//�򳵳�����
				{
					enQueue(Qu,no);
					printf("  �򳵳�λ��:%d\n",Qu->rear);
				}
				else
					printf("  �򳵳�����,����ͣ��\n");
			}
			break;
		case 2:		//�����뿪
			printf("  ���� �뿪ʱ��:");
			scanf("%d%d",&no,&time);
			for (i=0;i<=St->top && St->CarNo[i]!=no;i++);
			if (i>St->top)
				printf("  δ�ҵ��ñ�ŵ�����\n");
			else
			{
				for (j=i;j<=St->top;j++)
				{
					Pop(St,e1,e2);
					Push(St1,e1,e2);		//��������ʱջSt1��
				}
				Pop(St,e1,e2);				//�������뿪
				printf("  %d����ͣ������:%d\n",no,(time-e2)*Price);
				while (!StackEmpty(St1))	//����ʱջSt1���»ص�St��
				{
					Pop(St1,e1,e2);
					Push(St,e1,e2);
				}
				if (!QueueEmpty(Qu))		//�Ӳ���ʱ,����ͷ��ջSt
				{
					deQueue(Qu,e1);
					Push(St,e1,time);		//�Ե�ǰʱ�俪ʼ�Ʒ�
				}
			}
			break;
		case 3:		//��ʾͣ�������
			if (!StackEmpty(St))
			{
				printf("  ͣ�����еĳ���:");	//���ͣ�����еĳ���
				DispStack(St);
			}
			else
				printf("  ͣ�������޳���\n");	
			break;
		case 4:		//��ʾ�򳵳����
			if (!QueueEmpty(Qu))
			{
				printf("  �򳵳��еĳ���:");	//����򳵳��еĳ���
				DispQueue(Qu);
			}
			else
				printf("  �򳵳����޳���\n");	
			break;
		case 0:		//����
			if (!StackEmpty(St))
			{
				printf("  ͣ�����еĳ���:");	//���ͣ�����еĳ���
				DispStack(St);
			}
			if (!QueueEmpty(Qu))
			{
				printf("  �򳵳��еĳ���:");	//����򳵳��еĳ���
				DispQueue(Qu);
			}
			break;
		default:	//�������
			printf("  ������������\n");
			break;
		} 
	} while(comm!=0);
	return 1;
}
