#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N 5
#define Num 3

char coursename[Num+1][10]={"总分" ,"C语言" , "数学" ,"英语"};
int  coursetotal[Num+1];

typedef  struct 
{
	char ID[10];
	char name[10];
	int score[Num +1];
	int rank[Num +1];
	int total;
	double average ;
	int totalrank;
} student ;

student stu[N+1];

int sorted = 0;

void ListMenu( )
{
	printf("   成绩管理菜单   \n");
	printf("==================\n");
	printf("  1. 输入数据     \n");
	printf("  2. 统计处理     \n");
	printf("  3. 名次排序     \n");
	printf("  4. 输出数据     \n");
	printf("  5. 随机数据     \n");
	printf("  6. 查询数据     \n");
	printf("  7. 修改数据     \n");
	printf("  8. 删除数据     \n");
	printf("  9. 文件存盘     \n");
	printf(" 10. 文件读取     \n");
	printf("  0. 退出系统     \n");
	printf("==================\n");
}

void outputmenu( )
{
	printf("   输出二级菜单   \n");
	printf("==================\n");
	printf(" 1. 按学号输出成绩\n");
	printf(" 2. 按名次输出成绩\n");
	printf(" 3. 前几名输出    \n");
	printf(" 4. 输出不及格名单\n");
	printf(" 0. 返回主菜单    \n");
	printf("==================\n");
}

void inputmenu( )
{
	printf("   输入二级菜单  \n");
	printf("=================\n");
	printf(" 1. 课程名称     \n");
	printf(" 2. 学生学号     \n");
	printf(" 3. 学生姓名     \n");
	printf(" 4. 成绩         \n");
	printf(" 0. 返回主菜单   \n");
	printf("=================\n");
}

void seachmenu( )
{
	printf("   查询二级菜单  \n");
	printf("=================\n");
	printf(" 1. 按学号查询   \n");
	printf(" 2. 按课程查询   \n");
	printf(" 3. 按姓名查询   \n");
	printf(" 0. 返回主菜单   \n");
	printf("=================\n");
}

void rewritemenu( )
{
	printf("   修改二级菜单  \n");
	printf("=================\n");
	printf(" 1. 课程名称     \n");
	printf(" 2. 学生学号     \n");
	printf(" 3. 学生姓名     \n");
	printf(" 4. 成绩         \n");
	printf(" 0. 返回主菜单   \n");
	printf("=================\n");
}

void deletmenu( )
{
	printf("   删除二级菜单  \n");
	printf("=================\n");
	printf(" 1. 按学号删除   \n");
	printf(" 2. 按课程删除   \n");
	printf(" 3. 按姓名删除   \n");
	printf(" 0. 返回主菜单   \n");
	printf("=================\n");
}

void inputCrsname()
{
	int i ;

	for (i = 1 ; i <= Num ; i++ )
	{
		printf("\n请输入课程%d的名称：" , i);
		scanf("%s",&coursename[i]);
	}
}
void inputStuID()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n请输入第%d个学生的学号：" , i);
		scanf("%s",&stu[i].ID);

	}
}
void inputStuname()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n请输入第%d个学生的姓名：" , i);
		scanf("%s",&stu[i].name);
	}
}

int coursemenu( )
{
	char courseID;
	int i ;

	printf("      科目\n");
	printf("=================\n");
	printf(" 0. 所有科目\n");

	for ( i = 1 ; i <= Num ; i++)
		printf(" %d. %s\n" , i , coursename[i]);
	printf("=================\n");

	do
	{
		printf(" 请选择的科目:");
		courseID = getche();
		if (courseID < '0' || courseID > '0'+Num)
			printf("输入错误！课程号0-%d" , Num );	
	}while (courseID < '0' || courseID > '0'+Num);

	return (courseID - 48);
}

void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("\n请依次输入第%d科%s的成绩：\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("请输入第%d个同学%s的成绩：",i ,stu[i].name);
			scanf("%d",&stu[i].score[CrsId]);
			if (stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0)
				printf("\n成绩错误！");
		}while(stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0);
	}
	sorted = 0 ;
}
void inputallCrs()
{
	int i , j ;
	
	printf("\n请依次输入每个同学每一科的成绩：\n");
	printf("学号\t姓名");

	for (j = 1 ; j <= Num ; j++ )
		printf("\t%s" , coursename[j]);
		
	for (i = 1 ; i <= N ; i++)
	{
		printf("\n%s\t%s\t",stu[i].ID ,stu[i].name);
		for ( j = 1 ; j <= Num ; j++)
		{
			do
			{
				scanf("%d",&stu[i].score[j]);
				if (stu[i].score[j]>100 || stu[i].score[j] <0)
					printf("\n%s同学%s成绩错误！请重新输入！" ,stu[i].name,coursename[j]);
			}while(stu[i].score[j]>100 || stu[i].score[j] <0);
		}
	}
	sorted = 0 ;
}

void outputbyno( )
{
	int i,j ;

	printf("\n\n按学号输出\n\n" );

	printf("\n学号\t姓名");
	for (i = 1 ; i <= Num ; i ++)
		printf("\t%s" , coursename[i]);
	printf("\t总分\t平均分\t名次\n");

	printf("==============================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
			printf("%d\t" , stu[i].score[j]);
	
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
	}
	printf("==============================================================\n");

	printf("\t总分：\t" );
	for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , coursetotal[j]);

	printf("\n\t平均：\t" );
	for (j = 1 ; j <= Num ; j ++)
		printf("%.2f\t" , 1.0*coursetotal[j]/N);
	printf("\n");
}
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		stu[i].total = 0 ;

	for (j = 0 ; j <= Num ; j ++)
		coursetotal[j] = 0;


	for (i = 1 ; i <= N ; i ++)
		for ( j = 1 ; j <= Num ; j ++ )
		{
			stu[i].total += stu[i].score[j] ;
			stu[i].average = stu[i].total / Num;
			coursetotal[j] +=  stu[i].score[j] ;
		}
	printf("已经完成统计！\n");
}

void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) 
	{
		stu[i].totalrank = 1;
		for ( k = 1 ; k <= Num ; k++) 
			stu[i].rank[k] = 1 ;
	}

	for( k = 1 ; k  <= Num ; k++) 
	{
		for ( i = 1 ; i < N  ; i ++)
		{
			for ( j = i+1 ; j <= N ; j++)
				if (stu[i].score[k] > stu[j].score[k])
					stu[j].rank[k] ++ ;
				else if (stu[i].score[k] < stu[j].score[k])
					stu[i].rank[k] ++ ;	
		}
	}

	for ( i = 1 ; i < N  ; i ++)
	{
		for ( j = i+1 ; j <= N ; j++)
			if (stu[i].total > stu[j].total )
				stu[j].totalrank  ++ ;
			else if (stu[i].total < stu[j].total)
				stu[i].totalrank  ++ ;	
	}
	printf("名次已经排序!\n");
	sorted = 1 ;
}

void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
		for ( j = 1 ; j <= Num ; j++)
		{
			stu[i].score[j]  = 21 + rand() % 80;
		}
	printf("已经产生一组随机数.\n");
	sorted = 0 ;
}

void outputbyrank(int n)
{
	int i,j, r = 1,same;

	if (sorted == 0 )
	{
		printf("成绩未排序！");
		printf("请先执行主菜单中的排序功能！");
		return ;
	}

	printf("\n\n按名次输出前%d名单\n\n" ,n);

	printf("\n名次\t学号\t姓名");
	for (i = 1 ; i <= Num ; i ++)
		printf("\t%s" , coursename[i]);
	printf("\t总分\n");

	printf("====================================================\n");

	while ( r <= n)
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (stu[i].totalrank == r) 
			{
				printf("%d\t" , stu[i].totalrank);
				printf("%s\t" , stu[i].ID);
				printf("%s\t" , stu[i].name);
				for (j = 1 ; j <= Num ; j ++)
					printf("%d\t" , stu[i].score[j]);
				printf("%d\n" , stu[i].total);
				same ++ ;
			}		
		}
		r += same ; 
	}

	printf("====================================================\n");

	if (n == N)
	{
		printf("\t\t总分：\t" );
		for (j = 1 ; j <= Num ; j ++)
			printf("%d\t" , coursetotal[j]);

		printf("\n\t\t平均：\t" );
		for (j = 1 ; j <= Num ; j ++)
			printf("%.2f\t" , 1.0*coursetotal[j]/N);
		printf("\n");
	}
	printf("\n");
}

void failacourse(int courseID)
{
	int i ,count = 0 ;

	printf("\n\n\t%s不及格名单\n" , coursename[courseID] );

	printf("\n学号\t姓名\t成绩\t名次\n");
	printf("==============================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		if (stu[i].score[courseID] < 60 )
		{
			count ++ ;
			printf("%s\t" , stu[i].ID );
			printf("%s\t" , stu[i].name  );
			printf("%d\t" , stu[i].score[courseID] );
			printf("%d\n" , stu[i].rank[courseID] );
		}
	}
	printf("==============================\n");
	printf("%s共有%d个同学不及格。\n" ,coursename[courseID] ,count);
}

void allfail()
{
	int i , j , k,count = 0 ,allcount = 0 ;

	printf("\n\n\t所有科目不及格名单\n" );

	printf("\n学号\t姓名");
	for ( i = 1 ; i <= Num ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t不及格门数\n");

	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		count = 0 ;
		for ( j = 1 ; j <= Num ; j++)
		{
			if (stu[i].score[j] < 60 )
			{
				if (count == 0 )
				{
					printf("%d\t%s" , i,stu[i].name);
				
					for (k = 1 ; k <j ; k++)
						printf("\t" );
				}
				printf("\t%d" , stu[i].score[j]);
				count ++ ;			
			}
			else if (count > 0)
				printf("\t");	
		}
		if (count >0)
			printf("\t%d\n" , count);

		allcount += count ;
	}
	printf("==================================================\n");
	printf("所有共有%d门次不及格。\n" ,allcount);
}


void outputfail()
{
	int CrsID = coursemenu( );
	if (CrsID == 0 )
		allfail();
	else
		failacourse(CrsID);
}

void output()
{
	char choice , n;

	while (1)
	{
		system("cls");
		outputmenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;
		case '1':
			outputbyno( );
			break;

		case '2':
			outputbyrank(N);
			break;

		case '3': 
			do 
			{
				printf("想要输出前几名？");
				scanf("%d" ,&n);
				if (n >N || n <1)
					printf("名次有错误！");			
			}while(n >N || n <1);
			outputbyrank(n);
			break;
	
		case '4':
			outputfail();
			break;
		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}

void input()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		inputmenu();

		printf("请输入选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;
		case '1': 
			inputCrsname();
			break;

		case '2': 
			inputStuID();
			break;

		case '3': 
			inputStuname();
			break;

		case '4': 
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);
			else 
				inputallCrs(); 
			break;

		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}


void seachstuID()                      
{  	
	
	char s[10];  
	int i=1,j,k;  
	printf("请输入想查询的学生学号：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n按学号查询\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
		
	}    
	system("pause");  
}

void seachcoursename()                      
{  	
	
	char s[10];  
	int i,j,k=1;  
	printf("请输入想查询的课程名称：");  
	scanf("\t%s",s);  
	while(strcmp(coursename[k],s)!=0&&k<=Num)k++;

	if(k==Num+1)  
	{  
		printf("\t没有找到这个课程!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n按课程查询\n\n" );

		printf("\n学号\t姓名");
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		for ( i = 1 ; i <= N ; i++)
		{
			printf("%s\t" ,stu[i].ID);
			printf("%s\t" ,stu[i].name);
			
			printf("%d\t" , stu[i].score[k]);
		
			printf("%d\t" , stu[i].total);
			printf("%.2f\t" , stu[i].average);
			printf("%d\n" , stu[i].totalrank);
		}
			
	}    
	system("pause");  
}

void seachstuname()                      
{  	
	
	char s[10];  
	int i=1,j,k;  
	printf("请输入想查询的学生姓名：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n按姓名查询\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
		
	}    
	system("pause");  
}


void seach()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		seachmenu();

		printf("请输入选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;

		case '1': 
			seachstuID();
			break;

		case '2': 
			seachcoursename();
			break;

		case '3': 
			seachstuname();
			break;
			
		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}

void rewriteCrsname()
{
	char s[10];  
	int i=1,j;  
	printf("\n请输入想修改的课程名称：");  
	scanf("\t%s",s);  
	while(strcmp(coursename[i],s)!=0&&i<=Num)i++;  
	if(i==Num+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{		
		printf("\n\n请输入修改后的课程名称：");
		scanf("%s",&coursename[i]);	
		printf("修改成功！");
	}
} 

void rewriteStuID()
{
	char s[10];  
	int i=1,j,k;  
	printf("\n请输入想修改的学生学号：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{
		printf("\n\n学生信息如下：\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("\n请输入修改后的学生学号：" , i);
		scanf("%s",&stu[i].ID);	
		printf("修改成功！");
	}
}

void rewriteStuname()
{
	char s[10];  
	int i=1,j,k;  
	printf("\n请输入想修改的学生姓名：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{
		printf("\n\n学生信息如下：\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[i]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("\n请输入修改后的学生姓名：" , i);
		scanf("%s",&stu[i].name);
		printf("修改成功！");
	}
}

void rewritebyCrsId(int CrsId)
{
	char s[10];  
	int i=1,j;  
	printf("\n请输入想修改的学生学号：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  
		do
		{
			printf("请输入修改后的同学成绩：");
			scanf("%d",&stu[i].score[CrsId]);
			if (stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0)
				printf("\n成绩错误！");
		}while(stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0);
		printf("修改成功！");
	}
	sorted = 0 ;
}
void rewriteallCrs()
{
	char s[10];  
	int i=1,j;  
	printf("\n请输入想修改的学生学号：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  	
		printf("\n请依次输入每一科的成绩：\n");
		printf("学号\t姓名");

		for (j = 1 ; j <= Num ; j++ )
			printf("\t%s" , coursename[j]);

			printf("\n%s\t%s\t",stu[i].ID ,stu[i].name);

			for ( j = 1 ; j <= Num ; j++)
			{
				do
				{
					scanf("%d",&stu[i].score[j]);
					if (stu[i].score[j]>100 || stu[i].score[j] <0)
						printf("\n%s同学%s成绩错误！请重新输入！" ,stu[i].name,coursename[j]);
				}while(stu[i].score[j]>100 || stu[i].score[j] <0);
				printf("修改成功！");
			}
	}
	sorted = 0 ;
}  

void rewrite()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		rewritemenu();

		printf("请输入选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;

		case '1': 
			rewriteCrsname();
			break;

		case '2': 
			rewriteStuID();
			break;

		case '3': 
			rewriteStuname();
			break;

		case '4': 
			CrsID = coursemenu();
			if (CrsID > 0 )
				rewritebyCrsId(CrsID);
			else 
				rewriteallCrs(); 
			break;

		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}

void deletstuID()                      
{  	
	
	char s[10];  
	int i=1,j,k;
	char c;
	printf("请输入想删除的学生学号：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n该学生信息如下：\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("确定删除吗？(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			stu[i] = stu[i+1];
			printf("删除成功！");
		}
		
	}    
	system("pause");  
}

void deletcoursename()                      
{  	
	
	char s[10];  
	int i,j,k=1;
	char c;
	printf("请输入想删除的课程：");  
	scanf("\t%s",s);  
	while(strcmp(coursename[k],s)!=0&&k<=Num)k++;

	if(k==Num+1)  
	{  
		printf("\t没有找到这个课程!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n该课程信息如下：\n\n" );

		printf("\n学号\t姓名");
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		for ( i = 1 ; i <= N ; i++)
		{
			printf("%s\t" ,stu[i].ID);
			printf("%s\t" ,stu[i].name);
			
			printf("%d\t" , stu[i].score[k]);
		
			printf("%d\t" , stu[i].total);
			printf("%.2f\t" , stu[i].average);
			printf("%d\n" , stu[i].totalrank);
		}

		printf("确定删除吗？(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			strcpy(coursename[k] , coursename[k+1]);
			printf("删除成功！");
		}
			
	}    
	system("pause");  
}

void deletstuname()                      
{  	
	
	char s[10];  
	int i=1,j,k;
	char c;
	printf("请输入想删除的学生姓名：");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\t没有找到这个学生!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n该学生信息如下：\n\n" );

		printf("\n学号\t姓名");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t总分\t平均分\t名次\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("确定删除吗？(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			stu[i] = stu[i+1];
			printf("删除成功！");
		}
		
	}    
	system("pause");  
}

void delet()								
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		deletmenu();

		printf("请输入选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;

		case '1': 
			deletstuID();
			break;

		case '2': 
			deletcoursename();
			break;

		case '3': 
			deletstuname();
			break;
			
		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}

void savefilestudent()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","wb")) ==NULL )
	{
		printf("无法打开课程名文件student.dat!\n");
		exit(0);
	}
	for (i = 1 ; i <= N ; i++ )
	{
		if (fwrite(&stu[i],sizeof(student),1,f1) ==1)
		{
			
		}
		else
		{
			printf("写课程名文件student.dat失败！\n");
			return;
		}
	}
	printf("写课程名文件student.dat成功！\n");
	
	fclose(f1);
}

void readfilestudent()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","rb")) ==NULL )
	{
		printf("无法打开课程名文件student.dat!\n");
		exit(0);
	}
	for (i = 1 ; i <= N ; i++ )
	{
		if (fread(&stu[i],sizeof(student),1,f1) ==1)
		{
			
		}
		else
		{
			printf("读课程名文件student.dat失败！\n");
			return;
		}
	}

	printf("读课程名文件student.dat成功！\n");
	
	fclose(f1);
}

void savefilecourse()
{
	FILE * f1 , * f2;

	if ((f1 = fopen( "course.dat","wb")) ==NULL )
	{
		printf("无法打开课程名文件course.dat!\n");
		exit(0);
	}
	else if (fwrite(coursename,sizeof(coursename),1,f1) ==1)
	{
		printf("写课程名文件course.dat成功！\n");
	}
	else
	{
		printf("写课程名文件course.dat失败！\n");
	}
	fclose(f1);
}

void readfilecourse()
{
	FILE * f1 , * f2;

	if ((f1 = fopen( "course.dat","rb")) ==NULL )
	{
		printf("无法打开课程名文件course.dat!\n");
		exit(0);
	}
	else if (fread(coursename,sizeof(coursename),1,f1) ==1)
	{
		printf("读课程名文件course.dat成功！\n");
	}
	else
	{
		printf("读课程名文件course.dat失败！\n");
	}
	fclose(f1);
}

 
main()
{
	int choice;

	while (1)
	{
		system("cls");
		ListMenu();

		printf("请输入你的选择：");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
		case 0:
			printf("谢谢您的使用！\n");
			return;
		case 1:
			input();
			break;

		case 2:
			process();
			break;

		case 3:
			sortfun();
			break;

		case 4:
			output();
			break;

		case 5:
			randdata(); 
			break;

		case 6:
			seach(); 
			break;

		case 7:
			rewrite(); 
			break;

		case 8:
			delet(); 
			break;

		case 9:
			savefilestudent();
			savefilecourse();
			break;

		case 10:
			readfilestudent();
			readfilecourse();
			break;

		default :
			printf("输入错误！请重新输入！\n");	
		}
		printf("按任意键继续...\n");
		getch();	
	}
}
