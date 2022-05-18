//�ļ���:exp8-5.cpp
#include "graph.cpp"			//����ͼ�Ĵ洢�ṹ�����������㷨
void Prim(MatGraph g,int v)
{
	int lowcost[MAXV],min,n=g.n;
	int closest[MAXV],i,j,k;
	for (i=0;i<n;i++)          	//��lowcost[]��closest[]�ó�ֵ
	{	
		lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (i=1;i<n;i++)          	//�ҳ�n-1������
	{   
		min=INF;
	    for (j=0;j<n;j++)       //��(V-U)���ҳ���U����Ķ���k
		   	if (lowcost[j]!=0 && lowcost[j]<min) 
			{	
				min=lowcost[j]; k=j;  
			}
		printf("  ��(%d,%d)ȨΪ:%d\n",closest[k],k,min);
		lowcost[k]=0;         	//���k�Ѿ�����U
		for (j=0;j<n;j++)   	//�޸�����lowcost��closest
           	if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j]) 
			{	lowcost[j]=g.edges[k][j];
				closest[j]=k; 
			}
	}
}
int main()
{
	int v=3;
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,5,8,7,INF,3},
		{5,0,4,INF,INF,INF},
		{8,4,0,5,INF,9},
		{7,INF,5,0,5,6},
		{INF,INF,INF,5,0,1},
		{3,INF,9,6,1,0}};
	int n=6,e=10;
	CreateMat(g,A,n,e);		//����ͼ8.10���ڽӾ���
	printf("ͼG���ڽӾ���:\n");	DispMat(g);
	printf("����ķ�㷨�����:\n");
	Prim(g,0);
	return 1;
}
