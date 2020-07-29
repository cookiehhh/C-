#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define studentNum 10
#define people 3


typedef struct
{
	int number;
	char name[10];
	int math;
	int english;
	int Clanguage;
	int total;
	float aver;
}student,Temp;

student stu[studentNum];

Temp temp;

//int people;//全局变量

void MainMenu()
{
	printf("*********主菜单**********\n");
	printf("      1.输入数据         \n");
	printf("      2.查询数据         \n");
	printf("      3.求和、求平均     \n");
	printf("      4.数据排序         \n");
	printf("      5.输出数据         \n");
	printf("      6.修改数据         \n");
	printf("      7.删除数据         \n");
	printf("      8.文件存盘        \n");
	printf("      9.文件读取        \n");
	printf("      0.退出程序         \n");
	printf("*************************\n");
}

void InputMenu()
{
	printf("         输入菜单           \n");						
	printf("----------------------------\n");
	printf("     1. 输入学生学号		\n");
	printf("     2. 输入学生姓名        \n");
	printf("     3. 输入学生成绩        \n");
	printf("     0. 返回主菜单	    	\n");
	printf("----------------------------\n");
}

void InputScoreMenu()
{
	printf("       输入成绩菜单         \n");						
	printf("----------------------------\n");
	printf("    1. 输入数学成绩			\n");
	printf("    2. 输入英语成绩         \n");
	printf("    3. 输入C语言成绩        \n");
	printf("    0. 返回上级菜单			\n");
	printf("----------------------------\n");
}

void SearchMenu()
{
	printf("         查询菜单           \n");			
	printf("----------------------------\n");
	printf("  1. 按学号查成绩			\n");
	printf("  2. 按单个成绩查学号、姓名 \n");
	printf("  3. 按成绩段查学号、姓名   \n");
	printf("  0. 返回主菜单	       		\n");
	printf("----------------------------\n");
}

void OutputMenu()
{
	printf("         输出菜单           \n");				
	printf("----------------------------\n");
	printf("   1. 输出全班学生成绩     	\n");
	printf("   2. 输出全班不及格学生    \n");
	printf("   3. 输出某班前几名学生    \n");
	printf("   0. 返回主菜单			\n");
	printf("----------------------------\n");
}

void RewriteMenu()
{
	printf("         修改菜单           \n");						
	printf("----------------------------\n");
	printf("     1. 修改学生学号		\n");
	printf("     2. 修改学生姓名        \n");
	printf("     3. 修改学生成绩        \n");
	printf("     0. 返回主菜单	    	\n");
	printf("----------------------------\n");
}

void RewriteScoreMenu()
{
	printf("       修改成绩菜单         \n");						
	printf("----------------------------\n");
	printf("    1. 修改数学成绩			\n");
	printf("    2. 修改英语成绩         \n");
	printf("    3. 修改C语言成绩        \n");
	printf("    0. 返回上级菜单			\n");
	printf("----------------------------\n");
}

void DeletMenu()
{
	printf("         删除菜单           \n");						
	printf("----------------------------\n");
	printf("     1. 按学生学号删除		\n");
	printf("     2. 按学生姓名删除      \n");
	printf("     0. 返回主菜单	    	\n");
	printf("----------------------------\n");
}

void Inputnumber()
{
	int i , choice;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n请输入第%d个学生的学号：" , i+1);
		scanf("%d", &stu[i].number);
		
		//people++;

		printf("是否继续输入？(1.继续 其他.返回)\n");
		scanf("%d", &choice);
		if(choice != 1)
			break;

	}
}
//输入学号姓名
void Inputname()
{
	int i ;

	if(people == 0)
	{
		printf("请先输入学生学号\n");

		return;
	}

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n请输入第%d个学生的姓名：" , i+1);
		scanf("%s", stu[i].name);
	}
}
//输入数学成绩
void Inputmath()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n请输入第%d个学生的数学成绩：" , i+1);
		scanf("%d", &stu[i].math);
	}
}
//输入英语成绩
void Inputenglish()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n请输入第%d个学生的英语成绩：" , i+1);
		scanf("%d", &stu[i].english);
	}
}
//输入C语言成绩
void InputClanguage()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n请输入第%d个学生的C语言成绩：" , i+1);
		scanf("%d", &stu[i].Clanguage);
	}
}
//二级菜单输入成绩
void InputScore()
{
	char choice , n;
	
	if(people == 0)
	{
		printf("请先输入学生学号\n");

		return;
	}

	while (1)
	{
		system("cls");
		InputScoreMenu();

		printf("请输入选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回上级菜单！\n");
			return;

		case '1': 
			Inputmath();
			break;

		case '2': 
			Inputenglish();
			break;

		case '3': 
			InputClanguage();
			break;

		default :
			printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();	
	}
}
//二级菜单输入数据
void Input()
{
	char choice , n;

	while (1)
	{
		system("cls");
		InputMenu();

		printf("请输入选择：");
		choice = getche();//scanf("%c",&choice);
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("返回主菜单！\n");
			return;

		case '1': 
			Inputnumber();
			break;

		case '2':			
			Inputname();
			break;

		case '3':			
			InputScore();
			break;

		default :
			printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();	
	}
}
//按学号查成绩
void SearchByNo()
{
	int i, no, key = 0;
	
	system("cls");
	printf("请输入你想要查询的学号：");
	scanf("%d", &no);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(no == stu[i].number)
		{
			printf("结果如下：\n\n");
			printf("学号\t姓名\t数学\t英语\tC语言\t总分\t平均分\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
			getch();
			return;
		}
	}
	printf("没有找到相关信息！");
}
//按单个成绩查学号、姓名
void SearchByScore()
{
	int i, j, k, math, english, Clanguage;
	char choice;
	
	system("cls");
	printf("1.数学\n");
	printf("2.英语\n");
	printf("3.C语言\n");
	printf("0.返回\n");

	while(1)
	{
		printf("请输入你想要查询的成绩：");
		choice = getche();
		printf("\n");
		
		switch(choice)
		{
			case '1':
				printf("请输入数学成绩：");
				scanf("%d", &math);

				for(i = 0;i < people;i ++)
				{
					if(math == stu[i].math)
					{
						printf("结果如下：\n\n");
						printf("学号\t姓名\n");
						printf("%d\t%s\n", stu[i].number, stu[i].name);
						getch();
						return;
					}
				}
				printf("没有找到相关信息！");
				break;
			case '2':
				printf("请输入英语成绩：");
				scanf("%d", &english);

				for(j = 0;j < people;j ++)
				{
					if(english == stu[j].english)
					{
						printf("结果如下：\n\n");
						printf("学号\t姓名\n");
						printf("%d\t%s\n", stu[j].number, stu[j].name);
						getch();
						return;
					}
				}				
				printf("没有找到相关信息！");
				break;
			case '3':
				printf("请输入C语言成绩：");
				scanf("%d", &Clanguage);

				for(k = 0;k < people;k ++)
				{
					if(Clanguage == stu[k].Clanguage)
					{
						printf("结果如下：\n\n");
						printf("学号\t姓名\n");
						printf("%d\t%s\n", stu[k].number, stu[k].name);
						getch();
						return;
					}
				}				
				printf("没有找到相关信息！");				
				break;
			case '0':
				return;
			default:
				printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}
}
//按成绩段查学号、姓名
void SearchByScoreRange()
{
	int i, math, english, Clanguage;
	
	system("cls");
	printf("请依次输入数学、英语、C语言成绩：");
	scanf("%d%d%d", &math, &english, &Clanguage);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(math == stu[i].math && english == stu[i].english && Clanguage == stu[i].Clanguage)
		{
			printf("结果如下：\n\n");
			printf("学号\t姓名\n");
			printf("%d\t%s\n", stu[i].number, stu[i].name);
			getch();
			return;	
		}	
	}
	printf("没有找到相关信息！");

}
//二级菜单查询
void SearchChoice()
{
	char choice;
	
	while(1)
	{
		system("cls");
		SearchMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				SearchByNo();
				break;
			case '2':
				SearchByScore();
				break;
			case '3':
				SearchByScoreRange();
				break;
			case '0':
				return;
			default:
				printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}
}
//求和、求平均
void SumAver()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		stu[i].total = stu[i].math + stu[i].english + stu[i].Clanguage;
		stu[i].aver = (float)stu[i].total / 3;
	}
	printf("求和、求平均已完成！\n");
}
//排序
void Sort()
{
	int i, j;
	
	system("cls");
	for(i = 0;i < people - 1;i ++)
	{
		for(j = 0;j < people - 1 - i;j ++)
		{
			if(stu[j].total < stu[j+1].total)
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
		}
	}
	printf("排序已完成！\n");
}
//输出全班学生成绩
void OutputClass()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		printf("学号\t姓名\t数学\t英语\tC语言\t总分\t平均分\n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
	}
}
//输出全班不及格学生
void OutputFail()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		if(stu[i].math < 60 || stu[i].english < 60 || stu[i].Clanguage < 60)
		{
			printf("学号\t姓名\t数学\t英语\tC语言\t总分\t平均分\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
		}
	}
}
//输出某班前几名学生
void OutputTopN()
{
	int i, top;
	
	system("cls");
	printf("请输入名次数：");
	printf("\n");

	while(1)
	{
		scanf("%d", &top);
		if(top <= 0 || top > 10 || top > people)
			printf("名次数有错！请重新输入！\n");
		else
			break;
	}

	for(i = 0;i < top;i ++)
	{
		printf("学号\t姓名\t数学\t英语\tC语言\t总分\t平均分\n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
	}
}
//二级菜单输出
void OutputChoice()
{
	char choice;

	while(1)
	{
		system("cls");
		OutputMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				OutputClass();
				break;
			case '2':
				OutputFail();
				break;
			case '3':
				OutputTopN();
				break;
			case '0':
				return;
			default:
				printf("输入有误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}		
}

void Rewritenumber()
{
	int i, n;
	
	printf("请输入你想要修改的学生学号：");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("请输入修改后的学生学号：");
			scanf("%d", &stu[i].number);
			printf("修改成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Rewritename()
{
	int i;
	char n[10];
	
	printf("请输入你想要修改的学生姓名：");
	scanf("%s", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("请输入修改后的学生姓名：");
			scanf("%s", stu[i].name);
			printf("修改成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Rewritemath()
{
	int i, n;
	
	printf("请输入你想要修改的学生学号：");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("请输入修改后的数学成绩：");
			scanf("%d", &stu[i].math);
			printf("修改成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Rewriteenglish()
{
	int i, n;
	
	printf("请输入你想要修改的学生学号：");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("请输入修改后的英语成绩：");
			scanf("%d", &stu[i].english);
			printf("修改成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void RewriteClanguage()
{
	int i, n;
	
	printf("请输入你想要修改的学生学号：");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("请输入修改后的C语言成绩：");
			scanf("%d", &stu[i].Clanguage);
			printf("修改成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Rewritescore()
{
	char choice;
	
	while(1)
	{
		system("cls");
		RewriteScoreMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				Rewritemath();
				break;
			case '2':
				Rewriteenglish();
				break;
			case '3':
				RewriteClanguage();
				break;
			case '0':
				return;
			default:
				printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}
}

void Rewrite()
{
	char choice;
	
	while(1)
	{
		system("cls");
		RewriteMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				Rewritenumber();
				break;
			case '2':
				Rewritename();
				break;
			case '3':
				Rewritescore();
				break;
			case '0':
				return;
			default:
				printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}
}

void Deletnumber()
{
	int i, n;
	
	printf("请输入你想要删除的学生学号：");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			stu[i] = stu[i+1];
			printf("删除成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Deletname()
{
	int i;
	char n[10];
	
	printf("请输入你想要删除的学生姓名：");
	scanf("%s", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			stu[i] = stu[i+1];
			printf("删除成功！");
			return;
		}
	}
	printf("没有找到该学生！");
}

void Delet()
{
	char choice;
	
	while(1)
	{
		system("cls");
		DeletMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				Deletnumber();
				break;
			case '2':
				Deletname();
				break;
			case '0':
				return;
			default:
				printf("输入错误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}
}

void savefile()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","wb")) ==NULL )
	{
		printf("无法打开课程名文件student.dat!\n");
		exit(0);
	}
	for (i = 0 ; i < people ; i++ )
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

void readfile()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","rb")) ==NULL )
	{
		printf("无法打开课程名文件student.dat!\n");
		exit(0);
	}
	for (i = 0 ; i < people ; i++ )
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

int main(void)
{
	char choice;

	while(1)
	{
		system("cls");
		MainMenu();

		printf("请输入你的选择：");
		choice = getche();
		printf("\n");

		switch(choice)
		{
			case '1':
				Input();
				break;
			case '2':
				SearchChoice();
				break;
			case '3':
				SumAver();
				break;
			case '4':
				Sort();
				break;
			case '5':
				OutputChoice();
				break;
			case '6':
				Rewrite();
				break;
			case '7':
				Delet();
				break;
			case '8':
				savefile();
				break;
			case '9':
				readfile();
				break;
			case '0':
				printf("谢谢你使用本系统！\n");
				getch();
				return 0;
			default:
				printf("输入有误！请重新输入！\n");
		}
		printf("按任意键继续...\n");
		getch();
	}	
}

