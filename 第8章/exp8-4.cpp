//�ļ���:exp8-4.cpp
#include "graph.cpp"					//����ͼ�Ĵ洢�ṹ�����������㷨
#define MaxSize 100
int visited[MAXV]={0};
void DFSTree(AdjGraph *G,int v)			//��ͼG�Ӷ���v�������������������
{
	ArcNode *p;
	visited[v]=1;						//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;      		//pָ�򶥵�v�ĵ�һ�����ڵ�
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)		//��p->adjvex����δ����,�ݹ������
		{
			printf("(%d,%d) ",v,p->adjvex);
			DFSTree(G,p->adjvex);    
		}
		p=p->nextarc;              		//pָ�򶥵�v����һ�����ڵ�
	}
}
void BFSTree(AdjGraph *G,int v)			//��ͼG�Ӷ���v�����Ĺ������������
{
	int w,i;
	int qu[MAXV];						//���廷�ζ���
	int front=0,rear=0;
	ArcNode *p;
	int visited[MAXV];            		//���嶥����ʱ�־����
	for (i=0;i<G->n;i++) visited[i]=0;	//���ʱ�־�����ʼ��
	visited[v]=1;              			//���ѷ��ʱ��
	rear++;								//����v����
	qu[rear]=v;
	while (front!=rear)       			//�Ӳ���ѭ��
	{	
		front=(front+1) % MAXV;			//����һ������w
		w=qu[front];
		p=G->adjlist[w].firstarc; 		//pָ��w�ĵ�һ�����ڵ�
		while (p!=NULL)					//����w���������ڵ�
		{	
			if (visited[p->adjvex]==0) 	//����ǰ�ڽӵ�δ������
			{
				printf("(%d,%d) ",w,p->adjvex);
				visited[p->adjvex]=1;	//���ѷ��ʱ��
				rear=(rear+1) % MAXV;	//����p->adjvex����
				qu[rear]=p->adjvex;
           	}
           	p=p->nextarc;              	//pָ�򶥵�v����һ�����ڵ�
		}
	}
	printf("\n");
}
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV];
	int n=11, e=13;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			A[i][j]=0;
	A[0][1]=1; 	A[0][2]=1; A[0][3]=1;
	A[1][0]=1; A[1][4]=1; A[1][5]=1;
	A[2][0]=1; A[2][3]=1; A[2][5]=1; A[2][6]=1;
	A[3][0]=1; A[3][2]=1; A[3][7]=1;
	A[4][1]=1;
	A[5][1]=1; A[5][2]=1;
	A[6][2]=1; A[6][7]=1; A[6][8]=1; A[6][9]=1;
	A[7][3]=1; A[7][6]=1; A[7][10]=1;
	A[8][6]=1;
	A[9][6]=1;
	A[10][7]=1;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.24���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);	
	int v=3;					//����ڽӱ�G
	printf("�������������:\n");DFSTree(G,v);printf("\n");
	printf("�������������:\n");BFSTree(G,v);
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
