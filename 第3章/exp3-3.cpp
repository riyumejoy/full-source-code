//�ļ���:exp3-3.cpp
#include "sqqueue.cpp"		//�������ζ��еĻ��������㷨
int main()
{
	ElemType e;
	SqQueue *q;
	printf("���ζ��л�����������:\n");
	printf("  (1)��ʼ������q\n");
	InitQueue(q);
	printf("  (2)���ν�����Ԫ��a,b,c\n");
	if (!enQueue(q,'a')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'b')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'c')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (3)����Ϊ%s\n",(QueueEmpty(q)?"��":"�ǿ�"));
	if (deQueue(q,e)==0) 
		printf("�ӿ�,���ܳ���\n");
	else
		printf("  (4)����һ��Ԫ��%c\n",e);
	printf("  (5)���ν�����Ԫ��d,e,f\n");
	if (!enQueue(q,'d')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'e')) printf("\t��ʾ:����,���ܽ���\n");
	if (!enQueue(q,'f')) printf("\t��ʾ:����,���ܽ���\n");
	printf("  (6)����������:");
	while (!QueueEmpty(q))
	{	deQueue(q,e);
		printf("%c ",e);
	}
	printf("\n");
	printf("  (7)�ͷŶ���\n");
	DestroyQueue(q);
	return 1;
}
