//�ļ���:exp5-5.cpp
#include "linklist.cpp"		//����������Ļ��������㷨
void Reverse(LinkNode *p,LinkNode *&L)  
{  
    if(p->next==NULL)		//��pΪ�׽ڵ�ָ��ĵ�����ֻ��һ���ڵ�ʱ
    {  
        L->next=p;			//p�ڵ��Ϊβ�ڵ�
        return;
    }  
    Reverse(p->next,L);		//���ú��β�ڵ���p->next  
    p->next->next=p;		//���ڵ�������β�ڵ�֮��  
    p->next=NULL;			//β�ڵ�next����ΪNULL  
}  

int main()
{
	LinkNode *L;
	char a[]="12345678";
	int n=8;
	CreateListR(L,a,n);
	printf("L:"); DispList(L);
	printf("����L\n");
	Reverse(L->next,L);
	printf("L:"); DispList(L);
	DestroyList(L);
	return 1;
}
