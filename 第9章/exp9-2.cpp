//�ļ���:exp9-2.cpp
#include "seqlist.cpp"						//����˳�����������㷨
int BinSearch(RecType R[],int n,KeyType k)	//�۰�����㷨
{
	int low=0,high=n-1,mid,count=0;
	while (low<=high) 
	{	
		mid=(low+high)/2;
		printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n",++count,low,high,mid,R[mid].key);
			if (R[mid].key==k)   	//���ҳɹ�����
			return mid+1;
		if (R[mid].key>k)     		//������R[low..mid-1]�в���
			high=mid-1;
		else
			low=mid+1;       		//������R[mid+1..high]�в���
	}
	return 0;
}
int main()
{
	RecType R[MAXL];
	KeyType k=9;
	int a[]={1,2,3,4,5,6,7,8,9,10},i,n=10;
	CreateList(R,a,n);			//����˳���
	printf("�ؼ�������:"); DispList(R,n);
	printf("����%d�ıȽϹ�������:\n",k);
	if ((i=BinSearch(R,n,k))!=-1)
		printf("Ԫ��%d��λ����%d\n",k,i);
	else
		printf("Ԫ��%d���ڱ���\n",k);
	return 1;
}
