//�ļ���:exp6-4.cpp
#include <stdio.h>
#define M 4
#define N 4
void MinMax(int A[M][N])
{	int i,j;
	bool have=false;
	int min[M],max[N];
	for (i=0;i<M;i++)		//�����ÿ�е���СֵԪ��,����min[0..M-1]֮��
	{
		min[i]=A[i][0];
		for (j=1;j<N;j++)
			if (A[i][j]<min[i])
				min[i]=A[i][j];
	}
	for (j=0;j<N;j++)		//�����ÿ�е����ֵԪ��,����max[0..N-1]֮��
	{	max[j]=A[0][j];
		for (i=1;i<M;i++)
			if (A[i][j]>max[j]) 
				max[j]=A[i][j];
	}
	for (i=0;i<M;i++)		//�ж��Ƿ�Ϊ����
		for (j=0;j<N;j++)
			if (min[i]==max[j])
			{	printf("  A[%d][%d]=%d\n",i,j,A[i][j]);	//��ʾ����
				have=true;
			}
	if (!have)
		printf("û�а���\n");
}
int main()
{	int i,j;
	int A[M][N]={{9, 7, 6, 8},{20,26,22,25},{28,36,25,30},{12,4, 2, 6}};
	printf("A����:\n");
	for (i=0;i<M;i++)
	{	for (j=0;j<N;j++)
			printf("%4d",A[i][j]);
		printf("\n");
	}
	printf("A�����е�����:\n");
	MinMax(A);			//����MinMax()������
	return 1;
}
