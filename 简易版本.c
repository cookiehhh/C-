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

//int people;//ȫ�ֱ���

void MainMenu()
{
	printf("*********���˵�**********\n");
	printf("      1.��������         \n");
	printf("      2.��ѯ����         \n");
	printf("      3.��͡���ƽ��     \n");
	printf("      4.��������         \n");
	printf("      5.�������         \n");
	printf("      6.�޸�����         \n");
	printf("      7.ɾ������         \n");
	printf("      8.�ļ�����        \n");
	printf("      9.�ļ���ȡ        \n");
	printf("      0.�˳�����         \n");
	printf("*************************\n");
}

void InputMenu()
{
	printf("         ����˵�           \n");						
	printf("----------------------------\n");
	printf("     1. ����ѧ��ѧ��		\n");
	printf("     2. ����ѧ������        \n");
	printf("     3. ����ѧ���ɼ�        \n");
	printf("     0. �������˵�	    	\n");
	printf("----------------------------\n");
}

void InputScoreMenu()
{
	printf("       ����ɼ��˵�         \n");						
	printf("----------------------------\n");
	printf("    1. ������ѧ�ɼ�			\n");
	printf("    2. ����Ӣ��ɼ�         \n");
	printf("    3. ����C���Գɼ�        \n");
	printf("    0. �����ϼ��˵�			\n");
	printf("----------------------------\n");
}

void SearchMenu()
{
	printf("         ��ѯ�˵�           \n");			
	printf("----------------------------\n");
	printf("  1. ��ѧ�Ų�ɼ�			\n");
	printf("  2. �������ɼ���ѧ�š����� \n");
	printf("  3. ���ɼ��β�ѧ�š�����   \n");
	printf("  0. �������˵�	       		\n");
	printf("----------------------------\n");
}

void OutputMenu()
{
	printf("         ����˵�           \n");				
	printf("----------------------------\n");
	printf("   1. ���ȫ��ѧ���ɼ�     	\n");
	printf("   2. ���ȫ�಻����ѧ��    \n");
	printf("   3. ���ĳ��ǰ����ѧ��    \n");
	printf("   0. �������˵�			\n");
	printf("----------------------------\n");
}

void RewriteMenu()
{
	printf("         �޸Ĳ˵�           \n");						
	printf("----------------------------\n");
	printf("     1. �޸�ѧ��ѧ��		\n");
	printf("     2. �޸�ѧ������        \n");
	printf("     3. �޸�ѧ���ɼ�        \n");
	printf("     0. �������˵�	    	\n");
	printf("----------------------------\n");
}

void RewriteScoreMenu()
{
	printf("       �޸ĳɼ��˵�         \n");						
	printf("----------------------------\n");
	printf("    1. �޸���ѧ�ɼ�			\n");
	printf("    2. �޸�Ӣ��ɼ�         \n");
	printf("    3. �޸�C���Գɼ�        \n");
	printf("    0. �����ϼ��˵�			\n");
	printf("----------------------------\n");
}

void DeletMenu()
{
	printf("         ɾ���˵�           \n");						
	printf("----------------------------\n");
	printf("     1. ��ѧ��ѧ��ɾ��		\n");
	printf("     2. ��ѧ������ɾ��      \n");
	printf("     0. �������˵�	    	\n");
	printf("----------------------------\n");
}

void Inputnumber()
{
	int i , choice;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n�������%d��ѧ����ѧ�ţ�" , i+1);
		scanf("%d", &stu[i].number);
		
		//people++;

		printf("�Ƿ�������룿(1.���� ����.����)\n");
		scanf("%d", &choice);
		if(choice != 1)
			break;

	}
}
//����ѧ������
void Inputname()
{
	int i ;

	if(people == 0)
	{
		printf("��������ѧ��ѧ��\n");

		return;
	}

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n�������%d��ѧ����������" , i+1);
		scanf("%s", stu[i].name);
	}
}
//������ѧ�ɼ�
void Inputmath()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n�������%d��ѧ������ѧ�ɼ���" , i+1);
		scanf("%d", &stu[i].math);
	}
}
//����Ӣ��ɼ�
void Inputenglish()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n�������%d��ѧ����Ӣ��ɼ���" , i+1);
		scanf("%d", &stu[i].english);
	}
}
//����C���Գɼ�
void InputClanguage()
{
	int i ;

	for (i = 0 ; i < people ; i++ )
	{
		printf("\n�������%d��ѧ����C���Գɼ���" , i+1);
		scanf("%d", &stu[i].Clanguage);
	}
}
//�����˵�����ɼ�
void InputScore()
{
	char choice , n;
	
	if(people == 0)
	{
		printf("��������ѧ��ѧ��\n");

		return;
	}

	while (1)
	{
		system("cls");
		InputScoreMenu();

		printf("������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�����ϼ��˵���\n");
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
			printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();	
	}
}
//�����˵���������
void Input()
{
	char choice , n;

	while (1)
	{
		system("cls");
		InputMenu();

		printf("������ѡ��");
		choice = getche();//scanf("%c",&choice);
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
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
			printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();	
	}
}
//��ѧ�Ų�ɼ�
void SearchByNo()
{
	int i, no, key = 0;
	
	system("cls");
	printf("����������Ҫ��ѯ��ѧ�ţ�");
	scanf("%d", &no);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(no == stu[i].number)
		{
			printf("������£�\n\n");
			printf("ѧ��\t����\t��ѧ\tӢ��\tC����\t�ܷ�\tƽ����\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
			getch();
			return;
		}
	}
	printf("û���ҵ������Ϣ��");
}
//�������ɼ���ѧ�š�����
void SearchByScore()
{
	int i, j, k, math, english, Clanguage;
	char choice;
	
	system("cls");
	printf("1.��ѧ\n");
	printf("2.Ӣ��\n");
	printf("3.C����\n");
	printf("0.����\n");

	while(1)
	{
		printf("����������Ҫ��ѯ�ĳɼ���");
		choice = getche();
		printf("\n");
		
		switch(choice)
		{
			case '1':
				printf("��������ѧ�ɼ���");
				scanf("%d", &math);

				for(i = 0;i < people;i ++)
				{
					if(math == stu[i].math)
					{
						printf("������£�\n\n");
						printf("ѧ��\t����\n");
						printf("%d\t%s\n", stu[i].number, stu[i].name);
						getch();
						return;
					}
				}
				printf("û���ҵ������Ϣ��");
				break;
			case '2':
				printf("������Ӣ��ɼ���");
				scanf("%d", &english);

				for(j = 0;j < people;j ++)
				{
					if(english == stu[j].english)
					{
						printf("������£�\n\n");
						printf("ѧ��\t����\n");
						printf("%d\t%s\n", stu[j].number, stu[j].name);
						getch();
						return;
					}
				}				
				printf("û���ҵ������Ϣ��");
				break;
			case '3':
				printf("������C���Գɼ���");
				scanf("%d", &Clanguage);

				for(k = 0;k < people;k ++)
				{
					if(Clanguage == stu[k].Clanguage)
					{
						printf("������£�\n\n");
						printf("ѧ��\t����\n");
						printf("%d\t%s\n", stu[k].number, stu[k].name);
						getch();
						return;
					}
				}				
				printf("û���ҵ������Ϣ��");				
				break;
			case '0':
				return;
			default:
				printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}
}
//���ɼ��β�ѧ�š�����
void SearchByScoreRange()
{
	int i, math, english, Clanguage;
	
	system("cls");
	printf("������������ѧ��Ӣ�C���Գɼ���");
	scanf("%d%d%d", &math, &english, &Clanguage);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(math == stu[i].math && english == stu[i].english && Clanguage == stu[i].Clanguage)
		{
			printf("������£�\n\n");
			printf("ѧ��\t����\n");
			printf("%d\t%s\n", stu[i].number, stu[i].name);
			getch();
			return;	
		}	
	}
	printf("û���ҵ������Ϣ��");

}
//�����˵���ѯ
void SearchChoice()
{
	char choice;
	
	while(1)
	{
		system("cls");
		SearchMenu();

		printf("���������ѡ��");
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
				printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}
}
//��͡���ƽ��
void SumAver()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		stu[i].total = stu[i].math + stu[i].english + stu[i].Clanguage;
		stu[i].aver = (float)stu[i].total / 3;
	}
	printf("��͡���ƽ������ɣ�\n");
}
//����
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
	printf("��������ɣ�\n");
}
//���ȫ��ѧ���ɼ�
void OutputClass()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		printf("ѧ��\t����\t��ѧ\tӢ��\tC����\t�ܷ�\tƽ����\n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
	}
}
//���ȫ�಻����ѧ��
void OutputFail()
{
	int i;
	
	system("cls");
	for(i = 0;i < people;i ++)
	{
		if(stu[i].math < 60 || stu[i].english < 60 || stu[i].Clanguage < 60)
		{
			printf("ѧ��\t����\t��ѧ\tӢ��\tC����\t�ܷ�\tƽ����\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
		}
	}
}
//���ĳ��ǰ����ѧ��
void OutputTopN()
{
	int i, top;
	
	system("cls");
	printf("��������������");
	printf("\n");

	while(1)
	{
		scanf("%d", &top);
		if(top <= 0 || top > 10 || top > people)
			printf("�������д����������룡\n");
		else
			break;
	}

	for(i = 0;i < top;i ++)
	{
		printf("ѧ��\t����\t��ѧ\tӢ��\tC����\t�ܷ�\tƽ����\n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%0.2f\n", stu[i].number, stu[i].name, stu[i].math, stu[i].english, stu[i].Clanguage, stu[i].total, stu[i].aver);
	}
}
//�����˵����
void OutputChoice()
{
	char choice;

	while(1)
	{
		system("cls");
		OutputMenu();

		printf("���������ѡ��");
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
				printf("�����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}		
}

void Rewritenumber()
{
	int i, n;
	
	printf("����������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("�������޸ĺ��ѧ��ѧ�ţ�");
			scanf("%d", &stu[i].number);
			printf("�޸ĳɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Rewritename()
{
	int i;
	char n[10];
	
	printf("����������Ҫ�޸ĵ�ѧ��������");
	scanf("%s", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("�������޸ĺ��ѧ��������");
			scanf("%s", stu[i].name);
			printf("�޸ĳɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Rewritemath()
{
	int i, n;
	
	printf("����������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("�������޸ĺ����ѧ�ɼ���");
			scanf("%d", &stu[i].math);
			printf("�޸ĳɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Rewriteenglish()
{
	int i, n;
	
	printf("����������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("�������޸ĺ��Ӣ��ɼ���");
			scanf("%d", &stu[i].english);
			printf("�޸ĳɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void RewriteClanguage()
{
	int i, n;
	
	printf("����������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			printf("�������޸ĺ��C���Գɼ���");
			scanf("%d", &stu[i].Clanguage);
			printf("�޸ĳɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Rewritescore()
{
	char choice;
	
	while(1)
	{
		system("cls");
		RewriteScoreMenu();

		printf("���������ѡ��");
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
				printf("����������������룡\n");
		}
		printf("�����������...\n");
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

		printf("���������ѡ��");
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
				printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}
}

void Deletnumber()
{
	int i, n;
	
	printf("����������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			stu[i] = stu[i+1];
			printf("ɾ���ɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Deletname()
{
	int i;
	char n[10];
	
	printf("����������Ҫɾ����ѧ��������");
	scanf("%s", &n);
	printf("\n");

	for(i = 0;i < people;i ++)
	{
		if(n == stu[i].number)
		{
			stu[i] = stu[i+1];
			printf("ɾ���ɹ���");
			return;
		}
	}
	printf("û���ҵ���ѧ����");
}

void Delet()
{
	char choice;
	
	while(1)
	{
		system("cls");
		DeletMenu();

		printf("���������ѡ��");
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
				printf("����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}
}

void savefile()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","wb")) ==NULL )
	{
		printf("�޷��򿪿γ����ļ�student.dat!\n");
		exit(0);
	}
	for (i = 0 ; i < people ; i++ )
	{
		if (fwrite(&stu[i],sizeof(student),1,f1) ==1)
		{
			
		}
		else
		{
			printf("д�γ����ļ�student.datʧ�ܣ�\n");
			return;
		}
	}
	printf("д�γ����ļ�student.dat�ɹ���\n");
	
	fclose(f1);

}

void readfile()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","rb")) ==NULL )
	{
		printf("�޷��򿪿γ����ļ�student.dat!\n");
		exit(0);
	}
	for (i = 0 ; i < people ; i++ )
	{
		if (fread(&stu[i],sizeof(student),1,f1) ==1)
		{
			
		}
		else
		{
			printf("���γ����ļ�student.datʧ�ܣ�\n");
			return;
		}

	}
	printf("���γ����ļ�student.dat�ɹ���\n");
	
	fclose(f1);
}

int main(void)
{
	char choice;

	while(1)
	{
		system("cls");
		MainMenu();

		printf("���������ѡ��");
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
				printf("лл��ʹ�ñ�ϵͳ��\n");
				getch();
				return 0;
			default:
				printf("�����������������룡\n");
		}
		printf("�����������...\n");
		getch();
	}	
}

