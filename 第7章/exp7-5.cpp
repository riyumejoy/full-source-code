//�ļ���:exp7-5.cpp
#include <stdio.h>
#include <string.h>
#define N 50		//Ҷ�ӽ����
#define M 2*N-1		//���н������
typedef struct
{
	char data[5];	//���ֵ
	int weight;		//Ȩ��
	int parent;		//˫�׽��
	int lchild;		//���ӽ��
	int rchild;		//�Һ��ӽ��
} HTNode;
typedef struct
{
	char cd[N];		//��Ź�������
	int start;
} HCode;
void CreateHT(HTNode ht[],int n)  //��ht��Ҷ�ӽ�㹹�������Ĺ�������
{
	int i,k,lnode,rnode;
	int min1,min2;
	for (i=0;i<2*n-1;i++)			//���н���������ó�ֵ-1
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	for (i=n;i<2*n-1;i++)			//������������ķ�֧���
	{
		min1=min2=32767;			//lnode��rnodeΪ��СȨ�ص��������λ��
		lnode=rnode=-1;
		for (k=0;k<=i-1;k++)		//������С�ʹ�С�Ľ��
			if (ht[k].parent==-1)	//ֻ����δ����������Ľ���в���
			{
				if (ht[k].weight<min1)
				{
					min2=min1;rnode=lnode;
					min1=ht[k].weight;lnode=k;
				}
				else if (ht[k].weight<min2)
				{
					min2=ht[k].weight;rnode=k;
				}
			}
		ht[lnode].parent=i;ht[rnode].parent=i;	//�ϲ�������С�ʹ�С�Ľ��
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)	//�ɹ�������ht�������������hcd
{
	int i,f,c;
	HCode hc;
	for (i=0;i<n;i++)	//���ݹ���������������Ҷ�ӽ��Ĺ���������
	{
		hc.start=n;c=i;
		f=ht[i].parent;
		while (f!=-1)	//ѭ��ֱ���������
		{
			if (ht[f].lchild==c)	//�������ӽ��
				hc.cd[hc.start--]='0';
			else					//�����Һ��ӽ��
				hc.cd[hc.start--]='1';
			c=f;f=ht[f].parent;
		}
		hc.start++;		//startָ������������ʼ�ַ�
		hcd[i]=hc;
	}
}
void DispHCode(HTNode ht[],HCode hcd[],int n)	//�������������
{
	int i,k;
	int sum=0,m=0,j;
	printf("�������������:\n"); 
	for (i=0;i<n;i++)
	{
		j=0;
		printf("      %s:\t",ht[i].data);
		for (k=hcd[i].start;k<=n;k++)
		{
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		m+=ht[i].weight;
		sum+=ht[i].weight*j;
		printf("\n");
	}
	printf("ƽ������=%g\n",1.0*sum/m);
}
int main()
{
	int n=15,i;
	char *str[]={"The","of","a","to","and","in","that","he","is","at","on","for","His","are","be"};
	int fnum[]={1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123};
	HTNode ht[M];
	HCode hcd[N];
	for (i=0;i<n;i++)
	{
		strcpy(ht[i].data,str[i]);
		ht[i].weight=fnum[i];
	}
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
	return 1;
}
 
