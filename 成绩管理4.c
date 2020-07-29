/*
�汾4.0
�����ܣ�����һ���༶���ſεĳɼ�(�ɼ�Ϊ����)��
ʹ�ýṹ�����飬ÿ������Ԫ�ض�Ӧһ��ͬѧ��
����ѧ�š����������ſεĳɼ������Σ��ܷ֣������Ρ�

����2ά�ַ��������γ������γ����Ӽ������롣

���ڣ�2017.12.28
*/

#include <stdio.h>
#include <conio.h>
#include "�ɼ�ͷ�ļ�.c"

#define N 5
#define CrsNum 3

//ȫ�ֶ�ά���鱣��γ����ƣ�Ҳ���ԴӼ�������
char coursename[CrsNum+1][10]={"�ܷ�" ,"C����" , "��ѧ" ,"Ӣ��"};
int  coursetotal[CrsNum+1];//��������ܷ֣�0�ű��������ܷ�

//�ṹ������
typedef  struct 
{
	char ID[10];   //ѧ��
	char name[10]; //����
	int score[CrsNum +1]; //���Ƴɼ�,����0��Ԫ��
	int rank[CrsNum +1];  //��������,����0��Ԫ��
	int total;			//�ܷ�
	double average ;	//ƽ����
	int totalrank;		//������
}  STU ;

// ȫ������J15011����ȫ��ͬѧ��Ϣ
STU  J15011[N+1]; //Ϊ��ǰ��汾���ݣ�����0��Ԫ��

int sorted = 0; // �Ƿ��Ѿ�����

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
			input( );//����
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
	printf(" 1. ����         \n");
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
	printf(" 1. �γ�����\n");
	printf(" 2. ѧ�š�����\n");
	printf(" 3. �ɼ�\n");
	printf(" 0. �������˵�    \n");
	printf("=================\n");
}//end inputmenu( )

//����γ�����
void inputCrsname()
{
	int i ;

	for (i = 1 ; i <= CrsNum ; i++ )
	{
		printf("\n������γ�%d�����ƣ�" , i);
		gets(coursename[i]);		
	}
}//end inputCrsname

//����ѧ�š�����
void inputStuname()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n�������%d��ѧ����ѧ��(��J1501101)��" , i);
		gets(J15011[i].ID);	

		printf("\n�������%d��ѧ����������" , i);
		gets(J15011[i].name);	
	}
}//end inputStuname()

//�γ����˵������ؿγ̺�1��2��3
int  coursemenu( )
{
	char courseID;
	int i ;

	printf("      ��Ŀ\n");
	printf("=================\n");
	printf(" 0. ���п�Ŀ\n");

	for ( i = 1 ; i <= CrsNum ; i++)
		printf(" %d. %s\n" , i , coursename[i]);
	printf("=================\n");

	do
	{
		printf(" ��ѡ��Ŀ�Ŀ:");
		courseID = getche();
		if (courseID < '0' || courseID > '0'+CrsNum)
			printf("������󣡿γ̺�0-%d" , CrsNum );	
	}while (courseID < '0' || courseID > '0'+CrsNum);

	return (courseID - 48);
}//end coursemenu( )

//���γ̺����뵥�Ƴɼ�
void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("\n�����������%d��%s�ĳɼ���\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("�������%d��ͬѧ%s�ĳɼ���",i ,J15011[i].name);
			scanf("%d",&J15011[i].score[CrsId]);
			if (J15011[i].score[CrsId]>100 || J15011[i].score[CrsId] <0)
				printf("�ɼ�����");
		}while(J15011[i].score[CrsId]>100 || J15011[i].score[CrsId] <0);
	}
	sorted = 0 ;
}//end inputbyCrsId( )

//�������п�Ŀ�ɼ�
void inputallCrs()
{
	int i , j ;
	
	printf("\n����������ÿ��ͬѧÿһ�Ƶĳɼ���\n");
	printf("ѧ��\t����");

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
					printf("%sͬѧ%s�ɼ��������������룡" ,J15011[i].name,coursename[j]);
			}while(J15011[i].score[j]>100 || J15011[i].score[j] <0);
	
		}//end for j
	}// end foe i
	sorted = 0 ;
}// end inputallCrs()


void outputbyno( )//��ѧ������ɼ�
{
	int i , j;

	printf("\n\n��ѧ�����\n\n" );

	printf("\nѧ��\t����\t");
	for (j = 1 ; j <= CrsNum ; j ++)//�γ̺�
		printf("\t%s" , coursename[j]);//�γ���
	printf("\t�ܷ�\tƽ����\t����\n");

	printf("====================================================================\n");

	for ( i = 1 ; i <= N ; i++) //�ṹ�������±�
	{
		printf("%s\t" ,J15011[i].ID);
		printf("%s\t\t" ,J15011[i].name);
		
		for (j = 1 ; j <= CrsNum ; j ++)//�γ̺�
			printf("%d\t" , J15011[i].score[j]);//���Ƴɼ�
	
		printf("%d\t" , J15011[i].total);//�ܷ�
		printf("%.2f\t" , J15011[i].average);//ƽ����
		printf("%d\n" , J15011[i].totalrank);//������
	}
	printf("===================================================================\n");

	printf("\t\t�ܷ֣�\t" );
	for (j = 1 ; j <= CrsNum ; j ++)//�γ̺�
		printf("%d\t" , coursetotal[j]);//�����ܷ�
	printf("%d\t" , coursetotal[0]);//�����ܷ�

	printf("\n\t\tƽ����\t" );
	for (j = 1 ; j <= CrsNum ; j ++)//�γ̺�
		printf("%.2f\t" , 1.0*coursetotal[j]/N);//����ƽ����
	printf("%.2f\n" , 1.0*coursetotal[0]/N);//���п�ƽ����
}// end outputbyno( )


//ͳ�Ƹ��ơ�����ͬѧ���ܷ�
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		J15011[i].total = 0 ;//����ͬѧ���ܷ���0

	for (j = 0 ; j <= CrsNum ; j ++)
		coursetotal[j] = 0 ; //�����ܷ���0


	for (i = 1 ; i <= N ; i ++)//�ṹ�������±�
	{
		for ( j = 1 ; j <= CrsNum ; j ++ )//�γ̺�
		{
			J15011[i].total += J15011[i].score[j] ;//�����i��ͬѧ�ܷ�
			coursetotal[j] +=  J15011[i].score[j] ;//�����j���ܷ�
		}
		J15011[i].average = 1.0*J15011[i].total / CrsNum;//�����i��ͬѧƽ����
		coursetotal[0] += J15011[i].total; //0��Ԫ�ر������п�Ŀ�ܳɼ�
	}
	printf("�Ѿ����ͳ��!\n");
}


//���԰��յ��ƻ����ֶܷ���������
void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) //�ṹ��������±�
	{
		J15011[i].totalrank = 1;//�����γ�ֵ
		for ( k = 1 ; k <= CrsNum ; k++) //�γ̺�
			J15011[i].rank[k] = 1 ;//���Ƴɼ����γ�ֵ
	}

	//���Ƴɼ�����
	for( k = 1 ; k  <= CrsNum ; k++) //ÿ�ſε���������
	{
		for ( i = 1 ; i < N  ; i ++)//�ṹ��������±�
		{
			for ( j = i+1 ; j <= N ; j++)//�����ͬѧpk
				if (J15011[i].score[k] > J15011[j].score[k])
					J15011[j].rank[k] ++ ;
				else if (J15011[i].score[k] < J15011[j].score[k])
					J15011[i].rank[k] ++ ;	
		}//end for i
	}//end for k

	//�ܷ�����
	for ( i = 1 ; i < N  ; i ++)//�ṹ��������±�
	{
		for ( j = i+1 ; j <= N ; j++)//�����ͬѧpk
			if (J15011[i].total > J15011[j].total )
				J15011[j].totalrank  ++ ;
			else if (J15011[i].total < J15011[j].total)
				J15011[i].totalrank  ++ ;	
	}//end for i

	printf("�����Ѿ�����");
	sorted = 1 ;
}

//�����������Ϊ��������
void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)//�ṹ�������±�
		for ( j = 1 ; j <= CrsNum ; j++)//�γ̺�
		{
			J15011[i].score[j]  = 21 + rand() % 80;
		}
	printf("�Ѿ�����һ�������.\n");
	sorted = 0 ;
}//end of randdata


//����������ɼ�ǰ����
void outputbyrank(int n)
{
	int i,j, r = 1,same;

	if (sorted == 0 )
	{
		printf("�ɼ�δ����");
		printf("����ִ�����˵��е������ܣ�");
		return ;
	}

	printf("\n\n���������ǰ%d����\n\n" ,n);

	printf("\n����\tѧ��\t����");
	for (j = 1 ; j <= CrsNum ; j ++)
		printf("\t%s" , coursename[j]);
	printf("\t�ܷ�\n");

	printf("====================================================\n");

	while ( r <= n) //r�������Σ���1��ʼ����
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (J15011[i].totalrank == r) //��i��ͬѧ���ܷ�����
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
		printf("\t\t�ܷ֣�\t" );
		for (j = 1 ; j <= CrsNum ; j ++)
			printf("%d\t" , coursetotal[j]);
		printf("%d\t" , coursetotal[0]);//�����ܷ�

		printf("\n\t\tƽ����\t" );
		for (j = 1 ; j <= CrsNum ; j ++)
			printf("%.2f\t" , 1.0*coursetotal[j]/N);
		printf("%.2f\n" , 1.0*coursetotal[0]/N);//�ֵܷ�ƽ����
	}
	printf("\n");
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

//���빦��
void input()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		inputmenu();

		printf("������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;
		case '1': 
			inputCrsname();
			break;

		case '2': 
			inputStuname();
			break;
		case '3': //����ɼ�
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);//���γ̺�����ĳ�Ƴɼ�
			else 
				inputallCrs(); //һ���������пγ̳ɼ�
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}//end input()
