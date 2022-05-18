//�ļ���:exp7-11.cpp
#include "btree.cpp"				//�����������Ļ��������㷨
#include "sqstring.cpp"				//����˳�򴮵Ļ��������㷨
int i=0;							//ȫ�ֱ���
SqString PreOrderSeq(BTNode *b)  	//�ɶ�����b�����������л�����str
{
	SqString str,str1,leftstr,rightstr;
	if (b==NULL)
	{
		StrAssign(str,"#");
		return str;
	}
	str.data[0]=b->data; str.length=1;	//����ֻ��b->data�ַ����ַ���str
	leftstr=PreOrderSeq(b->lchild);
	str1=Concat(str,leftstr);
	rightstr=PreOrderSeq(b->rchild);
	str=Concat(str1,rightstr);
	return str;
}
BTNode *CreatePreSeq(SqString str)		//���������л�����str���������������ظ����
{
	BTNode *b;
	char value;
	if (i>=str.length)					//i���緵�ؿ�
		return NULL;
	value=str.data[i]; i++;				//��str��ȡ��һ���ַ�value
	if (value=='#')						//��valueΪ'#'�����ؿ�
		return NULL;
	b=(BTNode *)malloc(sizeof(BTNode));	//���������
	b->data=value;
	b->lchild=CreatePreSeq(str);		//�ݹ鹹��������
	b->rchild=CreatePreSeq(str);		//�ݹ鹹��������
	return b;							//���ظ����
}
