//�ļ���:exp10-1.cpp
#include "seqlist.cpp"				//��������˳���Ļ��������㷨
void InsertSort(RecType R[],int n)	//��R[0..n-1]�������������ֱ�Ӳ�������
{	int i, j; RecType tmp;
	for (i=1;i<n;i++) 
	{
		printf("  i=%d������%d��������: ",i,R[i].key); 
		if (R[i].key<R[i-1].key)	//����ʱ 
		{	tmp=R[i];
			j=i-1; 
			do						//��R[i]�Ĳ���λ�� 
			{	R[j+1]=R[j];   		//���ؼ��ִ���R[i].key�ļ�¼����
				j--;
			}  while  (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;      		//��j+1������R[i]
		}
		DispList(R,n);
	}
}
int main()
{	int n=10;
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	RecType R[MAXL];
	CreateList(R,a,n);
	printf("����ǰ: ");	DispList(R,n);
	InsertSort(R,n);
	printf("�����: "); DispList(R,n);
	return 1;
}
