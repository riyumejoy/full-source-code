//�ļ���:exp9-5.cpp
#include <stdio.h>
#define MaxSize 100			//��������ϣ����
#define NULLKEY -1			//����չؼ���ֵ
#define DELKEY	-2			//���屻ɾ�ؼ���ֵ
typedef int KeyType;		//�ؼ�������
typedef char InfoType;		//������������
typedef struct
{
	KeyType key;			//�ؼ�����
	InfoType data;			//����������
	int count;				//̽�������
} HashTable;				//��ϣ��Ԫ������
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)  //���ؼ���Ϊk�ļ�¼���뵽��ϣ����
{
	int i,adr;
	adr=k % p;
	if (ha[adr].key==NULLKEY || ha[adr].key==DELKEY) //x[j]����ֱ�ӷ��ڹ�ϣ����
	{
		ha[adr].key=k;
		ha[adr].count=1;
	}
	else					//������ͻʱ��������̽�ⷨ�����ͻ
	{
		i=1;				//i��¼x[j]������ͻ�Ĵ���
		do 
		{
			adr=(adr+1) % m;
			i++;
		} while (ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
		ha[adr].key=k;
		ha[adr].count=i;
	}
	n++;
}
void CreateHT(HashTable ha[],KeyType x[],int n,int m,int p)  //������ϣ��
{
	int i,n1=0;
	for (i=0;i<m;i++)			//��ϣ���ó�ֵ
    {
        ha[i].key=NULLKEY;
	    ha[i].count=0;
    }
	for (i=0;i<n;i++)
		InsertHT(ha,n1,m,p,x[i]);
}
int SearchHT(HashTable ha[],int m,int p,KeyType k)		//�ڹ�ϣ���в��ҹؼ���k
{
	int i=0,adr;
	adr=k % p;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)
	{
		i++;				//��������̽�ⷨ����һ����ַ
		adr=(adr+1) % m;
	}
	if (ha[adr].key==k)		//���ҳɹ�
		return adr;
	else					//����ʧ��
		return -1;
}
int DeleteHT(HashTable ha[],int m,int p,int &n,int k)	  //ɾ����ϣ���йؼ���k
{
	int adr;
	adr=SearchHT(ha,m,p,k);
	if (adr!=-1)		//�ڹ�ϣ�����ҵ��ùؼ���
	{
		ha[adr].key=DELKEY;
		n--;			//��ϣ���ȼ�1
		return 1;
	}
	else				//�ڹ�ϣ����δ�ҵ��ùؼ���
		return 0;
}
void DispHT(HashTable ha[],int n,int m)    //�����ϣ��
{
	float avg=0;
	int i;
	printf("    ��ϣ���ַ:   ");
	for (i=0;i<m;i++) 
		printf("%-4d",i);
	printf(" \n");
    printf("    ��ϣ��ؼ���: ");
	for (i=0;i<m;i++) 
		if (ha[i].key==NULLKEY || ha[i].key==DELKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d",ha[i].key);
	printf("\n");
	printf("    ̽�����:     ");
	for (i=0;i<m;i++)
		if (ha[i].key==NULLKEY || ha[i].key==DELKEY)
			printf("    ");			//���3���ո�
		else
			printf("%-4d",ha[i].count);
	printf(" \n");
    for (i=0;i<m;i++)
		if (ha[i].key!=NULLKEY && ha[i].key!=DELKEY)
			avg=avg+ha[i].count;
	avg=avg/n;
	printf("    ƽ�����ҳ���ASL(%d)=%g\n",n,avg);
}
int main()
{
	int x[]={16,74,60,43,54,90,46,31,29,88,77};
	int n=11,m=13,p=13,i,k=29;
	HashTable ha[MaxSize];
	printf("(1)������ϣ��\n");
	CreateHT(ha,x,n,m,p);
	printf("(2)�����ϣ��:\n"); DispHT(ha,n,m);
	printf("(3)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	i=SearchHT(ha,m,p,k);
	if (i!=-1)
		printf("   ha[%d].key=%d\n",i,k);
	else
		printf("   ��ʾ:δ�ҵ�%d\n",k);
	k=77;
	printf("(4)ɾ���ؼ���%d\n",k);
	DeleteHT(ha,m,p,n,k);
	printf("(5)ɾ����Ĺ�ϣ��\n"); DispHT(ha,n,m);
	printf("(6)���ҹؼ���Ϊ%d�ļ�¼λ��\n",k);
	i=SearchHT(ha,m,p,k);
	if (i!=-1)
		printf("   ha[%d].key=%d\n",i,k);
	else
		printf("   ��ʾ:δ�ҵ�%d\n",k);
	printf("(7)����ؼ���%d\n",k);
	InsertHT(ha,n,m,p,k);
	printf("(8)�����Ĺ�ϣ��\n"); DispHT(ha,n,m);
	return 1;
}
