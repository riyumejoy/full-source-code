//�ļ���:exp3-6.cpp
#include <stdio.h>
#include <malloc.h>
typedef struct qnode
{
    int data;					//������
    struct qnode *next;			//��һ���ڵ�ָ��
} QNode;						//���ӽڵ�����
typedef struct  	
{
    QNode *front,*rear;
} QuType;						//������������
void Destroyqueue(QuType *&qu)	//�ͷ�����
{
	QNode *pre,*p;
	pre=qu->front; 
	if (pre!=NULL)				//�����Ӳ���
	{
		p=pre->next;
		while (p!=NULL)			//�ͷŶ����������ݽڵ�
		{
			free(pre);
			pre=p;
			p=p->next;
		}
		free(pre);
	}
	free(qu);					//�ͷ����ӽڵ�
}
bool exist(QuType *qu,int no)	//�������Ƿ���no�����ŵĲ���
{
	bool find=false;
	QNode *p=qu->front;
	while (p!=NULL && !find)
	{
		if (p->data==no)							
			find=true;
		else
			p=p->next;
	}
	return find;
}
void SeeDoctor()				//ģ�ⲡ�˿����Ĺ���
{
    int sel,no;
	bool flag=true;
    QuType *qu;
    QNode *p;
    qu=(QuType *)malloc(sizeof(QuType));	//�����ն�
    qu->front=qu->rear=NULL;
    while (flag) 							//ѭ��ִ��
	{
       	printf(">1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4.�����Ŷ�,�������ξ��� 5:�°�  ��ѡ��:");
		scanf("%d",&sel); 
		switch(sel) 
		{
		case 1:	printf("  ���벡����:");
			while (true)
			{	
				scanf("%d",&no);
				if (exist(qu,no))
					printf("  ����Ĳ������ظ�,��������:");
				else
					break;
			};
			p=(QNode *)malloc(sizeof(QNode));	//�����ڵ�
			p->data=no;p->next=NULL;
			if (qu->rear==NULL)					//��һ�������Ŷ�
				qu->front=qu->rear=p;
			else
			{
				qu->rear->next=p; qu->rear=p;	//��p�ڵ����
			}
			break;
		case 2:	if (qu->front==NULL)				//�ӿ�
					printf("  û���ŶӵĲ���!\n");
			    else								//�Ӳ���
				{
					p=qu->front;
                   	printf("  >>����%d����\n",p->data);
                   	if (qu->rear==p)			//ֻ��һ�������Ŷӵ����
						qu->front=qu->rear=NULL;
				   	else
					   	qu->front=p->next;
				   	free(p);
			   	}
               	break;
          case 3:if (qu->front==NULL)  			//�ӿ�
                   	printf("  û�����еĲ���!\n");
			     else 							//�Ӳ���
				 {
					 p=qu->front;
					 printf("  >>�ŶӲ���:");
					 while (p!=NULL) 
					 {
						 printf("%d ",p->data);
						 p=p->next;
					 }
					 printf("\n");
				 }
				 break;
          case 4:if (qu->front==NULL)			//�ӿ�
                    printf("  >>û�����еĲ���!\n");
			     else							//�Ӳ���
				 {
					 p=qu->front;
					 printf("  >>���˰�����˳�����:");
					 while (p!=NULL) 
					 {
						 printf("%d ",p->data);
						 p=p->next;
					 }
					 printf("\n");
				 }
				 Destroyqueue(qu);				//�ͷ�����
				 flag=false;					//�˳�
				 break;
		  case 5:if (qu->front!=NULL)			//�Ӳ���
					printf("  ���ŶӵĲ��������ҽ!\n");

			     flag=false;					//�˳�
				 Destroyqueue(qu);				//�ͷ�����
               	 break;
		}
    }
}
int main()
{
    SeeDoctor();
	return 1;
}
