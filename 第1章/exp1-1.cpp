//�ļ�����exp1-1.cpp
#include <stdio.h>
#include <time.h>		 	//clock_t, clock, CLOCKS_PER_SEC
#include <math.h>

//------����1-----------------------------------------------
long add1(long n)			//����1����1+2+...+n
{
	long i,sum=0;
	for (i=1;i<=n;i++)
		sum+=i;
	return sum;
}

void AddTime1(long n)		//���÷���1�ĺ�ʱͳ��
{
	clock_t t;
	long sum;
	t=clock();
	sum=add1(n);
	t=clock()-t;
	printf("����1:\n");
	printf("  ���:1��%d֮��:%ld\n",n,sum);
	printf("  ��ʱ:%lf��\n" ,((float)t)/CLOCKS_PER_SEC);
}

//------����2-----------------------------------------------
long add2(long n)			//����2����1+2+...+n
{
	return n*(n+1)/2;
}
void AddTime2(long n)		//���÷���2�ĺ�ʱͳ��
{
	clock_t t;
	long sum;
	t=clock();
	sum=add2(n);
	t=clock()-t;
	printf("����2:\n");
	printf("  ���:1��%d֮��:%ld\n",n,sum);
	printf("  ��ʱ:%lf��\n" ,((float)t)/CLOCKS_PER_SEC);
}
//------------------------------------------------------------
int main()
{
	int n;
	printf("n(����1000000):");
	scanf("%d",&n);
	if (n<1000000) return 0;
	AddTime1(n);
	AddTime2(n);
	return 1;
}
