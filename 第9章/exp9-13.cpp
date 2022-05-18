//�ļ���:exp9-13.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
typedef int KeyType;				//����ؼ�������Ϊint
typedef char InfoType;
typedef struct
{	KeyType key;					//�ؼ�����
	InfoType data;					//�������������ΪInfoType
} RecType;							//����Ԫ�ص�����
int FindElem(RecType R[],int n,KeyType k)	//(1)С���Ӧ���㷨
{
	int i=4,j;
	if (k<R[1].key || k>R[4*n].key) 
		return 0;				//���ڷ�Χ�ڷ���0
	while(i<=4*n)
	{
		if (R[i].key==k)
			return i;			//���ҳɹ�����
		else if (R[i].key<k)
			i+=4;
		else					//�ҵ�����k��λ��i
			break;
	}
	j=i-3;
	while (j<i && R[j].key!=k)
		j++;					//��R[i-3..i-1]�в���
	if (j<i)					//���ҳɹ�����
		return j;
	else
		return 0;
}

int ImproveFindElem(RecType R[],int n,KeyType k)	//(2)С���Ӧ���㷨
{
	int low,high,mid;
	int i,j;
	if (k<R[1].key || k>R[4*n].key) 
		return 0;				//���ڷ�Χ�ڷ���0
	low=4; high=4*n;
	while (low<=high)			//���ֲ���
	{		
		mid=(low+high)/2;
		if (k<R[mid].key)
			high=mid-4;
		else if (k>R[mid].key)
			low=mid+4;
		else 
			return mid;
	}							//����ʧ��ʱ�պ���k>R[high].key����k<=R[high+4].key
	i=high+4;
	j=high+1;
	while (j<i && R[j].key!=k)
		j++;					//��R[high+1..high+4]�в���
	if (j<i)					//���ҳɹ�����j
		return j;
	else						//���Ҳ��ɹ�����0
		return 0;
}

int main()
{
	int i,m=13,n=3;
	KeyType keys[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	RecType R[MAXL];
	for (i=0;i<m;i++) R[i].key=keys[i];
	printf("R:");
	for (i=0;i<m;i++)
		printf("%3d",R[i].key);
	printf("\n");
	KeyType k=8;
	printf("���㷨(1)���ҹؼ���%d:\n",k);
	i=FindElem(R,n,k);
	if (i>=1)
		printf("  ���:R[%d]=%d\n",i,k);
	else
		printf("  δ�ҵ�%d\n",k);
	k=20;
	printf("���㷨(2)���ҹؼ���%d:\n",k);
	i=ImproveFindElem(R,n,k);
	if (i>=1)
		printf("  ���:R[%d]=%d\n",i,k);
	else
		printf("  δ�ҵ�%d\n",k);
	return 1;
}
