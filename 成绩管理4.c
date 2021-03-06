/*
版本4.0
程序功能：管理一个班级多门课的成绩(成绩为整数)。
使用结构体数组，每个数组元素对应一个同学，
包括学号、姓名、多门课的成绩、名次，总分，总名次。

利用2维字符数组管理课程名，课程名从键盘输入。

日期：2017.12.28
*/

#include <stdio.h>
#include <conio.h>
#include "成绩头文件.c"

#define N 5
#define CrsNum 3

//全局二维数组保存课程名称，也可以从键盘输入
char coursename[CrsNum+1][10]={"总分" ,"C语言" , "数学" ,"英语"};
int  coursetotal[CrsNum+1];//保存各科总分，0号保存所有总分

//结构体类型
typedef  struct 
{
	char ID[10];   //学号
	char name[10]; //姓名
	int score[CrsNum +1]; //各科成绩,舍弃0号元素
	int rank[CrsNum +1];  //各科名次,舍弃0号元素
	int total;			//总分
	double average ;	//平均分
	int totalrank;		//总名次
}  STU ;

// 全局数组J15011保存全班同学信息
STU  J15011[N+1]; //为与前面版本兼容，舍弃0号元素

int sorted = 0; // 是否已经排序

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
			input( );//输入
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
	printf(" 1. 输入         \n");
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
	printf(" 1. 课程名称\n");
	printf(" 2. 学号、姓名\n");
	printf(" 3. 成绩\n");
	printf(" 0. 返回主菜单    \n");
	printf("=================\n");
}//end inputmenu( )

//输入课程名称
void inputCrsname()
{
	int i ;

	for (i = 1 ; i <= CrsNum ; i++ )
	{
		printf("\n请输入课程%d的名称：" , i);
		gets(coursename[i]);		
	}
}//end inputCrsname

//输入学号、姓名
void inputStuname()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n请输入第%d个学生的学号(如J1501101)：" , i);
		gets(J15011[i].ID);	

		printf("\n请输入第%d个学生的姓名：" , i);
		gets(J15011[i].name);	
	}
}//end inputStuname()

//课程名菜单，返回课程号1，2，3
int  coursemenu( )
{
	char courseID;
	int i ;

	printf("      科目\n");
	printf("=================\n");
	printf(" 0. 所有科目\n");

	for ( i = 1 ; i <= CrsNum ; i++)
		printf(" %d. %s\n" , i , coursename[i]);
	printf("=================\n");

	do
	{
		printf(" 请选择的科目:");
		courseID = getche();
		if (courseID < '0' || courseID > '0'+CrsNum)
			printf("输入错误！课程号0-%d" , CrsNum );	
	}while (courseID < '0' || courseID > '0'+CrsNum);

	return (courseID - 48);
}//end coursemenu( )

//按课程号输入单科成绩
void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("\n请依次输入第%d科%s的成绩：\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("请输入第%d个同学%s的成绩：",i ,J15011[i].name);
			scanf("%d",&J15011[i].score[CrsId]);
			if (J15011[i].score[CrsId]>100 || J15011[i].score[CrsId] <0)
				printf("成绩错误！");
		}while(J15011[i].score[CrsId]>100 || J15011[i].score[CrsId] <0);
	}
	sorted = 0 ;
}//end inputbyCrsId( )

//输入所有科目成绩
void inputallCrs()
{
	int i , j ;
	
	printf("\n请依次输入每个同学每一科的成绩：\n");
	printf("学号\t姓名");

	for (j = 1 ; j <= CrsNum ; j++ )
		printf("\t%s" , coursename[j]);
		
	for (i = 1 ; i <= N ; i++)
	{
		printf("\n%d\t%s\t",J15011[i].ID,J15011[i].name);
		for ( j = 1 ; j <= CrsNum ; j++)
		{
			do
			{
				scanf("%d",&J15011[i].score[j]);
				if (J15011[i].score[j]>100 || J15011[i].score[j] <0)
					printf("%s同学%s成绩错误！请重新输入！" ,J15011[i].name,coursename[j]);
			}while(J15011[i].score[j]>100 || J15011[i].score[j] <0);
	
		}//end for j
	}// end foe i
	sorted = 0 ;
}// end inputallCrs()


void outputbyno( )//按学号输出成绩
{
	int i , j;

	printf("\n\n按学号输出\n\n" );

	printf("\n学号\t姓名\t");
	for (j = 1 ; j <= CrsNum ; j ++)//课程号
		printf("\t%s" , coursename[j]);//课程名
	printf("\t总分\t平均分\t名次\n");

	printf("====================================================================\n");

	for ( i = 1 ; i <= N ; i++) //结构体数组下标
	{
		printf("%s\t" ,J15011[i].ID);
		printf("%s\t\t" ,J15011[i].name);
		
		for (j = 1 ; j <= CrsNum ; j ++)//课程号
			printf("%d\t" , J15011[i].score[j]);//各科成绩
	
		printf("%d\t" , J15011[i].total);//总分
		printf("%.2f\t" , J15011[i].average);//平均分
		printf("%d\n" , J15011[i].totalrank);//总名次
	}
	printf("===================================================================\n");

	printf("\t\t总分：\t" );
	for (j = 1 ; j <= CrsNum ; j ++)//课程号
		printf("%d\t" , coursetotal[j]);//各科总分
	printf("%d\t" , coursetotal[0]);//所有总分

	printf("\n\t\t平均：\t" );
	for (j = 1 ; j <= CrsNum ; j ++)//课程号
		printf("%.2f\t" , 1.0*coursetotal[j]/N);//各科平均分
	printf("%.2f\n" , 1.0*coursetotal[0]/N);//所有科平均分
}// end outputbyno( )


//统计各科、各个同学的总分
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		J15011[i].total = 0 ;//各个同学的总分清0

	for (j = 0 ; j <= CrsNum ; j ++)
		coursetotal[j] = 0 ; //各科总分清0


	for (i = 1 ; i <= N ; i ++)//结构体数组下标
	{
		for ( j = 1 ; j <= CrsNum ; j ++ )//课程号
		{
			J15011[i].total += J15011[i].score[j] ;//计算第i个同学总分
			coursetotal[j] +=  J15011[i].score[j] ;//计算第j科总分
		}
		J15011[i].average = 1.0*J15011[i].total / CrsNum;//计算第i个同学平均分
		coursetotal[0] += J15011[i].total; //0号元素保存所有科目总成绩
	}
	printf("已经完成统计!\n");
}


//可以按照单科或者总分对名次排序
void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) //结构体数组的下标
	{
		J15011[i].totalrank = 1;//总名次初值
		for ( k = 1 ; k <= CrsNum ; k++) //课程号
			J15011[i].rank[k] = 1 ;//各科成绩名次初值
	}

	//各科成绩排序
	for( k = 1 ; k  <= CrsNum ; k++) //每门课单独排名次
	{
		for ( i = 1 ; i < N  ; i ++)//结构体数组的下标
		{
			for ( j = i+1 ; j <= N ; j++)//与后面同学pk
				if (J15011[i].score[k] > J15011[j].score[k])
					J15011[j].rank[k] ++ ;
				else if (J15011[i].score[k] < J15011[j].score[k])
					J15011[i].rank[k] ++ ;	
		}//end for i
	}//end for k

	//总分排序
	for ( i = 1 ; i < N  ; i ++)//结构体数组的下标
	{
		for ( j = i+1 ; j <= N ; j++)//与后面同学pk
			if (J15011[i].total > J15011[j].total )
				J15011[j].totalrank  ++ ;
			else if (J15011[i].total < J15011[j].total)
				J15011[i].totalrank  ++ ;	
	}//end for i

	printf("名次已经排序！");
	sorted = 1 ;
}

//产生随机数作为测试数据
void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)//结构体数组下标
		for ( j = 1 ; j <= CrsNum ; j++)//课程号
		{
			J15011[i].score[j]  = 21 + rand() % 80;
		}
	printf("已经产生一组随机数.\n");
	sorted = 0 ;
}//end of randdata


//按名次输出成绩前几名
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
	for (j = 1 ; j <= CrsNum ; j ++)
		printf("\t%s" , coursename[j]);
	printf("\t总分\n");

	printf("====================================================\n");

	while ( r <= n) //r代表名次，从1开始递增
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (J15011[i].totalrank == r) //第i行同学的总分名次
			{
				printf("%d\t" , J15011[i].totalrank);
				printf("%s\t" , J15011[i].ID);
				printf("%s\t" , J15011[i].name);
				for (j = 1 ; j <= CrsNum ; j ++)
					printf("%d\t" , J15011[i].score[j]);
				printf("%d\n" , J15011[i].total);
				same ++ ;
			}		
		}
		r += same ; //r ++ ;
	}

	printf("====================================================\n");

	if (n == N)
	{
		printf("\t\t总分：\t" );
		for (j = 1 ; j <= CrsNum ; j ++)
			printf("%d\t" , coursetotal[j]);
		printf("%d\t" , coursetotal[0]);//所有总分

		printf("\n\t\t平均：\t" );
		for (j = 1 ; j <= CrsNum ; j ++)
			printf("%.2f\t" , 1.0*coursetotal[j]/N);
		printf("%.2f\n" , 1.0*coursetotal[0]/N);//总分的平均分
	}
	printf("\n");
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
		if (J15011[i].score[courseID] < 60 )
		{
			count ++ ;
			printf("%s\t" , J15011[i].ID );
			printf("%s\t" , J15011[i].name  );
			printf("%d\t" , J15011[i].score[courseID] );
			printf("%d\n" , J15011[i].rank[courseID] );
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

	for ( i = 1 ; i <= N ; i++)
	{
		count = 0 ;
		for ( j = 1 ; j <= CrsNum ; j++)
		{
			if (J15011[i].score[j] < 60 )
			{
				if (count == 0 )
				{
					printf("%s\t%s" , J15011[i].ID,J15011[i].name);
				
					for (k = 1 ; k <j ; k++)
						printf("\t" );
				}
				printf("\t%d" , J15011[i].score[j]);
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

//输入功能
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
			inputStuname();
			break;
		case '3': //输入成绩
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);//按课程号输入某科成绩
			else 
				inputallCrs(); //一起输入所有课程成绩
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()
