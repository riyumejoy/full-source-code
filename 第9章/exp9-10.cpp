//�ļ���:exp9-10.cpp
#include "bst.cpp"   //�������������������㷨

void Succlength(BSTNode *bt,int &sumlen,int &m,int level) //����ҳɹ��ܵıȽϴ���sumlen�������m
{
	if (bt==NULL) return;	//����ֱ�ӷ���
	m++;
	sumlen+=level;
	Succlength(bt->lchild,sumlen,m,level+1);
	Succlength(bt->rchild,sumlen,m,level+1);
}
double ASLsucc(BSTNode *bt)	//����ҳɹ�����µ�ƽ�����ҳ���
{
	int sumlen=0,m=0;
	Succlength(bt,sumlen,m,1);
	return sumlen*1.0/m;
}
void Unsucclength(BSTNode *bt,int &sumlen,int &m,int level) //�����ʧ���ܵıȽϴ���sumlen�������m
{
	if (bt==NULL)		//��ָ���Ӧ�ⲿ�ڵ�
	{
		m++;
		sumlen+=level-1;
		return;
	}
	Unsucclength(bt->lchild,sumlen,m,level+1);
	Unsucclength(bt->rchild,sumlen,m,level+1);
}
double ASLunsucc(BSTNode *bt)	//�����ʧ������µ�ƽ�����ҳ���
{
	int sumlen=0,m=0;
	Unsucclength(bt,sumlen,m,1);
	return sumlen*1.0/m;
}
int main()
{
	BSTNode *bt;
	int n=12;
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
	printf("(1)����BST\n");				//�������̡̳���9.3��һ��BST
	bt=CreateBST(a,n);
	printf("(2)BST:"); DispBST(bt); printf("\n");
	printf("(3)ASLsucc=%g\n",ASLsucc(bt));
	printf("(4)ASLunsucc=%g\n",ASLunsucc(bt));
	DestroyBST(bt);
	return 1;
}
