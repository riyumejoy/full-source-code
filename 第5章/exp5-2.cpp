//�ļ���:exp5-2.cpp
#include <stdio.h>
#define MaxSize 100
int pathnum(int m,int n)		//����(m,n)��(1,1)��·������
{
	if (m<1 || n<1) return 0;
	if (m==1 && n==1) return 1;
	return pathnum(m-1,n)+pathnum(m,n-1);
}
typedef struct
{
	int i,j;
} PathType;							//·��Ԫ������
int count=0;						//·�����
void disppath(int m,int n,PathType path[],int d) //�����(m,n)��(1,1)������·��
{	
	if (m<1 || n<1) return;
	if (m==1 && n==1)				//�ҵ�Ŀ�ĵأ����һ��·��
	{
		d++;						//����ǰλ�÷���path��
		path[d].i=m; path[d].j=n;
		printf("·��%d: ",++count);
		for (int k=0;k<=d;k++)
			printf("(%d,%d) ",path[k].i,path[k].j);
		printf("\n");
	}
	else
	{
		d++;						//����ǰλ�÷���path��
		path[d].i=m; path[d].j=n;
		disppath(m-1,n,path,d);		//������һ��
		disppath(m,n-1,path,d);		//�˻�����������һ��
	}
}
int main()
{
	int m=2,n=5;
	printf("m=%d,n=%d��·������:%d\n",m,n,pathnum(m,n));
	PathType path[MaxSize];
	int d=-1;
	disppath(m,n,path,d);
	return 1;
}
