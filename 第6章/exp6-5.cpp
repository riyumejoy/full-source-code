//�ļ���:exp6-5.cpp
#include <stdio.h>
#define N 4
#define M 10
int value(int a[],int i,int j)	//����ѹ���洢a��A[i][j]ֵ֮
{
	if (i>=j)
		return a[(i*(i-1))/2+j];
	else
		return a[(j*(j-1))/2+i];
}
void madd(int a[],int b[],int c[][N])	//��ѹ���洢a��b�ĺ�
{
	int i,j;
    for (i=0;i<N;i++)
       for (j=0;j<N;j++)
           c[i][j]=value(a,i,j)+value(b,i,j);
}
void mult(int a[],int b[],int c[][N])	//��ѹ���洢a��b�ĳ˻�
{
	int i,j,k,s;
    for (i=0;i<N;i++)
       for (j=0;j<N;j++)
        {
		   s=0;
           for (k=0;k<N;k++)
			   s=s+value(a,i,k)*value(b,k,j);
           c[i][j]=s;
       }
}
void disp1(int a[])	//���ѹ���洢a
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
			printf("%4d",value(a,i,j));
		printf("\n");
	}
}
void disp2(int c[][N])	//����Գƾ���c
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
			printf("%4d",c[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[M]={1,2,3,4,5,6,7,8,9,10};
	int b[M]={1,1,1,1,1,1,1,1,1,1};
	int c1[N][N],c2[N][N];
	madd(a,b,c1);
	mult(a,b,c2);
	printf("a����:\n");disp1(a);
	printf("b����:\n");disp1(b);
    printf("a+b:\n");disp2(c1);
    printf("a��b:\n");disp2(c2);
	return 1;
}
