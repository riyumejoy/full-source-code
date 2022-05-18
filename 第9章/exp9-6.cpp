//�ļ���:exp9-6.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
typedef int KeyType;				//����ؼ�������Ϊint
typedef char InfoType;
typedef struct
{	KeyType key;					//�ؼ�����
	InfoType data;					//�������������ΪInfoType
} RecType;							//����Ԫ�ص�����
int lowerbound(RecType R[],int n,KeyType k)	//��ؼ���Ϊk��¼���½�
{
	int low=0, high=n-1, mid;
	while (low!=high)
	{
		mid=(low+high)/2;
		if (k>R[mid].key)
			low=mid+1;
		else
			high=mid;
	}
	return low;
}
int upperbound(RecType R[],int n,KeyType k)	//��ؼ���Ϊk��¼���Ͻ�
{
	int low=0, high=n-1, mid;
	while (low!=high)
	{
		mid=(low+high)/2;
		if (k>=R[mid].key)
			low=mid+1;
		else
			high=mid;
	}
	return low;
}
void SearchRange(RecType R[],int n,KeyType k)  //����ؼ���Ϊk�ļ�¼������
{
	int lower=lowerbound(R,n,k);
	int upper=upperbound(R,n,k);
	printf("lower=%d,upper=%d\n",lower,upper);
}
int main()
{
	RecType R[MAXL];
	KeyType k=9;
	int a[]={1,2,3,3,3,3,3,8,9,10},i,n=10;
	for (i=0;i<n;i++)				//����˳���
		R[i].key=a[i];
	printf("�ؼ�������:");
	for (i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
	printf("���ҹؼ���-1:\t",R[i].key); SearchRange(R,n,-1);
	for (i=0;i<n;i++)
	{
		printf("���ҹؼ���%d:\t",R[i].key); SearchRange(R,n,R[i].key);
	}
	printf("���ҹؼ���20:\t",R[i].key); SearchRange(R,n,20);
	return 1;
}
