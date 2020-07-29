/*
文本菜单第三版，多路分支，模块化设计
2017.9.25
*/



void ListC()
{
	printf("C语言：2317 ，4学分\n");
	printf("认课教师：刘学，OFFICE:周一下午1：30\n");
}

void ListCsharp()
{
	printf("C#语言：4210 ，6学分\n");
	printf("认课教师：刘益红，OFFICE:周三下午1：30\n");
}

void ListJava()
{	
	printf("Java语言：4208 ，6学分\n");
	printf("认课教师：赵，OFFICE:周四下午1：30\n");
}


//主函数
main()
{
	int choice;

	void ListMenu(); //函数声明
	ListMenu(); //函数调用

	printf("输入你的选择：");
	scanf("%d" , &choice);

	if (choice == 1)
		ListC();
	else if (choice == 2)
		ListCsharp();
	else if (choice == 3)
		ListJava();
	else 
		printf("输入错误！\n");

	getch();
}

//显示文本菜单
void ListMenu()
{
	printf("  课程菜单\n");
	printf("===========\n");
	printf("1.C语言\n");
	printf("2.C#语言\n");
	printf("3.Java语言\n");
	printf("===========\n");
}
