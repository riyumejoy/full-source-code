//�ļ���:exp11-3.cpp
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 50			//ÿ���ļ�����¼��
#define MAXKEY 32767		//���ؼ���ֵ��
#define W 5					//�ڴ湤���������ɵļ�¼����
typedef int LoserTree;		//�������ڵ����ͣ�������ȫ�������Ҳ���Ҷ��,�ɲ���˳��洢�ṹ
typedef int InfoType;		//�������������������
typedef int KeyType;		//����ؼ�������Ϊ����
typedef struct 
{	KeyType key;			//�ؼ�����
	InfoType otherinfo;		//����������,���������������ж���
} RecType;					//�����ļ��ļ�¼����
typedef struct
{	RecType recs[MaxSize];	//����ļ��е�������
	int length;				//����ļ���ʵ�ʼ�¼����
	int currec;				//��ŵ�ǰλ��
} FileType;					//�ļ�����
typedef struct
{	RecType rec;			//��ż�¼
	int rnum;				//�����鲢�εĶκ�
} WorkArea;					//�ڴ湤����Ԫ������,������ΪW
FileType Fi;				//���������ļ�,Ϊȫ�ֱ���
FileType Fo;				//��������ļ�,Ϊȫ�ֱ���
void initial()				//��������ļ���ʼ��
{	int n=19,i;
	KeyType a[]={15,4,97,64,17,32,108,44,76,9,39,82,56,31,80,73,255,68,MAXKEY};
	for (i=0;i<n;i++)		//��n����¼��ŵ������ļ���
		Fi.recs[i].key=a[i];
	Fi.length=n; 			//�����ļ�����n����¼
	Fi.currec=-1;			//�����ļ��е�ǰλ��Ϊ-1
	Fo.currec=-1;			//����ļ��е�ǰλ��Ϊ-1
	Fo.length=0; 			//����ļ���û���κμ�¼
}

void Select_MiniMax(LoserTree ls[W],WorkArea wa[W],int q) 
//��wa[q]�𵽰������ĸ��Ƚ�ѡ����С��¼,����qָʾ�����ڵĹ鲢��
{
	int p,s,t;
	for (t=(W+q)/2,p=ls[t];t>0;t=t/2,p=ls[t])
		if (wa[p].rnum<wa[q].rnum || wa[p].rnum==wa[q].rnum && wa[p].rec.key<wa[q].rec.key)
		{
			s=q;
			q=ls[t];		//qָʾ�µ�ʤ��
			ls[t]=s;
		}
		ls[0]=q;
}
void Construct_Loser(LoserTree ls[W],WorkArea wa[W])
//����W����¼���ڴ湤����wa,��������ls,ѡ��С�ļ�¼����sָʾ����wa�е�λ��
{
	int i;
	for(i=0;i<W;i++)
		wa[i].rnum=wa[i].rec.key=ls[i]=0;	//��������ʼ��
	for(i=W-1;i>=0;i--)
	{
		Fi.currec++;						//�������ļ�����һ����¼
		wa[i].rec=Fi.recs[Fi.currec];		
		wa[i].rnum=1;						//��κ�Ϊ1
		Select_MiniMax(ls,wa,i);			//��������
	}
}
void get_run(LoserTree ls[W],WorkArea wa[W],int rc,int &rmax)
//���һ����ʼ�鲢��
{
	int q;
	KeyType minimax;				//��ǰ��С�ؼ���
	while (wa[ls[0]].rnum==rc)		//ѡ�õĵ�ǰ��С��¼����ǰ��ʱ
	{
		q=ls[0];					//qָʾ��ǰ��С��¼��wa�е�λ��
		minimax=wa[q].rec.key;
		Fo.currec++;				//����ѡ�õĵ�ǰ��С��¼д������ļ�
		Fo.length++; 
		Fo.recs[Fo.currec]=wa[q].rec;
		Fi.currec++;				//�������ļ�������һ��¼
		wa[q].rec=Fi.recs[Fi.currec];
		if (Fi.currec>=Fi.length-1)	//�����ļ�����,�����¼(��rmax+1��)
		{	
			wa[q].rnum=rmax+1;	
			wa[q].rec.key=MAXKEY;
		}
		else						//�����ļ��ǿ�ʱ
		{	
			if(wa[q].rec.key<minimax)
			{ 
				rmax=rc+1;			//�¶���ļ�¼����һ��
				wa[q].rnum=rmax;
			}
			else					//�¶���ļ�¼����ǰ��
				wa[q].rnum=rc;
		}
		Select_MiniMax(ls,wa,q);	//ѡ���µĵ�ǰ��С��¼
    }
}
void Replace_Selection(LoserTree ls[W],WorkArea wa[W])
//�ڰ�����ls���ڴ湤����wa�����û���ѡ���������ʼ�鲢��
{
	int rc,rmax;
	RecType j;							//j��Ϊһ���ؼ�������¼,��Ϊһ������ν�����־
	j.key=MAXKEY;
	Construct_Loser(ls,wa);				//����������
	rc=1;								//rcָʾ��ǰ���ɵĳ�ʼ�鲢�εĶκ�
	rmax=1;								//rmaxָʾwa�йؼ���������ʼ�鲢�ε����κ�
	while(rc<=rmax)						//rc=rmax+1��־�����ļ����û���ѡ�����������
	{
		get_run(ls,wa,rc,rmax);			//���һ����ʼ�鲢��
		Fo.currec++;					//���ν�����־д������ļ�
		Fo.recs[Fo.currec]=j;
		Fo.length++; 
		rc=wa[ls[0]].rnum;				//������һ�εĶκ�
	}
}
int main()
{
	int i=0,rno=1;
	initial();
	LoserTree ls[W];
	WorkArea wa[W];
	printf("���ļ��ļ�¼Ϊ:\n  ");
	while (Fi.recs[i].key!=MAXKEY)
	{
		printf("%d ",Fi.recs[i].key);
		i++;
	}
	printf("\n");
	Replace_Selection(ls,wa);		//���û�-ѡ���������ʼ�鲢��
	printf("�����Ĺ鲢���ļ��ļ�¼����:\n");
	printf("  �鲢��%d:",rno);		//������еĹ鲢��
	for (i=0;i<Fo.length;i++)
		if (Fo.recs[i].key==MAXKEY)
		{
			printf("��");
			if (i<Fo.length-1)
			{
				rno++;
				printf("\n  �鲢��%d:",rno);
			}
		}
		else
			printf("%d ",Fo.recs[i].key);
	printf("\n  ������%d���鲢���ļ�\n",rno);
	return 1;
}
	
