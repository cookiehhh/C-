/*
�汾1.0
�����ܣ�reuse֮ǰ��д��������.c�����Һ���.c
���ǵ���������������ݺķ�ʱ�䣬����һ��ģ�飬
������������������ݡ�

���ڣ�2017.12.8
*/

#define N 50
#include <stdio.h>
#include "������.c"
#include "���Һ���.c"

void ListMenu( )
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. ����������� \n");
	printf(" 2. �������     \n");
	printf(" 3. ����������� \n");
	printf(" 4. ð������     \n");
	printf(" 5. ѡ������     \n");
	printf(" 6. ˳�����     \n");
	printf(" 7. �۰����     \n");
	printf(" 0. �˳�         \n");
	printf("=================\n");
}//end ListMenu( )

//��������
void input(int elem[] , int length)
{
	int i ;

	for (i = 1 ; i <= length ; i++ )
	{
		printf("�������%d�����ݣ�" ,i);
		scanf("%d" , &elem[i]);
	}
}// end input

//�������
void output(int elem[] , int length)
{
	int i ;

	printf("\n�������£�\n" );
	for (i = 1 ; i <= length ; i++ )
	{
		printf("%d\t" , elem[i]);		
	}
}//end output


//�����������
void randdata(int elem[] , int length)
{
	int i ;

	//srand();//����һ�����������
	srand((unsigned)time(NULL));

	for (i = 1 ; i <= length ; i++ )
	{
		elem[i] = rand();
	}
	printf("�Ѿ�������%d��������ݣ�\n" ,N);
}

main()
{
	char choice ;
	int key ,location ;
	int data[N+1]; //Լ��������0��Ԫ��

	while (1)
	{
		system("cls");
		ListMenu();

		printf("���������ѡ��");
		//scanf("%c" , &choice);
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("лл���ʹ�ã�\n");
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
			printf("�Ѿ��ź���\n");
			break;
		case '5':
			selectsort(data ,N);
			printf("�Ѿ��ź���\n");
			break;
		case '6':
			printf("������Ҫ���ҵ����ݣ�");
			scanf("%d" , &key);
			location = 	search_seq(data, N ,key);

			if (location == 0)
				printf("δ�ҵ�%d\n" ,key);
			else 
				printf("�ҵ�%d,�ڵ�%d��λ��\n" ,key,location);
			
			break;
		case '7':
			printf("������Ҫ���ҵ����ݣ�");
			scanf("%d" , &key);
			location = 	search_bin(data, N ,key);

			if (location == 0)
				printf("δ�ҵ�%d\n" ,key);
			else 
				printf("�ҵ�%d,�ڵ�%d��λ��\n" ,key,location);
			
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
