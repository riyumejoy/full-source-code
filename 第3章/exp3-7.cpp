//�ļ���:exp3-7.cpp
#include "sqstack.cpp"			//����˳��ջ�Ļ��������㷨
void StackSort(SqStack *&st)	//��ջst��Ԫ������
{
	SqStack *tmpst;
	InitStack(tmpst);
	ElemType e,e1;
	while (!StackEmpty(st))		//stջ����ѭ��
	{
		Pop(st,e);				//��ջԪ��e
		printf("    st:��ջ%c=> ",e);
		while(!StackEmpty(tmpst))
		{
			GetTop(tmpst,e1);
			printf("tmpst:ȡջ��Ԫ��%c ",e1);
			if (e1>e)
			{
				printf("��%c>%c ",e1,e);
				printf("tmpst:��ջ%c ",e1);
				Pop(tmpst,e1);
				printf("s:��ջ%c ",e1);
				Push(st,e1);
			}
			else
			{
				printf("��%c<%c,�˳�ѭ�� ",e1,e);
				break;
			}
		}
		Push(tmpst,e);
		printf("tmpst:��ջ%c\n",e);
	}
	while (!StackEmpty(tmpst))
	{
		Pop(tmpst,e);
		Push(st,e);
	}

	DestroyStack(tmpst);
}

int main()
{
	ElemType e;
	SqStack *s;
	InitStack(s);
	printf("(1)���ν�ջԪ��1,3,4,2\n");
	Push(s,'1');
	Push(s,'3');
	Push(s,'4');
	Push(s,'2');
	printf("(2)ջs�������:\n");
	StackSort(s);
	printf("(3)ջs�������\n");
	printf("(4)s�ĳ�ջ����:");
	while (!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c ",e);
	}
	printf("\n");
	DestroyStack(s);
	return 1;
}
