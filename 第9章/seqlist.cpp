//˳�����������㷨
#include <stdio.h>
#include <malloc.h>
#define MAXL 100		//��󳤶�
typedef int KeyType;	//����ؼ�������Ϊint
typedef char InfoType;

typedef struct
{	KeyType key;		//�ؼ�����
	InfoType data;		//�������������ΪInfoType
} RecType;				//����Ԫ�ص�����

void CreateList(RecType R[],KeyType keys[],int n)	//����˳���
{
	for (int i=0;i<n;i++)			//R[0..n-1]��������¼
		R[i].key=keys[i];
}
void DispList(RecType R[],int n)	//���˳���
{
	for (int i=0;i<n;i++)
		printf("%d ",R[i].key);
	printf("\n");
}
