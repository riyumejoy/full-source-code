//�ļ���:exp5-8.cpp
#include <stdio.h>
#define MAXN 20					//�����Ʒ��
int maxv; 						//������Ž���ܼ�ֵ
int maxw;						//������Ž��������
int x[MAXN];					//������ս�
int W=7;  						//���Ƶ�������
int	n=4;						//��Ʒ����
int w[]={5,3,2,1};				//��Ʒ����
int v[]={4,4,3,1};				//��Ʒ��ֵ

void knap(int i,int tw,int tv,int op[]) //���ǵ�i����Ʒ
{	int j;
	if (i>=n)					//�ݹ���ڣ�������Ʒ�����ǹ�
	{	if (tw<=W && tv>maxv)	//�ҵ�һ�����������ĸ��Ž�,������
		{	maxv=tv;
			maxw=tw;
			for (j=1;j<=n;j++)
				x[j]=op[j];
		}
	}
	else						//��δ����������Ʒ
	{	op[i]=1;				//ѡȡ��i����Ʒ
		knap(i+1,tw+w[i],tv+v[i],op);
		op[i]=0;				//��ѡȡ��i����Ʒ,����
		knap(i+1,tw,tv,op);
	}
}
void dispasolution(int x[],int n)//���һ����
{	int i;
	printf("���װ�����:\n");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",i);
	printf("������=%d,�ܼ�ֵ=%d\n",maxw,maxv);
}
int main()
{
	int op[MAXN];				//�����ʱ��
	knap(0,0,0,op);
	dispasolution(x,n);
	return 1;
}
