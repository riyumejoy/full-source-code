//�ļ���:exp11-4.cpp
#include <stdio.h>
#define MaxSize 20			//ÿ���ļ�������¼
#define K 5					//5·ƽ��鲢
#define MAXKEY 32767		//���ؼ���ֵ��
#define MINKEY -32768		//��С�ؼ���ֵ-��
typedef int InfoType;
typedef int KeyType;
typedef struct				//��¼����
{
	KeyType key;			//�ؼ�����
	InfoType otherinfo;		//����������,���������������ж���
} RecType;
typedef struct
{
	RecType recs[MaxSize];
	int currec;
} FileType;					//�ļ�����
typedef int LoserTree;		//������ΪLoserTree[K]
RecType b[K];				//b�д�Ÿ�����ȡ���ĵ�ǰ��¼
FileType F[K];				//����ļ���¼������
void initial()				//��ʼ������ļ���¼������F
{
	int i;					//5����ʼ�ļ�,��ǰ����¼��Ϊ-1
	F[0].recs[0].key=17;
	F[0].recs[1].key=21;
	F[0].recs[2].key=MAXKEY;
	F[1].recs[0].key=5;
	F[1].recs[1].key=44;
	F[1].recs[2].key=MAXKEY;
	F[2].recs[0].key=10;
	F[2].recs[1].key=12;
	F[2].recs[2].key=MAXKEY;
	F[3].recs[0].key=29;
	F[3].recs[1].key=32;
	F[3].recs[2].key=MAXKEY;
	F[4].recs[0].key=15;
	F[4].recs[1].key=56;
	F[4].recs[2].key=MAXKEY;
	for (i=0;i<K;i++)
		F[i].currec=-1;
}
void input(int i,int &key)	//��F[i]�ļ��ж�һ����¼��b[i]��
{
	F[i].currec++;
	key=F[i].recs[F[i].currec].key;
}
void output(int q)		//���F[q]�еĵ�ǰ��¼
{
	printf("���F[%d]�Ĺؼ���%d\n",q,F[q].recs[F[q].currec].key);   
}
void Adjust(LoserTree ls[K],int s)
//�ش�Ҷ�ӽڵ�b[s]�����ڵ�ls[0]��·������������
{
	int i,t;
	t=(s+K)/2;			//ls[t]��b[s]��˫�׽ڵ�
	while(t>0)
	{
		if(b[s].key>b[ls[t]].key)
		{
			i=s;
			s=ls[t];	//sָʾ�µ�ʤ��
			ls[t]=i;
		}
		t=t/2;
	}
	ls[0]=s;
}
void display(LoserTree ls[K])	//���������ls
{
	int i;
	printf("������:");
	for (i=0;i<K;i++)
		if (b[ls[i]].key==MAXKEY)
			printf("%d(��) ",ls[i]);
		else if (b[ls[i]].key==MINKEY)
			printf("%d(-��) ",ls[i]);
		else
			printf("%d(%d) ",ls[i],b[ls[i]].key);
	printf("\n");
}
void CreateLoserTree(LoserTree ls[K])	//����������ls
{
	int i;
	b[K].key=MINKEY;		//b[K]��Ϊ��С�ؼ���
	for (i=0;i<K;i++)
		ls[i]=K;			//����ls�С����ߡ��ĳ�ֵ,ȫ��Ϊ��С�ؼ��ֶκ�
	for(i=K-1;i>=0;--i)		//���δ�b[K-1]��b[K-2]������b[0]������������
		Adjust(ls,i);
}
void K_Merge(LoserTree ls[K])	//���ð�����ls������K·�鲢�����
{
	int i,q;
	for(i=0;i<K;++i)		//�ֱ��k������鲢�ζ���öε�ǰ��һ����¼�Ĺؼ��ֵ�b
		input(i,b[i].key);
	CreateLoserTree(ls);	//��������ls,ѡ����С�ؼ���Ϊb[ls[0]].key
	display(ls);
	while(b[ls[0]].key!=MAXKEY)
	{
		q=ls[0];			//qָʾ��ǰ��С�ؼ������ڹ鲢��
		output(q);			//�����Ϊq�Ĺ鲢���е�ǰ���ؼ���Ϊb[q].key���ļ�¼���
		input(q,b[q].key);	//�ӱ��Ϊq������鲢���ж�����һ����¼�Ĺؼ���
		if (b[q].key==MAXKEY)
			printf("��F[%d]����ӹؼ��֡޲�����\n",q);
		else
			printf("��F[%d]����ӹؼ���%d������\n",q,b[q].key);
		Adjust(ls,q);		//������������ѡ���µ���С�ؼ���
		display(ls);
	}
}
int main()
{
	LoserTree ls[K];
	printf("F0:{17,21,��}  F1:{5,44,��}  F2:{10,12,��}  F3:{29,32,��}  F4:{15,56,��}\n");
	initial();
	K_Merge(ls);
	return 1;
}
