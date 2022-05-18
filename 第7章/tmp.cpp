//�ļ���:algo7-1.cpp
#include "btree.cpp"   //�����������Ļ��������㷨
void levelnodes(BTNode *b,int h,int a[])
{
	if (b==NULL)
		return;
	else
	{
		a[h]++;
		levelnodes(b->lchild,h+1,a);
		levelnodes(b->lchild,h+1,a);
	}
}
int BTWidth1(BTNode *b)
{
	int width=0,i;
	int a[MaxSize];
	for (i=1;i<MaxSize;i++)
		a[i]=0;				//a��������Ԫ�س�ʼ��Ϊ0
	levelnodes(b,1,a);
	i=1;
	while (a[i]!=0)			//��a�����Ԫ�ؼ����
	{
		if (a[i]>width)
			width=a[i];
		i++;
	}
	return width;
}

int BTWidth2(BTNode *b)					//�������b�Ŀ��
{
	struct 
	{
		int lno;						//���Ĳ��
		BTNode *p;						//���ָ��
	} Qu[MaxSize];						//����ǻ��ζ���
	int front,rear;						//�����ͷ�Ͷ�βָ��
	int lnum,width,i,n;
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
		width=0;lnum=1;i=1;				//width��ſ��
		while (i<=rear)
		{
			n=0;
			while (i<=rear && Qu[i].lno==lnum) //iɨ����������н��
			{
				n++;					//n�ۼ�һ���еĽ�����
				i++;
			}
			lnum=Qu[i].lno;
			if (n>width) width=n;
		}
		return width;
	}
	else return 0;
}
int main()
{
	ElemType x='K';
	BTNode *b,*p,*lp,*rp;;
	CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("���������b:");DispBTree(b);printf("\n");
	printf("������b�Ŀ��:%d\n",BTWidth2(b));
	DestroyBTree(b);
	return 1;
}

