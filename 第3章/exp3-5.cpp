//�ļ���:exp3-5.cpp
#include <stdio.h>
#define M 4					//����
#define N 4					//����
#define MaxSize 100			//ջ���Ԫ�ظ���
int mg[M+2][N+2]={			//һ���Թ�,������Ҫ���Ͼ�Ϊ1�����
{1,1,1,1,1,1},
{1,0,0,0,1,1},
{1,0,1,0,0,1},
{1,0,0,0,1,1},
{1,1,0,0,0,1},
{1,1,1,1,1,1}
};
struct 
{
	int i,j;
	int di;
} St[MaxSize],Path[MaxSize];	//����ջ�ʹ�����·��������
int top=-1;						//ջ��ָ��
int count=1;					//·��������
int minlen=MaxSize;				//���·������
void dispapath()				//���һ��·���������·��
{
	int k;
	printf("%5d: ",count++);	//�����count��·��
	for (k=0;k<=top;k++)
		printf("(%d,%d) ",St[k].i,St[k].j);
	printf("\n");
	if (top+1<minlen)			//�Ƚ������·��
	{
		for (k=0;k<=top;k++)	//�����·�������path��
			Path[k]=St[k];
		minlen=top+1;			//�����·�����ȴ����minlen��
	}
}
void dispminpath()				//�����һ�����·��
{
	printf("���·������:\n");
	printf("����: %d\n",minlen);
	printf("·��: ");
	for (int k=0;k<minlen;k++)
		printf("(%d,%d) ",Path[k].i,Path[k].j);
	printf("\n");
}
void mgpath(int xi,int yi,int xe,int ye) //���Թ�·��
{
	int i,j,i1,j1,di;
	bool find;
	top++;							//��ջ
	St[top].i=xi;
	St[top].j=yi;
	St[top].di=-1;mg[xi][yi]=-1;	//��ʼ�����ջ
	while (top>-1)					//ջ����ʱѭ��
	{
		i=St[top].i;j=St[top].j;di=St[top].di;
		if (i==xe && j==ye)			//�ҵ��˳���
		{
			dispapath();			//���һ��·��
			mg[i][j]=0;				//�ó��ڱ�Ϊ����·�����߷���
			top--;					//������ջ,������һ������
			i=St[top].i;j=St[top].j;
			di=St[top].di;			//��ջ�������Ϊ��ǰ����
		}
		find=false;					//����һ�����߷���(i,1j1)
		while (di<4 && !find)	
		{	di++;
			switch(di)
			{
			case 0:i1=i-1; j1=j;   break;
			case 1:i1=i;   j1=j+1; break;
			case 2:i1=i+1; j1=j;   break;
			case 3:i1=i,   j1=j-1; break;
			}
			if (mg[i1][j1]==0) find=true;
		}
		if (find)					//�ҵ�����һ�����߷���(i1,j1)
		{	St[top].di=di;			//�޸�ԭջ��Ԫ�ص�diֵ
			top++;St[top].i=i1;St[top].j=j1;
			St[top].di=-1;			//��һ�����߷���(i1,j1)��ջ
			mg[i1][j1]=-1;			//�����ظ��ߵ��÷���
		}
		else						//û��·������,����ջ(i,j)����
		{
			mg[i][j]=0;				//�ø�λ�ñ�Ϊ����·�����߷���
			top--;
		}
	}
	dispminpath();					//������·��
}
int main()
{
	printf("�Թ�����·������:\n");
	mgpath(1,1,M,N);
	return 1;
}
