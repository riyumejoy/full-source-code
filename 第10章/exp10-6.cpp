//�ļ���:exp10-6.cpp
#include "seqlist.cpp"				//��������˳���Ļ��������㷨

void SelectSort(RecType R[],int n)	//��ѡ�������㷨
{
	int i,j,k;
	for (i=0;i<n-1;i++)    	 	//����i������
	{	
		k=i;
		for (j=i+1;j<n;j++)  	//�ڵ�ǰ������R[i..n-1]��ѡkey��С��R[k] 
			if (R[j].key<R[k].key)
				k=j;           	//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k!=i)          		//����R[i]��R[k] 
			swap(R[i],R[k]);
		printf(" i=%d,ѡ��ؼ���:%d,������Ϊ:",i,R[i].key);
		DispList(R,n);			//���ÿһ�˵�������
	}
}
int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={9,8,7,6,5,4,3,2,1,0};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	SelectSort(R,n);
	printf("�����:"); DispList(R,n);
	return 1;
}

