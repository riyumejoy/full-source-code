//�ļ���:exp5-3.cpp
#include <stdio.h>
#define MaxSize 100
typedef struct
{	char data[MaxSize];
	int length;
} IP;
void addch(IP &ip,char ch)	//ip��ĩβ���һ���ַ�ch
{	ip.data[ip.length]=ch;
	ip.length++;
}
IP adddot(IP ip)			//ip��ĩβ���һ��'.'�������ؽ��
{	addch(ip,'.');
	return ip;
}
void solveip(char s[],int n,int start,int step,IP ip)	//�ָ�IP��ַ��
{
	if (start<=n)
	{
		if (start==n && step==4)			//�ҵ�һ���Ϸ���
		{
			for (int i=0;i<ip.length-1;i++)	//�������,��������һ��'.'
				printf("%c",ip.data[i]);
			printf("\n");
		}
	}
	int num=0;
	for (int i=start;i<n && i<start+3;i++)
	{
		num=10*num+(s[i]-'0');			//��start��ʼ��i�����ַ�ת��Ϊ��ֵ		
		if (num<=255)					//Ϊ�Ϸ��㣬�����ݹ�
		{
			addch(ip,s[i]);
			solveip(s,n,i+1,step+1,adddot(ip));
		}
		if (num==0) break;				//������ǰ׺0����������0
	}
}
int main()
{
	char s[MaxSize]="25525511135";
	int n=11;
	IP ip;
	ip.length=0;
	solveip(s,n,0,0,ip);
	return 1;
}
