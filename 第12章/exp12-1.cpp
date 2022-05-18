//�ļ���:exp12-1.cpp
#include <stdio.h>
typedef struct
{	int no;					//ѧ��
	char name[10];			//����
	int age;				//����
	char sex[3];			//�Ա�
	int deg1,deg2,deg3;		//�γ�1-�γ�3�ɼ�
} StudType;
void CreateFile()			//��st�����ѧ����¼����stud.dat�ļ�
{
	int n=8;
	StudType st[]={
		{1,"�»�",20,"��",78,90,84},
		{5,"����",21,"��",78,68,92},
		{8,"��Ӣ",20,"Ů",86,81,86},
		{3,"����",21,"Ů",78,92,88},
		{2,"���",20,"��",80,83,78},
		{4,"�¾�",20,"��",78,88,82},
		{7,"��ʤ",21,"��",56,67,75},
		{6,"��ǿ",20,"��",78,89,82} };
	FILE *fp;
	if ((fp=fopen("stud.dat","wb"))==NULL)
	{
		printf("\t��ʾ:���ܴ���stud.dat�ļ�\n");
		return;
	}
	for (int i=0;i<n;i++)
		fwrite(&st[i],1,sizeof(StudType),fp);
	fclose(fp);
	printf("   ��ʾ:�ļ�stud.dat�������\n");
}

bool Findi(StudType &s,int i)		//��stud.dat�ļ��в������Ϊi��ѧ����¼s
{
	FILE *fp;
	if (i<=0) return false;			//i���󷵻ؼ�
	if ((fp=fopen("stud.dat","rb"))==NULL)
	{
		printf("\t��ʾ:���ܴ�stud.dat�ļ�\n");
		return false;
	}
	fseek(fp,(i-1)*sizeof(StudType),SEEK_SET);	//��λ�ڵ�i����¼֮ǰ
	if (fread(&s,sizeof(StudType),1,fp)==1)
	{
		fclose(fp);
		return true;				//�ɹ���ȡ��i����¼,������
	}
	else
	{
		fclose(fp);
		return false;				//���ܶ�ȡ��i����¼,���ؼ�
	}
}

bool Findno(StudType &s,int no)		//��stud.dat�ļ��в���ѧ��Ϊno��ѧ����¼s
{
	FILE *fp;
	if ((fp=fopen("stud.dat","rb"))==NULL)
	{
		printf("\t��ʾ:���ܴ�stud.dat�ļ�\n");
		return false;
	}
	fseek(fp,0,SEEK_SET);				//��λ���ļ���ͷ
	while (fread(&s,sizeof(StudType),1,fp)==1)
	{
		if (s.no==no)				//�ҵ�ѧ��Ϊno�ļ�¼��������
		{
			fclose(fp);
			return true;
		}
	}
	fclose(fp);
	return false;					//û���ҵ�ѧ��Ϊno�ļ�¼�����ؼ�
}

void DispaStud(StudType s)			//��ʾһ��ѧ����¼s
{
	printf("  ѧ��     ����   ���� �Ա� ���� ��ѧ Ӣ��\n");
	printf("%5d%10s%6d%5s%5d%5d%5d\n",s.no,s.name,s.age,s.sex,s.deg1,s.deg2,s.deg3);
}
int main()
{
	int i,no;
	StudType s;
	printf("������������:\n");
	printf("  (1)����ѧ����¼stud.dat�ļ�\n");
	CreateFile();
	printf("  (2)����Ų��ң��������:");
	scanf("%d",&i);
	if (Findi(s,i))
		DispaStud(s);
	else
		printf("    >�ļ����ܴ򿪻�������ļ�¼��Ŵ���n\n");
	printf("  (3)��ѧ�Ų��ң�����ѧ��:");
	scanf("%d",&no);
	if (Findno(s,no))
		DispaStud(s);
	else
		printf("    >�ļ����ܴ򿪻��������ѧ�Ŵ���\n");
	return 1;
}
