#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N 5
#define Num 3

char coursename[Num+1][10]={"�ܷ�" ,"C����" , "��ѧ" ,"Ӣ��"};
int  coursetotal[Num+1];

typedef  struct 
{
	char ID[10];
	char name[10];
	int score[Num +1];
	int rank[Num +1];
	int total;
	double average ;
	int totalrank;
} student ;

student stu[N+1];

int sorted = 0;

void ListMenu( )
{
	printf("   �ɼ�����˵�   \n");
	printf("==================\n");
	printf("  1. ��������     \n");
	printf("  2. ͳ�ƴ���     \n");
	printf("  3. ��������     \n");
	printf("  4. �������     \n");
	printf("  5. �������     \n");
	printf("  6. ��ѯ����     \n");
	printf("  7. �޸�����     \n");
	printf("  8. ɾ������     \n");
	printf("  9. �ļ�����     \n");
	printf(" 10. �ļ���ȡ     \n");
	printf("  0. �˳�ϵͳ     \n");
	printf("==================\n");
}

void outputmenu( )
{
	printf("   ��������˵�   \n");
	printf("==================\n");
	printf(" 1. ��ѧ������ɼ�\n");
	printf(" 2. ����������ɼ�\n");
	printf(" 3. ǰ�������    \n");
	printf(" 4. �������������\n");
	printf(" 0. �������˵�    \n");
	printf("==================\n");
}

void inputmenu( )
{
	printf("   ��������˵�  \n");
	printf("=================\n");
	printf(" 1. �γ�����     \n");
	printf(" 2. ѧ��ѧ��     \n");
	printf(" 3. ѧ������     \n");
	printf(" 4. �ɼ�         \n");
	printf(" 0. �������˵�   \n");
	printf("=================\n");
}

void seachmenu( )
{
	printf("   ��ѯ�����˵�  \n");
	printf("=================\n");
	printf(" 1. ��ѧ�Ų�ѯ   \n");
	printf(" 2. ���γ̲�ѯ   \n");
	printf(" 3. ��������ѯ   \n");
	printf(" 0. �������˵�   \n");
	printf("=================\n");
}

void rewritemenu( )
{
	printf("   �޸Ķ����˵�  \n");
	printf("=================\n");
	printf(" 1. �γ�����     \n");
	printf(" 2. ѧ��ѧ��     \n");
	printf(" 3. ѧ������     \n");
	printf(" 4. �ɼ�         \n");
	printf(" 0. �������˵�   \n");
	printf("=================\n");
}

void deletmenu( )
{
	printf("   ɾ�������˵�  \n");
	printf("=================\n");
	printf(" 1. ��ѧ��ɾ��   \n");
	printf(" 2. ���γ�ɾ��   \n");
	printf(" 3. ������ɾ��   \n");
	printf(" 0. �������˵�   \n");
	printf("=================\n");
}

void inputCrsname()
{
	int i ;

	for (i = 1 ; i <= Num ; i++ )
	{
		printf("\n������γ�%d�����ƣ�" , i);
		scanf("%s",&coursename[i]);
	}
}
void inputStuID()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n�������%d��ѧ����ѧ�ţ�" , i);
		scanf("%s",&stu[i].ID);

	}
}
void inputStuname()
{
	int i ;

	for (i = 1 ; i <= N ; i++ )
	{
		printf("\n�������%d��ѧ����������" , i);
		scanf("%s",&stu[i].name);
	}
}

int coursemenu( )
{
	char courseID;
	int i ;

	printf("      ��Ŀ\n");
	printf("=================\n");
	printf(" 0. ���п�Ŀ\n");

	for ( i = 1 ; i <= Num ; i++)
		printf(" %d. %s\n" , i , coursename[i]);
	printf("=================\n");

	do
	{
		printf(" ��ѡ��Ŀ�Ŀ:");
		courseID = getche();
		if (courseID < '0' || courseID > '0'+Num)
			printf("������󣡿γ̺�0-%d" , Num );	
	}while (courseID < '0' || courseID > '0'+Num);

	return (courseID - 48);
}

void inputbyCrsId(int CrsId)
{
	int i ;
	
	printf("\n�����������%d��%s�ĳɼ���\n\n",CrsId,coursename[CrsId]);

	for (i = 1 ; i <= N ; i++)
	{
		do
		{
			printf("�������%d��ͬѧ%s�ĳɼ���",i ,stu[i].name);
			scanf("%d",&stu[i].score[CrsId]);
			if (stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0)
				printf("\n�ɼ�����");
		}while(stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0);
	}
	sorted = 0 ;
}
void inputallCrs()
{
	int i , j ;
	
	printf("\n����������ÿ��ͬѧÿһ�Ƶĳɼ���\n");
	printf("ѧ��\t����");

	for (j = 1 ; j <= Num ; j++ )
		printf("\t%s" , coursename[j]);
		
	for (i = 1 ; i <= N ; i++)
	{
		printf("\n%s\t%s\t",stu[i].ID ,stu[i].name);
		for ( j = 1 ; j <= Num ; j++)
		{
			do
			{
				scanf("%d",&stu[i].score[j]);
				if (stu[i].score[j]>100 || stu[i].score[j] <0)
					printf("\n%sͬѧ%s�ɼ��������������룡" ,stu[i].name,coursename[j]);
			}while(stu[i].score[j]>100 || stu[i].score[j] <0);
		}
	}
	sorted = 0 ;
}

void outputbyno( )
{
	int i,j ;

	printf("\n\n��ѧ�����\n\n" );

	printf("\nѧ��\t����");
	for (i = 1 ; i <= Num ; i ++)
		printf("\t%s" , coursename[i]);
	printf("\t�ܷ�\tƽ����\t����\n");

	printf("==============================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
			printf("%d\t" , stu[i].score[j]);
	
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
	}
	printf("==============================================================\n");

	printf("\t�ܷ֣�\t" );
	for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , coursetotal[j]);

	printf("\n\tƽ����\t" );
	for (j = 1 ; j <= Num ; j ++)
		printf("%.2f\t" , 1.0*coursetotal[j]/N);
	printf("\n");
}
void process()
{
	int i , j ;

	for (i = 1 ; i <= N ; i ++)
		stu[i].total = 0 ;

	for (j = 0 ; j <= Num ; j ++)
		coursetotal[j] = 0;


	for (i = 1 ; i <= N ; i ++)
		for ( j = 1 ; j <= Num ; j ++ )
		{
			stu[i].total += stu[i].score[j] ;
			stu[i].average = stu[i].total / Num;
			coursetotal[j] +=  stu[i].score[j] ;
		}
	printf("�Ѿ����ͳ�ƣ�\n");
}

void sortfun()
{
	int i , k , j ;

	for (i = 1 ; i <= N ; i++) 
	{
		stu[i].totalrank = 1;
		for ( k = 1 ; k <= Num ; k++) 
			stu[i].rank[k] = 1 ;
	}

	for( k = 1 ; k  <= Num ; k++) 
	{
		for ( i = 1 ; i < N  ; i ++)
		{
			for ( j = i+1 ; j <= N ; j++)
				if (stu[i].score[k] > stu[j].score[k])
					stu[j].rank[k] ++ ;
				else if (stu[i].score[k] < stu[j].score[k])
					stu[i].rank[k] ++ ;	
		}
	}

	for ( i = 1 ; i < N  ; i ++)
	{
		for ( j = i+1 ; j <= N ; j++)
			if (stu[i].total > stu[j].total )
				stu[j].totalrank  ++ ;
			else if (stu[i].total < stu[j].total)
				stu[i].totalrank  ++ ;	
	}
	printf("�����Ѿ�����!\n");
	sorted = 1 ;
}

void randdata()
{
	int i , j;

	srand((unsigned)time(NULL));

	for ( i = 1 ; i <= N ; i++)
		for ( j = 1 ; j <= Num ; j++)
		{
			stu[i].score[j]  = 21 + rand() % 80;
		}
	printf("�Ѿ�����һ�������.\n");
	sorted = 0 ;
}

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
	for (i = 1 ; i <= Num ; i ++)
		printf("\t%s" , coursename[i]);
	printf("\t�ܷ�\n");

	printf("====================================================\n");

	while ( r <= n)
	{
		same = 0 ;
		for ( i = 1 ; i <= N ; i++)
		{
			if (stu[i].totalrank == r) 
			{
				printf("%d\t" , stu[i].totalrank);
				printf("%s\t" , stu[i].ID);
				printf("%s\t" , stu[i].name);
				for (j = 1 ; j <= Num ; j ++)
					printf("%d\t" , stu[i].score[j]);
				printf("%d\n" , stu[i].total);
				same ++ ;
			}		
		}
		r += same ; 
	}

	printf("====================================================\n");

	if (n == N)
	{
		printf("\t\t�ܷ֣�\t" );
		for (j = 1 ; j <= Num ; j ++)
			printf("%d\t" , coursetotal[j]);

		printf("\n\t\tƽ����\t" );
		for (j = 1 ; j <= Num ; j ++)
			printf("%.2f\t" , 1.0*coursetotal[j]/N);
		printf("\n");
	}
	printf("\n");
}

void failacourse(int courseID)
{
	int i ,count = 0 ;

	printf("\n\n\t%s����������\n" , coursename[courseID] );

	printf("\nѧ��\t����\t�ɼ�\t����\n");
	printf("==============================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		if (stu[i].score[courseID] < 60 )
		{
			count ++ ;
			printf("%s\t" , stu[i].ID );
			printf("%s\t" , stu[i].name  );
			printf("%d\t" , stu[i].score[courseID] );
			printf("%d\n" , stu[i].rank[courseID] );
		}
	}
	printf("==============================\n");
	printf("%s����%d��ͬѧ������\n" ,coursename[courseID] ,count);
}

void allfail()
{
	int i , j , k,count = 0 ,allcount = 0 ;

	printf("\n\n\t���п�Ŀ����������\n" );

	printf("\nѧ��\t����");
	for ( i = 1 ; i <= Num ; i++)
		printf("\t%s" , coursename[i]);

	printf("\t����������\n");

	printf("==================================================\n");

	for ( i = 1 ; i <= N ; i++)
	{
		count = 0 ;
		for ( j = 1 ; j <= Num ; j++)
		{
			if (stu[i].score[j] < 60 )
			{
				if (count == 0 )
				{
					printf("%d\t%s" , i,stu[i].name);
				
					for (k = 1 ; k <j ; k++)
						printf("\t" );
				}
				printf("\t%d" , stu[i].score[j]);
				count ++ ;			
			}
			else if (count > 0)
				printf("\t");	
		}
		if (count >0)
			printf("\t%d\n" , count);

		allcount += count ;
	}
	printf("==================================================\n");
	printf("���й���%d�Ŵβ�����\n" ,allcount);
}


void outputfail()
{
	int CrsID = coursemenu( );
	if (CrsID == 0 )
		allfail();
	else
		failacourse(CrsID);
}

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
			outputbyno( );
			break;

		case '2':
			outputbyrank(N);
			break;

		case '3': 
			do 
			{
				printf("��Ҫ���ǰ������");
				scanf("%d" ,&n);
				if (n >N || n <1)
					printf("�����д���");			
			}while(n >N || n <1);
			outputbyrank(n);
			break;
	
		case '4':
			outputfail();
			break;
		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}

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
			inputStuID();
			break;

		case '3': 
			inputStuname();
			break;

		case '4': 
			CrsID = coursemenu();
			if (CrsID > 0 )
				inputbyCrsId(CrsID);
			else 
				inputallCrs(); 
			break;

		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}


void seachstuID()                      
{  	
	
	char s[10];  
	int i=1,j,k;  
	printf("���������ѯ��ѧ��ѧ�ţ�");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n��ѧ�Ų�ѯ\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
		
	}    
	system("pause");  
}

void seachcoursename()                      
{  	
	
	char s[10];  
	int i,j,k=1;  
	printf("���������ѯ�Ŀγ����ƣ�");  
	scanf("\t%s",s);  
	while(strcmp(coursename[k],s)!=0&&k<=Num)k++;

	if(k==Num+1)  
	{  
		printf("\tû���ҵ�����γ�!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n���γ̲�ѯ\n\n" );

		printf("\nѧ��\t����");
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		for ( i = 1 ; i <= N ; i++)
		{
			printf("%s\t" ,stu[i].ID);
			printf("%s\t" ,stu[i].name);
			
			printf("%d\t" , stu[i].score[k]);
		
			printf("%d\t" , stu[i].total);
			printf("%.2f\t" , stu[i].average);
			printf("%d\n" , stu[i].totalrank);
		}
			
	}    
	system("pause");  
}

void seachstuname()                      
{  	
	
	char s[10];  
	int i=1,j,k;  
	printf("���������ѯ��ѧ��������");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n��������ѯ\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);
		
	}    
	system("pause");  
}


void seach()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		seachmenu();

		printf("������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;

		case '1': 
			seachstuID();
			break;

		case '2': 
			seachcoursename();
			break;

		case '3': 
			seachstuname();
			break;
			
		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}

void rewriteCrsname()
{
	char s[10];  
	int i=1,j;  
	printf("\n���������޸ĵĿγ����ƣ�");  
	scanf("\t%s",s);  
	while(strcmp(coursename[i],s)!=0&&i<=Num)i++;  
	if(i==Num+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{		
		printf("\n\n�������޸ĺ�Ŀγ����ƣ�");
		scanf("%s",&coursename[i]);	
		printf("�޸ĳɹ���");
	}
} 

void rewriteStuID()
{
	char s[10];  
	int i=1,j,k;  
	printf("\n���������޸ĵ�ѧ��ѧ�ţ�");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{
		printf("\n\nѧ����Ϣ���£�\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("\n�������޸ĺ��ѧ��ѧ�ţ�" , i);
		scanf("%s",&stu[i].ID);	
		printf("�޸ĳɹ���");
	}
}

void rewriteStuname()
{
	char s[10];  
	int i=1,j,k;  
	printf("\n���������޸ĵ�ѧ��������");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{
		printf("\n\nѧ����Ϣ���£�\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[i]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("\n�������޸ĺ��ѧ��������" , i);
		scanf("%s",&stu[i].name);
		printf("�޸ĳɹ���");
	}
}

void rewritebyCrsId(int CrsId)
{
	char s[10];  
	int i=1,j;  
	printf("\n���������޸ĵ�ѧ��ѧ�ţ�");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  
		do
		{
			printf("�������޸ĺ��ͬѧ�ɼ���");
			scanf("%d",&stu[i].score[CrsId]);
			if (stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0)
				printf("\n�ɼ�����");
		}while(stu[i].score[CrsId]>100 || stu[i].score[CrsId] <0);
		printf("�޸ĳɹ���");
	}
	sorted = 0 ;
}
void rewriteallCrs()
{
	char s[10];  
	int i=1,j;  
	printf("\n���������޸ĵ�ѧ��ѧ�ţ�");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  	
		printf("\n����������ÿһ�Ƶĳɼ���\n");
		printf("ѧ��\t����");

		for (j = 1 ; j <= Num ; j++ )
			printf("\t%s" , coursename[j]);

			printf("\n%s\t%s\t",stu[i].ID ,stu[i].name);

			for ( j = 1 ; j <= Num ; j++)
			{
				do
				{
					scanf("%d",&stu[i].score[j]);
					if (stu[i].score[j]>100 || stu[i].score[j] <0)
						printf("\n%sͬѧ%s�ɼ��������������룡" ,stu[i].name,coursename[j]);
				}while(stu[i].score[j]>100 || stu[i].score[j] <0);
				printf("�޸ĳɹ���");
			}
	}
	sorted = 0 ;
}  

void rewrite()
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		rewritemenu();

		printf("������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;

		case '1': 
			rewriteCrsname();
			break;

		case '2': 
			rewriteStuID();
			break;

		case '3': 
			rewriteStuname();
			break;

		case '4': 
			CrsID = coursemenu();
			if (CrsID > 0 )
				rewritebyCrsId(CrsID);
			else 
				rewriteallCrs(); 
			break;

		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}

void deletstuID()                      
{  	
	
	char s[10];  
	int i=1,j,k;
	char c;
	printf("��������ɾ����ѧ��ѧ�ţ�");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].ID,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n��ѧ����Ϣ���£�\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("ȷ��ɾ����(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			stu[i] = stu[i+1];
			printf("ɾ���ɹ���");
		}
		
	}    
	system("pause");  
}

void deletcoursename()                      
{  	
	
	char s[10];  
	int i,j,k=1;
	char c;
	printf("��������ɾ���Ŀγ̣�");  
	scanf("\t%s",s);  
	while(strcmp(coursename[k],s)!=0&&k<=Num)k++;

	if(k==Num+1)  
	{  
		printf("\tû���ҵ�����γ�!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n�ÿγ���Ϣ���£�\n\n" );

		printf("\nѧ��\t����");
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		for ( i = 1 ; i <= N ; i++)
		{
			printf("%s\t" ,stu[i].ID);
			printf("%s\t" ,stu[i].name);
			
			printf("%d\t" , stu[i].score[k]);
		
			printf("%d\t" , stu[i].total);
			printf("%.2f\t" , stu[i].average);
			printf("%d\n" , stu[i].totalrank);
		}

		printf("ȷ��ɾ����(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			strcpy(coursename[k] , coursename[k+1]);
			printf("ɾ���ɹ���");
		}
			
	}    
	system("pause");  
}

void deletstuname()                      
{  	
	
	char s[10];  
	int i=1,j,k;
	char c;
	printf("��������ɾ����ѧ��������");  
	scanf("\t%s",s);  
	while(strcmp(stu[i].name,s)!=0&&i<=N)i++;  
	if(i==N+1)  
	{  
		printf("\tû���ҵ����ѧ��!\n");  
		return;  
	}  
	else
	{  
		printf("\n\n��ѧ����Ϣ���£�\n\n" );

		printf("\nѧ��\t����");
		for (k = 1 ; k <= Num ; k ++)
		printf("\t%s" , coursename[k]);
		printf("\t�ܷ�\tƽ����\t����\n");

		
		printf("%s\t" ,stu[i].ID);
		printf("%s\t" ,stu[i].name);
		
		for (j = 1 ; j <= Num ; j ++)
		printf("%d\t" , stu[i].score[j]);
		
		printf("%d\t" , stu[i].total);
		printf("%.2f\t" , stu[i].average);
		printf("%d\n" , stu[i].totalrank);

		printf("ȷ��ɾ����(Y/N)");
		scanf("%s",&c);
		if(c == 'Y' || c == 'y')
		{
			stu[i] = stu[i+1];
			printf("ɾ���ɹ���");
		}
		
	}    
	system("pause");  
}

void delet()								
{
	char choice , n , CrsID;

	while (1)
	{
		system("cls");
		deletmenu();

		printf("������ѡ��");
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case '0':
			printf("�������˵���\n");
			return;

		case '1': 
			deletstuID();
			break;

		case '2': 
			deletcoursename();
			break;

		case '3': 
			deletstuname();
			break;
			
		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}

void savefilestudent()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","wb")) ==NULL )
	{
		printf("�޷��򿪿γ����ļ�student.dat!\n");
		exit(0);
	}
	for (i = 1 ; i <= N ; i++ )
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

void readfilestudent()
{
	FILE * f1 , * f2;

	int i = 1;

	if ((f1 = fopen( "student.dat","rb")) ==NULL )
	{
		printf("�޷��򿪿γ����ļ�student.dat!\n");
		exit(0);
	}
	for (i = 1 ; i <= N ; i++ )
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

void savefilecourse()
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
}

void readfilecourse()
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
}

 
main()
{
	int choice;

	while (1)
	{
		system("cls");
		ListMenu();

		printf("���������ѡ��");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
		case 0:
			printf("лл����ʹ�ã�\n");
			return;
		case 1:
			input();
			break;

		case 2:
			process();
			break;

		case 3:
			sortfun();
			break;

		case 4:
			output();
			break;

		case 5:
			randdata(); 
			break;

		case 6:
			seach(); 
			break;

		case 7:
			rewrite(); 
			break;

		case 8:
			delet(); 
			break;

		case 9:
			savefilestudent();
			savefilecourse();
			break;

		case 10:
			readfilestudent();
			readfilecourse();
			break;

		default :
			printf("����������������룡\n");	
		}
		printf("�����������...\n");
		getch();	
	}
}
