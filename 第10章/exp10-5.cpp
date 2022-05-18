//�ļ���:exp10-5.cpp
#include "seqlist.cpp"					//��������˳���Ļ��������㷨
void disppart(RecType R[],int s,int t)	//��ʾһ�˻��ֺ�Ľ��
{
	static int i=1;
	int j;
	printf("��%d�λ���:",i);
	for (j=0;j<s;j++)
		printf("   ");
	for (j=s;j<=t;j++)
		printf("%3d",R[j].key);
	printf("\n");
	i++;
}
int partition(RecType R[],int s,int t)	//һ�˻���
{
	int i=s,j=t;
	RecType tmp=R[i];			//��R[i]Ϊ��׼
	while (i<j)  				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//��������ɨ��,��һ��С��tmp.key��R[j]
		R[i]=R[j];				//�ҵ�������R[j],����R[i]��
		while (i<j && R[i].key<=tmp.key)
			i++;				//��������ɨ��,��һ������tmp.key��R[i]
		R[j]=R[i];				//�ҵ�������R[i],����R[j]��
	}
	R[i]=tmp;
	disppart(R,s,t);
	return i;
}
void QuickSort(RecType R[],int s,int t) //��R[s..t]��Ԫ�ؽ��е�����������
{
	int i;
	if (s<t) 					//���������ٴ�������Ԫ�ص����
	{	i=partition(R,s,t);
		QuickSort(R,s,i-1);		//��������ݹ�����
		QuickSort(R,i+1,t);		//��������ݹ�����
	}
}

int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	QuickSort(R,0,n-1);
	printf("�����:"); DispList(R,n);
	return 1;
}
