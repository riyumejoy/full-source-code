//�ļ���:exp12_2.cpp
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MaxRec 100  		//���ļ�¼����
typedef struct Index 		//���������ļ��ṹ
{
	int no;					//ѧ��
	long offset;			//���ļ��еļ�¼��
} Index;
typedef struct
{	int no;					//ѧ��
	char name[10];			//����
	int age;				//����
	char sex[3];			//�Ա�
	int deg1,deg2,deg3;		//�γ�1-�γ�3�ɼ�
} StudType;
void InsertSort(Index R[],int n) //����ֱ�Ӳ������򷨶�R[0..n-1]��ѧ�ŵ�������
{
	int i,j;
	Index temp;
	for (i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1; 
		while (j>=0 && temp.no<R[j].no) 
		{ 	
			R[j+1]=R[j];	//���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
		R[j+1]=temp;		//��j+1������R[i]
	}
}
void CreatIdxFile()			//���������ļ�
{
	FILE *mfile,*idxfile;
	Index idx[MaxRec];
	StudType st;
	int n=0,i;
	if ((mfile=fopen("stud.dat","rb"))==NULL) 
	{
	    printf("  ��ʾ:���ܴ����ļ�\n");
		return;
	}
	if ((idxfile=fopen("index.dat","wb"))==NULL) 
	{
	    printf("  ��ʾ:���ܽ��������ļ�\n");
		return;
	}
	i=0;
   	while ((fread(&st,sizeof(StudType),1,mfile))!=NULL)
	{
		idx[i].no=st.no;
		idx[i].offset=++n;
		i++;
	}
	InsertSort(idx,n);	//��idx���鰴noֵ����
	rewind(idxfile);
	for (i=0;i<n;i++)
		fwrite(&idx[i],sizeof(Index),1,idxfile);
	fclose(mfile);
	fclose(idxfile);
	printf("  ��ʾ:�����ļ��������\n");
}
void OutputMainFile()	//������ļ�ȫ����¼
{
 	FILE *mfile;
	StudType st;
	int i=1;
	if ((mfile=fopen("stud.dat","rb"))==NULL)
	{
		printf("  ��ʾ:���ܶ����ļ�\n");
		return;
	}
	printf("                ----ѧ���ɼ���----\n");
	printf("��¼��  ѧ��     ����   ���� �Ա� ���� ��ѧ Ӣ��\n");
   	while ((fread(&st,sizeof(StudType),1,mfile))==1)
	{
		printf("%6d%5d%10s%6d%5s%5d%5d%5d\n",i,st.no,st.name,st.age,st.sex,st.deg1,st.deg2,st.deg3);
		i++;
	}
	fclose(mfile);
}
void OutputIdxFile()	//��������ļ�ȫ����¼
{
 	FILE *idxfile;
	Index irec;
	int i=0;
	printf("     ----ѧ��������----\n");
	printf("\tѧ��  ��¼��\n");
	if ((idxfile=fopen("index.dat","rb"))==NULL)
	{
		printf("  ��ʾ:���ܶ������ļ�\n");
		return;
	}
   	while ((fread(&irec,sizeof(Index),1,idxfile))==1)
		printf("\t%5d%6d\n",irec.no,irec.offset);
	fclose(idxfile);
}
void ReadIndexFile(Index idx[MaxRec],int &n)	//�������ļ����ݴ���idx������
{
	int j;
	FILE *idxfile;
	if ((idxfile=fopen("index.dat","rb"))==NULL) 
	{
	    printf("  ��ʾ:�����ļ����ܴ�\n");
		return;
	}
	fseek(idxfile,0,2); 
	j=ftell(idxfile);    	//j����ļ�����
	rewind(idxfile);
	n=j/sizeof(Index); 		//n����ļ��еļ�¼����
	fread(idx,sizeof(Index),n,idxfile);
	fclose(idxfile);
}
int SearchNum(Index idx[],int n,int no)	//�ں���n����¼�������ļ�idx�в���ѧ��Ϊno�ļ�¼��Ӧ�ļ�¼��
{
	int mid,low=0,high=n-1;
	while (low<=high)    				//���ֲ���
	{
		mid=(low+high)/2;
		if (idx[mid].no>no) 
			high=mid-1;
		else if (idx[mid].no<no) 
			low=mid+1;
		else	//idx[mid].no==no
			return idx[mid].offset;
	}
	return -1;
}
void FindStudent()			//���ָ��ѧ�ŵļ�¼
{
	int no;
	FILE *mfile;
	Index idx[MaxRec];
	StudType st;
	int i,n;
	if ((mfile=fopen("stud.dat","rb+"))==NULL)
	{
		printf("  ��ʾ:���ļ���û���κμ�¼\n");
		return;
	}
	ReadIndexFile(idx,n);		//��ȡ��������idx
	printf("  ����ѧ��:");	
	scanf("%d",&no);		
	i=SearchNum(idx,n,no);		//��idx�в���
	if (i==-1)
		printf("  ��ʾ:ѧ��%d������\n",no);
	else 
	{
		fseek(mfile,(i-1)*sizeof(StudType),SEEK_SET); //�ɼ�¼��ֱ���������ļ��ж�Ӧ�ļ�¼
		fread(&st,sizeof(StudType),1,mfile);
		printf("%5d%10s%6d%5s%5d%5d%5d\n",st.no,st.name,st.age,st.sex,st.deg1,st.deg2,st.deg3);
	}
	fclose(mfile);
}
void WriteFile(int n)  //��st�����е�n��ѧ����¼д��stud.dat�ļ���
{
	StudType st[]={{1,"�»�",20,"��",78,90,84},
	{5,"����",21,"��",78,68,92},
	{8,"��Ӣ",20,"Ů",86,81,86},
	{3,"����",21,"Ů",78,92,88},
	{2,"���",20,"��",80,83,78},
	{4,"�¾�",20,"��",78,88,82},
	{7,"��ʤ",21,"��",56,67,75},
	{6,"��ǿ",20,"��",78,89,82}};
	int i;
	FILE *fp;
	if ((fp=fopen("stud.dat","wb"))==NULL)
	{	printf("\t��ʾ:���ܴ���stud.dat�ļ�\n");
		return;
	}
	for (i=0;i<n;i++)
		fwrite(&st[i],1,sizeof(StudType),fp);
	fclose(fp);
	printf("  ��ʾ:�ļ�stud.dat�������\n");
}
int main()
{
	int n=8,sel;		//nΪʵ��ѧ������
	printf("�������ļ�\n");
	WriteFile(n);		//�������ļ�
	do
	{
		printf("1:������ļ� 2:�������ļ� 3:��������ļ� 4:��ѧ�Ų��� 0:�˳�:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:
			OutputMainFile();
			break;
		case 2:
			CreatIdxFile();
			break;
		case 3:
			OutputIdxFile();
			break;
		case 4:
			FindStudent();
			break;
		}
	} while (sel!=0);
	return 1;
}
