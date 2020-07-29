/*
�汾4.1
�����ܣ�����һ���༶���ſεĳɼ�(�ɼ�Ϊ����)��
ʹ�ýṹ�����飬ÿ������Ԫ�ض�Ӧһ��ͬѧ��
����ѧ�š����������ſεĳɼ������Σ��ܷ֣������Ρ�

����2ά�ַ����������γ������γ����Ӽ������롣
�����ļ�������

���ڣ�2018.1.15
*/

#include <stdio.h>
#include <conio.h>

#define N 5
#define CrsNum 3

//ȫ�ֶ�ά���鱣��γ����ƣ�Ҳ���ԴӼ�������
char coursename[CrsNum+1][10]={"�ܷ�" ,"C����" , "��ѧ" ,"Ӣ��"};

//�ṹ������
typedef  struct 
{
	char ID[10];   //ѧ��
	char name[10]; //����
	int score[CrsNum ]; //���Ƴɼ�
	int rank[CrsNum ];  //��������
	int total;			//�ܷ�
	double average ;	//ƽ����
	int totalrank;		//������
}  STU ;

// ȫ������J12004����ȫ��ͬѧ��Ϣ
STU J12004[N];

int sorted = 0;

void ListMenu( )
{
	printf("   �ɼ�����˵�  \n");
	printf("=================\n");
	printf(" 1. ����         \n");
	printf(" 2. ͳ�ƴ���     \n");
	printf(" 3. ��������     \n");
	printf(" 4. ���         \n");
	printf(" 5. �ļ�����     \n");
	printf(" 6. �ļ���ȡ     \n");
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
	printf(" 3. ���������Topn\n");
	printf(" 4. �������������\n");
	printf(" 0. �������˵�    \n");
	printf("=================\n");
}//end outputmenu( )

void inputmenu( )
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. �γ�����\n");
	printf(" 2. ѧ������\n");
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

void inputStuname()
{
	int i ;

	for (i = 0 ; i < N ; i++ )
	{
		printf("\n�������%d��ѧ����ѧ��(��J1200401)��" , i +1);
		gets(J12004[i].ID);	

		printf("\n�������%d��ѧ����������" , i +1);
		gets(J12004[i].name);	
	}
}//end inputStuname()

//�γ����˵�
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

/*
void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("�����������%d��%s�ĳɼ���\n\n",CrsId,coursename[CrsId]);

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
	sorted = 0 ;
}//end inputbyCrsId( )

void inputallCrs()
{
	int i , j ;
	
	printf("\n����������ÿ��ͬѧÿһ�Ƶĳɼ���\n");
	printf("ѧ��\t����");

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
					printf("%sͬѧ%s�ɼ��������������룡" ,name[i],coursename[j]);
			}while(score[i][j]>100 || score[i][j] <0);
	
		}//end for j
	}// end foe i
	sorted = 0 ;
}// end inputallCrs()

void outputbyno( )
{
	int i ;

	printf("\n\n��ѧ�����\n\n" );

	printf("\nѧ��\t����");
	for (i = 1 ; i <= CrsNum ; i ++)
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
	sorted = 1 ;
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
	sorted = 0 ;
}//end of randdata

//����������ɼ�ǰ����
void outputbyrank(int n)
{
	int i, r = 1,same;

	if (sorted == 0 )
	{
		printf("�ɼ�δ����");
		printf("����ִ�����˵��е������ܣ�");
		return ;
	}

	printf("\n\n���������ǰ%d����\n\n" ,n);

	printf("\n����\tѧ��\t����");
	for (i = 1 ; i <= CrsNum ; i ++)
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
*/
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
/*
		case '3': //����ɼ�
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);//���γ̺�����ĳ�Ƴɼ�
			else 
				inputallCrs(); //һ���������пγ̳ɼ�
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
		printf("�޷��򿪿γ����ļ�course.dat!\n");
		exit(0);
	}
	else if (fwrite(coursename,sizeof(coursename),1,f1) ==1)
	{
		printf("д�γ����ļ�course.dat�ɹ���\n");
	}
	else
	{
		printf("д�γ����ļ�course.datʧ�ܣ�\n");
	}
	fclose(f1);

}//end savefile()

void readfile( )
{
	FILE * f1 , * f2;

	if ((f1 = fopen( "course.dat","rb")) ==NULL )
	{
		printf("�޷��򿪿γ����ļ�course.dat!\n");
		exit(0);
	}
	else if (fread(coursename,sizeof(coursename),1,f1) ==1)
	{
		printf("���γ����ļ�course.dat�ɹ���\n");
	}
	else
	{
		printf("���γ����ļ�course.datʧ�ܣ�\n");
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
/*
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
*/
		case '5':
			savefile( );//�ļ�����
			break;
		case '6':
			readfile( );//�ļ���ȡ
			break;
		default :
			printf("Error Input!");	
		}//end switch
		printf("Press any key to continue...");
		getch();	
	}// end while
}// end main
