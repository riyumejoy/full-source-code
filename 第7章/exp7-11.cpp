//�ļ���:exp7-11.cpp
#include "preseq.cpp"				//�������л��ͷ����л��㷨
int main()
{
	BTNode *b,*b1;
	SqString str;
	printf("(1)����������b\n");
	CreateBTree(b,"A(B(D,E(,G)),C(,F(H,I)))"); 
	printf("(2)������b:");DispBTree(b);printf("\n");
	printf("(3)��b������������������������л�����str\n");
	str=PreOrderSeq(b);
	printf("(4)str:"); DispStr(str);
	printf("(5)��str����������b1\n");
	b1=CreatePreSeq(str);
	printf("(6)������b1:");DispBTree(b1);printf("\n");
	printf("(7)����b��b1\n");
	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
 