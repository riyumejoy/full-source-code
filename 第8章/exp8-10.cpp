//�ļ���:exp8-10.cpp
#include "graph.cpp"	//����ͼ�Ĵ洢�ṹ�����������㷨
int visited[MAXV];		//ȫ������
void PathAll1(AdjGraph *G,int u,int v,int path[],int d)
//���ͼG�дӶ���u��v�����м�·��
{
	ArcNode *p;
	int j,w;
	d++; path[d]=u;						//·������d��1,����ǰ������ӵ�·����
	visited[u]=1;
	if (u==v && d>0)					//�ҵ��յ�
	{
		for (j=0;j<=d;j++)
			printf("%3d",path[j]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;  			//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{
		w=p->adjvex;					//wΪu�����ڵ���
		if (visited[w]==0 ) 			//���ö���δ��Ƿ���,��ݹ����֮
			PathAll1(G,w,v,path,d);
		p=p->nextarc;					//��u����һ�����ڵ�
	}
	visited[u]=0;
}
void PathAll2(AdjGraph *G,int u,int v,int l,int path[],int d)
//���ͼG�дӶ���u��v�ĳ���Ϊl�����м�·��,d�ǵ���ǰΪֹ���߹���·������,����ʱ��ֵΪ-1
{
	int w,i;
	ArcNode *p;
	visited[u]=1;
	d++; path[d]=u;					//·������d��1,����ǰ������ӵ�·����
	if (u==v && d==l)				//�������������һ��·��
	{
		for (i=0;i<=d;i++)
			printf("%3d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;  		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{
		w=p->adjvex;				//wΪ����u�����ڵ�
		if (visited[w]==0)			//���ö���δ��Ƿ���,��ݹ����֮
			PathAll2(G,w,v,l,path,d);
		p=p->nextarc;				//��u����һ�����ڵ�
	}
	visited[u]=0;					//ȡ�����ʱ��,��ʹ�ö��������ʹ��
}
int ShortPath(AdjGraph *G,int u,int v,int path[])
//�󶥵�u������v(u��v)�����·��
{	struct 
	{	int vno;						//��ǰ������
		int level;					//��ǰ����Ĳ��
		int parent;					//��ǰ����ĵ�һ���ڵ���
	} qu[MAXV];						//����˳���ѭ������
	int front=-1,rear=-1,k,lev,i,j;
	ArcNode *p;
	visited[u]=1;
	rear++;							//����u�ѷ���,�������
	qu[rear].vno=u;
	qu[rear].level=0;					//���ڵ�����Ϊ1
	qu[rear].parent=-1;
	while (front<rear)					//�ӷǿ���ִ��
	{	front++;
		k=qu[front].vno;				//���Ӷ���k
		lev=qu[front].level;
		if (k==v) 					//������kΪ�յ�
		{	i=0;						//�ڶ�����ǰ�ƴ�һ������·��
			j=front;					//��·�������path��
			while (j!=-1)
			{	path[lev-i]=qu[j].vno;	//�����·������path��
				j=qu[j].parent;
				i++;
			}
			return lev;				//�ҵ�����v,��������
		}
		p=G->adjlist[k].firstarc;		//pָ�򶥵�k�ĵ�һ�����ڵ�           
		while (p!=NULL)                 	//��������k�����ڵ�
		{	if (visited[p->adjvex]==0)  //��δ���ʹ�
			{	visited[p->adjvex]=1;
				rear++;
				qu[rear].vno=p->adjvex;	//���ʹ������ڵ����
				qu[rear].level=lev+1;
				qu[rear].parent=front;
			}
			p=p->nextarc;				//�Ҷ���k����һ���ڵ�
		}
	}
	return -1;     			//���δ�ҵ�����v,����һ����ֵ-1
}
int main()
{ 
	int i,j;
	int u=5,v=2,l=3;
	int path[MAXV];
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,0,1,0,0},
		{0,0,1,0,0,0},
		{1,0,0,0,0,1},
		{0,0,1,0,0,1},
		{0,0,0,1,0,0},
		{1,1,0,1,1,0}};
	int n=6, e=10;
	CreateAdj(G,A,n,e);		//����ͼ8.21���ڽӱ�
	printf("ͼG���ڽӱ�:\n"); DispAdj(G);
	printf("(1)�Ӷ���%d��%d������·��:\n",u,v);
	for (i=0;i<n;i++) visited[i]=0;
	PathAll1(G,u,v,path,-1);

	printf("(2)�Ӷ���%d��%d�����г���Ϊ%d·��:\n",u,v,l);
	PathAll2(G,u,v,l,path,-1);

	printf("(3)�Ӷ���%d��%d�����·��:\n",u,v);
	for (i=0;i<n;i++) visited[i]=0;
	j=ShortPath(G,u,v,path);
	for (i=0;i<=j;i++)
		printf("%3d",path[i]);
	printf("\n");
	DestroyAdj(G);
	return 1;
}
