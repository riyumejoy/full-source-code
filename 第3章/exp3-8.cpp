//�ļ���:exap3-8.cpp
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct
{	int col[MaxSize];					//col[i]��ŵ�i���ʺ���к�
	int top;							//ջ��ָ��
} StackType;							//����˳��ջ����
void dispasolution(StackType St)   		//���һ����
{	static int count=0;					//��̬��������ͳ�ƽ����
	printf("  ��%d����:",++count);
	for (int i=1;i<=St.top;i++)
		printf("(%d,%d) ",i,St.col[i]);
	printf("\n");
}
bool place(StackType St,int k,int j)	//����(k,j)�Ƿ���1��k-1�Ļʺ��г�ͻ
{	int i=1;
	if (k==1) return true;				//�ŵ�һ���ʺ�ʱû�г�ͻ
	while (i<=k-1)						//������ǰ���ѷ��õĻʺ��Ƿ��г�ͻ
	{	if ((St.col[i]==j) || (abs(j-St.col[i])==abs(i-k)))
			return false;				//�г�ͻʱ���ؼ�
		i++;
	}
	return true;						//û�г�ͻʱ������
}
void queen(int n)						//���n�ʺ�����
{
	int k;
	bool find;
	StackType St;						//����ջst
	St.top=0;							//��ʼ��ջ��ָ��,Ϊ���ûʺ�ӵ�1�п�ʼ,�����±�0
	St.top++; St.col[St.top]=0;			//col[1]=0,��ʾ�ӵ�1���ʺ�ʼ,��ʼ�к�Ϊ0
	while (St.top!=0)					//ջ����ʱѭ��
	{	k=St.top;						//��̽ջ���ĵ�k���ʺ�
		find=false;						//��δ�ҵ���k���ʺ��λ��,find����Ϊ��
		for (int j=St.col[k]+1;j<=n;j++)//Ϊ��k���ʺ����һ�����ʵ��к�
			if (place(St,k,j))			//�ڵ�k���ҵ�һ���Żʺ��λ��(k,j)
			{	St.col[St.top]=j;		//�޸ĵ�k���ʺ��λ��(���к�)
				find=true;				//�ҵ���k���ʺ��λ��,find����Ϊ��
				break;					//�ҵ����˳�forѭ��
			}
		if (find)						//�ڵ�k���ҵ�һ���Żʺ��λ��(k,j)
		{	if (k==n)					//�����лʺ���ź�,���һ����
				dispasolution(St);
			else						//���лʺ�δ��ʱ,����k+1���ʺ��ջ
			{	St.top++;
				St.col[St.top]=0;		//�½�ջ�Ļʺ�ӵ�0�п�ʼ��̽��
			}
		}
		else							//����k���ʺ�û�к���λ��,����
			St.top--;					//������k���ʺ���ջ
	}
}
int main()
{	int n;								//n���ʵ�ʻʺ����
	printf("�ʺ�����(n<20) n=");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��\n");
	else
	{	printf(" %d�ʺ�����������£�\n",n);
		queen(n);
	}
	return 1;
}
