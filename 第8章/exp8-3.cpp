//�ļ���:exp8-3.cpp
#include "graph.cpp"		//����ͼ�Ĵ洢�ṹ�����������㷨
int visited[MAXV];
void DFSALL(AdjGraph *G,int v,int path[],int d)  
{
	ArcNode *p;
	visited[v]=1;                   //���ѷ��ʱ��
	path[d]=v;
	d++;
	if (d==G->n)					//����ѷ������ж��㣬�������������
	{
		for (int k=0;k<d;k++)
			printf("%2d",path[k]);
		printf("\n");
	}
	p=G->adjlist[v].firstarc;      	//pָ�򶥵�v�ĵ�һ�����ڵ�
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFSALL(G,p->adjvex,path,d);    
		p=p->nextarc;              	//�Ҷ���v����һ�����ڵ�
	}
	visited[v]=0;
}
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,0,1,1},
		{1,0,1,1,0},
		{0,1,0,1,1},
		{1,1,1,0,1},
		{1,0,1,1,0}};	
	int n=5,e=8;			//���̡̳���ͼ8.1�е�����
	CreateAdj(G,A,n,e);
	printf("ͼG���ڽӱ�:\n"); DispAdj(G);
	
	int path[MAXV],v=1;
	printf("�Ӷ���%d���������������������:\n",v);
	DFSALL(G,v,path,0);
	printf("\n");

	DestroyAdj(G);
	return 1;

}
