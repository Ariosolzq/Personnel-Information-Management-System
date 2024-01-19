 #include <stdio.h>
#include <windows.h> 
#include <string.h>
/*1.����һ���ṹ��*/ 
struct doctor 
{
	char num[20];     //����
	char name[10];    //����
	char sex[10];      //�Ա�ʹ������ʱ��Ҫ���ӳ��� 
	char age[5];      //����
	char addr[30];    //��ַ
	char tel[20];     //�绰
	char qq[20];      //QQ��
}doc[100];   

struct people 
{
	char num[20];     //���֤�ţ�Ϊ�˷����ڲ�����ʹ�ñ�ţ� 
	char name[10];    //����
	char sex[10];      //�Ա�
	char age[5];      //����
	char from[30];    //���� 
	char tes[5];      //�������� 
	char addr[30];    //��ַ
	char tel[20];     //�绰
	char qq[20];      //QQ��
}peo[100]; 

/*2.���������ܺ���*/
void mainMenu();   //���˵�
void menu_doc();   //ҽ����Ա�˵�
void menu_doc_doc();   //ҽ����Ա��Ϣ����˵�
void menu_doc_peo();   //��Ա�˵�
void menu_peo();   //������Ա�˵�
void save_doc(int);  //���� 
void save_peo(int);  //���� 
int  load_doc();  /*���뺯��*/ 
int  load_peo();  /*���뺯��*/ 
void display_doc();   //��� 
void display_peo();   //��� 
void del_doc();       //ɾ��
void del_peo();       //ɾ��
void add_doc();      //���
void add_peo_doc();      //���
void add_peo_peo();      //���
void search_doc();   //��ѯ
void search_doc_num();  //����Ż����֤�Ų�
void search_doc_name();  //��������
void search_peo();   //��ѯ
void search_peo_num();  //����Ż����֤�Ų�
void search_peo_name();  //��������
void search_peo_doc();   //������Ա��ѯ�����ҽ����Ա��Ϣ 
void search_tes();   //��ѯ��������Ϣ 
void search_peo_doc_num();//��ѯ��������Ϣ 
void search_peo_doc_name();//��ѯ��������Ϣ 
void modify_doc();     //�޸�
void modify_peo();     //�޸�
void modify_tes();     //�޸ĺ����� 

/*3.��ʽ��ʼ*/
void main()
{  
	printf("\n��ӭʹ�ù����з�����Ա����ϵͳ�������ˣ������ \n"); 
	printf("\n\n");   
	int n;   
	char a;
	mainMenu();   //���ò˵�����
	   
	 
		printf("��ѡ������Ҫ�����Ĳ���(1--3):\n");  
		scanf("%d",&n);  
		while(n<1&&n>3) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ����������ҽ����Ա�ˡ�����\n");
			printf("\n");
			menu_doc();
			break;         
		case 2:
			printf("             ���������뷵����Ա�ˡ�����\n");
			printf("\n");
			menu_peo();
			break;      
		case 3:
			printf("               �������˳�ϵͳ������\n");
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			mainMenu();
			/*�������˵�����*/   
			printf("���ٴ�ѡ������Ҫ�����Ĳ���(1--3):\n");  
			scanf("%d",&n);    
			printf("\n"); 
		}   
		else  
			exit(0);
	}	
} 


void mainMenu()/*���˵�*/
{
    printf("        *******��ӭ������������������Ϣ����ϵͳ*******\n"); 
    printf("           1.ҽ����Ա��\n");
    printf("           2.������Ա��\n");
    printf("           3.�˳�ϵͳ\n");
    printf("        ********************ллʹ��******************\n"); 
}

void menu_doc()   /*�˵�����*/
{
	printf("        *******************ҽ����Ա��*****************\n"); 
    printf("           1.ҽ����Ա��Ϣ����\n");
    printf("           2.������Ա��Ϣ����\n");
    printf("           3.�������˵�\n");
    printf("           4.�˳�ϵͳ\n");
	printf("        ********************ллʹ��******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("��ѡ������Ҫ�����Ĳ���(1--3):\n");  
		scanf("%d",&n);  
		while(n<1&&n>3) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("           ������ҽ����Ա��Ϣ���������\n");
			menu_doc_doc();
			break;         
		case 2:
			printf("           ������������Ա��Ϣ���������\n");
			menu_doc_peo();
			break;     
		case 3:
            printf("             �������������˵�������\n");
			main();
			break;  
		case 4:
			printf("               �������˳�ϵͳ������\n");
			exit(0);
			break;      
		default :
			break;
		} 
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			menu_doc();
		}   
		else  
			exit(0);  
	}
} 

void menu_doc_doc()   /*�˵�����*/
{
	printf("        ****************ҽ����Ա��Ϣ����**************\n"); 
	printf("           1.���ҽ����Ա��Ϣ\n");
	printf("           2.�������ҽ����Ա��Ϣ\n");  
	printf("           3.��ѯҽ����Ա��Ϣ\n"); 
	printf("           4.ɾ��ҽ����Ա��Ϣ\n");  
	printf("           5.�޸�ҽ����Ա��Ϣ\n"); 
    printf("           6.����ҽ����Ա��\n"); 
	printf("           7.�������˵�\n");  
	printf("           8.�˳�ϵͳ\n");   
	printf("        ********************ллʹ��******************\n"); 
	printf("\n");  
	printf("\n");  
	
	int n;   
	char a;
	   
		printf("��ѡ������Ҫ�����Ĳ���(1--8):\n");  
		scanf("%d",&n);  
		while(n<1&&n>8) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ���������ҽ����Ա��Ϣ������\n");
			printf("\n");
			add_doc();
			break;         
		case 2:
			printf("             �������������ҽ����Ա��Ϣ������\n");
			printf("\n");
			display_doc();
			break;        
		case 3:
			printf("             ��������ѯҽ����Ա��Ϣ������\n");
			printf("\n");
			search_doc();
			break;       
		case 4:
			printf("             ������ɾ��ҽ����Ա��Ϣ������\n");
			printf("\n");
			del_doc();
			break;        
		case 5:
			printf("             �������޸�ҽ����Ա��Ϣ������\n");
			printf("\n");
			modify_doc();
			break;  
		case 6:
			printf("             ����������ҽ����Ա�ˡ�����\n");
			menu_doc(); 
			break;    
		case 7:
			printf("             �������������˵�������\n");
			main(); 
			break;      
		case 8:
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			menu_doc_doc();
			/*���ò˵�����*/   
		}   
		else  
			exit(0);
	} 
}  

void menu_doc_peo()   /*�˵�����*/
{
	printf("        ****************������Ա��Ϣ����**************\n"); 
	printf("           1.��ӷ�����Ա��Ϣ\n");
	printf("           2.������з�����Ա��Ϣ\n");  
	printf("           3.��ѯ������Ա��Ϣ\n"); 
	printf("           4.ɾ��������Ա��Ϣ\n");  
	printf("           5.�޸ķ�����Ա��Ϣ\n");  
	printf("           6.���·�����Ա������\n");  
    printf("           7.����ҽ����Ա��\n"); 
	printf("           8.�������˵�\n");  
	printf("           9.�˳�ϵͳ\n");    
	printf("        ********************ллʹ��******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("��ѡ������Ҫ�����Ĳ���(1--9):\n");  
		scanf("%d",&n);  
		while(n<1&&n>9) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ��������ӷ�����Ա��Ϣ������\n");
			printf("\n");
			add_peo_doc();
			break;         
		case 2:
			printf("             ������������з�����Ա��Ϣ������\n");
			printf("\n");
			display_peo();
			break;        
		case 3:
			printf("             ��������ѯ������Ա��Ϣ������\n");
			printf("\n");
			search_peo();
			break;       
		case 4:
			printf("             ������ɾ��������Ա��Ϣ������\n");
			printf("\n");
			del_peo();
			break;        
		case 5:
			printf("             �������޸ķ�����Ա��Ϣ������\n");
			printf("\n");
			modify_peo();
			break;  
		case 6:
			printf("             ���������·�����Ա������������\n");
			printf("\n");
			modify_tes();
			break;
		case 7:
			printf("             ����������ҽ����Ա�ˡ�����\n");
			menu_doc(); 
			break;    
		case 8:
			printf("             �������������˵�������\n");
			main(); 
			break;      
		case 9:
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			menu_doc_peo();
			/*���ò˵�����*/   
		}   
		else  
			exit(0);
	}
}

void menu_peo()   /*�˵�����*/
{
	printf("        *******************������Ա��*****************\n"); 
	printf("           1.����������Ա��Ϣ\n");
	printf("           2.��ѯ������Ա��Ϣ\n");  
	printf("           3.��ѯ����������Ϣ\n"); 
	printf("           4.��ѯ��������Ϣ\n");  
	printf("           5.�������˵�\n");  
	printf("           6.�˳�ϵͳ\n");      
	printf("        ********************ллʹ��******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("��ѡ������Ҫ�����Ĳ���(1--6):\n");  
		scanf("%d",&n);  
		while(n<1&&n>6) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ����������������Ա��Ϣ������\n");
			printf("\n");
			add_peo_peo();
			break;         
		case 2:
			printf("             ��������ѯ������Ա��Ϣ������\n");
			printf("\n");
			search_peo();
			break;        
		case 3:
			printf("             ��������ѯ����������Ϣ������\n");
			printf("\n");
			search_tes();
			break;       
		case 4:
			printf("             ��������ѯ��������Ϣ������\n");
			printf("\n");
			search_peo_doc();
			break;        
		case 5:
			printf("             �������������˵�������\n");
			main(); 
			break;      
		case 6:
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			menu_peo();
			/*���ò˵�����*/   
		}   
		else  
			exit(0);
	}
}  

void save_doc(int m)  /*�����ļ�����*/ 
{
	int i;   
	FILE*fp;   
	fp=fopen("D:\\doc.txt","wb");
	for (i=0;i<m;i++) /*���ڴ���ҽ����Ա����Ϣ����������ļ���ȥ*/  
		if (fwrite(&doc[i],sizeof(struct doctor),1,fp)!=1)   
			printf("file write error\n");    fclose(fp);
}  

void save_peo(int m)  /*�����ļ�����*/ 
{
	int i;   
	FILE*fp;   
	fp=fopen("D:\\peo.txt","wb");
	for (i=0;i<m;i++) /*���ڴ��з�����Ա����Ϣ����������ļ���ȥ*/  
		if (fwrite(&peo[i],sizeof(struct people),1,fp)!=1)   
			printf("file write error\n");    fclose(fp);
}  

int load_doc()  /*����+�ⳤ�Ⱥ���*/ 
{ 
	FILE*fp;   
	int i=0;  
	if((fp=fopen("D:\\doc.txt","rb"))==NULL)/*�ж��Ƿ��ܴ�*/  
	{ 
		  return 0;
    }   
	else  
	{  
		do   
		{  
			fread(&doc[i],sizeof(struct doctor),1,fp);     //���ļ������� 
			i++;             //˳���������
		}      
		while(feof(fp)==0);   //�ж��ļ��Ƿ����
	}      
	fclose(fp);   //���ļ�����
	return(i-1);   //�����ļ�����
}  

int load_peo()  /*����+�ⳤ�Ⱥ���*/ 
{ 
	FILE*fp;   
	int i=0;  
	if((fp=fopen("D:\\peo.txt","rb"))==NULL)/*�ж��Ƿ��ܴ�*/  
	{ 
		  return 0;
    }   
	else  
	{  
		do   
		{  
			fread(&peo[i],sizeof(struct people),1,fp);     //���ļ������� 
			i++;             //˳���������
		}      
		while(feof(fp)==0);   //�ж��ļ��Ƿ����
	}      
	fclose(fp);   //���ļ�����
	return(i-1);   //�����ļ�����
}  

void display_doc()  /*�������*/
{
	int i;  
	int m=load_doc();
	for(i=0;i<m;i++)
	{
	   printf(" ���            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
       printf(" %s            %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
	   printf("\n");
	   printf("\n");
	}
} 

void display_peo()  /*�������*/
{
	int i;  
	int m=load_peo();
	for(i=0;i<m;i++)
	{
	   printf(" ���֤��            ����           �Ա�           ����          ����;������        ������            ��ַ            �绰           QQ��\n");
       printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);
	   printf("\n");
	   printf("\n");
	}
} 
void add_doc()/*��Ӻ���*/
{
	FILE*fp;  
	int n; /*����Ա���ĸ���*/    
	int i;     
	int m=load_doc();/*����һ���������ܺ����ķ���ֵ*/   
	printf("�����������ӵ�ҽ����Ա����:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*�ӵ�m�����鿪ʼ�����������������*/ 
	{
		printf("\n ������������ҽ����Ա����Ϣ:\n");  
	    printf("��������:  ");   
	    scanf("%s",&doc[i].num);     
	    printf("����������:  ");   
	    scanf("%s",doc[i].name);     
	    printf("�������Ա�:  ");
        scanf("%s",&doc[i].sex);
	    printf("����������:  ");  
	    scanf("%s",&doc[i].age);  
	    printf("������סַ:  ");  
	    scanf("%s",doc[i].addr); 
	    printf("������绰:  ");   
	    scanf("%s",doc[i].tel); 
		printf("������QQ:  ");   
	    scanf("%s",doc[i].qq); 
	    printf("\n");   
	}   
	printf("\n������!\n"); 
	m=m+n; /*��������*/       
	save_doc(m);/*���õ���Ա�������ص��ı���*/  
} 

void add_peo_doc()/*��Ӻ���*/
{
	FILE*fp;  
	int n; /*���ӷ�����Ա�ĸ���*/    
	int i;     
	int m=load_peo();/*����һ���������ܺ����ķ���ֵ*/   
	printf("�����������ӵķ�����Ա����:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*�ӵ�m�����鿪ʼ�����������������*/ 
	{
		printf("\n �����������ӷ�����Ա����Ϣ:\n");  
	    printf("���������֤��:  ");   
	    scanf("%s",&peo[i].num);     
	    printf("����������:  ");   
	    scanf("%s",peo[i].name);     
	    printf("�������Ա�:  ");
        scanf("%s",&peo[i].sex);
	    printf("����������:  ");  
	    scanf("%s",&peo[i].age); 
	    printf("�����뷵��;������:  ");  
	    scanf("%s",&peo[i].from); 
		printf("���������������δ�������д �� ��:  ");  
	    scanf("%s",peo[i].tes);   
	    printf("������סַ:  ");  
	    scanf("%s",peo[i].addr); 
	    printf("������绰:  ");   
	    scanf("%s",peo[i].tel); 
		printf("������QQ:  ");   
	    scanf("%s",peo[i].qq); 
	    printf("\n");   
	}   
	printf("\n������!\n"); 
	m=m+n; /*�ܷ�����Ա��*/       
	save_peo(m);/*���õ��ķ�����Ա�����ص��ı���*/  
} 

void add_peo_peo()/*��Ӻ���*/
{
	FILE*fp;  
	int n; /*���ӷ�����Ա�ĸ���*/    
	int i;     
	int m=load_peo();/*����һ���������ܺ����ķ���ֵ*/   
	printf("�������뱨���ķ�����Ա����:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*�ӵ�m�����鿪ʼ�����������������*/ 
	{
		printf("\n �����뱨��������Ա����Ϣ:\n");  
	    printf("���������֤��:  ");   
	    scanf("%s",&peo[i].num);     
	    printf("����������:  ");   
	    scanf("%s",peo[i].name);     
	    printf("�������Ա�:  ");
        scanf("%s",&peo[i].sex);
	    printf("����������:  ");  
	    scanf("%s",&peo[i].age); 
	    printf("�����뷵��;������:  ");  
	    scanf("%s",&peo[i].from); 
	    printf("������סַ:  ");  
	    scanf("%s",peo[i].addr); 
	    printf("������绰:  ");   
	    scanf("%s",peo[i].tel); 
		printf("������QQ:  ");   
	    scanf("%s",peo[i].qq); 
	    printf("\n");   
	}   
	printf("\n������!\n"); 
	m=m+n; /*�ܷ�����Ա��*/       
	save_peo(m);/*���õ��ķ�����Ա�����ص��ı���*/  
} 

void del_doc()   /*ɾ������*/ 
{
	int m=load_doc();  
	int i,j,n,t,flag;  
	char name[10];  
	printf("\n ԭ����ҽ����Ա��Ϣ:\n");   
	display_doc(); /*չʾ*/     
	printf("\n");  
	printf("������Ҫɾ����ҽ����Ա������:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++) 
	{
		if(strcmp(doc[i].name,name)==0)  
	      {
		    printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n"); 
			printf(" ���            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			printf("\nȷʵҪɾ��������Ϣ�밴1,��ɾ���밴0\n");    scanf("%d",&n);    
			if(n==1) 
			{
				for(j=i;j<m-1;j++)     //����ɾ����  
				{
					strcpy(doc[j].num,doc[j+1].num);  /*�ַ�������*/
					strcpy(doc[j].name,doc[j+1].name);                    
					strcpy(doc[j].sex,doc[j+1].sex);             
					strcpy(doc[j].age,doc[j+1].age);             
					strcpy(doc[j].addr,doc[j+1].addr);        
					strcpy(doc[j].tel,doc[j+1].tel);     
					strcpy(doc[j].qq,doc[j+1].qq);  
				}
                flag=0;    //����ѭ�� 
			}
             
		 } 
	 } 
	if(flag==0)     m=m-1; 
	else    
		printf("\n�Բ��𣬲��޴���!\n");       
	save_doc(m);     /*���ñ��溯��*/     
	printf("\n����ɾ���밴1������ɾ���밴0\n");  
	scanf("%d",&t);  
	switch(t)
	{ 
	case 1:
		del_doc();
		break;    
	case 0:
		break;   
	default :
		break; 
	} 
} 

void del_peo()   /*ɾ������*/ 
{
	int m=load_peo();  
	int i,j,n,t,flag;  
	char name[10];  
	printf("\n ԭ����Ա����Ϣ:\n");   
	display_peo();      
	printf("\n");  
	printf("������Ҫɾ����Ա��������:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++) 
	{
		if(strcmp(peo[i].name,name)==0)  
	      {
		    printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n"); 
	        printf(" ���֤��            ����           �Ա�           ����          ����;������        ������            ��ַ            �绰           QQ��\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			printf("\nȷʵҪɾ��������Ϣ�밴1,��ɾ���밴0\n");    scanf("%d",&n);    
			if(n==1) 
			{
				for(j=i;j<m-1;j++)     //����ɾ����  
				{
					strcpy(peo[j].num,peo[j+1].num);  /*�ַ�������*/
					strcpy(peo[j].name,peo[j+1].name);                    
					strcpy(peo[j].sex,peo[j+1].sex);             
					strcpy(peo[j].age,peo[j+1].age);             
					strcpy(peo[j].from,peo[j+1].from);    
					strcpy(peo[j].tes,peo[j+1].tes);             
					strcpy(peo[j].addr,peo[j+1].addr);    
					strcpy(peo[j].tel,peo[j+1].tel);     
					strcpy(peo[j].qq,peo[j+1].qq);  
				}
                flag=0;    //����ѭ�� 
			}
             
		 } 
	 } 
	if(flag==0)     m=m-1; 
	else    
		printf("\n�Բ��𣬲��޴���!\n");       
	save_peo(m);     /*���ñ��溯��*/     
	printf("\n����ɾ���밴1������ɾ���밴0\n");  
	scanf("%d",&t);  
	switch(t)
	{ 
	case 1:
		del_peo();
		break;    
	case 0:
		break;   
	default :
		break; 
	} 
} 

void search_doc()/*��ѯ����*/
{  
	int t,flag; 

	
		printf("\n1:����Ų�ѯ�밴     2:��������ѯ�밴 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*�����t������1����2*/   
		{
			printf("�����������������:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("����Ų�ѯ\n");
			search_doc_num();break;    
		case 2:
			printf("��������ѯ\n");
			search_doc_name();break;   
		default:break;  
		} 
} 
void search_doc_num()   //����Ų�ѯ����
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_doc();/*���ı�������������ݶ���*/ 
	printf("������Ҫ���ҵı��:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,doc[i].num)==0)/*�Ƚ�����ĺ��ı�������ַ���*/ 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
			printf(" ����            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			k=1;
		}     
		if(k==0)  
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
			{ 
		case 1:
			search_doc();
			break;   
		case 2: 
			break;

		default:break;  
		}
} 
void search_doc_name()   //��������ѯ
{
	char name[10];
	int i,t,k=0;  
	int m=load_doc();   
	printf("������Ҫ���ҵ�����:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(doc[i].name,name)==0) 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
			printf(" ���            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			k=1;						
		}     
		if(k==0) /*��¼Ա���治����*/ 
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
		{ 
		    case 1:
			search_doc();
			break;   
		    case 2: 
			break;
		    default:
			break;  
		}
}  

void search_peo()/*��ѯ����*/
{  
	int t,flag; 

	
		printf("\n1:�����֤�Ų�ѯ�밴     2:��������ѯ�밴 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*�����t������1����2*/   
		{
			printf("����������������:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("�����֤�Ų�ѯ\n");
			search_peo_num();break;    
		case 2:
			printf("��������ѯ\n");
			search_peo_name();break;   
		default:break;  
		} 
	
} 
void search_peo_num()   //�����֤�Ų�ѯ����
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_peo();/*���ı�������������ݶ���*/ 
	printf("������Ҫ���ҵ����֤��:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,peo[i].num))/*�Ƚ�����ĺ��ı�������ַ���*/ 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
			printf(" ���֤��            ����           �Ա�           ����          ����;������        ������            ��ַ            �绰           QQ��\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			k=1;
		}     
		if(k==0)  
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
			{ 
		case 1:
			search_peo();
			break;   
		case 2: 
			break;

		default:break;  
		}
} 
void search_peo_name()   //��������ѯ
{
	char name[10];
	int i,t,k=0;  
	int m=load_peo();   
	printf("������Ҫ���ҵ�����:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(peo[i].name,name)==0) 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
            printf(" ���֤��            ����           �Ա�           ����          ����;������        ������            ��ַ            �绰           QQ��\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			k=1;						
		}     
		if(k==0) /*��¼Ա���治����*/ 
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
			{ 
		case 1:
			search_peo();
			break;   
		case 2: 
			break;

		default:break;  
		}
}  

void search_tes()/*��ѯ����*/
{  
	printf("        ********************����������������******************\n"); 
	printf("           1.�����\n");
	printf("           2.������\n");  
	printf("           3.��ɽ��\n"); 
	printf("           4.������\n");  
	printf("           5.��ɽ��\n");  
	printf("           6.�ٹ���\n");  
	printf("\n");  
	printf("\n");  
	printf("        ************************����**************************\n"); 
	printf("           7.���ط�����Ա��\n");  
	printf("           8.�������˵�\n");  
	printf("           9.�˳�ϵͳ\n");  
	
	int n;   
	char a;
	   
		printf("��ѡ������Ҫ��ѯ������������Ĳ���(1--9):\n");  
		scanf("%d",&n);  
		while(n<1&&n>9) 
		{
			printf("����������������ѡ��!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ������1.�����������\n");
			printf("\n");
			printf("             ����ҽѧԺ����ҽԺ\n");
			break;         
		case 2:
			printf("             ������2.������������\n");
			printf("\n");
			printf("             ��������ҽԺ\n");
			break;        
		case 3:
			printf("             ������3.��ɽ��������\n");
			printf("\n");
			printf("             ������ϪɽҽԺ\n");
			break;       
		case 4:
			printf("             ������4.������������\n");
			printf("\n");
			printf("             ��ž���924ҽԺ\n");
			break;        
		case 5:
			printf("             ������5.��ɽ��������\n");
			printf("\n");
			printf("             ������ɽҽԺ\n");
			break;  
		case 6:
			printf("             ������6.�ٹ���������\n");
			printf("\n");
			printf("             ��������ҽԺ\n");
			break;
		case 7:
			printf("             ���������ط�����Ա�ˡ�����\n");
			menu_peo(); 
			break;    
		case 8:
			printf("             �������������˵�������\n");
			mainMenu(); 
			break;      
		case 9:
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("�Ƿ��������(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*����*/   
			search_tes();
			/*���ò˵�����*/   
		}   
		else  
			exit(0);
	}
} 

void search_peo_doc()
{  
	int t,flag; 

	
		printf("\n1:����Ų�ѯ�밴     2:��������ѯ�밴 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*�����t������1����2*/   
		{
			printf("�����������������:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("����Ų�ѯ\n");
			search_peo_doc_num();break;    
		case 2:
			printf("��������ѯ\n");
			search_peo_doc_name();break;   
		default:break;  
		} 
	
} 
void search_peo_doc_num()   //����Ų�ѯ����
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_doc();/*���ı�������������ݶ���*/ 
	printf("������Ҫ���ҵı��:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,doc[i].num))/*�Ƚ�����ĺ��ı�������ַ���*/ 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
			printf(" ����            ����           �Ա�         �绰           QQ��\n");
            printf(" %s               %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].tel,doc[i].qq);
			k=1;
		}     
		if(k==0)  
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
		{ 
		case 1:
			search_peo_doc();
			break;   
		case 2: 
			break;

		default:break;  
		}
} 
void search_peo_doc_name()   //��������ѯ
{
	char name[10];
	int i,t,k=0;  
	int m=load_doc();   
	printf("������Ҫ���ҵ�����:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(doc[i].name,name)==0) 
		{ 
			printf("\n���ҵ������¼Ϊ��\n");
			printf(" ����            ����           �Ա�         �绰           QQ��\n");
            printf(" %s               %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].tel,doc[i].qq);
			k=1;						
		}     
		if(k==0) /*��¼Ա���治����*/ 
			printf("\n�Բ��𣬲��޴���\n");  
		printf("\n");   
		printf("������ѯ�밴1,������ѯ�밴2\n"); 
		scanf("%d",&t);  
		switch(t)
		{ 
		    case 1:
			search_peo_doc();
			break;   
		    case 2: 
			break;
		    default:
			break;  
		}
}  

void modify_doc() /*�޸ĺ���*/
{ 
	char num[20];   
	char name[10];   
	char sex[10];     
	char age[5];      
	char addr[30];   
	char tel[20]; 
	char qq[20];
	int c,i,t,flag;  
	int m=load_doc();    
	printf("\n ԭ����Ա����Ϣ:\n"); 
	display_doc();   
	printf("\n"); 
	printf("������Ҫ�޸ĵ�Ա��������:\n"); 
	scanf("%s",name); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(doc[i].name,name)==0)
           { 
			   printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");    
			   
	           printf(" ���            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
               printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			  	 printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.��� 2.���� 3.�Ա� 4.���� 5.סַ 6.�绰  7:QQ��\n");         
				   printf("�����������޸ĵ���һ�����:\n");           
				   scanf("%d",&c);             
				   while(c>7||c<1)
				   {
					   printf("\nѡ�����������ѡ��!\n");
					   scanf("%d",&c);
				   }
			              
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n�Բ��𣬲��޴���!\n");  
	  if(flag==0)   
	 {
		 switch(c)      /*��Ϊ���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����*/  
		 { 
		 case 1:printf("���Ÿ�Ϊ: ");   
			 scanf("%s",num);    
			 strcpy(doc[i-1].num,num);      
			 break;         
		 case 2:printf("������Ϊ: ");  
			 scanf("%s",name);       
			 strcpy(doc[i-1].name,name);      
			 break;            
		 case 3:
			 printf("�Ա��Ϊ: "); 
              scanf("%s",sex);     
			  strcpy(doc[i-1].sex,sex); 
               break;    
		 case 4:
			 printf("�����Ϊ: ");   
			 scanf("%s",age);    
			 strcpy(doc[i-1].age,age);        
			 break;           
		 case 5:printf("סַ��Ϊ: ");  
			 scanf("%s",addr);      
			 strcpy(doc[i-1].addr,addr);     
			 break;             
		 case 6:printf("�绰��Ϊ: ");    
			 scanf("%s",tel);      
			 strcpy(doc[i-1].tel,tel);    
			 break;  
			 case 7:printf("QQ��Ϊ: ");    
			 scanf("%s",qq);      
			 strcpy(doc[i-1].qq,qq);    
			 break;  
		 }    
        printf("�޸ĳɹ�\n");
	 }      
	 save_doc(m);    
	 printf("\n�����޸��밴1�������޸��밴2\n");  
	 scanf("%d",&t);   
	 switch(t)   
	 { 
	 case 1:modify_doc();
		 break;  
	 case 2:
		 break;  
	 default :break;
	 } 
}

void modify_peo() /*�޸ĺ���*/
{ 
	char num[20];   
	char name[10];   
	char sex[10];     
	char age[5];      
	char addr[30];   
	char tel[20]; 
	char qq[20];
	int c,i,t,flag;  
	int m=load_peo();    
	printf("\n ԭ����Ա����Ϣ:\n"); 
	display_peo();   
	printf("\n"); 
	printf("������Ҫ�޸ĵ�Ա��������:\n"); 
	scanf("%s",name); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(peo[i].name,name)==0)
           { 
			   printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");    
			   
	           printf(" ���֤��            ����           �Ա�           ����            ��ַ            �绰           QQ��\n");
               printf(" %s               %s            %s              %s            %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].addr,peo[i].tel,peo[i].qq);
			  	 printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.��� 2.���� 3.�Ա� 4.���� 5.סַ 6.�绰  7:QQ��\n");         
				   printf("�����������޸ĵ���һ�����:\n");           
				   scanf("%d",&c);             
				   while(c>7||c<1)
				   {
					   printf("\nѡ�����������ѡ��!\n");
					   scanf("%d",&c);
				   }
			              
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n�Բ��𣬲��޴���!\n");  
	  if(flag==0)   
	 {
		 switch(c)      /*��Ϊ���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����*/  
		 { 
		 case 1:printf("���֤�Ÿ�Ϊ: ");   
			 scanf("%s",num);    
			 strcpy(peo[i-1].num,num);      
			 break;         
		 case 2:printf("������Ϊ: ");  
			 scanf("%s",name);       
			 strcpy(peo[i-1].name,name);      
			 break;            
		 case 3:
			 printf("�Ա��Ϊ: "); 
              scanf("%s",sex);     
			  strcpy(peo[i-1].sex,sex); 
               break;    
		 case 4:
			 printf("�����Ϊ: ");   
			 scanf("%s",age);    
			 strcpy(peo[i-1].age,age);        
			 break;           
		 case 5:printf("סַ��Ϊ: ");  
			 scanf("%s",addr);      
			 strcpy(peo[i-1].addr,addr);     
			 break;             
		 case 6:printf("�绰��Ϊ: ");    
			 scanf("%s",tel);      
			 strcpy(peo[i-1].tel,tel);    
			 break;  
			 case 7:printf("QQ��Ϊ: ");    
			 scanf("%s",qq);      
			 strcpy(peo[i-1].qq,qq);    
			 break;  
		 }    
        printf("�޸ĳɹ�\n");
	 }      
	 save_peo(m);    
	 printf("\n�����޸��밴1�������޸��밴2\n");  
	 scanf("%d",&t);   
	 switch(t)   
	 { 
	 case 1:modify_peo();
		 break;  
	 case 2:
		 break;  
	 default :break;
	 } 
}

void modify_tes() /*�޸ĺ���*/
{   
	char num[20];  
	char tes[5];      
	int c,i,t,flag;  
	int m=load_peo();    
	printf("\n ԭ���ķ�����Ա��Ϣ:\n"); 
	display_peo();   
	printf("\n"); 
	printf("�����뷵����Ա�����֤��:\n"); 
	scanf("%s",num); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(peo[i].num,num)==0)
           { 
			   printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");    
               printf(" ���֤��            ����           �Ա�           ����            ������            ��ַ            �绰           QQ��\n");
               printf(" %s                  %s            %s              %s            %s          %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);
  
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n�Բ��𣬲��޴���!\n");  
	  if(flag==0)   
	 {
		  /*��Ϊ���ҵ���i��ְ��ʱ,for����i�Լ���1,���������Ӧ�ðѸĺ����Ϣ��ֵ����i-1����*/  
			 printf("������Ϊ: "); 
              scanf("%s",tes);     
			  strcpy(peo[i-1].tes,tes);  
		 
        printf("�޸ĳɹ�\n");
	 }      
	 save_peo(m);    
	 printf("\n�����޸��밴1�������޸��밴2\n");  
	 scanf("%d",&t);   
	 switch(t)   
	 { 
	 case 1:modify_tes();
		 break;  
	 case 2:
		 break;  
	 default :break;
	 } 
}


