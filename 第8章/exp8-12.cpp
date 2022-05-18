//�ļ���:exp8-12.cpp
#include<stdio.h>
#include<malloc.h>
#define MAXV 201
//------ͼ���ڽӱ���---------
typedef struct ANode
{	int no;					//������
	struct ANode *nextarc;	//ָ����һ����ͨ�Ŷ���ڵ�
} ArcNode;
typedef struct Vnode
{
	ArcNode *firstarc;		//ָ���һ����ͨ�Ŷ���ڵ�
} VNode;
typedef struct
{	int n;					//�����������������
	int m;					//��ͨ�Ŷ������,������
	VNode adjlist[MAXV];	//��ͷ�ڵ�����
} ALGraph;

int BFS(ALGraph *G,int s,int e)			//���ù�����ȱ�������s��e�����·������
{
	int visited[MAXV];
	struct
	{	int no;							//���ﶥ����
		int level;						//���
	} qu[MAXV];							//���ζ���
	int front=0,rear=0,i,w,l;
	ArcNode *p;
	if (s==e) return 0;
	for (i=0;i<G->n;i++) visited[i]=0;
	visited[s]=1;
	rear=(rear+1) % MAXV;				//���s����
	qu[rear].no=s; 
	qu[rear].level=0;					//���Ĳ������Ϊ0
	while (front!=rear)					//�Ӳ���ѭ��
	{
		front=(front+1) % MAXV;
		w=qu[front].no;					//���Ӷ���w
		l=qu[front].level;				//����w�Ĳ��Ϊl
		p=G->adjlist[w].firstarc;		//�Ҷ���w�ĵ�һ�����ڵ�
		while (p!=NULL)
		{
			if (visited[p->no]==0)		//���ö���û�з��ʹ�
			{
				if (p->no==e)			//�ҵ��յ�e����������
					return qu[rear].level;
				visited[p->no]=1;		//������
				rear=(rear+1) % MAXV;	//��������
				qu[rear].no=p->no;
				qu[rear].level=l+1;
			}
			p=p->nextarc;
		}
	}
	return -1;
}

void InitGraph(ALGraph *&G,int n)		//��ʼ���ڽӱ�
{	int i;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	G->n=n;
	G->m=0;
}
void Add(ALGraph *&G,int a,int b)		//ͼ�����һ����(a,b)
{	ArcNode *p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->no=b;
	p->nextarc=G->adjlist[a].firstarc;
	G->adjlist[a].firstarc=p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->no=a;
	p->nextarc=G->adjlist[b].firstarc;
	G->adjlist[b].firstarc=p;
	G->m++;
}
void DestroyGraph(ALGraph *&G)	//����ͼ
{
	ArcNode *pre,*p;
	for (int i=0;i<G->n;i++)
	{
		pre=G->adjlist[i].firstarc;
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
void DispGraph(ALGraph *G)		//���ͼ
{
	int i;
	ArcNode *p;
	printf("n=%d,e=%d\n",G->n,G->m);
	for (i=0;i<G->n;i++)
	{	printf("[%3d]:",i);
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	printf("��(%d)",p->no);
			p=p->nextarc;
		}
		printf("����\n");
	}
}
int main()
{
	ALGraph *G;
	int m,n,k,a,b,s,e,i;
	FILE *fp;
	fp=fopen("test.txt","r");
	if (fp==NULL)
	{
		printf("���ܴ�test.txt�ļ�\n");
		return 0;
	}
	fscanf(fp,"%d%d",&n,&m);
	InitGraph(G,n);
	for (i=0;i<m;i++)		//�������뽨���ڽӱ��еĵ�����
	{
		fscanf(fp,"%d%d",&a,&b);
		Add(G,a,b);
	}
	printf("�ڽӱ�:\n"); DispGraph(G);
	printf("�����:\n");
	fscanf(fp,"%d",&k);
	for (i=0;i<k;i++)
	{
		fscanf(fp,"%d %d",&s,&e);
		printf("  case%d������Ҫ%d������\n",i+1,BFS(G,s,e));
	}
	DestroyGraph(G);
	fclose(fp);
	return 1;
}
