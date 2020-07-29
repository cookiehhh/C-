/*
版本1.0
程序功能：reuse之前编写的排序函数.c、查找函数.c
考虑到输入大量测试数据耗费时间，加入一个模块，
可以随机产生测试数据。

日期：2017.12.8
*/

#define N 50
#include <stdio.h>
#include "排序函数.c"
#include "查找函数.c"

void ListMenu( )
{
	printf("   查找排序菜单  \n");
	printf("=================\n");
	printf(" 1. 输入测试数据 \n");
	printf(" 2. 输出数据     \n");
	printf(" 3. 产生随机数据 \n");
	printf(" 4. 冒泡排序     \n");
	printf(" 5. 选择排序     \n");
	printf(" 6. 顺序查找     \n");
	printf(" 7. 折半查找     \n");
	printf(" 0. 退出         \n");
	printf("=================\n");
}//end ListMenu( )

//输入数据
void input(int elem[] , int length)
{
	int i ;

	for (i = 1 ; i <= length ; i++ )
	{
		printf("请输入第%d个数据：" ,i);
		scanf("%d" , &elem[i]);
	}
}// end input

//输出数据
void output(int elem[] , int length)
{
	int i ;

	printf("\n数据如下：\n" );
	for (i = 1 ; i <= length ; i++ )
	{
		printf("%d\t" , elem[i]);		
	}
}//end output


//产生随机数据
void randdata(int elem[] , int length)
{
	int i ;

	//srand();//产生一个随机数种子
	srand((unsigned)time(NULL));

	for (i = 1 ; i <= length ; i++ )
	{
		elem[i] = rand();
	}
	printf("已经产生了%d个随机数据！\n" ,N);
}

main()
{
	char choice ;
	int key ,location ;
	int data[N+1]; //约定：舍弃0号元素

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
			input(data ,N);
			break;
		case '2':
			output(data ,N);
			break;
		case '3':
			randdata(data ,N);
			break;
		case '4':
			bubblesort(data ,N);
			printf("已经排好序！\n");
			break;
		case '5':
			selectsort(data ,N);
			printf("已经排好序！\n");
			break;
		case '6':
			printf("请输入要查找的数据：");
			scanf("%d" , &key);
			location = 	search_seq(data, N ,key);

			if (location == 0)
				printf("未找到%d\n" ,key);
			else 
				printf("找到%d,在第%d个位置\n" ,key,location);
			
			break;
		case '7':
			printf("请输入要查找的数据：");
			scanf("%d" , &key);
			location = 	search_bin(data, N ,key);

			if (location == 0)
				printf("未找到%d\n" ,key);
			else 
				printf("找到%d,在第%d个位置\n" ,key,location);
			
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
