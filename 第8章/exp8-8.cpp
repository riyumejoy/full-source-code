//�ļ���:exp8-8.cpp
#include "graph.cpp"   //����ͼ�Ĵ洢�ṹ�����������㷨
void Dispath(MatGraph g,int A[][MAXV],int path[][MAXV])	//������·��
{	int i,j,k,s;
	int apath[MAXV],d;		//���һ�����·���м䶥��(����)���䶥�����
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{	if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{	printf("  ��%d��%d��·��Ϊ:",i,j);
				k=path[i][j];
				d=0; apath[d]=j;				//·��������յ�
				while (k!=-1 && k!=i)			//·��������м��
				{	d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//·����������
				printf("%d",apath[d]);			//������
				for (s=d-1;s>=0;s--)			//���·���ϵ��м䶥��
					printf(",%d",apath[s]);
				printf("     \t·������Ϊ:%d\n",A[i][j]);
			}
		}
}

void Floyd(MatGraph g)						//Floyd�㷨
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;				//����i��j�б�ʱ
			else
				path[i][j]=-1;				//����i��jû�б�ʱ
		}
	for (k=0;k<g.n;k++)						//���ο������ж���
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{	A[i][j]=A[i][k]+A[k][j];	//�޸����·������
					path[i][j]=path[k][j];		//�޸����·��
				}
	}
	Dispath(g,A,path);							//������·��
}
int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	int n=6, e=10;
	CreateMat(g,A,n,e);		//����ͼ8.1���ڽӾ���
	printf("����ͼG���ڽӾ���:\n"); DispMat(g);
	printf("���������㷨�����:\n");
	Floyd(g);
	return 1;
}