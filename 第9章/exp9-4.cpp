//�ļ���:exp9-4.cpp
#include "bst.cpp"		//���������������������㷨
int main()
{
	BSTNode *bt;
	int path[MaxSize];
	KeyType k=6;
	int a[]={4,9,0,1,8,6,3,5,2,7},n=10;
	printf("(1)����һ��BST��:");
	printf("\n");
	bt=CreateBST(a,n);
	printf("(2)BST:");DispBST(bt);printf("\n");
	printf("(3)bt%s\n",(JudgeBST(bt)?"��һ��BST":"����һ��BST"));
	printf("(4)����%d�ؼ���(�ݹ�,˳��):",k);SearchBST1(bt,k,path,-1);
	printf("(5)����%d�ؼ���(�ǵݹ�,����):",k);SearchBST2(bt,k);
	printf("\n(6)ɾ������:\n");
	printf("   ԭBST:");DispBST(bt);printf("\n");
	printf("   ɾ���ڵ�4:");
	DeleteBST(bt,4); DispBST(bt); printf("\n");
	printf("   ɾ���ڵ�5:");
	DeleteBST(bt,5); DispBST(bt); printf("\n");
	printf("(7)����BST\n"); DestroyBST(bt);
	return 1;
}
