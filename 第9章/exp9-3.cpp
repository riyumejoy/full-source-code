//�ļ���:exp9-3.cpp
#include "seqlist.cpp"				//����˳�����������㷨
#define MAXI 20						//�������������󳤶�
typedef struct 
{	
	KeyType key;					//KeyTypeΪ�ؼ��ֵ�����
	int link;						//ָ��ֿ����ʼ�±�
} IdxType;							//������Ԫ������

int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k) //�ֿ����
{
	int s=(n+b-1)/b;			//sΪÿ���Ԫ�ظ�����ӦΪn/bȡ�Ͻ�
	int count1=0,count2=0;
	int low=0,high=b-1,mid,i;
	printf("(1)�����������۰����\n");
	while (low<=high)			//���������н����۰���ң��ҵ���λ��Ϊhigh+1
	{
		mid=(low+high)/2;
		printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n",count1+1,low,high,mid,R[mid].key);
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
		count1++;				//count1�ۼ����������еıȽϴ���
	}
	printf("�Ƚ�%d��,�ڵ�%d���в���Ԫ��%d\n",count1,low,k);
	//Ӧ���������high+1���У����������ݱ��н���˳�����
	i=I[high+1].link;			//�ҵ���Ӧ�Ŀ�
	printf("(2)�ڶ�Ӧ����˳�����:\n    ");
	while (i<=I[high+1].link+s-1)
	{	printf("%d ",R[i].key);
		count2++;				//count2�ۼ���˳����Ӧ���еıȽϴ���
		if (R[i].key==k) break;
		i++;
	}
	printf("�Ƚ�%d��,��˳����в���Ԫ��%d\n",count2,k);
	if (i<=I[high+1].link+s-1)
		return i+1;			//���ҳɹ������ظ�Ԫ�ص��߼����
	else
		return 0;			//����ʧ�ܣ�����0
}

int main()
{
	RecType R[MAXL];
	IdxType I[MAXI];
	int n=25, i;
	int a[]={8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87};
	CreateList(R,a,n);				//����˳���
	I[0].key=14;I[0].link=0;		//����������
	I[1].key=34;I[1].link=4;
	I[2].key=66;I[2].link=10;
	I[3].key=85;I[3].link=15;
	I[4].key=100;I[4].link=20;
	printf("�ؼ�������:");
	for (i=0;i<n;i++)
	{
		printf("%4d",R[i].key);
		if (((i+1)%5)==0) printf("   ");
		if (((i+1)%10)==0) printf("\n\t   ");
	}
	printf("\n");
	KeyType k=46;
	printf("����%d�ıȽϹ�������:\n",k);

	if ((i=IdxSearch(I,5,R,25,k))!=-1)
		printf("Ԫ��%d��λ����%d\n",k,i);
	else
		printf("Ԫ��%d���ڱ���\n",k);
	return 1;
}
