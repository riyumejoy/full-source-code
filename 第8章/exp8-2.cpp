//�ļ���:exp8-2.cpp
#include "travsal.cpp"
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
	int n=6,e=10;			//ͼ8.1�е�����
	CreateAdj(G,A,n,e);
	printf("ͼG���ڽӱ�:\n"); DispAdj(G);
	printf("�Ӷ���0��ʼ��DFS(�ݹ��㷨):\n");
	DFS(G,0);printf("\n");
	printf("�Ӷ���0��ʼ��DFS(�ǵݹ��㷨):\n");
	DFS1(G,0);
	printf("�Ӷ���0��ʼ��BFS:\n");
	BFS(G,0);
	DestroyAdj(G);
	return 1;
}
