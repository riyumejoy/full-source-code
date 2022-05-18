//�ļ���:algo7-1.cpp
#include "btree.cpp"   //�����������Ļ��������㷨
int Nodes(BTNode *b)	//�������b�Ľ�����
{
	int num1,num2;
    if (b==NULL) 
		return 0;
    else if (b->lchild==NULL && b->rchild==NULL) 
		return 1;
    else
    {
        num1=Nodes(b->lchild);
        num2=Nodes(b->rchild);
        return (num1+num2+1);
	}
}
int LeafNodes(BTNode *b)	//�������b��Ҷ�ӽ�����
{
	int num1,num2;
    if (b==NULL) 
		return 0;
    else if (b->lchild==NULL && b->rchild==NULL) 
		return 1;
    else
    {
        num1=LeafNodes(b->lchild);
        num2=LeafNodes(b->rchild);
        return (num1+num2);
	}
}
int Level(BTNode *b,ElemType x,int h)	//�������b�н��ֵΪx�Ľ��Ĳ��
{	int l;
	if (b==NULL)
		return(0);
	else if (b->data==x)
		return(h);
	else
	{	l=Level(b->lchild,x,h+1);	//���������в���
		if (l!=0)
			return(l);
		else						//����������δ�ҵ�,�����������в���
			return(Level(b->rchild,x,h+1));
	}
}

int BTWidth(BTNode *b)					//�������b�Ŀ��
{
	struct 
	{
		int lno;						//���Ĳ��
		BTNode *p;						//���ָ��
	} Qu[MaxSize];						//����ǻ��ζ���
	int front,rear;						//������׺Ͷ�βָ��
	int lnum,max,i,n;
	front=rear=0;						//�ö���Ϊ�ն�
    if (b!=NULL) 
	{
		rear++;	
		Qu[rear].p=b;					//��������
		Qu[rear].lno=1;					//�����Ĳ��Ϊ1
		while (rear!=front)				//�Ӳ���ʱѭ��
		{
			front++;
			b=Qu[front].p;				//���ӽ��p
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)		//�����ӣ��������
			{
				rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)		//���Һ��ӣ��������
			{
				rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		max=0;lnum=1;i=1;				//max��ſ��
		while (i<=rear)
		{
			n=0;
			while (i<=rear && Qu[i].lno==lnum) //iɨ����������н��
			{
				n++;					//n�ۼ�һ���еĽ�����
				i++;
			}
			lnum=Qu[i].lno;
			if (n>max) max=n;
		}
		return max;
	}
	else return 0;
}
int main()
{
	ElemType x='K';
	BTNode *b,*p,*lp,*rp;;
	CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("���������b:");DispBTree(b);printf("\n");
	printf("������b�Ľ�����:%d\n",Nodes(b));
	printf("������b��Ҷ�ӽ�����:%d\n",LeafNodes(b));
	printf("������b��ֵΪ%c���Ĳ��:%d\n",x,Level(b,x,1));
	printf("������b�Ŀ��:%d\n",BTWidth(b));
	DestroyBTree(b);
	return 1;
}

