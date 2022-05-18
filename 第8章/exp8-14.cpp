//�ļ���:exp8-14.cpp
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
#define M 4
#define N 4
//���¶����ڽӱ�����
typedef struct ANode           	//�ߵĽڵ�ṹ����
{	int i,j;              		//�ñߵ��յ�λ��(i,j)
   	struct ANode *nextarc; 		//ָ����һ���ߵ�ָ��
} ArcNode;
typedef struct Vnode      		//�ڽӱ�ͷ�ڵ������
{
    ArcNode *firstarc;     		//ָ���һ�����ڵ�
} VNode;
typedef struct 
{
	VNode adjlist[M+2][N+2];    //�ڽӱ�ͷ�ڵ�����
} ALGraph;                   	//ͼ���ڽӱ�����

typedef struct
{
	int i;						//��ǰ������к�
	int j;						//��ǰ������к�
} Box;
typedef struct
{
	Box data[MaxSize];
	int length;					//·������
} PathType;						//����·������
int visited[M+2][N+2]={0};
int count=0;
void CreateAdj(ALGraph *&G,int mg[][N+2]) //�����Թ������Ӧ���ڽӱ�G
{
	int i,j,i1,j1,di;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<M+2;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		for (j=0;j<N+2;j++)
			G->adjlist[i][j].firstarc=NULL;
	for (i=1;i<=M;i++)					//���mg��ÿ��Ԫ��
		for (j=1;j<=N;j++)
			if (mg[i][j]==0)
			{
				di=0;
				while (di<4)
				{
					switch(di)
					{
					case 0:i1=i-1; j1=j; break;
					case 1:i1=i; j1=j+1;break;
					case 2:i1=i+1; j1=j;break;
					case 3:i1=i, j1=j-1;break;
					}
					if (mg[i1][j1]==0)							//(i1,j1)Ϊ���߷���
					{   
						p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
						p->i=i1; p->j=j1;
						p->nextarc=G->adjlist[i][j].firstarc;	//��*p�ڵ����������
						G->adjlist[i][j].firstarc=p;
					}
					di++;
				}
			}
}
void DispAdj(ALGraph *G)  //����ڽӱ�G
{
	int i,j;
	ArcNode *p;
	for (i=0;i<M+2;i++)
		for (j=0;j<N+2;j++)
		{
			printf("  [%d,%d]: ",i,j);
			p=G->adjlist[i][j].firstarc;
			while (p!=NULL)
			{
				printf("(%d,%d)  ",p->i,p->j);
				p=p->nextarc;
			}
			printf("\n");
		}
}
void DestroyAdj(ALGraph *&G)	//�����ڽӱ�
{
	int i,j;
	ArcNode *pre,*p;
	for (i=0;i<M+2;i++)
		for (j=0;j<N+2;j++)
		{
			pre=G->adjlist[i][j].firstarc;
			if (pre!=NULL)
			{
				p=pre->nextarc;
				while (p!=NULL)
				{
					free(pre);
					pre=p; p=p->nextarc;
				}
				free(pre);
			}
		}
	free(G);
}

void FindPath(ALGraph *G,int xi,int yi,int xe,int ye,PathType path)
 //��ͼG�в���DFS�㷨��(xi,yi)��(xe,ye)������·��
{
	ArcNode *p;
	visited[xi][yi]=1;                   //���ѷ��ʱ��
	path.data[path.length].i=xi; path.data[path.length].j=yi;
	path.length++;
	if (xi==xe && yi==ye)
	{
		printf("  �Թ�·��%d: ",++count);
		for (int k=0;k<path.length;k++)
			printf("(%d,%d) ",path.data[k].i,path.data[k].j);
		printf("\n");
	}
	p=G->adjlist[xi][yi].firstarc;	//pָ�򶥵�v�ĵ�һ���߶���
	while (p!=NULL) 
	{
		if (visited[p->i][p->j]==0)	//��(p->i,p->j)����δ����,�ݹ������
			FindPath(G,p->i,p->j,xe,ye,path);    
		p=p->nextarc;              	//pָ�򶥵�v����һ���߶���
	}
	visited[xi][yi]=0;
}

int main()
{ 
	ALGraph *G;
	int mg[M+2][N+2]={							//�Թ�����
		{1,1,1,1,1,1},
		{1,0,0,0,1,1},
		{1,0,1,0,0,1},
		{1,0,0,0,1,1},
		{1,1,0,0,0,1},
		{1,1,1,1,1,1}};	
	CreateAdj(G,mg);
	printf("�Թ���Ӧ���ڽӱ�:\n");DispAdj(G);	//����ڽӱ�
	PathType path;
	path.length=0; 
	printf("���е��Թ�·��:\n");
	FindPath(G,1,1,M,N,path);
	DestroyAdj(G);
	return 1;
}
