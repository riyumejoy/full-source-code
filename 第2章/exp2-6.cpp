//�ļ���:exp2-6.cpp
#include "linklist.cpp"				//����������Ļ��������㷨
void Split(LinkNode *&L,ElemType x)	//��L���������ݽ�㰴x���л���
{
	LinkNode *p=L->next,*q,*r;
	L->next=NULL;				//L��Ϊ������
	r=L;
	while (p!=NULL)
	{
		if (p->data<x)			//��p���ֵС��x����������ڿ�ͷ
		{
			q=p->next;
			p->next=L->next;
			L->next=p;
			if (p->next==NULL)	//��p����ǵ�һ���ڿ�ͷ����Ľ��
				r=p;			//������β���
			p=q;
		}
		else					//��p���ֵ���ڻ����x��������뵽ĩβ
		{
			r->next=p;
			r=p;
			p=p->next;
		}
	}
	r->next=NULL;
}
int main()
{
	LinkNode *L;
	ElemType a[]="abcdefgh";
	int n=8;
	CreateListR(L,a,n);
	printf("L:"); DispList(L);
	ElemType x='d';
	printf("��%c���л���\n",x);
	Split(L,x);
	printf("L:"); DispList(L);
	DestroyList(L);
	return 1;
}
