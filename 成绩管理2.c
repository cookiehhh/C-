/*
�汾2
�����ܣ�����һ���༶һ�ſεĳɼ�(�ɼ�Ϊ����)��
ʹ��1ά����score������0��Ԫ��,�±����ѧ�š�
����1ά����rank������ÿ��ͬѧ�����Ρ�
��2���˵��������е�������ܡ�

���ڣ�2017.11.13
*/

#include <stdio.h>
#include <conio.h>

#define N 38
int score[N+1]; //ȫ�����飬����0��Ԫ��,�±����ѧ�š�
int rank[N+1] ; //ȫ�����飬�������Ρ�
int max , min ,total = 0;
double aver;

void ListMenu( )
{
	printf("   �ɼ�����˵�  \n");
	printf("=================\n");
	printf(" 1. ����ɼ�     \n");
	printf(" 2. ͳ�ƴ���     \n");
	printf(" 3. ��������     \n");
	printf(" 4. ���         \n");
	printf(" 9. ����������� \n");
	printf(" 0. �˳�         \n");
	printf("=================\n");
}//end ListMenu( )

void outputmenu( )
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. ��ѧ������ɼ�\n");
	printf(" 2. ����������ɼ�\n");
	printf(" 3. ���������Top n\n");
	printf(" 4. �������������\n");
	printf(" 0. �������˵�    \n");
	printf("=================\n");
}//end outputmenu( )

//��ѧ������ɼ�
void outputbyno( )
{
	int i ;

	printf("\n\n��ѧ�����\n\n" );

	printf("\nѧ��\t�ɼ�\t����\n");
	printf("======================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%d\t%d\t%d" , i, score[i], rank[i]);
		printf("\n");
	}
	printf("======================\n");

	printf("\nƽ���֣�%.2f\n" , aver);
	printf("��߷֣�%d\n" , max);
	printf("��ͷ֣�%d\n" , min);
}// end outputbyno( )

//����ɼ�
void input( )
{
	int i ;
	
	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("�������%d��ͬѧ�ĳɼ���",i);
			scanf("%d",&score[i]);
			if (score[i]>100 || score[i] <0)
				printf("�ɼ�����");
		}while(score[i]>100 || score[i] <0);
	}	
}//end input( )

//ͳ�Ƴɼ�
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
	printf("�Ѿ����ͳ��!\n");
}

//�ɼ�����
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
	printf("�����Ѿ�����");
}

//�����������Ϊ��������
void randdata()
{
	int i;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
	{
		score[i] = 51 + rand() % 50;
	}
	printf("�Ѿ�����һ�������.\n");
}//end of randdata

//����������ɼ�ǰ����
void outputbyrank(int n)
{
	int i, r = 1, same;

	printf("\n\n���������ǰ%d����\n\n" ,n);
	printf("����\tѧ��\t�ɼ�\n");
	printf("======================\n");
	while ( r <= n) //r�������Σ���1��ʼ����
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

//�������������
void outputfail()
{
	int i ,count = 0 ;

	printf("\n\t����������\n\n" );

	printf("\nѧ��\t�ɼ�\t����\n");
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
	printf("����%d��ͬѧ������\n" ,count);
}//end 

//������������˵������д���
void output()
{
	char choice , n;

	while (1)
	{
		system("cls");
		outputmenu();

		printf("���������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;
		case '1':
			outputbyno( );//��ѧ�����
			break;
		case '2':
			outputbyrank(N);//������������гɼ�
			break;
		case '3': //���������Top n
			do 
			{
				printf("��Ҫ���ǰ������");
				scanf("%d" ,&n);
				if (n >N || n <1)
					printf("�����д���");			
			}while(n >N || n <1);
			outputbyrank(n);//���������Topn
			break;
		
		case '4':
			outputfail();//������������гɼ�
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
			input( );//����ɼ�
			break;
		case '2':
			process();//ͳ�ƴ���
			break;
		case '3':
			sortfun();//������
			break;
		case '4':
			output( );//���
			break;
		case '9':
			randdata(); //�����������Ϊ��������
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
