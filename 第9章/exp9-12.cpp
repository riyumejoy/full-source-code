//�ļ���:exp9-12.cpp
#include "bst.cpp"   //�������������������㷨

BSTNode *LCA(BSTNode *bt,KeyType x,KeyType y) //�ڶ���������bt����x��y�ڵ��LCA�������ظýڵ��ָ��
{
	if (bt==NULL) return NULL;
	if (x<bt->key && y<bt->key)
		return LCA(bt->lchild,x,y);
	else if (x>bt->key && y>bt->key)
		return LCA(bt->rchild,x,y);
	else
		return bt;
}


int main()
{
	BSTNode *bt,*p;
	KeyType x=1,y=4;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	printf("(1)�������������bt\n");
	bt=CreateBST(a,n);		//����һ�ö���������
	printf("(2)���BST:");DispBST(bt);printf("\n");
	printf("(3)����%d��%d�ڵ��LCA\n",x,y);
	if (p=LCA(bt,x,y))
		printf("  LCA��:%d\n",p->key);
	else
		printf("  ָ���Ĺؼ��ֲ�����\n");
	printf("(4)����bt"); DestroyBST(bt); printf("\n");
	return 1;
}
