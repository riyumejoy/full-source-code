//�ļ���:exp2-7.cpp
#include "linklist.cpp"				//����������Ļ��������㷨
void Merge(LinkNode *L1,LinkNode *L2,LinkNode *&L3) //L1��L2�ϲ�����L3
{
	LinkNode *p=L1->next,*q=L2->next,*r;
	L3=L1;
	r=L3;				//rָ���½�������L3��β���
	free(L2);			//�ͷ�L2��ͷ���
	while (p!=NULL && q!=NULL)
	{
		r->next=p; r=p; p=p->next;
		r->next=q; r=q; q=q->next;
	}
	r->next=NULL;
	if (q!=NULL) p=q;
	r->next=p;
}

int main()
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]="abcdefgh";
	int n=8;
	CreateListR(L1,a,n);
	printf("L1:"); DispList(L1);

	ElemType b[]="12345";
	n=5;
	CreateListR(L2,b,n);
	printf("L2:"); DispList(L2);
	printf("L1��L2�ϲ�����L3\n");
	Merge(L1,L2,L3);
	printf("L3:"); DispList(L3);
	DestroyList(L3);
	return 1;
}
