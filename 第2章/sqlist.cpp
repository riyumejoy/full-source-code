//˳��������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType; 
typedef struct 
{	ElemType data[MaxSize];		//���˳���Ԫ��
   	int length;					//���˳���ĳ���
} SqList;						//����˳��������
void CreateList(SqList *&L,ElemType a[],int n) //���彨��˳���
{
	L=(SqList *)malloc(sizeof(SqList));
	for (int i=0;i<n;i++)
		L->data[i]=a[i];
	L->length=n;
}
void InitList(SqList *&L)	//��ʼ�����Ա�
{
	L=(SqList *)malloc(sizeof(SqList));	//���������Ա�Ŀռ�
	L->length=0;
}
void DestroyList(SqList *&L)  //�������Ա�
{
	free(L);
}
bool ListEmpty(SqList *L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->length==0);
}
int ListLength(SqList *L)	//�����Ա�ĳ���
{
	return(L->length);
}
void DispList(SqList *L)	//������Ա�
{
	for (int i=0;i<L->length;i++)
		printf("%c ",L->data[i]);
	printf("\n");
}
bool GetElem(SqList *L,int i,ElemType &e)	//�����Ա��е�i��Ԫ��ֵ
{
	if (i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList *L, ElemType e)	//���ҵ�һ��ֵ��Ϊe��Ԫ�����
{
	int i=0;
	while (i<L->length && L->data[i]!=e) i++;
	if (i>=L->length)
		return 0;
	else
		return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)	//�����i��Ԫ��
{
	int j;
	if (i<1 || i>L->length+1)
		return false;
	i--;						//��˳���λ��ת��Ϊelem�±�
	for (j=L->length;j>i;j--) 	//��data[i]������Ԫ�غ���һ��λ��
		L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;				//˳�������1
	return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)	//ɾ����i��Ԫ��
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;						//��˳���λ��ת��Ϊelem�±�
	e=L->data[i];
	for (j=i;j<L->length-1;j++)	//��data[i]֮���Ԫ��ǰ��һ��λ��
		L->data[j]=L->data[j+1];
	L->length--;				//˳����ȼ�1
	return true;
}
