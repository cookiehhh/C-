/*
�汾3.1
�����ܣ�����һ���༶���ſεĳɼ�(�ɼ�Ϊ����)��
ʹ��2ά����score���±����ѧ�š�ÿһ�б���һ��ͬѧ�ɼ���
��0�б�������ܷ֣���0�б���ÿ��ͬѧ�ܷ֡�
����2ά����rank������ÿ��ͬѧÿһ���Լ��ֵܷ����Ρ�
��2���˵��������е�������ܡ�

����2ά�ַ��������ѧ��������γ�����

���ڣ�2017.12.23
*/

#include <stdio.h>
#include <conio.h>
#include "�ɼ�ͷ�ļ�.c"

#define N 5
#define CrsNum 3

//score��rankΪȫ������,���±����ѧ�ţ�1-N����
//���±����γ̺ţ�1-CrsNum��
//score��0�б���ÿ���ܷ֣���0�б���ÿ��ͬѧ���ܷ֡�
int score[N+1][CrsNum+1]; 
int rank[N+1][CrsNum+1] ; //ȫ�����飬�������Ρ�

char coursename[CrsNum+1][10]={"�ܷ�" ,"Java" , "����" ,"����"};
char name[N+1][10] = {"","����","����","����","����","С��"};

main()
{
	char choice , n;

	while (1)
	{
		system("cls");
		ListMenu();

		printf("���������ѡ��");
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
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main

void ListMenu( )//��ʾ���˵�
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

void outputmenu( )//��������˵�
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. ��ѧ������ɼ�\n");
	printf(" 2. ����������ɼ�\n");
	printf(" 3. ���������Topn\n");
	printf(" 4. �������������\n");
	printf(" 0. �������˵�    \n");
	printf("=================\n");
}//end outputmenu( )

void inputmenu( )//��������˵�
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. %s\n" ,coursename[1]);
	printf(" 2. %s\n" ,coursename[2]);
	printf(" 3. %s\n" ,coursename[3]);
	printf(" 0. �������˵�    \n");
	printf("=================\n");
}//end inputmenu( )

int  coursemenu( )//�γ̲˵������ؿγ̺�1��2��3
{
	char courseID;

	printf(" ����Ŀ�Ŀ\n");
	printf("=================\n");
	printf(" 0. ���п�Ŀ\n");
	printf(" 1. %s\n" ,coursename[1]);
	printf(" 2. %s\n" ,coursename[2]);
	printf(" 3. %s\n" ,coursename[3]);
	printf("=================\n");

	do
	{
		printf(" ��ѡ������Ŀ�Ŀ:");
		courseID = getche();
		if (courseID < '0' || courseID > '4')
			printf("������󣡿γ̺�0-3");	
	}while (courseID < '0' || courseID > '4');

	return (courseID - 48);
}//end coursemenu( )

void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("�����������%d��(%s)�ĳɼ���\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("�������%d��ͬѧ%s�ĳɼ���",i ,name[i]);
			scanf("%d",&score[i][CrsId]);
			if (score[i][CrsId]>100 || score[i][CrsId] <0)
				printf("�ɼ�����");
		}while(score[i][CrsId]>100 || score[i][CrsId] <0);
	}	
}//end inputbyCrsId( )

void outputbyno( )
{
	int i ;

	printf("\n\n��ѧ�����\n\n" );

	printf("\nѧ��\t����");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t�ܷ�\t����\n");
	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%d\t%s\t%d\t" , i,name[i] ,score[i][1]);
		printf("%d\t%d\t" , score[i][2],score[i][3]);
		printf("%d\t%d" , score[i][0],rank[i][0]);
		printf("\n");
	}
	printf("=================================================\n");

	printf("\t�ܷ֣�\t" );
	printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
	printf("\n\tƽ����\t" );
	printf("%.2f\t%.2f\t%.2f\n" , 1.0*score[0][1]/N,1.0*score[0][2]/N,1.0*score[0][3]/N);
}// end outputbyno( )

//ͳ�Ƹ��ơ�����ͬѧ���ܷ�
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		score[i][0] = 0 ;//����ͬѧ���ܷ���0

	for (j = 1 ; j <= CrsNum ; j ++)
		score[0][j] = 0 ; //�����ܷ���0


	for (i = 1 ; i <= N ; i ++)
		for ( j = 1 ; j <= CrsNum ; j ++ )
		{
			score[i][0] += score[i][j] ;
			score[0][j] += score[i][j] ;
		}
	printf("�Ѿ����ͳ��!\n");
}

//���԰��յ��ƻ����ֶܷ���������
void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) //ѧ��
		for ( k = 0 ; k <= CrsNum ; k++) //�γ̺ţ�0Ϊ�ܷ���
			rank[i][k] = 1 ;

	for( k = 0 ; k  <= CrsNum ; k++) //ÿ�ſε���������
	{
		for ( i = 1 ; i < N  ; i ++)//ѧ��
		{
			for ( j = i+1 ; j <= N ; j++)//�����ѧ��pk
				if (score [i][k] > score [j][k])
					rank [j][k] ++ ;
				else if (score [i][k] < score [j][k])
					rank [i][k] ++ ;	
		}//end for i
	}//end for k
	printf("�����Ѿ�����");
}

//�����������Ϊ��������
void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
		for ( j = 1 ; j <= CrsNum ; j++)
		{
			score[i][j] = 21 + rand() % 80;
		}
	printf("�Ѿ�����һ�������.\n");
}//end of randdata

//����������ɼ�ǰ����
void outputbyrank(int n)
{
	int i, r = 1,same;

	printf("\n\n���������ǰ%d����\n\n" ,n);

	printf("\n����\tѧ��\t����");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t�ܷ�\n");
	printf("====================================================\n");

	while ( r <= n) //r�������Σ���1��ʼ����
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (rank[i][0] == r) //��i�е�0�м�¼��i��ͬѧ���ܷ�����
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
		printf("\t\t�ܷ֣�\t" );
		printf("%d\t%d\t%d\t" , score[0][1],score[0][2],score[0][3]);
		printf("\n\t\tƽ����\t" );
		printf("%.2f\t%.2f\t%.2f\n" , 1.0*score[0][1]/N,1.0*score[0][2]/N,1.0*score[0][3]/N);
	}
}

//���ĳ�Ʋ���������
void failacourse(int courseID)
{
	int i ,count = 0 ;

	printf("\n\n\t%s����������\n" , coursename[courseID] );

	printf("\nѧ��\t����\t�ɼ�\t����\n");
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
	printf("%s����%d��ͬѧ������\n" ,coursename[courseID] ,count);
}//end outputfail()

//������п�Ŀ����������
void allfail()
{
	int i , j , k,count = 0 ,allcount = 0 ;

	printf("\n\n\t���п�Ŀ����������\n" );

	printf("\nѧ��\t����");
	for ( i = 1 ; i <= CrsNum ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t����������\n");

	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++) //ѧ��
	{
		count = 0 ;
		for ( j = 1 ; j <= CrsNum ; j++) //�γ̺�
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
	printf("���й���%d�Ŵβ�����\n" ,allcount);
}//end allfail()


//�������������
void outputfail()
{
	int CrsID = coursemenu( );

	if (CrsID == 0 )
		allfail();
	else
		failacourse(CrsID);
}

//������� 
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
			outputbyno( );//��ѧ��������гɼ�
			break;

		case '2':
			outputbyrank(N);//���ܷ�����������гɼ�
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
			outputfail();//���������������ɼ�
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end output()

void input()
{
	char choice , n;

	while (1)
	{
		system("cls");
		inputmenu();

		printf("������γ̺ţ�");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;
		case '1': //��Ŀ1

		case '2': //��Ŀ2

		case '3': //��Ŀ3		
			inputbyCrsId(choice-48);//���γ̺�����ĳ�Ƴɼ�
			break;

		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()

