//�ļ���:exp4-5.cpp
#include "sqstring.cpp"				//����˳�򴮵Ļ��������㷨
#include <malloc.h>
SqString *MaxSubstr(SqString s)
{
	SqString *subs;	
	int index=0,length=0,length1,i=0,j,k;
	while (i<s.length) 
	{
		j=i+1;
		while (j<s.length) 
		{
			if (s.data[i]==s.data[j]) //��һ�Ӵ�,�����Ϊi,����Ϊlength1
			{
				length1=1;
				for(k=1;s.data[i+k]==s.data[j+k];k++)
					length1++;
				if (length1>length)    //���ϴ󳤶��߸���index��length
				{
					index=i;
					length=length1;
				}
				j+=length1;
			}
			else j++;
		}
		i++;                                 //����ɨ���i�ַ�֮����ַ�
	}
	subs=(SqString *)malloc(sizeof(SqString));
	subs->length=length;
	for (i=0;i<length;i++)
		subs->data[i]=s.data[index+i];
	return subs;
}
int main()
{
	char str[MaxSize];
	SqString s,*subs;
	printf("���봮:");
	gets(str);
	StrAssign(s,str);			//������s
	subs=MaxSubstr(s);
	printf("����ظ��Ӵ�:\n");
	printf("    ԭ��:");
	DispStr(s);
	printf("  ��ظ��Ӵ�:");	//�����ظ��Ӵ�
	DispStr(*subs);
	DestroyStr(s); free(subs);
	return 1;
}
