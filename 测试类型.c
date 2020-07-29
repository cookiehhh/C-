/*
文本菜单第6版， 用while(1) 实现循环
用字符类型解决第5版中的异常：用户在应该输入数字时输入字符，程序不能正常运行。
2017.10.20
*/

#include <stdio.h>

//显示课程菜单
void ListMenu()
{
	printf("   课程菜单\n");
	printf(" ============\n");
	printf(" 1. short类型\n");
	printf(" 2. char类型\n");
	printf(" 3. unsigned short类型\n");
	printf(" 4. unsigned char类型\n");
	printf(" ============\n");
}

//测试short
void testshort()
{
	short  x = 32766 ; 

	printf("short占%d个字节\n"  , sizeof(short));
	printf("short变量x占%d个字节\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
}

//测试char
void testchar()
{
	char  x = 126 ; 

	printf("char占%d个字节\n"  , sizeof(char));
	printf("char变量x占%d个字节\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);

}

//测试unsigned short
void testushort()
{
	unsigned short  x = 65534 ; 

	printf("unsigned short占%d个字节\n"  , sizeof(unsigned short));
	printf("unsigned short变量x占%d个字节\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
}

//测试unsigned char
void testuchar()
{
	unsigned char  x = 254 ; 

	printf("unsigned char占%d个字节\n"  , sizeof(unsigned char));
	printf("unsigned char变量x占%d个字节\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);

}

//主函数
main()
{
	char choice;

	while(1) //永真循环
	{
		system("cls");//清屏 = clear screen
		ListMenu(); //函数调用
		printf("请输入你的选择：");
		//scanf("%c" , &choice);
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case 0:
			return ;
		case '1':
			testshort();
			break;
		case '2':
			testchar();
			break;
		case '3':
			testushort();
			break;
		case '4':
			testuchar();
			break;
		default :
			printf("输入错误！\n");
		}//end switch
		printf("Press any key to continue ......");
		getch();//从键盘输入任意字符
	}//end while
}//end main
