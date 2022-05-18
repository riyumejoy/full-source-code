//�ļ���:exp4-6.cpp
#include "sqstring.cpp"				//����˳�򴮵Ļ��������㷨

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
void display(SqString s,SqString t,int i,int j) //��ʾƥ��״̬
{
	int k;
	printf("  ");
	for (k=0;k<i;k++)
		printf("  ");
	printf("�� i=%d,j=%d\n",i,j);
	printf("s:");
	for (k=0;k<s.length;k++)
		printf("%c ",s.data[k]);
	printf("\n");
	printf("t:");
	for (k=0;k<i-j;k++)
		printf("  ");
	for (k=0;k<t.length;k++)
		printf("%c ",t.data[k]);
	printf("\n");
	for (k=0;k<i-j;k++)
		printf("  ");
	for (k=0;k<=j;k++)
		printf("  ");
	printf("��\n");

}
int Count(SqString s,SqString t)	//����KMP�㷨��t��s�г��ֵĴ���
{
	int next[MaxSize],i=0,j=0,count=0;
	GetNext(t,next);
	display(s,t,i,j);
	while (i<s.length && j<t.length) 
	{
		if (j==-1 || s.data[i]==t.data[j])
		{
			i++;
			j++;				//i,j����1
		}
		else
		{
			j=next[j]; 			//i����,j����
			display(s,t,i,j);
		}
		if (j==t.length)
		{
			display(s,t,i,j);
			printf("\t�ɹ�ƥ��1��\n");
			count++;
			j=0;
		}
	
	}
	return count;
}

int main()
{
	SqString s,t;
	StrAssign(s,"aaabbdaabbde");
	StrAssign(t,"aabbd");
	printf("t��s�г��ִ���:%d\n",Count(s,t));
	DestroyStr(s); DestroyStr(t); 
	return 1;
}
