//�ļ���:exp7-10.cpp
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 100			//����¼����
#define MaxSons 10			//����¼���λ��
typedef struct
{
	char fname[20];			//��λ����
	char sname[20];			//�¼���λ���ƻ�������
} RecType;

typedef struct node
{	char data[20];					//����ֵ����λ���ƻ�������
	struct node *sons[MaxSons];		//ָ���ӽ��
} TSonNode;							//�����������洢�ṹ�������

void ReadFile(RecType R[],int &n)	//��abc.txt�ļ�����R������
{
	FILE *fp;
	n=0;
	if ((fp=fopen("abc.txt","r"))==NULL) 
	{
		printf("���ܴ��ļ�abc.txt");
		return;
	}
	while (!feof(fp))
	{
		fscanf(fp,"%s",&R[n].fname);	//��fname������
		fscanf(fp,"%s",&R[n].sname);	//��sname������
		n++;
	}	
	fclose(fp);
}
TSonNode *CreateTree(char root[],RecType R[],int n) //����һ����
{
	int i,j,k;
	TSonNode *t;
	t=(TSonNode *)malloc(sizeof(TSonNode));		//���������
	strcpy(t->data,root);
	for (k=0;k<MaxSons;k++)						//�������ָ������Ϊ��
		t->sons[k]=NULL;
	i=0; j=0;
	while (i<n)
	{
		if (strcmp(R[i].fname,root)==0)			//�ҵ�fnameΪroot�ļ�¼
		{
			t->sons[j]=CreateTree(R[i].sname,R,n);
			j++;
		}
		i++;
	}
	return t;
}

void DispTree(TSonNode *t)				//����������洢�ṹ
{
	int i;
	if (t!=NULL)
	{	printf("%s",t->data);
		if (t->sons[0]!=NULL)			//t���������һ������
		{	printf("(");				//���һ��������
			for (i=0;i<MaxSons;i++)
			{	DispTree(t->sons[i]);
				if (t->sons[i+1]!=NULL)	//�������һ������
					printf(",");		//���һ��','
				else					//���û����һ������
					break;				//�˳�ѭ��
			}
			printf(")");				//���һ��������
		}
	}
}
void DestroyTree(TSonNode *&t)				//������t
{
	int i;
	if (t!=NULL)
	{	for (i=0;i<MaxSons;i++)
		{	if (t->sons[i]!=NULL)			//������
				DestroyTree(t->sons[i]);	//���ٸ�����
			else							//��û������
				break;						//�˳�ѭ��
		}
		free(t);							//�ͷŸ����
	}
}
TSonNode *FindNode(TSonNode *t,char x[])	//��x����ָ��
{	int i;
	TSonNode *p;
	if (t==NULL)
		return NULL;
	else if (strcmp(t->data,x)==0)			//�ҵ�ֵΪx�Ľ��
		return t;
	else
	{	for (i=0;i<MaxSons;i++)
			if (t->sons[i]!=NULL)
			{	p=FindNode(t->sons[i],x);
				if (p!=NULL) return p;
			}
			else break;
		return NULL;
	}
}
int ChildCount(TSonNode *p)		//��p��ָ���ĺ��Ӹ���
{	int i,num=0;
	for (i=0;i<MaxSons;i++)
		if (p->sons[i]!=NULL)
			num++;
		else
			break;
	return num;
}
int Sonnum(TSonNode *t,char x[])	//��x��λ����һ����λ��
{
	TSonNode *p;
	p=FindNode(t,x);
	if (p==NULL)
		return 0;
	else
		return ChildCount(p);
}
int LeafCount(TSonNode *t)			//������Ҷ�ӽ�����
{
	int i,num=0;
	if (t==NULL)
		return 0;
	else
	{	if (t->sons[0]==NULL)	//tΪҶ�ӽ��
			num++;
		else					//t��ΪҶ�ӽ��
		{	for (i=0;i<MaxSons;i++)
				if (t->sons[i]!=NULL)
					num+=LeafCount(t->sons[i]);
				else break;
		}
		return num;
	}
}
int Classnum(TSonNode *t,char x[])	//��x��λ�İ���
{
	TSonNode *p;
	p=FindNode(t,x);
	if (p==NULL)
		return 0;
	else
		return LeafCount(p);
}
int LeafSum(TSonNode *t)		//������Ҷ�ӽ�����ֵ��
{
	int i,sum=0;
	if (t==NULL)
		return 0;
	else
	{
		if (t->sons[0]==NULL)	//tΪҶ�ӽ��
			return atoi(t->data);
		else					//t��ΪҶ�ӽ��
		{	for (i=0;i<MaxSons;i++)
				if (t->sons[i]!=NULL)
					sum+=LeafSum(t->sons[i]);
				else break;
		}
		return sum;
	}
}
int Studnum(TSonNode *t,char x[])	//��x��λ����ѧ������
{
	TSonNode *p;
	p=FindNode(t,x);
	if (p==NULL)
		return 0;
	else
		return LeafSum(p);
}
int main()
{
	TSonNode *t;
	RecType R[MaxSize];
	int n;
	printf("(1)��abc.txt�ļ������ݵ�R������\n");
	ReadFile(R,n);
	if (n==0) return 1;				//��¼����Ϊ0ʱֱ�ӷ���
	printf("(2)������R������t�ĺ������洢�ṹ\n");
	t=CreateTree(R[0].fname,R,n);	//����һ����
	printf("(3)�����t:"); DispTree(t); printf("\n");
	printf("(4)�����ѧԺ��רҵ��:%d\n",Sonnum(t,"�����ѧԺ"));
	printf("(5)�����ѧԺ�İ���:%d\n",Classnum(t,"�����ѧԺ"));
	printf("(6)����ѧԺ��ѧ����:%d\n",Studnum(t,"����ѧԺ"));
	printf("(7)������t\n");
	DestroyTree(t);

	return 1;
}
