#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>

typedef struct Adress_List//�洢��Ϣ�ṹ�� 
{
	char Name[20];//���� 
	char City[20];//���� 
	char Number[20];//�绰���� 
	int Dial_Time;//ͨ��ʱ�� 
	int Close_Score;//���ܶ� 
}AL;

typedef struct LL//����ṹ
{
	AL data;
	struct LL *nxt;
}LinkList;

char Name[20];//���� 
char City[20];//���� 
char Number[20];//�绰���� 
int Dial_Time;//ͨ������
int Close_Score;//���ܶ�

int Num;//��ϵ������
LinkList *L,*head;//����

void login();//��½���� 
void menu();//���ܲ˵� 
void Initail();//�����ʼ�� 
void Insert(LinkList *p);//�����½ڵ�
void Standardize(char str[]);//��ĸСд�� 
void Add();//�����ϵ�� 
void Delete();//ɾ����ϵ�� 
void Edit();// �༭��Ϣ 
void PrintAll();//��ӡ������ϵ�����ļ�����Ļ 
void Dial();//����绰����ʾͨ��ʱ�� 
void Fuzzy_Match();//ģ�����ң�������ң�
void FM_Name();
void FM_City();
void FM_Number();
void Sort_Close();//���ܶ�����
void Acquaintance_Possibility();//��ʶ����

int main()
{
	login();
	Initail();
	Sleep(1000);
	
	int Key_Print,Flag;
	while (1)
	{
		system("cls");
		menu();
		printf("��ѡ���ܣ�");
		Flag=scanf("%d",&Key_Print);
		getchar();
		if (Flag)
		switch(Key_Print)
	 	{
			case 0://�˳�
				printf("��ӭʹ�ã��ڴ��´ι��٣�");
				exit(0);
				return 0;
			case 1://���
				Add();
				break;
			case 2://��ӡ
				PrintAll();
				break;
			case 3://ɾ��
				Delete();
				break; 
			case 4://�༭
				Edit();
				break; 
			case 5://����绰
				Dial();
				break; 
			case 6://ģ������
				Fuzzy_Match();
				break;
			case 7://���ܶȲ�ѯ
				Sort_Close();
				break;
            case 8://��ʶ����
            	Acquaintance_Possibility();
				break;
			default:
				break;
		}
		else printf("�������\n");
		system("pause");
	}
	return 0;
}

void login()//��½����  
{ 
    while (1)
	{
 	    system("color b1");
		printf("\n");
    	printf("```````````````````````````````````````````````````````````````````````````");  
    	printf("\n");  
    	printf("\n");  
    	printf("\n");  
    	printf("   ***********************  ��ӭ��½����ͨѶ¼ *************************  \n");  
    	printf("\n");
		printf("\n");
    	printf("                           ---Created By GZN---                            \n");
    	printf("\n");
    	printf("\n");
    	printf("```````````````````````````````````````````````````````````````````````````");
		printf("\n");
		
		char LOG[20],PW[20];
		char log[3]={'g','z','n'},pw[3]={'1','2','3'};//�Զ����û�����
		printf("                              LoginName:");
		scanf("%s",LOG);
		printf("                              Password:");
		scanf("%s",PW);
		if (strcmp(LOG,log)==0&&strcmp(PW,pw)==0)
		{
			printf("��½�ɹ�����ӭʹ�ã�\n");
			return;
		}
		else
		{
			printf("\n");
			printf("                          �û���������������������룡\n");
			
			system("color F0");
			Sleep(200);
			system("color CD");
			Sleep(200);
			system("color A2");
			Sleep(200);//�û����������Ӿ���ʾ
			
			system("cls");
		}
	}
	return;
}  

void menu()//���ܲ˵�  
{
	//system("cls");
    system("color E1");
    printf("\n");
    printf("     ____________________________________________ \n");
    printf("    |                                            |\n");
    printf("    |                ����ͨѶ¼                  |\n");
    printf("    |                                            |\n");
    printf("    |             0���˳�ϵͳ                    |\n");
    printf("    |             1��������ϵ����Ϣ              |\n");
    printf("    |             2����ӡ��ϵ����Ϣ              |\n");
    printf("    |             3��ɾ����ϵ����Ϣ              |\n");
    printf("    |             4���޸���ϵ����Ϣ              |\n");
    printf("    |             5������绰                    |\n");
    printf("    |             6��ģ������                    |\n");
    printf("    |             7�����ܶ����м���ѯ            |\n");
    printf("    |             8����ʶ����                    |\n");
    printf("    |                                            |\n");
    printf("    |____________________________________________|\n");
    return;
}

void Initail()//�����ʼ��
{
	head=(LinkList*)malloc(sizeof(LinkList));
	L=(LinkList*)malloc(sizeof(LinkList));//ͷ�ڵ�����ռ�
	head->nxt=L;
	L->nxt=NULL;
	return; 
} 

void Insert(LinkList *New)//�����½ڵ�
{
	LinkList *Old=NULL;
	Old=L;
	New->nxt=Old->nxt;
	Old->nxt=New;
	New->data.Dial_Time=0;
    New->data.Close_Score=0;
	return;
}

void Standardize(char str[])//��ĸСд��
{
	int i,len=strlen(str);
	for (i=0;i<len;i++)
	{
		if (*(str+i)>='A'&&*(str+i)<='Z')
		*(str+i)=*(str+i)-'A'+'a';
	}
	return;
}

void Add()//�����ϵ��
{
	system("color fa");
    printf("��������ϵ�˵���Ϣ��\n");  
    printf("������"); 
    scanf("%s",Name);
    Standardize(Name);
    LinkList *q=L->nxt;
    while(q!=NULL)
    {  
        if(strcmp(q->data.Name,Name)==0)//�ж��Ƿ����  
        {
            printf("�����Ѵ���\n");  
            return;
        }
        q=q->nxt;
    }  
    if(q==NULL)  
    {  
        LinkList *p;  
        p=(LinkList*)malloc(sizeof(LinkList));
		p->nxt=NULL; 
		
        strcpy(p->data.Name,Name);  
        
        printf("���У�") ;  
        scanf("%s",City) ;
        Standardize(City);
        strcpy(p->data.City,City);
        
        printf("�绰��");  
        scanf("%s",Number);
        Standardize(Number);
        strcpy(p->data.Number,Number);
        
        Insert(p);//����p�ڵ�
        printf("�����ϵ�˳ɹ���\n");
    }
    return;
}

void Delete()//ɾ����ϵ��
{
	system("color f4");
    if (L->nxt==NULL)
    {  
        printf("ͨѶ¼Ϊ��,��������ϵ����Ϣ\n");  
        return;
    }
	printf("��������Ҫɾ������ϵ�˵�����:");
    scanf("%s",Name);
    Standardize(Name);
    LinkList *p,*pre;
    pre=L;
    p=pre->nxt;
    int judge=0;
    while (p!=NULL)
    {
 		if (strcmp(p->data.Name,Name)==0)
    	{
        	judge=1;
			pre->nxt=p->nxt;//ǰ���������̽��
			free(p);//�ͷ��ڴ�
			printf("ɾ����ϵ�˳ɹ���\n");
			break;
        }
        pre=p;
        p=p->nxt;//��һ�ƽ�Ѱ��
    } 
    if (judge==0)
	{
		printf("����ϵ�˲����ڣ����������룡\n");
		return;
	}
    return;
}

void Edit()// �༭��Ϣ
{
	system("color 0A");
	if (L->nxt==NULL)
    {
        printf("ͨѶ¼Ϊ��,��������ϵ����Ϣ\n");  
        return;
    }
    printf("��������Ҫ�༭����ϵ�˵�����:");
    scanf("%s",Name);
    Standardize(Name);
    LinkList *ed=L;
    int choice;
	while (ed!=NULL)
	{
		if (strcmp(ed->data.Name,Name)==0)
		{
			do
			{
                printf("��������Ҫ�༭����ϵ�˵���Ϣ\n");
				printf("������1�����У�2���绰��3���޸�����˳���0��:");//���ֱ༭��Ϣ
				scanf("%d",&choice);
				printf("�����޸�Ϊ:");
				switch(choice)
				{
					case 1:
						scanf("%s",Name);
						Standardize(Name);
						strcpy(ed->data.Name,Name);
						break;
					case 2:
						scanf("%s",City);
						Standardize(City);
						strcpy(ed->data.City,City);
						break;
					case 3:
						scanf("%s",Number);
						Standardize(Number);
						strcpy(ed->data.Number,Number);
						break;
					default:
						return;
				}
				printf("�༭�ɹ���\n");
				choice=0;
				scanf("%d",&choice);
			}while (choice!=0);
			return;
		}
		ed=ed->nxt;
	}
	printf("����ϵ�˲����ڣ�����������\n");
	return;
}

void PrintAll()//��ӡ������ϵ��
{
	system("color 0E");
	int choice;
	printf("��ѡ���ӡ����Ļ��1�����ļ���2����");
	scanf("%d",&choice);
	if (choice!=1&&choice!=2) return;
	if (choice==2) freopen("Adress_List.txt","w",stdout);//��ӡͨѶ¼���ļ�
	LinkList *i,*j;
	AL t;
	for (i=L->nxt;i!=NULL;i=i->nxt)//���ֵ����С��������
	{
		for (j=i->nxt;j!=NULL;j=j->nxt)
		if (i->data.Name>j->data.Name)
		{
			t=i->data;
			i->data=j->data;
			j->data=t;
		}
	}
	LinkList *p=L,*q;
	int k=0;
	while (p->nxt!=NULL)
	{
		q=p->nxt;
		printf("%d:%5s %5s %11s\n",++k,q->data.Name,q->data.City,q->data.Number);
		p=q;
	}
	printf("�ɹ���ӡ��ϵ����");
	if (choice=='2')
	{
		fclose(stdout);
		printf("�ļ�");
	}
	else printf("��Ļ");
	printf("��\n");
	return;
}

void Dial()//����绰����ʾͨ��ʱ��
{
	system("color 70");
	if(L->nxt==NULL)
    {
        printf("ͨѶ¼Ϊ��,��������ϵ����Ϣ\n");  
        return;
    }
    
	printf("��������Ҫ���е��û�������");
	scanf("%s",Name);
	Standardize(Name);
	LinkList *p=L;
	while (p!=NULL)
	{
		if (strcmp(p->data.Name,Name)==0) break;
		p=p->nxt;
	}
	if (p==NULL)
	{
		printf("����ϵ�˲����ڣ������²��ң�\n");
		return;
	}
	
	clock_t start,finish;
	start=clock();//ͨ����ʼʱ��
	printf("����ͨ��...\n");
	system("pause");
	finish=clock();//ͨ������ʱ��
	int duration=(int)(finish-start)/CLOCKS_PER_SEC;//��¼ʱ���λΪ��
	
	printf("ͨ������,��л����ʹ��\n");
	Sleep(500);
	printf("����ͨ������%d��\n",duration+2);
	Sleep(500);
	
	p->data.Dial_Time+=duration+2;//�ۼ�ͨ��ʱ��
	printf("���͸���ϵ��һ��ͨ��%d��\n",p->data.Dial_Time);
	return;
}

void Fuzzy_Match()//ģ�����ң�������ң�
{
	system("color 5E");
	printf("��������Ҫƥ�����Ϣ���ͣ�������1�����У�2���绰��3��\n");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			FM_Name();//����ƥ��
			break;
		case 2:
			FM_City();//����ƥ��
			break;
		case 3:
			FM_Number();//�绰ƥ��
			break;
	}
	return;
}

void FM_Name()
{
	printf("��������Ҫƥ�������\n");
	scanf("%s",Name);
	Standardize(Name);
	int l1=strlen(Name),l2,i,j,flag,cnt=0;
	LinkList *p=L;
	while (p!=NULL)
	{
		l2=strlen(p->data.Name);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (Name[j]!=p->data.Name[i+j]) flag=0;//����ƥ������
			}
			if (flag)
			{
				printf("%d:%5s\n",++cnt,p->data.Name);
				break;
			}
		}
		p=p->nxt;
	}
	if (cnt==0)
	{
		printf("û�д洢������ҵ���ϵ�ˣ������²��ң�\n");
		return;
	}
	int choice;
	printf("��ѡ��������ҵ���ϵ�˱�ţ�");
	scanf("%d",&choice);
	while (choice>cnt||choice<1)
	{
		printf("�����Ŵ������������룡");
		scanf("%d",&choice);
	}
	p=head->nxt;
	cnt=0;
	while (p!=NULL)
	{
		l2=strlen(p->data.Name);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (Name[j]!=p->data.Name[i+j]) flag=0;
			}
			if (flag)
			{
				cnt++;
				if (cnt==choice)//�ҵ��û����ѯ����ϵ��
				{
					printf("%5s %5s %15s\n",p->data.Name,p->data.City,p->data.Number);
					return;
				}
			}
		}
		p=p->nxt;
	}
	return;
}

void FM_City()
{
	printf("��������Ҫƥ��ĳ���\n");
	scanf("%s",City);
	Standardize(City);
	int l1=strlen(City),l2,i,j,flag,cnt=0;
	LinkList *p=L;
	while (p!=NULL)
	{
		l2=strlen(p->data.City);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (City[j]!=p->data.City[i+j]) flag=0;
			}
			if (flag)
			{
				printf("%d:%5s\n",++cnt,p->data.Name);
				break;
			}
		}
		p=p->nxt;
	}
	if (cnt==0)
	{
		printf("û�д洢������ҵ���ϵ�ˣ������²��ң�\n");
		return;
	}
	int choice;
	printf("��ѡ��������ҵ���ϵ�˱�ţ�");
	scanf("%d",&choice);
	while (choice>cnt||choice<1)
	{
		printf("�����Ŵ������������룡");
		scanf("%d",&choice);
	}
	p=head->nxt;
	cnt=0;
	while (p!=NULL)
	{
		l2=strlen(p->data.City);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (City[j]!=p->data.City[i+j]) flag=0;
			}
			if (flag)
			{
				cnt++;
				if (cnt==choice)
				{
					printf("%5s %5s %15s\n",p->data.Name,p->data.City,p->data.Number);
					return;
				}
			}
		}
		p=p->nxt;
	}
	return;
}

void FM_Number()
{
	printf("��������Ҫƥ��ĵ绰\n");
	scanf("%s",Number);
	Standardize(Number);
	int l1=strlen(Number),l2,i,j,flag,cnt=0;
	LinkList *p=L;
	while (p!=NULL)
	{
		l2=strlen(p->data.Number);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (Number[j]!=p->data.Number[i+j]) flag=0;
			}
			if (flag)
			{
				printf("%d:%5s\n",++cnt,p->data.Name);
				break;
			}
		}
		p=p->nxt;
	}
	if (cnt==0)
	{
		printf("û�д洢������ҵ���ϵ�ˣ������²��ң�\n");
		return;
	}
	int choice;
	printf("��ѡ��������ҵ���ϵ�˱�ţ�");
	scanf("%d",&choice);
	while (choice>cnt||choice<1)
	{
		printf("�����Ŵ������������룡");
		scanf("%d",&choice);
	}
	p=head->nxt;
	cnt=0;
	while (p!=NULL)
	{
		l2=strlen(p->data.Number);
		for (i=0;i<=l2-l1;i++)
		{
			flag=1;
			for (j=0;j<l1;j++)
			{
				if (Number[j]!=p->data.Number[i+j]) flag=0;
			}
			if (flag)
			{
				cnt++;
				if (cnt==choice)
				{
					printf("%5s %5s %15s\n",p->data.Name,p->data.City,p->data.Number);
					return;
				}
			}
		}
		p=p->nxt;
	}
	return;
}

void Sort_Close()//���ܶ�����
{
	system("color CF");
	if(L->nxt==NULL)
    {
        printf("ͨѶ¼Ϊ��,��������ϵ����Ϣ\n");
        return;
    }
	LinkList *i,*j;
	AL t;//��Ϣ�洢����
	int Sum_Dial=0,k=0;
	for (i=L->nxt;i!=NULL;i=i->nxt) Sum_Dial+=i->data.Dial_Time;//�ۼ��û���ͨ��ʱ��
	if (Sum_Dial==0)//δͨ���޷��������ܶ�
	{
		printf("����ͨ����¼Ϊ�գ�\n");
		return;
	}
	for (i=L->nxt;i!=NULL;i=i->nxt)
	i->data.Close_Score=min(99,i->data.Dial_Time*100/Sum_Dial+rand()%20+20);
	for (i=L->nxt;i!=NULL;i=i->nxt)//���ܶ�����
	{
		for (j=i->nxt;j!=NULL;j=j->nxt)
		if (i->data.Close_Score<j->data.Close_Score)
		{
			t=i->data;
			i->data=j->data;
			j->data=t;
		}
	}
	for (i=L->nxt;i!=NULL;i=i->nxt)
	printf("Rank%d:%5s  Dial:%4d  Close_Score:%2d%%\n",++k,i->data.Name,i->data.Dial_Time,i->data.Close_Score);
	return;
}

void Acquaintance_Possibility()//��ʶ����
{
	system("color F0");
	printf("������������ϵ�������������������ʶ�ĸ��ʣ�\n");
	int poss=rand()%10;
	char n1[20],n2[20];
	LinkList *i,*j;
	printf("�������һ����ϵ������:");
	scanf("%s",n1);
	for (i=L->nxt;i!=NULL;i=i->nxt)
	if (strcmp(i->data.Name,n1)==0) break;//Ѱ��Ŀ����ϵ�˴洢���
	if (i==NULL)
	{
		printf("����ϵ�˲����ڣ�\n");
		return;
	}
	printf("������ڶ�����ϵ������:");
	scanf("%s",n2);
	if (strcmp(n1,n2)==0)
	{
		printf("������ϵ����ͬ���������\n");
		return;
	}
	for (j=L->nxt;j!=NULL;j=j->nxt)
	if (strcmp(j->data.Name,n2)==0) break;
	if (j==NULL)
	{
		printf("����ϵ�˲����ڣ�\n");
		return;
	}
	if (strcmp(i->data.City,j->data.City)==0) poss+=20+rand()%50;//���ʹ�ʽ������ʶ����
	printf("������ʶ�ĸ���Ϊ��%d%%\n",poss);
	return;
}
