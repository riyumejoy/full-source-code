//�ļ���:exp10-8.cpp
#include "seqlist.cpp"					//��������˳���Ļ��������㷨
#include <malloc.h>

void Merge(RecType R[],int low,int mid,int high) 
//һ�ι鲢�������������R[low..mid]��R[mid+1..high]�鲢Ϊһ�������R[low..high]��
{
	RecType *R1;
	int i=low,j=mid+1,k=0; //k��R1���±�,i��j�ֱ�Ϊ��1��2�ε��±�
	R1=(RecType *)malloc((high-low+1)*sizeof(RecType));  //��̬����ռ�
	while (i<=mid && j<=high)     	//�ڵ�1�κ͵�2�ξ�δɨ����ʱѭ��
		if (R[i].key<=R[j].key)    	//����1���еļ�¼����R1��
		{	
			R1[k]=R[i];
			i++;k++; 
		}
        else                       	//����2���еļ�¼����R1��
		{	
			R1[k]=R[j];
			j++;k++; 
		}
    while (i<=mid)          	   	//����1�����²��ָ��Ƶ�R1
	{   	
		R1[k]=R[i];
		i++;k++; 
	}
    while (j<=high)                	//����2�����²��ָ��Ƶ�R1
	{	
		R1[k]=R[j];
		j++;k++;  
	}
    for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
	    R[i]=R1[k];
}
int count=1;									//ȫ�ֱ���
void MergePass(RecType R[],int length,int n)	//ʵ��һ�˹鲢
{
	int i;
	printf("��%d�˹鲢:",count++);
	for (i=0;i+2*length-1<n;i=i+2*length) 	//�鲢length�����������ӱ�
	{
		printf("R[%d,%d]��R[%d,%d]�鲢  ",i,i+length-1,i+length,i+2*length-1);
		Merge(R,i,i+length-1,i+2*length-1);
	}
    if (i+length-1<n-1)                		//���������ӱ�,���߳���С��length
	{
		printf("*R[%d,%d]��R[%d,%d]�鲢  ",i,i+length-1,i+length,n-1);
		Merge(R,i,i+length-1,n-1);  		//�鲢�������ӱ�
	}
	printf("\n�鲢�����"); DispList(R,n);		//������˵�������
}
void MergeSort(RecType R[],int n)  //��·�鲢�����㷨
{
	int length;	
	for (length=1;length<n;length=2*length)
		MergePass(R,length,n);
}
int main()
{
	int n=11;
	RecType R[MAXL];
	KeyType a[]={18,2,20,34,12,32,6,16,5,8,1};
	CreateList(R,a,n);
	printf("����ǰ:"); DispList(R,n);
	MergeSort(R,n);
	printf("�����:"); DispList(R,n);
	return 1;
}
