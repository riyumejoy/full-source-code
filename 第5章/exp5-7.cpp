//�ļ���:exp5-7.cpp
#include <stdio.h>
#include <stdlib.h>
const int N=20;      	//���ʺ����
int q[N];            	//��Ÿ��ʺ����ڵ��к�
int count=0;          	//��Ž����
void print(int n)    	//���һ����
{
	count++;
	int i;
	printf("  ��%d���⣺",count);
	for (i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
bool place(int k,int j)			//����(k,j)λ���ܷ�ڷŻʺ�
{
	int i=1;
	while (i<k)       			//i=1��k-1���ѷ����˻ʺ����
	{
	    if ((q[i]==j) || (abs(q[i]-j)==abs(i-k)))
		    return false;		//�г�ͻʱ���ؼ�
	    i++;
	}
	return true;				//û�г�ͻʱ������
}
void queen(int k,int n)			//����1��k�Ļʺ�
{
	int j;
	if (k>n) 
		print(n);         		//���лʺ���ý���
	else
		for (j=1;j<=n;j++) 		//�ڵ�k�������ÿһ��λ��
		    if (place(k,j))		//�ڵ�k�����ҵ�һ������λ��(k,j)
			{
				q[k]=j;
				queen(k+1,n);
     		}
}
int main()
{
	int n;     					//n���ʵ�ʻʺ����
	printf(" �ʺ�����(n<20) n:");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��,�������\n");
	else
	{
		printf(" %d�ʺ�����������£�\n",n);
		queen(1,n);
		printf("\n");
    }
	return 1;
}
