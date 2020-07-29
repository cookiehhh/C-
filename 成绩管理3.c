/*
版本3.0
程序功能：管理一个班级多门课的成绩(成绩为整数)。
使用2维数组score，下标代表学号。每一行保存一个同学成绩。
第0行保存各科总分，第0列保存每个同学总分。
利用2维数组rank，保存每个同学每一科以及总分的名次。
用2级菜单管理所有的输出功能。

日期：2017.12.23
*/

#include <stdio.h>
#include <conio.h>

#define N 5
#define CrsNum 3

//score和rank为全局数组,行下标代表学号（1-N），
//列下标代表课程号（1-CrsNum）
//score第0行保存每科总分，第0列保存每个同学的总分。
int score[N+1][CrsNum+1]; 
int rank[N+1][CrsNum+1] ; //全局数组，保存名次。
char coursename[CrsNum+1][10]={"总分" ,"C语言" , "数学" ,"英语"};

void ListMenu( )
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

void outputmenu( )
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

void inputmenu( )
{
	printf("   输入二级菜单  \n");
	printf("=================\n");
	printf(" 1. C语言\n");
	printf(" 2. 数学\n");
	printf(" 3. 英语\n");
	printf(" 0. 返回主菜单    \n");
	printf("=================\n");
}//end inputmenu( )

int  coursemenu( )
{
	char courseID;

	printf(" 输出的科目\n");
	printf("=================\n");
	printf(" 1. C语言\n");
	printf(" 2. 数学\n");
	printf(" 3. 英语\n");
	printf("=================\n");

	do
	{
		printf(" 请选择输出的科目:");
		courseID = getche();
		if (courseID < '1' || courseID > '3')
			printf("输入错误！课程号0-3");	
	}while (courseID < '1' || courseID > '3');

	return (courseID - 48);
}//end coursemenu( )

void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("请依次输入第%d科的成绩：\n\n",CrsId);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("请输入第%d个同学的成绩：",i);
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

	printf("\n学号\tC语言\t数学\t英语\t总分\t名次\n");
	printf("==========================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%d\t%d\t" , i,  score[i][1]);
		printf("%d\t%d\t" , score[i][2],score[i][3]);
		printf("%d\t%d" , score[i][0],rank[i][0]);
		printf("\n");
	}
	printf("=========================================\n");

	printf("总分：\t" );
	printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
	printf("\n平均：\t" );
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

	for( k = 0 ; k  <= CrsNum ; k++) //每门课单独排名次
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
			score[i][j] = 51 + rand() % 50;
		}
	printf("已经产生一组随机数.\n");
}//end of randdata

//按名次输出成绩前几名
void outputbyrank(int n)
{
	int i, r = 1,same;

	printf("\n\n按名次输出前%d名单\n\n" ,n);

	printf("\n名次\t学号\tC语言\t数学\t英语\t总分\n");
	printf("============================================\n");

	while ( r <= n) //r代表名次，从1开始递增
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (rank[i][0] == r) //第i行第0列记录了i号同学的总分名次
			{
				printf("%d\t%d\t%d\t" , rank[i][0],i,score[i][1]);
				printf("%d\t%d\t" , score[i][2],score[i][3]);
				printf("%d\n" , score[i][0]);
				same ++ ;
			}		
		}
		r += same ; //r ++ ;
	}

	printf("===========================================\n");

	if (n == N)
	{
		printf("\t总分：\t" );
		printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
		printf("\n\t平均：\t" );
		printf("%.2f\t%.2f\t%.2f\n" , 1.0*score[0][1]/N,1.0*score[0][2]/N,1.0*score[0][3]/N);
	}
}

//输出某科不及格名单
void failacourse(int courseID)
{
	int i ,count = 0 ;

	printf("\n\t%s不及格名单\n\n" , coursename[courseID] );

	printf("\n学号\t成绩\t名次\n");
	printf("======================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		if (score[i][courseID] < 60 )
		{
			count ++ ;
			printf("%d\t%d\t%d" , i,score[i][courseID],rank[i][courseID]);
			printf("\n");		
		}
	}
	printf("======================\n");
	printf("%s共有%d个同学不及格。\n" ,coursename[courseID] ,count);
}//end outputfail()

//输出不及格名单
void outputfail()
{
	failacourse(coursemenu( ));
}
 
 /*
//输出不及格名单
void outputfail()
{
	int i ,count = 0 ;

	printf("\n\t不及格名单\n\n" );

	printf("\n学号\t成绩\t名次\n");
	printf("======================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		if (score[i] < 60 )
		{
			count ++ ;
			printf("%d\t%d\t%d" , i,score[i],rank[i]);
			printf("\n");		
		}
	}
	printf("======================\n");
	printf("共有%d个同学不及格。\n" ,count);
}//end outputfail()
*/


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
		case '1': //C语言

		case '2': //数学

		case '3': //英语		
			inputbyCrsId(choice-48);//按课程号输入某科成绩
			break;

		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()

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
