 #include <stdio.h>
#include <windows.h> 
#include <string.h>
/*1.定义一个结构体*/ 
struct doctor 
{
	char num[20];     //工号
	char name[10];    //姓名
	char sex[10];      //性别，使用中文时需要增加长度 
	char age[5];      //年龄
	char addr[30];    //地址
	char tel[20];     //电话
	char qq[20];      //QQ号
}doc[100];   

struct people 
{
	char num[20];     //身份证号（为了方便在测试中使用编号） 
	char name[10];    //姓名
	char sex[10];      //性别
	char age[5];      //年龄
	char from[30];    //来自 
	char tes[5];      //核酸检测结果 
	char addr[30];    //地址
	char tel[20];     //电话
	char qq[20];      //QQ号
}peo[100]; 

/*2.声明各功能函数*/
void mainMenu();   //主菜单
void menu_doc();   //医护人员菜单
void menu_doc_doc();   //医护人员信息管理菜单
void menu_doc_peo();   //人员菜单
void menu_peo();   //返乡人员菜单
void save_doc(int);  //保存 
void save_peo(int);  //保存 
int  load_doc();  /*导入函数*/ 
int  load_peo();  /*导入函数*/ 
void display_doc();   //浏览 
void display_peo();   //浏览 
void del_doc();       //删除
void del_peo();       //删除
void add_doc();      //添加
void add_peo_doc();      //添加
void add_peo_peo();      //添加
void search_doc();   //查询
void search_doc_num();  //按编号或身份证号查
void search_doc_name();  //按姓名查
void search_peo();   //查询
void search_peo_num();  //按编号或身份证号查
void search_peo_name();  //按姓名查
void search_peo_doc();   //返乡人员查询负责的医护人员信息 
void search_tes();   //查询核酸检测信息 
void search_peo_doc_num();//查询负责人信息 
void search_peo_doc_name();//查询负责人信息 
void modify_doc();     //修改
void modify_peo();     //修改
void modify_tes();     //修改核酸结果 

/*3.正式开始*/
void main()
{  
	printf("\n欢迎使用桂林市防疫人员管理系统，开发人：林子淇 \n"); 
	printf("\n\n");   
	int n;   
	char a;
	mainMenu();   //调用菜单函数
	   
	 
		printf("请选择你需要操作的步骤(1--3):\n");  
		scanf("%d",&n);  
		while(n<1&&n>3) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ◆◆◆进入医护人员端◆◆◆\n");
			printf("\n");
			menu_doc();
			break;         
		case 2:
			printf("             ◆◆◆进入返乡人员端◆◆◆\n");
			printf("\n");
			menu_peo();
			break;      
		case 3:
			printf("               ◆◆◆退出系统◆◆◆\n");
			exit(0);
			break;      
		default :
			break;
		}   
		getchar(); 
		printf("\n");  
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			mainMenu();
			/*调用主菜单函数*/   
			printf("请再次选择你需要操作的步骤(1--3):\n");  
			scanf("%d",&n);    
			printf("\n"); 
		}   
		else  
			exit(0);
	}	
} 


void mainMenu()/*主菜单*/
{
    printf("        *******欢迎进入桂林市疫情防控信息管理系统*******\n"); 
    printf("           1.医护人员端\n");
    printf("           2.返乡人员端\n");
    printf("           3.退出系统\n");
    printf("        ********************谢谢使用******************\n"); 
}

void menu_doc()   /*菜单函数*/
{
	printf("        *******************医护人员端*****************\n"); 
    printf("           1.医护人员信息管理\n");
    printf("           2.返乡人员信息管理\n");
    printf("           3.返回主菜单\n");
    printf("           4.退出系统\n");
	printf("        ********************谢谢使用******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("请选择你需要操作的步骤(1--3):\n");  
		scanf("%d",&n);  
		while(n<1&&n>3) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("           ◆◆◆医护人员信息管理◆◆◆\n");
			menu_doc_doc();
			break;         
		case 2:
			printf("           ◆◆◆返乡人员信息管理◆◆◆\n");
			menu_doc_peo();
			break;     
		case 3:
            printf("             ◆◆◆返回主菜单◆◆◆\n");
			main();
			break;  
		case 4:
			printf("               ◆◆◆退出系统◆◆◆\n");
			exit(0);
			break;      
		default :
			break;
		} 
		getchar(); 
		printf("\n");  
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			menu_doc();
		}   
		else  
			exit(0);  
	}
} 

void menu_doc_doc()   /*菜单函数*/
{
	printf("        ****************医护人员信息管理**************\n"); 
	printf("           1.添加医护人员信息\n");
	printf("           2.浏览所有医护人员信息\n");  
	printf("           3.查询医护人员信息\n"); 
	printf("           4.删除医护人员信息\n");  
	printf("           5.修改医护人员信息\n"); 
    printf("           6.返回医护人员端\n"); 
	printf("           7.返回主菜单\n");  
	printf("           8.退出系统\n");   
	printf("        ********************谢谢使用******************\n"); 
	printf("\n");  
	printf("\n");  
	
	int n;   
	char a;
	   
		printf("请选择你需要操作的步骤(1--8):\n");  
		scanf("%d",&n);  
		while(n<1&&n>8) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ◆◆◆添加医护人员信息◆◆◆\n");
			printf("\n");
			add_doc();
			break;         
		case 2:
			printf("             ◆◆◆浏览所有医护人员信息◆◆◆\n");
			printf("\n");
			display_doc();
			break;        
		case 3:
			printf("             ◆◆◆查询医护人员信息◆◆◆\n");
			printf("\n");
			search_doc();
			break;       
		case 4:
			printf("             ◆◆◆删除医护人员信息◆◆◆\n");
			printf("\n");
			del_doc();
			break;        
		case 5:
			printf("             ◆◆◆修改医护人员信息◆◆◆\n");
			printf("\n");
			modify_doc();
			break;  
		case 6:
			printf("             ◆◆◆返回医护人员端◆◆◆\n");
			menu_doc(); 
			break;    
		case 7:
			printf("             ◆◆◆返回主菜单◆◆◆\n");
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
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			menu_doc_doc();
			/*调用菜单函数*/   
		}   
		else  
			exit(0);
	} 
}  

void menu_doc_peo()   /*菜单函数*/
{
	printf("        ****************返乡人员信息管理**************\n"); 
	printf("           1.添加返乡人员信息\n");
	printf("           2.浏览所有返乡人员信息\n");  
	printf("           3.查询返乡人员信息\n"); 
	printf("           4.删除返乡人员信息\n");  
	printf("           5.修改返乡人员信息\n");  
	printf("           6.更新返乡人员核酸结果\n");  
    printf("           7.返回医护人员端\n"); 
	printf("           8.返回主菜单\n");  
	printf("           9.退出系统\n");    
	printf("        ********************谢谢使用******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("请选择你需要操作的步骤(1--9):\n");  
		scanf("%d",&n);  
		while(n<1&&n>9) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ◆◆◆添加返乡人员信息◆◆◆\n");
			printf("\n");
			add_peo_doc();
			break;         
		case 2:
			printf("             ◆◆◆浏览所有返乡人员信息◆◆◆\n");
			printf("\n");
			display_peo();
			break;        
		case 3:
			printf("             ◆◆◆查询返乡人员信息◆◆◆\n");
			printf("\n");
			search_peo();
			break;       
		case 4:
			printf("             ◆◆◆删除返乡人员信息◆◆◆\n");
			printf("\n");
			del_peo();
			break;        
		case 5:
			printf("             ◆◆◆修改返乡人员信息◆◆◆\n");
			printf("\n");
			modify_peo();
			break;  
		case 6:
			printf("             ◆◆◆更新返乡人员核酸结果◆◆◆\n");
			printf("\n");
			modify_tes();
			break;
		case 7:
			printf("             ◆◆◆返回医护人员端◆◆◆\n");
			menu_doc(); 
			break;    
		case 8:
			printf("             ◆◆◆返回主菜单◆◆◆\n");
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
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			menu_doc_peo();
			/*调用菜单函数*/   
		}   
		else  
			exit(0);
	}
}

void menu_peo()   /*菜单函数*/
{
	printf("        *******************返乡人员端*****************\n"); 
	printf("           1.报备返乡人员信息\n");
	printf("           2.查询返乡人员信息\n");  
	printf("           3.查询待核酸检测信息\n"); 
	printf("           4.查询负责人信息\n");  
	printf("           5.返回主菜单\n");  
	printf("           6.退出系统\n");      
	printf("        ********************谢谢使用******************\n"); 
	printf("\n");  
	printf("\n");   
	
	int n;   
	char a;
	   
		printf("请选择你需要操作的步骤(1--6):\n");  
		scanf("%d",&n);  
		while(n<1&&n>6) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ◆◆◆报备返乡人员信息◆◆◆\n");
			printf("\n");
			add_peo_peo();
			break;         
		case 2:
			printf("             ◆◆◆查询返乡人员信息◆◆◆\n");
			printf("\n");
			search_peo();
			break;        
		case 3:
			printf("             ◆◆◆查询待核酸检测信息◆◆◆\n");
			printf("\n");
			search_tes();
			break;       
		case 4:
			printf("             ◆◆◆查询负责人信息◆◆◆\n");
			printf("\n");
			search_peo_doc();
			break;        
		case 5:
			printf("             ◆◆◆返回主菜单◆◆◆\n");
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
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			menu_peo();
			/*调用菜单函数*/   
		}   
		else  
			exit(0);
	}
}  

void save_doc(int m)  /*保存文件函数*/ 
{
	int i;   
	FILE*fp;   
	fp=fopen("D:\\doc.txt","wb");
	for (i=0;i<m;i++) /*将内存中医护人员的信息输出到磁盘文件中去*/  
		if (fwrite(&doc[i],sizeof(struct doctor),1,fp)!=1)   
			printf("file write error\n");    fclose(fp);
}  

void save_peo(int m)  /*保存文件函数*/ 
{
	int i;   
	FILE*fp;   
	fp=fopen("D:\\peo.txt","wb");
	for (i=0;i<m;i++) /*将内存中返乡人员的信息输出到磁盘文件中去*/  
		if (fwrite(&peo[i],sizeof(struct people),1,fp)!=1)   
			printf("file write error\n");    fclose(fp);
}  

int load_doc()  /*导入+测长度函数*/ 
{ 
	FILE*fp;   
	int i=0;  
	if((fp=fopen("D:\\doc.txt","rb"))==NULL)/*判断是否能打开*/  
	{ 
		  return 0;
    }   
	else  
	{  
		do   
		{  
			fread(&doc[i],sizeof(struct doctor),1,fp);     //读文件到数组 
			i++;             //顺便测量长度
		}      
		while(feof(fp)==0);   //判断文件是否读完
	}      
	fclose(fp);   //关文件操作
	return(i-1);   //返回文件长度
}  

int load_peo()  /*导入+测长度函数*/ 
{ 
	FILE*fp;   
	int i=0;  
	if((fp=fopen("D:\\peo.txt","rb"))==NULL)/*判断是否能打开*/  
	{ 
		  return 0;
    }   
	else  
	{  
		do   
		{  
			fread(&peo[i],sizeof(struct people),1,fp);     //读文件到数组 
			i++;             //顺便测量长度
		}      
		while(feof(fp)==0);   //判断文件是否读完
	}      
	fclose(fp);   //关文件操作
	return(i-1);   //返回文件长度
}  

void display_doc()  /*浏览函数*/
{
	int i;  
	int m=load_doc();
	for(i=0;i<m;i++)
	{
	   printf(" 编号            姓名           性别           年龄            地址            电话           QQ号\n");
       printf(" %s            %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
	   printf("\n");
	   printf("\n");
	}
} 

void display_peo()  /*浏览函数*/
{
	int i;  
	int m=load_peo();
	for(i=0;i<m;i++)
	{
	   printf(" 身份证号            姓名           性别           年龄          返乡途径城市        核酸结果            地址            电话           QQ号\n");
       printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);
	   printf("\n");
	   printf("\n");
	}
} 
void add_doc()/*添加函数*/
{
	FILE*fp;  
	int n; /*增加员工的个数*/    
	int i;     
	int m=load_doc();/*定义一个变量接受函数的返回值*/   
	printf("请输入想增加的医护人员人数:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*从第m个数组开始，继续填充数组数据*/ 
	{
		printf("\n 请输入新增加医护人员的信息:\n");  
	    printf("请输入编号:  ");   
	    scanf("%s",&doc[i].num);     
	    printf("请输入姓名:  ");   
	    scanf("%s",doc[i].name);     
	    printf("请输入性别:  ");
        scanf("%s",&doc[i].sex);
	    printf("请输入年龄:  ");  
	    scanf("%s",&doc[i].age);  
	    printf("请输入住址:  ");  
	    scanf("%s",doc[i].addr); 
	    printf("请输入电话:  ");   
	    scanf("%s",doc[i].tel); 
		printf("请输入QQ:  ");   
	    scanf("%s",doc[i].qq); 
	    printf("\n");   
	}   
	printf("\n添加完毕!\n"); 
	m=m+n; /*总人数数*/       
	save_doc(m);/*将得到的员工数返回到文本中*/  
} 

void add_peo_doc()/*添加函数*/
{
	FILE*fp;  
	int n; /*增加返乡人员的个数*/    
	int i;     
	int m=load_peo();/*定义一个变量接受函数的返回值*/   
	printf("请输入想增加的返乡人员人数:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*从第m个数组开始，继续填充数组数据*/ 
	{
		printf("\n 请输入新增加返乡人员的信息:\n");  
	    printf("请输入身份证号:  ");   
	    scanf("%s",&peo[i].num);     
	    printf("请输入姓名:  ");   
	    scanf("%s",peo[i].name);     
	    printf("请输入性别:  ");
        scanf("%s",&peo[i].sex);
	    printf("请输入年龄:  ");  
	    scanf("%s",&peo[i].age); 
	    printf("请输入返乡途径城市:  ");  
	    scanf("%s",&peo[i].from); 
		printf("请输入核酸结果（若未检测请填写 无 ）:  ");  
	    scanf("%s",peo[i].tes);   
	    printf("请输入住址:  ");  
	    scanf("%s",peo[i].addr); 
	    printf("请输入电话:  ");   
	    scanf("%s",peo[i].tel); 
		printf("请输入QQ:  ");   
	    scanf("%s",peo[i].qq); 
	    printf("\n");   
	}   
	printf("\n添加完毕!\n"); 
	m=m+n; /*总返乡人员数*/       
	save_peo(m);/*将得到的返乡人员数返回到文本中*/  
} 

void add_peo_peo()/*添加函数*/
{
	FILE*fp;  
	int n; /*增加返乡人员的个数*/    
	int i;     
	int m=load_peo();/*定义一个变量接受函数的返回值*/   
	printf("请输入想报备的返乡人员人数:\n");
	scanf("%d",&n);    
	for (i=m;i<(m+n);i++) /*从第m个数组开始，继续填充数组数据*/ 
	{
		printf("\n 请输入报备返乡人员的信息:\n");  
	    printf("请输入身份证号:  ");   
	    scanf("%s",&peo[i].num);     
	    printf("请输入姓名:  ");   
	    scanf("%s",peo[i].name);     
	    printf("请输入性别:  ");
        scanf("%s",&peo[i].sex);
	    printf("请输入年龄:  ");  
	    scanf("%s",&peo[i].age); 
	    printf("请输入返乡途径城市:  ");  
	    scanf("%s",&peo[i].from); 
	    printf("请输入住址:  ");  
	    scanf("%s",peo[i].addr); 
	    printf("请输入电话:  ");   
	    scanf("%s",peo[i].tel); 
		printf("请输入QQ:  ");   
	    scanf("%s",peo[i].qq); 
	    printf("\n");   
	}   
	printf("\n添加完毕!\n"); 
	m=m+n; /*总返乡人员数*/       
	save_peo(m);/*将得到的返乡人员数返回到文本中*/  
} 

void del_doc()   /*删除函数*/ 
{
	int m=load_doc();  
	int i,j,n,t,flag;  
	char name[10];  
	printf("\n 原来的医护人员信息:\n");   
	display_doc(); /*展示*/     
	printf("\n");  
	printf("请输入要删除的医护人员的姓名:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++) 
	{
		if(strcmp(doc[i].name,name)==0)  
	      {
		    printf("\n已找到此人，原始记录为：\n"); 
			printf(" 编号            姓名           性别           年龄            地址            电话           QQ号\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			printf("\n确实要删除此人信息请按1,不删除请按0\n");    scanf("%d",&n);    
			if(n==1) 
			{
				for(j=i;j<m-1;j++)     //覆盖删除法  
				{
					strcpy(doc[j].num,doc[j+1].num);  /*字符串复制*/
					strcpy(doc[j].name,doc[j+1].name);                    
					strcpy(doc[j].sex,doc[j+1].sex);             
					strcpy(doc[j].age,doc[j+1].age);             
					strcpy(doc[j].addr,doc[j+1].addr);        
					strcpy(doc[j].tel,doc[j+1].tel);     
					strcpy(doc[j].qq,doc[j+1].qq);  
				}
                flag=0;    //跳出循环 
			}
             
		 } 
	 } 
	if(flag==0)     m=m-1; 
	else    
		printf("\n对不起，查无此人!\n");       
	save_doc(m);     /*调用保存函数*/     
	printf("\n继续删除请按1，不再删除请按0\n");  
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

void del_peo()   /*删除函数*/ 
{
	int m=load_peo();  
	int i,j,n,t,flag;  
	char name[10];  
	printf("\n 原来的员工信息:\n");   
	display_peo();      
	printf("\n");  
	printf("请输入要删除的员工的姓名:\n"); 
	scanf("%s",name); 
	for(flag=1,i=0;flag&&i<m;i++) 
	{
		if(strcmp(peo[i].name,name)==0)  
	      {
		    printf("\n已找到此人，原始记录为：\n"); 
	        printf(" 身份证号            姓名           性别           年龄          返乡途径城市        核酸结果            地址            电话           QQ号\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			printf("\n确实要删除此人信息请按1,不删除请按0\n");    scanf("%d",&n);    
			if(n==1) 
			{
				for(j=i;j<m-1;j++)     //覆盖删除法  
				{
					strcpy(peo[j].num,peo[j+1].num);  /*字符串复制*/
					strcpy(peo[j].name,peo[j+1].name);                    
					strcpy(peo[j].sex,peo[j+1].sex);             
					strcpy(peo[j].age,peo[j+1].age);             
					strcpy(peo[j].from,peo[j+1].from);    
					strcpy(peo[j].tes,peo[j+1].tes);             
					strcpy(peo[j].addr,peo[j+1].addr);    
					strcpy(peo[j].tel,peo[j+1].tel);     
					strcpy(peo[j].qq,peo[j+1].qq);  
				}
                flag=0;    //跳出循环 
			}
             
		 } 
	 } 
	if(flag==0)     m=m-1; 
	else    
		printf("\n对不起，查无此人!\n");       
	save_peo(m);     /*调用保存函数*/     
	printf("\n继续删除请按1，不再删除请按0\n");  
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

void search_doc()/*查询函数*/
{  
	int t,flag; 

	
		printf("\n1:按编号查询请按     2:按姓名查询请按 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*输入的t必须是1或者2*/   
		{
			printf("输入出错，请重新输入:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("按编号查询\n");
			search_doc_num();break;    
		case 2:
			printf("按姓名查询\n");
			search_doc_name();break;   
		default:break;  
		} 
} 
void search_doc_num()   //按编号查询函数
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_doc();/*把文本里面的所有数据读出*/ 
	printf("请输入要查找的编号:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,doc[i].num)==0)/*比较输入的和文本里面的字符串*/ 
		{ 
			printf("\n已找到，其记录为：\n");
			printf(" 工号            姓名           性别           年龄            地址            电话           QQ号\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			k=1;
		}     
		if(k==0)  
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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
void search_doc_name()   //按姓名查询
{
	char name[10];
	int i,t,k=0;  
	int m=load_doc();   
	printf("请输入要查找的姓名:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(doc[i].name,name)==0) 
		{ 
			printf("\n已找到，其记录为：\n");
			printf(" 编号            姓名           性别           年龄            地址            电话           QQ号\n");
            printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			k=1;						
		}     
		if(k==0) /*记录员工存不存在*/ 
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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

void search_peo()/*查询函数*/
{  
	int t,flag; 

	
		printf("\n1:按身份证号查询请按     2:按姓名查询请按 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*输入的t必须是1或者2*/   
		{
			printf("输入出错，请从新输入:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("按身份证号查询\n");
			search_peo_num();break;    
		case 2:
			printf("按姓名查询\n");
			search_peo_name();break;   
		default:break;  
		} 
	
} 
void search_peo_num()   //按身份证号查询函数
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_peo();/*把文本里面的所有数据读出*/ 
	printf("请输入要查找的身份证号:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,peo[i].num))/*比较输入的和文本里面的字符串*/ 
		{ 
			printf("\n已找到，其记录为：\n");
			printf(" 身份证号            姓名           性别           年龄          返乡途径城市        核酸结果            地址            电话           QQ号\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			k=1;
		}     
		if(k==0)  
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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
void search_peo_name()   //按姓名查询
{
	char name[10];
	int i,t,k=0;  
	int m=load_peo();   
	printf("请输入要查找的姓名:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(peo[i].name,name)==0) 
		{ 
			printf("\n已找到，其记录为：\n");
            printf(" 身份证号            姓名           性别           年龄          返乡途径城市        核酸结果            地址            电话           QQ号\n");
            printf(" %s                  %s            %s              %s            %s          %s             %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].from,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);

			k=1;						
		}     
		if(k==0) /*记录员工存不存在*/ 
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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

void search_tes()/*查询函数*/
{  
	printf("        ********************桂林市区行政区划******************\n"); 
	printf("           1.秀峰区\n");
	printf("           2.叠彩区\n");  
	printf("           3.象山区\n"); 
	printf("           4.七星区\n");  
	printf("           5.雁山区\n");  
	printf("           6.临桂区\n");  
	printf("\n");  
	printf("\n");  
	printf("        ************************返回**************************\n"); 
	printf("           7.返回返乡人员端\n");  
	printf("           8.返回主菜单\n");  
	printf("           9.退出系统\n");  
	
	int n;   
	char a;
	   
		printf("请选择你需要查询的区划或操作的步骤(1--9):\n");  
		scanf("%d",&n);  
		while(n<1&&n>9) 
		{
			printf("您输入有误，请重新选择!"); 
			scanf("%d",&n);  	
		} 
	while(1)
	{
		switch(n)  
		{  
		case 1:
			printf("             ◆◆◆1.秀峰区◆◆◆\n");
			printf("\n");
			printf("             桂林医学院附属医院\n");
			break;         
		case 2:
			printf("             ◆◆◆2.叠彩区◆◆◆\n");
			printf("\n");
			printf("             桂林人民医院\n");
			break;        
		case 3:
			printf("             ◆◆◆3.象山区◆◆◆\n");
			printf("\n");
			printf("             桂林南溪山医院\n");
			break;       
		case 4:
			printf("             ◆◆◆4.七星区◆◆◆\n");
			printf("\n");
			printf("             解放军第924医院\n");
			break;        
		case 5:
			printf("             ◆◆◆5.雁山区◆◆◆\n");
			printf("\n");
			printf("             桂林雁山医院\n");
			break;  
		case 6:
			printf("             ◆◆◆6.临桂区◆◆◆\n");
			printf("\n");
			printf("             桂林人民医院\n");
			break;
		case 7:
			printf("             ◆◆◆返回返乡人员端◆◆◆\n");
			menu_peo(); 
			break;    
		case 8:
			printf("             ◆◆◆返回主菜单◆◆◆\n");
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
		printf("是否继续进行(y or n):\n"); 
		scanf("%c",&a); 
		if(a=='y') 
		{  
			system("cls");
			/*清屏*/   
			search_tes();
			/*调用菜单函数*/   
		}   
		else  
			exit(0);
	}
} 

void search_peo_doc()
{  
	int t,flag; 

	
		printf("\n1:按编号查询请按     2:按姓名查询请按 \n"); 
		scanf("%d",&t);  
		while(t>2&&t<1)/*输入的t必须是1或者2*/   
		{
			printf("输入出错，请重新输入:\n");
			scanf("%d",&t);
		}  	      
	 
	
		switch(t) 
		{   
		case 1:
			printf("按编号查询\n");
			search_peo_doc_num();break;    
		case 2:
			printf("按姓名查询\n");
			search_peo_doc_name();break;   
		default:break;  
		} 
	
} 
void search_peo_doc_num()   //按编号查询函数
{ 
	char num[20];  
	int i,t,k=0;   
	int m=load_doc();/*把文本里面的所有数据读出*/ 
	printf("请输入要查找的编号:\n");  
	scanf("%d",&num); 
	for(i=0;i<m;i++) 
		if(strcmp(num,doc[i].num))/*比较输入的和文本里面的字符串*/ 
		{ 
			printf("\n已找到，其记录为：\n");
			printf(" 工号            姓名           性别         电话           QQ号\n");
            printf(" %s               %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].tel,doc[i].qq);
			k=1;
		}     
		if(k==0)  
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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
void search_peo_doc_name()   //按姓名查询
{
	char name[10];
	int i,t,k=0;  
	int m=load_doc();   
	printf("请输入要查找的姓名:\n");  
	scanf("%s",name); 
	for(i=0;i<m;i++)   
		if(strcmp(doc[i].name,name)==0) 
		{ 
			printf("\n已找到，其记录为：\n");
			printf(" 工号            姓名           性别         电话           QQ号\n");
            printf(" %s               %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].tel,doc[i].qq);
			k=1;						
		}     
		if(k==0) /*记录员工存不存在*/ 
			printf("\n对不起，查无此人\n");  
		printf("\n");   
		printf("继续查询请按1,结束查询请按2\n"); 
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

void modify_doc() /*修改函数*/
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
	printf("\n 原来的员工信息:\n"); 
	display_doc();   
	printf("\n"); 
	printf("请输入要修改的员工的姓名:\n"); 
	scanf("%s",name); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(doc[i].name,name)==0)
           { 
			   printf("\n已找到此人，原始记录为：\n");    
			   
	           printf(" 编号            姓名           性别           年龄            地址            电话           QQ号\n");
               printf(" %s               %s            %s              %s            %s          %s            %s  \n",doc[i].num,doc[i].name,doc[i].sex,doc[i].age,doc[i].addr,doc[i].tel,doc[i].qq);
			  	 printf("\n需要进行修改的选项\n 1.编号 2.姓名 3.性别 4.年龄 5.住址 6.电话  7:QQ号\n");         
				   printf("请输入你想修改的那一项序号:\n");           
				   scanf("%d",&c);             
				   while(c>7||c<1)
				   {
					   printf("\n选择错误，请重新选择!\n");
					   scanf("%d",&c);
				   }
			              
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n对不起，查无此人!\n");  
	  if(flag==0)   
	 {
		 switch(c)      /*因为当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人*/  
		 { 
		 case 1:printf("工号改为: ");   
			 scanf("%s",num);    
			 strcpy(doc[i-1].num,num);      
			 break;         
		 case 2:printf("姓名改为: ");  
			 scanf("%s",name);       
			 strcpy(doc[i-1].name,name);      
			 break;            
		 case 3:
			 printf("性别改为: "); 
              scanf("%s",sex);     
			  strcpy(doc[i-1].sex,sex); 
               break;    
		 case 4:
			 printf("年龄改为: ");   
			 scanf("%s",age);    
			 strcpy(doc[i-1].age,age);        
			 break;           
		 case 5:printf("住址改为: ");  
			 scanf("%s",addr);      
			 strcpy(doc[i-1].addr,addr);     
			 break;             
		 case 6:printf("电话改为: ");    
			 scanf("%s",tel);      
			 strcpy(doc[i-1].tel,tel);    
			 break;  
			 case 7:printf("QQ改为: ");    
			 scanf("%s",qq);      
			 strcpy(doc[i-1].qq,qq);    
			 break;  
		 }    
        printf("修改成功\n");
	 }      
	 save_doc(m);    
	 printf("\n继续修改请按1，不再修改请按2\n");  
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

void modify_peo() /*修改函数*/
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
	printf("\n 原来的员工信息:\n"); 
	display_peo();   
	printf("\n"); 
	printf("请输入要修改的员工的姓名:\n"); 
	scanf("%s",name); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(peo[i].name,name)==0)
           { 
			   printf("\n已找到此人，原始记录为：\n");    
			   
	           printf(" 身份证号            姓名           性别           年龄            地址            电话           QQ号\n");
               printf(" %s               %s            %s              %s            %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].addr,peo[i].tel,peo[i].qq);
			  	 printf("\n需要进行修改的选项\n 1.编号 2.姓名 3.性别 4.年龄 5.住址 6.电话  7:QQ号\n");         
				   printf("请输入你想修改的那一项序号:\n");           
				   scanf("%d",&c);             
				   while(c>7||c<1)
				   {
					   printf("\n选择错误，请重新选择!\n");
					   scanf("%d",&c);
				   }
			              
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n对不起，查无此人!\n");  
	  if(flag==0)   
	 {
		 switch(c)      /*因为当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人*/  
		 { 
		 case 1:printf("身份证号改为: ");   
			 scanf("%s",num);    
			 strcpy(peo[i-1].num,num);      
			 break;         
		 case 2:printf("姓名改为: ");  
			 scanf("%s",name);       
			 strcpy(peo[i-1].name,name);      
			 break;            
		 case 3:
			 printf("性别改为: "); 
              scanf("%s",sex);     
			  strcpy(peo[i-1].sex,sex); 
               break;    
		 case 4:
			 printf("年龄改为: ");   
			 scanf("%s",age);    
			 strcpy(peo[i-1].age,age);        
			 break;           
		 case 5:printf("住址改为: ");  
			 scanf("%s",addr);      
			 strcpy(peo[i-1].addr,addr);     
			 break;             
		 case 6:printf("电话改为: ");    
			 scanf("%s",tel);      
			 strcpy(peo[i-1].tel,tel);    
			 break;  
			 case 7:printf("QQ改为: ");    
			 scanf("%s",qq);      
			 strcpy(peo[i-1].qq,qq);    
			 break;  
		 }    
        printf("修改成功\n");
	 }      
	 save_peo(m);    
	 printf("\n继续修改请按1，不再修改请按2\n");  
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

void modify_tes() /*修改函数*/
{   
	char num[20];  
	char tes[5];      
	int c,i,t,flag;  
	int m=load_peo();    
	printf("\n 原来的返乡人员信息:\n"); 
	display_peo();   
	printf("\n"); 
	printf("请输入返乡人员的身份证号:\n"); 
	scanf("%s",num); 
     for(flag=1,i=0;flag&&i<m;i++) 
	 { 
		 if(strcmp(peo[i].num,num)==0)
           { 
			   printf("\n已找到此人，原始记录为：\n");    
               printf(" 身份证号            姓名           性别           年龄            核酸结果            地址            电话           QQ号\n");
               printf(" %s                  %s            %s              %s            %s          %s          %s            %s  \n",peo[i].num,peo[i].name,peo[i].sex,peo[i].age,peo[i].tes,peo[i].addr,peo[i].tel,peo[i].qq);
  
			   flag=0;  
		 }         
	 }  
	 if(flag==1)  
		 printf("\n对不起，查无此人!\n");  
	  if(flag==0)   
	 {
		  /*因为当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人*/  
			 printf("核酸结果为: "); 
              scanf("%s",tes);     
			  strcpy(peo[i-1].tes,tes);  
		 
        printf("修改成功\n");
	 }      
	 save_peo(m);    
	 printf("\n继续修改请按1，不再修改请按2\n");  
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


