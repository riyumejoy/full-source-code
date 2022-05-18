//�ļ���:exp10-7.cpp
#include "seqlist.cpp"					//��������˳���Ļ��������㷨

int count=1;							//ȫ�ֱ���
void DispHeap(RecType R[],int i,int n)	//�����ű�ʾ����������Ķ�
{
	if (i<=n)
		printf("%d",R[i].key);			//������ڵ�
	if (2*i<=n || 2*i+1<n)
	{
		printf("(");
		if (2*i<=n)
			DispHeap(R,2*i,n);			//�ݹ�������������
		printf(",");
		if (2*i+1<=n)
			DispHeap(R,2*i+1,n);		//�ݹ�������������
		printf(")");
	}
}
void Sift(RecType R[],int low,int high)		//R[loww..high}��ɸѡ�㷨
{
	int i=low,j=2*i;     					//R[j]��R[i]������
	RecType temp=R[i];
	while (j<=high) 
	{	
		if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;    						//��Ϊ2i+1
	    if (temp.key<R[j].key) 
		{	
			R[i]=R[j];              		//��R[j]������˫�׽ڵ�λ����
		    i=j;                    		//�޸�i��jֵ,�Ա��������ɸѡ
		    j=2*i;
		}
	    else break;                 		//ɸѡ����
	}
    R[i]=temp;                      		//��ɸѡ�ڵ��ֵ��������λ��
}
void HeapSort(RecType R[],int n)	//��R[1]��R[n]Ԫ��ʵ�ֶ�����
{
	int i,j;
	for (i=n/2;i>=1;i--)  		//ѭ��������ʼ��
		Sift(R,i,n); 
	printf("��ʼ��:");DispHeap(R,1,n);printf("\n");	//�����ʼ��
	for (i=n;i>=2;i--)   	//����n-1��ѭ��,���������
	{  	
		printf("��%d������:",count++);
		printf(" ����%d��%d,���%d ",R[i].key,R[1].key,R[1].key);
		swap(R[1],R[i]);        //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
		printf(" ������:");	//���ÿһ�˵�������
		for (j=1;j<=n;j++)
			printf("%2d",R[j].key);
		printf("\n");
        Sift(R,1,i-1);     		//ɸѡR[1]�ڵ�,�õ�i-1���ڵ�Ķ�
		printf("ɸѡ�����õ���:");DispHeap(R,1,i-1);printf("\n");
	}
}
int main()
{
	int n=10;
	RecType R[MAXL];
	KeyType a[]={6,8,7,9,0,1,3,2,4,5};
	CreateList1(R,a,n);
	printf("����ǰ:"); DispList1(R,n);
	HeapSort(R,n);
	printf("�����:"); DispList1(R,n);
	return 1;
}
