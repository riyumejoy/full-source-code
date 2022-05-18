//�ļ�����exp1-3.cpp
#include <stdio.h>
#include <time.h>		 	//clock_t, clock, CLOCKS_PER_SEC
#include <math.h>

//------����1-----------------------------------------------
bool prime1(long n)			//����1���ж�������n�Ƿ�Ϊ����
{
	long i;
	for (i=2;i<n;i++)
		if (n%i==0) 
			return false;	//��n��������,���˳�������false
	return true;
}

void PrimeTime1(long n)		//���÷���1�ĺ�ʱͳ��
{
	clock_t t;
	long sum=0,i;
	t=clock();
	for (i=2;i<=n;i++)
		if (prime1(i))
			sum++;
	t=clock()-t;
	printf("����1:\n");
	printf("  ���:2��%d����������:%d\n",n,sum);
	printf("  ��ʱ:%lf��\n" ,((float)t)/CLOCKS_PER_SEC);
}

//------����2-----------------------------------------------
bool prime2(long n)			//����2���ж�������n�Ƿ�Ϊ����
{
	long i;
	for (i=2;i<=(int)sqrt(n);i++)
		if (n%i==0) 
			return false;	//��n��������,���˳�������false
	return true;
}
void PrimeTime2(long n)		//���÷���2�ĺ�ʱͳ��
{
	clock_t t;
	long sum=0,i;
	t=clock();
	for (i=2;i<=n;i++)
		if (prime2(i))
			sum++;
	t=clock()-t;
	printf("����2:\n");
	printf("  ���:2��%d����������:%d\n",n,sum);
	printf("  ��ʱ:%lf��\n" ,((float)t)/CLOCKS_PER_SEC);
}
//------------------------------------------------------------
int main()
{
	long n;
	printf("n(����100000):");
	scanf("%d",&n);
	if (n<10000) return 0;
	PrimeTime1(n);
	PrimeTime2(n);
	return 1;
}
