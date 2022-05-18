//�ļ���:exp11-1.cpp
#include <stdio.h>
#define K 5					//5·ƽ��鲢
#define MINKEY -32768		//��С�ؼ���ֵ-��
typedef int KeyType;
typedef KeyType LoserTree;	//������ΪLoserTree[K]
KeyType b[K];				//b�д�����еļ�¼(�ؼ���)
int count=1;				//ȫ�ֱ���
void Adjust(LoserTree ls[K],int s)
//�ش�Ҷ�ӽڵ�b[s]�����ڵ�ls[0]��·������������
{	int i,t;
	t=(s+K)/2;				//ls[t]��b[s]��˫�׽ڵ�
	while (t>0)
	{
		if(b[s]>b[ls[t]])	//��˫�׽ڵ�ls[t]�Ƚ�С(ʤ��)
		{
			i=s;			//iָ�����(����)
			s=ls[t];		//sָʾ�µ�ʤ��
			ls[t]=i;		//������(����)����˫�׽ڵ���
		}
		t=t/2;				//�������ϵ���
	}
	ls[0]=s;				//�ھ��ڵ�����С��
}
void display(LoserTree ls[K])	//���������ls
{	int i;
	printf("������:");
	for (i=0;i<K;i++)
		if (b[ls[i]]==MINKEY)
			printf("%d(-��) ",ls[i]);
		else
			printf("%d(%d) ",ls[i],b[ls[i]]);
	printf("\n");
}
void CreateLoserTree(LoserTree ls[K]) //����������ls
{
	int i;
	b[K]=MINKEY;			//b[K]��Ϊ��С�ؼ���
	for (i=0;i<K;i++)
		ls[i]=K;			//����ls��"����"�ĳ�ֵ,ȫ��Ϊ��С�ؼ��ֶκ�
	for(i=K-1;i>=0;--i)		//���δ�b[K-1]��b[K-2]������b[0]������������
	{
		printf("(%d)��b[%d](%d)���е�����",count++,i,b[i]);
		Adjust(ls,i);
		display(ls);
	}
}

int main()
{
	LoserTree ls[K];
	int n=5;
	KeyType a[]={17,5,10,29,15};
	printf("%d·�鲢�Ĺؼ�������:",K);
	for (int i=0;i<n;i++)
	{
		b[i]=a[i];
		printf("%d ",b[i]);
	}
	printf("\n");
	CreateLoserTree(ls);
	printf("���ս��  "); display(ls);
	return 1;
}
	
