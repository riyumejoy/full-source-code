//�ļ���:exp9-11.cpp
#include "bst.cpp"   //�������������������㷨
bool Findseq(BSTNode *bt,int a[],int n)	//�ж�a�Ƿ�Ϊbt�е�һ���Ϸ���������
{	BSTNode *p=bt;
	int i=0;
	while (i<n && p!=NULL)
	{
		if (i==n-1 && a[i]==p->key)			//a������ϣ�����true
			return true;
		if (p->key!=a[i])					//�����ȣ���ʾa���ǲ�������
			return false;					//����false
		i++;								//��������ָ����һ���ؼ���
		if (a[i]<p->key) p=p->lchild;		//���������в���
		else if (a[i]>p->key) p=p->rchild;	//���������в���
	}
	return false;
}


int main()
{
	BSTNode *bt;
	KeyType keys[]={5,2,3,4,1,6,8,7,9};
	int m=9;
	printf("(1)�������������bt\n");
	bt=CreateBST(keys,m);		//��������������
	printf("(2)���BST:");DispBST(bt);printf("\n");
	int n=4;
	KeyType a[]={5,6,8,9};
	printf("(3)�ؼ�������:");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	if (Findseq(bt,a,n))
		printf("��һ����������\n");
	else
		printf("����һ����������\n");
	printf("(4)����bt\n"); DestroyBST(bt);
	return 1;
}
