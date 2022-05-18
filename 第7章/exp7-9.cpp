//�ļ���:exp7-9.cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 30			//ջ�����Ԫ�ظ���
#define NAMEWIDTH 10		//����������ַ�����
typedef struct fnode
{
	char father[NAMEWIDTH];	//��
	char wife[NAMEWIDTH];	//ĸ
	char son[NAMEWIDTH];	//��
} FamType;					//�����ļ��ļ�¼����
typedef struct tnode
{
	char name[NAMEWIDTH];
	struct tnode *lchild,*rchild;
} BTree;					//���׶��������������
int n;						//���׼�¼����
FamType fam[MaxSize];		//���׼�¼����
//----���׶����������㷨-----------------------------------
BTree *CreateBTree(char *root)	//��fam(��n����¼)�ݹ鴴��һ�ö�����
{
	int i=0,j;
	BTree *b,*p;
	b=(BTree *)malloc(sizeof(BTree));			//�������׽��
	strcpy(b->name,root);
	b->lchild=b->rchild=NULL;
	while (i<n && strcmp(fam[i].father,root)!=0) 
		i++;
	if (i<n)									//�ҵ��˸������ļ�¼
	{
		p=(BTree *)malloc(sizeof(BTree));		//����ĸ�׽��
		p->lchild=p->rchild=NULL;
		strcpy(p->name,fam[i].wife);
		b->lchild=p;
		for (j=0;j<n;j++)						//�����ж���
			if (strcmp(fam[j].father,root)==0)	//�ҵ�һ������
			{
				p->rchild=CreateBTree(fam[j].son);
				p=p->rchild;
			}
	}
	return(b);
}
void DispTree(BTree *b)	//�����ű�ʾ�����������
{
	if (b!=NULL)
	{
		printf("%s",b->name);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{
			printf("(");
			DispTree(b->lchild);
			if (b->rchild!=NULL) 
				printf(",");
			DispTree(b->rchild);
			printf(")");
		}
	}
}
BTree *FindNode(BTree *b,char xm[]) //��������ݹ��㷨��nameΪxm�Ľ��
{
	BTree *p;
	if (b==NULL) 
		return(NULL);
	else
	{
		if (strcmp(b->name,xm)==0)
			return(b);
		else
		{
			p=FindNode(b->lchild,xm);
			if (p!=NULL) 
				return(p);
			else 
				return(FindNode(b->rchild,xm));
		}
	}
}
void FindSon(BTree *b)		//���ĳ�˵����ж���
{
	char xm[NAMEWIDTH];
	BTree *p;
	printf("  >>��������:");
	scanf("%s",xm);
	p=FindNode(b,xm);
	if (p==NULL)
		printf("  >>������%s�ĸ���!\n",xm);
	else
	{
		p=p->lchild;
		if (p==NULL)
			printf("  >>%sû������\n",xm);
		else
		{
			p=p->rchild;
			if (p==NULL)
				printf("  >>%sû�ж���!\n",xm);
			else
			{
				printf("  >>%s�Ķ���:",xm);
				while (p!=NULL)
				{
					printf("%10s",p->name);
					p=p->rchild;
				}
				printf("\n");
			}
		} 
	}
}
int Path(BTree *b,BTree *s)		//���ú���ǵݹ������������Ӹ���㵽s����·��
{
	BTree *St[MaxSize];
	BTree *p;
	int i,top=-1;					//ջָ���ó�ֵ
	bool flag;
	do
	{
		while (b)                 	//��b���������½���ջ
		{	
			top++;
			St[top]=b;
			b=b->lchild;
		}
		p=NULL;                   	//pָ��ǰ����ǰһ���ѷ��ʵĽ��
		flag=true;					//flagΪ���ʾ���ڴ���ջ�����
		while (top!=-1 && flag)
		{	
			b=St[top];          	//ȡ����ǰ��ջ��Ԫ��
			if (b->rchild==p)		//�����������ڻ��ѱ�����,����֮
			{	if (b==s)			//��ǰ���ʵĽ��ΪҪ�ҵĽ��,���·��
				{	
					printf("  >>��������:");
					for (i=0;i<top;i++) 
					   	printf("%s ",St[i]->name);
					printf("\n");
				   	return 1;
				}
				else
				{	
					top--;
				   	p=b;			//pָ���򱻷��ʵĽ��
				}
			}
			else
			{	
				b=b->rchild;		//bָ��������
				flag=false;         //��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (top!=-1);				//ջ����ʱѭ��
	return 0;						//�������ʱ����0
}
void Ancestor(BTree *b)				//���ĳ�˵���������
{
	BTree *p;
	char xm[NAMEWIDTH];
	printf("  >>��������:");
	scanf("%s",xm);
	p=FindNode(b,xm);
	if (p!=NULL)
		Path(b,p);
	else
		printf("  >>������%s\n",xm);
}
void DestroyBTree(BTree *b)		//���ټ��׶�����
{
	if (b!=NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
		
//----�����ļ������㷨---------------------------------------------
void DelAll()					//��������ļ�ȫ����¼
{
	FILE *fp;
	if ((fp=fopen("fam.dat","wb"))==NULL) 
	{	
		printf("  >>���ܴ򿪼����ļ�\n");
		return;
	}
	n=0;
	fclose(fp);
}
void ReadFile()				//�������ļ�����fam������
{
	FILE *fp;
	long len;
	int i;
	if ((fp=fopen("fam.dat","rb"))==NULL) 
	{
		n=0;
		return;
	}
	fseek(fp,0,2);				//�����ļ�λ��ָ���Ƶ������ļ�β
	len=ftell(fp);    			//len��������ļ�����
	rewind(fp);					//�����ļ�λ��ָ���Ƶ������ļ���
	n=len/sizeof(FamType); 		//n��������ļ��еļ�¼����
	for (i=0;i<n;i++)
		fread(&fam[i],sizeof(FamType),1,fp);//�������ļ��е����ݶ���fam��
	fclose(fp);
}
void SaveFile()					//��fam����������ݼ����ļ�
{
	int i;
	FILE *fp;
	if ((fp=fopen("fam.dat","wb"))==NULL) 
	{	
		printf("  >>���ݼ����ļ����ܴ�\n");
		return;
	}
	for (i=0;i<n;i++)
		fwrite(&fam[i],sizeof(FamType),1,fp);
	fclose(fp);
}
void InputFam()					//���һ����¼
{
	printf("  >>���븸�ס�ĸ�׺Ͷ�������:");
	scanf("%s%s%s",fam[n].father,fam[n].wife,fam[n].son);
	n++;
}
void OutputFile()				//��������ļ�ȫ����¼
{
	int i;
	if (n<=0)
	{
		printf("  >>û���κμ�¼\n");
		return;
	}
	printf("         ����     ĸ��      ����\n");
	printf("       ------------------------------\n");
	for (i=0;i<n;i++)
		printf("  %10s%10s%10s\n",fam[i].father,fam[i].wife,fam[i].son);
	printf("       ------------------------------\n");
}
//---------------------------------------------------------------------
void Fileop()		//�����ļ�����
{
	int sel;
	do 
	{
		printf(" >1:���� 2:��� 9:ȫ�� 0:���̷��� ��ѡ��:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 9:
			DelAll();
			break;
		case 1:
			InputFam();
			break;
		case 2:
			OutputFile();
			break;
		case 0:
			SaveFile();
			break;
		} 
	} while (sel!=0);
}
void BTreeop()		//���׶���������
{
	BTree *b;
	int sel;
	if (n==0) return;				//���׼�¼Ϊ0ʱֱ�ӷ���
	b=CreateBTree(fam[0].father);
	do 
	{
		printf(" >1:���ű�ʾ�� 2.��ĳ�����ж��� 3.��ĳ���������� 0:���� ��ѡ��:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:
			printf("  >>");DispTree(b);printf("\n");
			break;
		case 2:
			FindSon(b);
			break;
		case 3:
			printf("  >>");Ancestor(b);
			break;
		} 
	} while (sel!=0);
	DestroyBTree(b);		//���ټ��׶�����
}
int main()
{
	BTree *b;
	int sel;
	ReadFile();
	do
	{	
		printf("*1.�ļ����� 2:���ײ��� 0:�˳� ��ѡ��:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 1:
			Fileop();
			break;
		case 2:
			BTreeop();
			break;
		}
	} while (sel!=0);
	return 1;
}
