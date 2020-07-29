/*
版本4.1
程序功能：管理一个班级多门课的成绩(成绩为整数)。
使用结构体数组，每个数组元素对应一个同学，
包括学号、姓名、多门课的成绩、名次，总分，总名次。

利用2维字符数组管理与课程名，课程名从键盘输入。
加入文件操作。

日期：2018.1.15
*/

#include <stdio.h>
#include <conio.h>

#define N 5
#define CrsNum 3

//全局二维数组保存课程名称，也可以从键盘输入
char coursename[CrsNum+1][10]={"总分" ,"C语言" , "数学" ,"英语"};

//结构体类型
typedef  struct 
{
	char ID[10];   //学号
	char name[10]; //姓名
	int score[CrsNum ]; //各科成绩
	int rank[CrsNum ];  //各科名次
	int total;			//总分
	double average ;	//平均分
	int totalrank;		//总名次
}  STU ;

// 全局数组J12004保存全班同学信息
STU J12004[N];

int sorted = 0;

void ListMenu( )
{
	printf("   成绩管理菜单  \n");
	printf("=================\n");
	printf(" 1. 输入         \n");
	printf(" 2. 统计处理     \n");
	printf(" 3. 名次排序     \n");
	printf(" 4. 输出         \n");
	printf(" 5. 文件存盘     \n");
	printf(" 6. 文件读取     \n");
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
	printf(" 1. 课程名称\n");
	printf(" 2. 学生姓名\n");
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

void inputStuname()
{
	int i ;

	for (i = 0 ; i < N ; i++ )
	{
		printf("\n请输入第%d个学生的学号(如J1200401)：" , i +1);
		gets(J12004[i].ID);	

		printf("\n请输入第%d个学生的姓名：" , i +1);
		gets(J12004[i].name);	
	}
}//end inputStuname()

//课程名菜单
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

/*
void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("请依次输入第%d科%s的成绩：\n\n",CrsId,coursename[CrsId]);

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
	sorted = 0 ;
}//end inputbyCrsId( )

void inputallCrs()
{
	int i , j ;
	
	printf("\n请依次输入每个同学每一科的成绩：\n");
	printf("学号\t姓名");

	for (j = 1 ; j <= CrsNum ; j++ )
		printf("\t%s" , coursename[j]);
		
	for (i = 1 ; i <= N ; i++)
	{
		printf("\n%d\t%s\t",i ,name[i]);
		for ( j = 1 ; j <= CrsNum ; j++)
		{
			do
			{
				scanf("%d",&score[i][j]);
				if (score[i][j]>100 || score[i][j] <0)
					printf("%s同学%s成绩错误！请重新输入！" ,name[i],coursename[j]);
			}while(score[i][j]>100 || score[i][j] <0);
	
		}//end for j
	}// end foe i
	sorted = 0 ;
}// end inputallCrs()

void outputbyno( )
{
	int i ;

	printf("\n\n按学号输出\n\n" );

	printf("\n学号\t姓名");
	for (i = 1 ; i <= CrsNum ; i ++)
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
	sorted = 1 ;
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
	sorted = 0 ;
}//end of randdata

//按名次输出成绩前几名
void outputbyrank(int n)
{
	int i, r = 1,same;

	if (sorted == 0 )
	{
		printf("成绩未排序！");
		printf("请先执行主菜单中的排序功能！");
		return ;
	}

	printf("\n\n按名次输出前%d名单\n\n" ,n);

	printf("\n名次\t学号\t姓名");
	for (i = 1 ; i <= CrsNum ; i ++)
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

	for ( i = 1 ; i <= N ; i++)
	{
		count = 0 ;
		for ( j = 1 ; j <= CrsNum ; j++)
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
*/
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
/*
		case '3': //输入成绩
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);//按课程号输入某科成绩
			else 
				inputallCrs(); //一起输入所有课程成绩
			break;
*/
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()

void savefile()
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

}//end savefile()

void readfile( )
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
	coursemenu( );
}// end readfile( )

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
/*
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
*/
		case '5':
			savefile( );//文件存盘
			break;
		case '6':
			readfile( );//文件读取
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
