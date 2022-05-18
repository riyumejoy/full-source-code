//�ļ���:exp7-8.cpp
#include "btree.cpp"   //�����������Ļ��������㷨
#include <stdlib.h>
#include <string.h>
typedef char ElemType;
BTNode *CRTree(char s[],int i,int j) //�������������ʽs[i..j]��Ӧ�Ķ�����
{
	BTNode *p;
	int k,plus=0,posi;			//plus��¼������ĸ���
	if (i==j)					//����i=j�������˵��ֻ��һ���ַ�
	{
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=s[i];
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	//����Ϊi!=j�����
	for (k=i;k<=j;k++)			//���Ȳ���+��-�����
		if (s[k]=='+' || s[k]=='-')
		{
			plus++;				//plus��¼+����-�ĸ���
			posi=k;             //posi��¼���һ��+��-��λ��
		}
	if (plus==0)                //û��+��-�����
		for (k=i;k<=j;k++)
			if (s[k]=='*' || s[k]=='/')
			{
				plus++;			//plus��¼*����/�ĸ���
				posi=k;			//posi��¼���һ��*��/��λ��
			}
   if (plus!=0)					//������������,����һ��������Ľ��
   {
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=s[posi];
		p->lchild=CRTree(s,i,posi-1);	//�ݹ鴦��s[i..posi-1]����������
		p->rchild=CRTree(s,posi+1,j);	//�ݹ鴦��s[posi+1..j]����������
		return p;
	}
   else       //��û���κ������������NULL
	   return NULL;
}
double Comp(BTNode *b)	//�����������Ӧ���ʽ��ֵ
{
	double v1,v2;
	if (b==NULL) return 0;
	if (b->lchild==NULL && b->rchild==NULL)
		return b->data-'0';		//Ҷ�ӽ��ֱ�ӷ��ؽ��ֵ
	v1=Comp(b->lchild);			//�ݹ������������ֵv1
	v2=Comp(b->rchild);			//�ݹ������������ֵv2
	switch(b->data)				//����b�������Ӧ����
	{
	case '+':
		return v1+v2;
	case '-':
		return v1-v2;
	case '*':
		return v1*v2;
	case '/':
		if (v2!=0)
			return v1/v2;
		else
			abort();		//��0�쳣�˳�

	}
}
int main()
{
	BTNode *b;
	char s[MaxSize]="1+2*3-4/5";
    printf("�������ʽ%s\n",s);
	b=CRTree(s,0,strlen(s)-1);
	printf("��Ӧ������:");
	DispBTree(b);
	printf("\n�������ʽ��ֵ:%g\n",Comp(b));
	DestroyBTree(b);
	return 1;
}
