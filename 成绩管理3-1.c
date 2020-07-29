/*
版本3.1
程序功能：管理一个班级多门课的成绩(成绩为整数)。
使用2维数组score，下标代表学号。每一行保存一个同学成绩。
第0行保存各科总分，第0列保存每个同学总分。
利用2维数组rank，保存每个同学每一科以及总分的名次。
用2级菜单管理所有的输出功能。

利用2维字符数组管理学生姓名与课程名。

日期：2017.12.23
*/

#include <stdio.h>
#include <conio.h>
#include "成绩头文件.c"

#define N 5
#define CrsNum 3

//score和rank为全局数组,行下标代表学号（1-N），
//列下标代表课程号（1-CrsNum）
//score第0行保存每科总分，第0列保存每个同学的总分。
int score[N+1][CrsNum+1]; 
int rank[N+1][CrsNum+1] ; //全局数组，保存名次。

char coursename[CrsNum+1][10]={"总分" ,"Java" , "政治" ,"语文"};
char name[N+1][10] = {"","张三","李四","王五","丁六","小七"};

main()
{
	char choice , n;

	while (1)
	{
		system("cls");
		ListMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("谢谢你的使用！\n");
			return;
		case '1':
			input( );//输入成绩
			break;

		case '2':
			process();//统计处理
			break;
		case '3':
			sortfun();//排序处理
			break;
		case '4':
			output( );//输出
			break;
		case '9':
			randdata(); //产生随机数作为测试数据
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main

void ListMenu( )//显示主菜单
{
	printf("   成绩管理菜单  \n");
	printf("=================\n");
	printf(" 1. 输入成绩     \n");
	printf(" 2. 统计处理     \n");
	printf(" 3. 名次排序     \n");
	printf(" 4. 输出         \n");
	printf(" 9. 随机测试数据 \n");
	printf(" 0. 退出         \n");
	printf("=================\n");
}//end ListMenu( )

void outputmenu( )//输出二级菜单
{
	printf("   输出二级菜单  \n");
	printf("=================\n");
	printf(" 1. 按学号输出成绩\n");
	printf(" 2. 按名次输出成绩\n");
	printf(" 3. 按名次输出Topn\n");
	printf(" 4. 输出不及格名单\n");
	printf(" 0. 返回主菜单    \n");
	printf("=================\n");
}//end outputmenu( )

void inputmenu( )//输入二级菜单
{
	printf("   输入二级菜单  \n");
	printf("=================\n");
	printf(" 1. %s\n" ,coursename[1]);
	printf(" 2. %s\n" ,coursename[2]);
	printf(" 3. %s\n" ,coursename[3]);
	printf(" 0. 返回主菜单    \n");
	printf("=================\n");
}//end inputmenu( )

int  coursemenu( )//课程菜单，返回课程号1，2，3
{
	char courseID;

	printf(" 输出的科目\n");
	printf("=================\n");
	printf(" 0. 所有科目\n");
	printf(" 1. %s\n" ,coursename[1]);
	printf(" 2. %s\n" ,coursename[2]);
	printf(" 3. %s\n" ,coursename[3]);
	printf("=================\n");

	do
	{
		printf(" 请选择输出的科目:");
		courseID = getche();
		if (courseID < '0' || courseID > '4')
			printf("输入错误！课程号0-3");	
	}while (courseID < '0' || courseID > '4');

	return (courseID - 48);
}//end coursemenu( )

void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("请依次输入第%d科(%s)的成绩：\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("请输入第%d个同学%s的成绩：",i ,name[i]);
			scanf("%d",&score[i][CrsId]);
			if (score[i][CrsId]>100 || score[i][CrsId] <0)
				printf("成绩错误！");
		}while(score[i][CrsId]>100 || score[i][CrsId] <0);
	}	
}//end inputbyCrsId( )

void outputbyno( )
{
	int i ;

	printf("\n\n按学号输出\n\n" );

	printf("\n学号\t姓名");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t总分\t名次\n");
	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%d\t%s\t%d\t" , i,name[i] ,score[i][1]);
		printf("%d\t%d\t" , score[i][2],score[i][3]);
		printf("%d\t%d" , score[i][0],rank[i][0]);
		printf("\n");
	}
	printf("=================================================\n");

	printf("\t总分：\t" );
	printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
	printf("\n\t平均：\t" );
	printf("%.2f\t%.2f\t%.2f\n" , 1.0*score[0][1]/N,1.0*score[0][2]/N,1.0*score[0][3]/N);
}// end outputbyno( )

//统计各科、各个同学的总分
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		score[i][0] = 0 ;//各个同学的总分清0

	for (j = 1 ; j <= CrsNum ; j ++)
		score[0][j] = 0 ; //各科总分清0


	for (i = 1 ; i <= N ; i ++)
		for ( j = 1 ; j <= CrsNum ; j ++ )
		{
			score[i][0] += score[i][j] ;
			score[0][j] += score[i][j] ;
		}
	printf("已经完成统计!\n");
}

//可以按照单科或者总分对名次排序
void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) //学号
		for ( k = 0 ; k <= CrsNum ; k++) //课程号，0为总分列
			rank[i][k] = 1 ;

	for( k = 0 ; k  <= CrsNum ; k++) //每门课单独牌名次
	{
		for ( i = 1 ; i < N  ; i ++)//学号
		{
			for ( j = i+1 ; j <= N ; j++)//与后面学号pk
				if (score [i][k] > score [j][k])
					rank [j][k] ++ ;
				else if (score [i][k] < score [j][k])
					rank [i][k] ++ ;	
		}//end for i
	}//end for k
	printf("名次已经排序！");
}

//产生随机数作为测试数据
void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
		for ( j = 1 ; j <= CrsNum ; j++)
		{
			score[i][j] = 21 + rand() % 80;
		}
	printf("已经产生一组随机数.\n");
}//end of randdata

//按名次输出成绩前几名
void outputbyrank(int n)
{
	int i, r = 1,same;

	printf("\n\n按名次输出前%d名单\n\n" ,n);

	printf("\n名次\t学号\t姓名");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t总分\n");
	printf("====================================================\n");

	while ( r <= n) //r代表名次，从1开始递增
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (rank[i][0] == r) //第i行第0列记录了i号同学的总分名次
			{
				printf("%d\t%d\t%s\t%d\t" , rank[i][0],i,name[i],score[i][1]);
				printf("%d\t%d\t" , score[i][2],score[i][3]);
				printf("%d\n" , score[i][0]);
				same ++ ;
			}		
		}
		r += same ; //r ++ ;
	}

	printf("====================================================\n");

	if (n == N)
	{
		printf("\t\t总分：\t" );
		printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
		printf("\n\t\t平均：\t" );
		printf("%.2f\t%.2f\t%.2f\n" , 1.0*score[0][1]/N,1.0*score[0][2]/N,1.0*score[0][3]/N);
	}
}

//输出某科不及格名单
void failacourse(int courseID)
{
	int i ,count = 0 ;

	printf("\n\n\t%s不及格名单\n" , coursename[courseID] );

	printf("\n学号\t姓名\t成绩\t名次\n");
	printf("==============================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		if (score[i][courseID] < 60 )
		{
			count ++ ;
			printf("%d\t%s\t%d\t%d" , i,name[i],score[i][courseID],rank[i][courseID]);
			printf("\n");		
		}
	}
	printf("==============================\n");
	printf("%s共有%d个同学不及格。\n" ,coursename[courseID] ,count);
}//end outputfail()

//输出所有科目不及格名单
void allfail()
{
	int i , j , k,count = 0 ,allcount = 0 ;

	printf("\n\n\t所有科目不及格名单\n" );

	printf("\n学号\t姓名");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t不及格门数\n");

	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++) //学号
	{
		count = 0 ;
		for ( j = 1 ; j <= CrsNum ; j++) //课程号
		{
			if (score[i][j] < 60 )
			{
				if (count == 0 )
				{
					printf("%d\t%s" , i,name[i]);
				
					for (k = 1 ; k <j ; k++)
						printf("\t" );
				}
				printf("\t%d" , score[i][j]);
				count ++ ;			
			}
			else if (count > 0)
				printf("\t");	
		}//end for j
		if (count >0)
			printf("\t%d\n" , count);

		allcount += count ;
	}
	printf("==================================================\n");
	printf("所有共有%d门次不及格。\n" ,allcount);
}//end allfail()


//输出不及格名单
void outputfail()
{
	int CrsID = coursemenu( );

	if (CrsID == 0 )
		allfail();
	else
		failacourse(CrsID);
}

//输出功能 
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
			outputbyno( );//按学号输出所有成绩
			break;

		case '2':
			outputbyrank(N);//按总分名次输出所有成绩
			break;

		case '3': //按名次输出Top n
			do 
			{
				printf("想要输出前几名？");
				scanf("%d" ,&n);
				if (n >N || n <1)
					printf("名次有错误！");			
			}while(n >N || n <1);
			outputbyrank(n);//按名次输出Topn
			break;
	
		case '4':
			outputfail();//按名次输出不及格成绩
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end output()

void input()
{
	char choice , n;

	while (1)
	{
		system("cls");
		inputmenu();

		printf("请输入课程号：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;
		case '1': //科目1

		case '2': //科目2

		case '3': //科目3		
			inputbyCrsId(choice-48);//按课程号输入某科成绩
			break;

		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()

