//�ļ���:exp7-7.cpp
#include "btree.cpp"			//�����������Ļ��������㷨
void AllPath1(BTNode *b,ElemType path[],int pathlen)
//���������������������д�Ҷ�ӽ�㵽��������·��
{
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//bΪҶ�ӽ��
		{
			printf("   %c���������·��: %c->",b->data,b->data);
			for (int i=pathlen-1;i>0;i--)
				printf("%c->",path[i]);
			printf("%c\n",path[0]);
		}
		else
		{
			path[pathlen]=b->data;				//����ǰ������·����
			pathlen++;							//·��������1
			AllPath1(b->lchild,path,pathlen);	//�ݹ�ɨ��������
			AllPath1(b->rchild,path,pathlen);	//�ݹ�ɨ��������
		}
	}
}
void LongPath1(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],int &longpathlen)
//��������������������һ�������·��
{
	if (b==NULL)
	{
		if (pathlen>longpathlen)	//����ǰ·������,��·��������longpath��
		{
			for (int i=pathlen-1;i>=0;i--)
				longpath[i]=path[i];
			longpathlen=pathlen;
		}
	}
	else	
	{
		path[pathlen]=b->data;					//����ǰ������·����
		pathlen++;								//·��������1
		LongPath1(b->lchild,path,pathlen,longpath,longpathlen);	//�ݹ�ɨ��������
		LongPath1(b->rchild,path,pathlen,longpath,longpathlen);	//�ݹ�ɨ��������
	}
}
void AllPath2(BTNode *b)	//���ú���ǵݹ��������������д�Ҷ�ӽ�㵽��������·��
{
	BTNode *st[MaxSize];			//����һ��˳��ջst
	int top=-1;						//ջ��ָ���ʼ��
	BTNode *p,*r;
	bool flag;
	p=b;
	do
	{
		while (p!=NULL)				//ɨ����p���������½�㲢��ջ
		{
			top++;
			st[top]=p;				//���p��ջ
			p=p->lchild;			//�ƶ�������
		}
		r=NULL;						//rָ��ոշ��ʵĽ�㣬��ʼʱΪ��
		flag=true;					//flagΪ���ʾ���ڴ���ջ�����
		while (top>-1 && flag)		//ջ������flagΪ��ʱѭ��
		{
			p=st[top];				//ȡ����ǰ��ջ�����p
			if (p->rchild==r)		//�����p���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľ��
			{
				if (p->lchild==NULL && p->rchild==NULL)	//��ΪҶ�ӽ��
				{					//���ջ�����н��ֵ
					printf("   %c���������·����",p->data);
					for (int i=top;i>0;i--)
						printf("%c->",st[i]->data);
					printf("%c\n",st[0]->data);
				}
				top--;				//��ջ
				r=p;				//rָ��շ��ʹ��Ľ��
			}
			else
			{	p=p->rchild;		//ת������������
				flag=false;			//��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (top>-1);			//ջ����ѭ��
}

void AllPath3(BTNode *b)
//���ò�α�������������д�Ҷ�ӽ�㵽��������·��
{
	struct snode
	{
	   BTNode *node;			//��ŵ�ǰ���ָ��
	   int parent;				//���˫�׽���ڶ����е�λ��
	} Qu[MaxSize];				//����˳�����
	int front,rear,p;			//�����ͷ�Ͷ�βָ��
    front=rear=-1;				//�ö���Ϊ�ն���
	rear++;
    Qu[rear].node=b;			//�����ָ��������
	Qu[rear].parent=-1;			//�����û��˫�׽��
    while (front<rear)			//���в�Ϊ��
    {
		front++;
		b=Qu[front].node;		//��ͷ������
		if (b->lchild==NULL && b->rchild==NULL)	//*bΪҶ�ӽ��
		{
			printf("   %c���������·����",b->data);
			p=front;
			while (Qu[p].parent!=-1)
			{
				printf("%c->",Qu[p].node->data);
				p=Qu[p].parent;
			}
			printf("%c\n",Qu[p].node->data);
		}
		if (b->lchild!=NULL)		//���������
		{
			rear++;
			Qu[rear].node=b->lchild;
			Qu[rear].parent=front;
		}
		if (b->rchild!=NULL)		//�Һ��������
		{
			rear++;
			Qu[rear].node=b->rchild;
			Qu[rear].parent=front;
		}
	} 
}

int main()
{
	BTNode *b;
	ElemType path[MaxSize],longpath[MaxSize];
	int i,longpathlen=0;
	CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"); 
	printf("������b:");DispBTree(b);printf("\n");
	printf("�����������:\n");AllPath1(b,path,0);
	LongPath1(b,path,0,longpath,longpathlen);
	printf("   ��һ�����·������:%d\n",longpathlen);
	printf("   ��һ�����·��:");
	for (i=longpathlen-1;i>=0;i--)
		printf("%c ",longpath[i]);
	printf("\n");
	printf("����ǵݹ��������:\n");AllPath2(b);
	printf("��α�������:\n");AllPath3(b);
	DestroyBTree(b);
	return 1;
}
