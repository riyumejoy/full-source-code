//�ļ���:exp12-1.cpp
#include <stdio.h>
#include <string.h>
#define N 10				//���ѧ������
typedef struct
{	int no;					//ѧ��
	char name[10];			//����
	int age;				//����
	char sex[3];			//�Ա�
	int deg1,deg2,deg3;		//�γ�1-�γ�3�ɼ�
} StudType;
typedef struct
{	int no;					//ѧ��
	char name[10];			//����
	int age;				//����
	char sex[2];			//�Ա�
	int deg1,deg2,deg3;		//�γ�1-�γ�3�ɼ�
	double avg;				//ƽ����
} StudType1;
void WriteFile(StudType st[],int n)		//��st�����е�ѧ����¼д�뵽stud.dat�ļ���
{
	int i;
	FILE *fp;
	if ((fp=fopen("stud.dat","wb"))==NULL)
	{
		printf("\t��ʾ:���ܴ���stud.dat�ļ�\n");
		return;
	}
	for (i=0;i<n;i++)
		fwrite(&st[i],1,sizeof(StudType),fp);
	fclose(fp);
	printf("\t��ʾ:�ļ�stud.dat�������\n");
}
void WriteFile1(StudType1 st1[],int n)	//��st1�����е�ѧ����¼д�뵽stud1.dat�ļ���
{
	int i;
	FILE *fp;
	if ((fp=fopen("stud1.dat","wb"))==NULL)
	{
		printf("\t��ʾ:���ܴ���stud1.dat�ļ�\n");
		return;
	}
	for (i=0;i<n;i++)
		fwrite(&st1[i],1,sizeof(StudType),fp);
	fclose(fp);
	printf("\t��ʾ:�ļ�stud1.dat�������\n");
}
void ReadFile(StudType st[],int &n)		//��stud.dat�ļ��е�n��ѧ����¼���뵽st������
{
	FILE *fp;
	if ((fp=fopen("stud.dat","rb"))==NULL)
	{
		printf("\t��ʾ:���ܴ�stud.dat�ļ�\n");
		return;
	}
	n=0;
	while (fread(&st[n],sizeof(StudType),1,fp)==1)
		n++;
	printf("\t��ʾ:�ļ�stud.dat��ȡ���\n");
}
void ReadFile1(StudType1 st1[],int &n)	//��stud1.dat�ļ��е�n��ѧ����¼���뵽st1������
{
	FILE *fp;
	if ((fp=fopen("stud1.dat","rb"))==NULL)
	{
		printf("\t��ʾ:���ܴ�stud1.dat�ļ�\n");
		return;
	}
	n=0;
	while (fread(&st1[n],sizeof(StudType),1,fp)==1)
		n++;
	printf("\t��ʾ:�ļ�stud1.dat��ȡ���\n");
}
void Display(StudType st[],int n)	//��ʾѧ����¼
{
	int i;
	printf("                ----ѧ���ɼ���----\n");
	printf("  ѧ��     ����   ���� �Ա� ���� ��ѧ Ӣ��\n");
	for (i=0;i<n;i++)
		printf("%5d%10s%6d%5s%5d%5d%5d\n",st[i].no,st[i].name,st[i].age,st[i].sex,st[i].deg1,st[i].deg2,st[i].deg3);
	printf("\n");
}
void Display1(StudType1 st1[],int n)	//��ʾ��ƽ���ֺ��ѧ����¼
{
	int i;
	printf("                ----�����ѧ���ɼ���----\n");
	printf("  ѧ��     ����   ���� �Ա� ���� ��ѧ Ӣ�� ƽ����\n");
	for (i=0;i<n;i++)
		printf("%5d%10s%6d%5s%5d%5d%5d%6.1f\n",st1[i].no,st1[i].name,st1[i].age,st1[i].sex,st1[i].deg1,st1[i].deg2,st1[i].deg3,st1[i].avg);
	printf("\n");
}
void Average(StudType st[],StudType1 st1[],int n)	//��ƽ����
{
	int i;
	for (i=0;i<n;i++)
	{
		st1[i].no=st[i].no;
		strcpy(st1[i].name,st[i].name);
		st1[i].age=st[i].age;
		strcpy(st1[i].sex,st[i].sex);
		st1[i].deg1=st[i].deg1;
		st1[i].deg2=st[i].deg2;
		st1[i].deg3=st[i].deg3;
		st1[i].avg=(st1[i].deg1+st1[i].deg2+st1[i].deg3)/3.0;
	}
}
void Sort(StudType1 st1[],int n)		//��ƽ���ֵݼ�����
{
	int i,j;
	StudType1 temp;
	for (i=1;i<n;i++)			//ֱ�Ӳ�������
	{
		temp=st1[i];
		for (j=i-1;j>=0 && temp.avg>st1[j].avg;j--)
			st1[j+1]=st1[j];
		st1[j+1]=temp;
	}
}
int main()
{
	int n=8;
	StudType st[]={{1,"�»�",20,"��",78,90,84},
	{5,"����",21,"��",78,68,92},
	{8,"��Ӣ",20,"Ů",86,81,86},
	{3,"����",21,"Ů",78,92,88},
	{2,"���",20,"��",80,83,78},
	{4,"�¾�",20,"��",78,88,82},
	{7,"��ʤ",21,"��",56,67,75},
	{6,"��ǿ",20,"��",78,89,82}};
	StudType1 st1[N];
	printf("������������:\n");
	printf("  (1)��st������ѧ����¼д��stud.dat�ļ�\n");
	WriteFile(st,n);
	printf("  (2)��stud.dat�ļ���ѧ����¼���뵽st������\n");
	ReadFile(st,n);
	printf("  (3)��ʾst�����е�ѧ����¼\n");
	Display(st,n);
	printf("  (4)��ѧ����ƽ���ֲ�����st1������\n");
	Average(st,st1,n);
	printf("  (5)��st1���鰴ƽ���ֵݼ�����\n");
	Sort(st1,n);
	printf("  (6)��st1������ѧ����¼д��stud1.dat�ļ�\n");
	WriteFile1(st1,n);
	printf("  (7)��stud1.dat�ļ���ѧ����¼���뵽st1������\n");
	ReadFile1(st1,n);
	printf("  (8)��ʾst1�����е�ѧ����¼\n");
	Display1(st1,n);
	return 1;
}
