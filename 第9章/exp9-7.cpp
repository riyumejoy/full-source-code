//�ļ���:exp9-7.cpp
#include <stdio.h>
#define MAXL 100					//�����������¼����
typedef int KeyType;				//����ؼ�������Ϊint
typedef char InfoType;
typedef struct
{	KeyType key;					//�ؼ�����
	InfoType data;					//�������������ΪInfoType
} RecType;							//����Ԫ�ص�����

KeyType M_Search(RecType A[],RecType B[],int n)	//��A��B����λ��
{
	int start1,end1,mid1,start2,end2,mid2;
	start1=0; end1=n-1;
	start2=0; end2=n-1;
	while(start1!=end1 || start2!=end2)
	{
		mid1=(start1+end1)/2;
		mid2 = (start2+end2)/2;
		if(A[mid1].key==B[mid2].key)
			return A[mid1].key;
		if(A[mid1].key<B[mid2].key)
		{				//�ֱ���������ż������������������Ԫ�ظ������
			if((start1+end1)%2==0) //��Ԫ��Ϊ������
			{	
				start1=mid1;		//����A�м����ǰ�Ĳ����ұ����м��
				end2=mid2;			//����B�м���Ժ�Ĳ����ұ����м��
			}
			else					//��Ԫ��Ϊż����
			{	
				start1=mid1+1;		//����A��ǰ�벿��
				end2=mid2;			//����B�ĺ�벿��
			}
		}
		else
		{	if((start1+end1)%2==0)	//��Ԫ��Ϊ������
			{
				end1 = mid1;		//����A�м���Ժ�Ĳ����ұ����м��
				start2 = mid2;		//����B�м����ǰ�Ĳ����ұ����м��
			}
			else					//��Ԫ��Ϊż����
			{
				end1=mid1;			//����A�ĺ�벿��
				start2=mid2+1;		//����B��ǰ�벿��
			}
		}
	}
	return A[start1].key<B[start2].key?A[start1].key:B[start2].key;
}


int main()
{
	KeyType keys1[]={11,13,15,17,19};
	KeyType keys2[]={2,4,6,8,20};
	int n=5,i;
	RecType A[MAXL],B[MAXL];
	for (i=0;i<n;i++)
		A[i].key=keys1[i];
	for (i=0;i<n;i++)
		B[i].key=keys2[i];
	printf("A:"); 
	for (i=0;i<n;i++) printf("%3d",A[i].key);
	printf("\n");
	printf("B:"); 
	for (i=0;i<n;i++) printf("%3d",B[i].key);
	printf("\n");
	printf("A��B����λ��:%d\n",M_Search(A,B,n));

	return 1;
}