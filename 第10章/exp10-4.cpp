//�ļ���:exp10-4.cpp
#include "seqlist.cpp"				//��������˳���Ļ��������㷨

void BubbleSort(RecType R[],int n)		//��R[0..n-1]�������������ð������
{	int i,j;
	bool exchange;
	for (i=0;i<n-1;i++) 
	{	exchange=false;					//һ��ǰexchange��Ϊ��
		for (j=n-1;j>i;j--)				//��λR[i],ѭ��n-i-1��
			if (R[j].key<R[j-1].key)	//��������Ԫ�ط���ʱ
			{	swap(R[j],R[j-1]);		//��������Ԫ�ؽ���
				exchange=true;			//һ���н�����exchange��Ϊ��
			}
		printf("  i=%d: ��λԪ��%d����������",i,R[i].key);
		DispList(R,n);
		if (!exchange)					//����û�з�����������;�����㷨
			return;
	}
}

int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	BubbleSort(R,n);
	printf("�����:"); DispList(R,n);
	return 1;
}
