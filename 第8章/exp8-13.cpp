//�ļ���:exp8-13.cpp
#include "graph.cpp"			//����ͼ�Ĵ洢�ṹ�����������㷨
void Dispapath(int path[][MAXV],int i,int j)	//�������i��j��һ�����·��
{
	int apath[MAXV],d;			//���һ�����·���м䶥��(����)���䶥�����
	int k=path[i][j];
	d=0; apath[d]=j;			//·��������յ�
	while (k!=-1 && k!=i)		//·��������м��
	{	
		d++; apath[d]=k;
		k=path[i][k];
	}
	d++; apath[d]=i;			//·����������
	for (int s=d;s>=0;s--)		//���·���ϵ��м䶥��
		printf("%d��",apath[s]);
}
int Mincycle(MatGraph g,int A[MAXV][MAXV],int &mini,int &minj)	//��ͼg��A�еĲ���һ����С��
{
	int i,j,min=INF;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			if (i!=j && g.edges[j][i]<INF)
			{
				if (A[i][j]+g.edges[j][i]<min)
				{
					min=A[i][j]+g.edges[j][i];
					mini=i; minj=j;
				}
			}
	return min;
}

void Floyd(MatGraph g)						//Floyd�㷨��ͼg�е�һ����С��
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k,min,mini,minj;
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
	min=Mincycle(g,A,mini,minj);
	if (min!=INF)
	{
		printf("  ͼ����С����");
		Dispapath(path,mini,minj);	//���һ�����·��
		printf("%d, ���ȣ�%d\n",mini,min);
	}
	else
		printf("  ͼ��û���κλ�\n");


}
int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,10,1,INF},
		{21,0,INF,6},
		{INF,1,0,INF},
		{5,INF,INF,0} };
	int n=4, e=6;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���
	printf("����ͼG���ڽӾ���:\n"); DispMat(g);
	printf("�����:\n");
	Floyd(g);
	return 1;
}