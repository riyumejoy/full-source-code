//�ļ���:exp2-4.cpp
#include "clinklist.cpp"
int main()
{
	LinkNode *h;
	ElemType e;
	printf("ѭ��������Ļ�����������:\n");
	printf("  (1)��ʼ��ѭ��������h\n");
	InitList(h);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
	ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("  (3)���ѭ��������h:");
	DispList(h);
	printf("  (4)ѭ��������h����:%d\n",ListLength(h));
	printf("  (5)ѭ��������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("  (6)ѭ��������h�ĵ�3��Ԫ��:%c\n",e);
	printf("  (7)Ԫ��a��λ��:%d\n",LocateElem(h,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("  (9)���ѭ��������h:");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
	ListDelete(h,3,e);
	printf("  (11)���ѭ��������h:");
	DispList(h);
	printf("  (12)�ͷ�ѭ��������h\n");
	DestroyList(h);
	return 1;
}
