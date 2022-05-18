//�ļ���:exp7-12.cpp
#include "preseq.cpp"				//�������л��ͷ����л��㷨
void GetNext(SqString t,int next[])	//��ģʽ��t���nextֵ
{	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{	if (k==-1 || t.data[j]==t.data[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++;k++;
			next[j]=k;
		}
		else  k=next[k];
	}
}
int KMPIndex(SqString s,SqString t)	//KMP�㷨
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length) 
	{	if (j==-1 || s.data[i]==t.data[j]) 
		{	i++;
			j++;				//i,j����1
		}
		else j=next[j]; 		//i����,j����
	}
	if (j>=t.length)
		return(i-t.length);		//����ƥ��ģʽ�������ַ��±�
	else
		return(-1);				//���ز�ƥ���־
}
bool isSubtree(BTNode *b1,BTNode *b2)	//�ж�b2�Ƿ���b1������
{
	SqString s1=PreOrderSeq(b1);	//��b1���������л�����s1
	SqString s2=PreOrderSeq(b2);	//��b2���������л�����s2
	if (KMPIndex(s1,s2)!=-1)		//��s2��s1���Ӵ���������
		return true;
	else							//��s2����s1���Ӵ������ؼ�
		return false;
}
int main()
{
	BTNode *b1,*b2;
	CreateBTree(b1,"A(B(D,E(,G)),C(,F(H,I)))"); 
	printf("������b1:");DispBTree(b1);printf("\n");
	CreateBTree(b2,"C(,F(H,I))"); 
	printf("������b2:");DispBTree(b2);printf("\n");

	if (isSubtree(b1,b2))
		printf("�����b2��b1������\n");
	else
		printf("�����b2����b1������\n");
	DestroyBTree(b1); DestroyBTree(b2);
	return 1;
}
 