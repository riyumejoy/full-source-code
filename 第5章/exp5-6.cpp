//�ļ���:exp5-6.cpp
#include "linklist.cpp"		//����������Ļ��������㷨
LinkNode *kthNode(LinkNode *L,int k,int &i)  //������k���ڵ�
{
	LinkNode *p;
    if(L==NULL) return NULL;	//�ձ���NULL
	p=kthNode(L->next,k,i);
	i++;
	if (i==k) return L;
	return p;
}  

int main()
{
	LinkNode *L,*p;
	char a[]="12345678";
	int n=8,k=2,i=0;
	CreateListR(L,a,n);
	printf("L:"); DispList(L);
	p=kthNode(L->next,k,i);
	if (p!=NULL)
		printf("������%d���ڵ�:%c\n",k,p->data);
	else
		printf("û���ҵ�\n");
	DestroyList(L);
	return 1;
}
