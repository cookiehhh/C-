/*
版本2
程序功能：管理一个班级一门课的成绩(成绩为整数)。
使用1维数组score，舍弃0号元素,下标代表学号。
利用1维数组rank，保存每个同学的名次。
用2级菜单管理所有的输出功能。

日期：2017.11.13
*/

#include <stdio.h>
#include <conio.h>

#define N 38
int score[N+1]; //全局数组，舍弃0号元素,下标代表学号。
int rank[N+1] ; //全局数组，保存名次。
int max , min ,total = 0;
double aver;

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
	printf(" 3. 按名次输出Top n\n");
	printf(" 4. 输出不及格名单\n");
	printf(" 0. 返回主菜单    \n");
	printf("=================\n");
}//end outputmenu( )

//按学号输出成绩
void outputbyno( )
{
	int i ;

	printf("\n\n按学号输出\n\n" );

	printf("\n学号\t成绩\t名次\n");
	printf("======================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%d\t%d\t%d" , i, score[i], rank[i]);
		printf("\n");
	}
	printf("======================\n");

	printf("\n平均分：%.2f\n" , aver);
	printf("最高分：%d\n" , max);
	printf("最低分：%d\n" , min);
}// end outputbyno( )

//输入成绩
void input( )
{
	int i ;
	
	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("请输入第%d个同学的成绩：",i);
			scanf("%d",&score[i]);
			if (score[i]>100 || score[i] <0)
				printf("成绩错误！");
		}while(score[i]>100 || score[i] <0);
	}	
}//end input( )

//统计成绩
void process()
{
	int i ;
	total = 0 ;
	max = score[1] ;
	min = score[1] ;

	for (i = 1 ; i <= N ; i ++)
	{
		total += score[i] ;

		if (score[i] > max)
			max = score[i];	

		if (score[i] < min)
			min = score[i];	
	}
	aver = (double)total / N;
	printf("已经完成统计!\n");
}

//成绩排序
void sortfun()
{
	int i , j ;

	for (i = 1 ; i <= N ; i++)
		rank[i] = 1 ;

	for ( i = 1 ; i < N  ; i ++)
	{
		for ( j = i+1 ; j <= N ; j++)
		{
			if (score [i] > score [j])
				rank [j] ++ ;
			else if (score [i] < score [j])
				rank [i] ++ ;	
		}
	}
	printf("名次已经排序！");
}

//产生随机数作为测试数据
void randdata()
{
	int i;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
	{
		score[i] = 51 + rand() % 50;
	}
	printf("已经产生一组随机数.\n");
}//end of randdata

//按名次输出成绩前几名
void outputbyrank(int n)
{
	int i, r = 1, same;

	printf("\n\n按名次输出前%d名单\n\n" ,n);
	printf("名次\t学号\t成绩\n");
	printf("======================\n");
	while ( r <= n) //r代表名次，从1开始递增
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (rank[i] == r)
			{
				printf("%d\t%d\t%d\n"  ,rank[i], i , score[i]);
				same ++ ;
			}
		
		}
		r += same ; //r ++ ;
	}
	printf("======================\n");
}

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
}//end 

//调用输出二级菜单，进行处理
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
			outputbyno( );//按学号输出
			break;
		case '2':
			outputbyrank(N);//按名次输出所有成绩
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
			outputfail();//按名次输出所有成绩
			break;

		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}

main()
{
	char choice , n;

	while (1)
	{
		system("cls");
		ListMenu();

		printf("请输入你的选择：");
		//scanf("%c" , &choice);
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
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
