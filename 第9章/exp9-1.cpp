//�ļ���:exp9-1.cpp
#include "seqlist.cpp"						//����˳�����������㷨
int SeqSearch(RecType R[],int n,KeyType k)	//˳������㷨
{
    int i=0;
    while (i<n && R[i].key!=k) 
	{
		printf("%d ",R[i].key);
		i++;					//�ӱ�ͷ������
	}
    if (i>=n) 
		return 0;
    else 
	{
		printf("%d",R[i].key);
		return i+1;
	}
}
int main()
{
	RecType R[MAXL];
	int n=10,i;
	KeyType k=5;
	int a[]={3,6,2,10,1,8,5,7,4,9};
	CreateList(R,a,n);			//����˳���
	printf("�ؼ�������:"); DispList(R,n);
	printf("����%d���ȽϵĹؼ���:\n\t",k);
	if ((i=SeqSearch(R,n,k))!=0)
		printf("\nԪ��%d��λ����%d\n",k,i);
	else
		printf("\nԪ��%d���ڱ���\n",k);
	return 1;
}
