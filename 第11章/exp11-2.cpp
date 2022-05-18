//�ļ���:exp11-2.cpp
#include <stdio.h>
#define MaxSize 100
#define MAXKEY 32767		//���ؼ���ֵ��
#define K 5					//�ڴ湤���������ɵļ�¼����
typedef int KeyType;		//�ؼ�������
typedef struct
{	KeyType recs[MaxSize];	//����ļ��е�������
	int length;				//����ļ���ʵ�ʼ�¼����
	int currec;				//��ŵ�ǰλ��
} FileType;					//�ļ�����
FileType Fi;				//���������ļ�,Ϊȫ�ֱ���
KeyType R[K+1];				//��Ŵ����
void initial()				//�����ļ���ʼ��
{	int n=18,i;
	KeyType a[]={15,4,97,64,17,32,108,44,76,9,39,82,56,31,80,73,255,68};
	for (i=0;i<n;i++)		//��n����¼��ŵ������ļ���
		Fi.recs[i]=a[i];
	Fi.length=n; 			//�����ļ�����n����¼
	Fi.currec=-1;			//�����ļ��е�ǰλ��Ϊ-1
}
bool GetaRec(KeyType &r)	//�������ļ���ȡһ����¼r	
{
	Fi.currec++;
	if (Fi.currec==Fi.length)
		return false;
	else
	{
		r=Fi.recs[Fi.currec];
		return true;
	}
}
void sift(int low,int high)			//ɸѡΪ������㷨
{
	int i=low,j=2*i;     			//R[j]��R[i]������
	KeyType tmp=R[i];
	while (j<=high) 
	{
		if (j<high && R[j]<R[j+1]) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    				//��Ϊ2i+1
		if (tmp<R[j]) 
		{
			R[i]=R[j];              //��R[j]������˫�׽��λ����
			i=j;                    //�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;                 //ɸѡ����
	}
	R[i]=tmp;                      	//��ɸѡ����ֵ��������λ��
}
void dispHeap()						//��ʾ�������м�¼
{
	for (int i=1;i<=K;i++)
		printf("%d ",R[i]);
	printf("\n");
}
void SelectK()				//�������ļ�Fi����ѡK����С�ļ�¼
{
	int i;
	KeyType r;
	for (i=0;i<K;i++)		//�������ļ�Fi��ȡ��K����¼����R[1..K]��
	{
		GetaRec(r);
		R[i+1]=r;
	}
	for (i=K/2;i>=1;i--)	//������ʼ��
		sift(i,K);
	printf("��ͷ%d����¼�����Ĵ����:",K); dispHeap();
	while (GetaRec(r))		//�������ļ�Fi��ȡ������ļ�¼
	{
		printf("  ����%d:",r);
		if (r<R[1])			//��rС�ڶѵĸ��ڵ�
		{
			R[1]=r;			//��r����ѵĸ��ڵ�
			sift(1,K);		//����ɸѡ
			printf("\t��Ҫɸѡ�����:"); dispHeap();
		}
		else
			printf("\t����Ҫɸѡ\n");
	}
}
int main()
{
	initial();
	SelectK();
	printf("���ս��: "); dispHeap();
	return 1;
}
	
