/*
�ɼ������1.2�棬��doubleȡ��float

2017.11.13
*/

#include <stdio.h>
#define N 5
double  score[N] ={100 , 90 ,80  }; //ȫ�ֱ���
double total , max ,min ;
double average ;

void input() //����ɼ�
{
	int i ;

	for ( i = 0 ; i < N ; i++)
	{
		do
		{
			printf("�������%dͬѧ�ĳɼ���" , i);
			scanf("%lf" , &score[i]);

			if(score[i] < 0 || score[i] > 100)
				printf("�ɼ�Խ�磡" );		
		}while (score[i] < 0 || score[i] > 100);	
	}
}

void output()
{
	int i ;

	for (i = 0 ; i < N ; i++)
		printf("%.2f\t" , score[i]);

	printf ("\n��߷֣�%.2lf\n" , max);
	printf ("��ͷ֣�%.2lf\n" , min);
	printf ("ƽ���֣�%.2lf\n" , average);
}

void process()
{
	int i ;

	total = min = max = score [0];

	for ( i = 1 ; i < N ; i++)
	{
		total +=  score [i] ;

		if (score [i] > max)
			max = score [i] ;

		if (score [i] < min)
			min = score [i] ;	
	}
	average =(float) total / N ; //
	printf("ͳ�ƽ�����");
}

void randdata()
{
	int i ;

	srand((unsigned)time(NULL));  //����ʱ�亯��������

	for (i = 0 ; i < N ; i++)
	{
		score[i] = rand() % 1000 / 10.0 ; //���������50-100
	}
	printf("����������ɼ���");

}

//������
main()
{
	char choice;
	void ListMenu(); //��������

	while(1)
	{
		system("cls"); // ���� clear screen
		ListMenu(); //��������
		printf("�������ѡ��");
		//scanf("%c" , &choice);
		choice = getche() ; //���뵥���ַ������ûس�
		printf("\n");

		switch(choice)
		{
		case '0':
			return;
		case '1':
			input();
			break;
		case '2':
			process();
			break;
		case '3':
			output();
			break;
		case '4':
			randdata();
			break;
		default:
			printf("�������\n");	
		}// end switch
		printf("Press any key to continue.....");
		getch();
	}//end while
	getch();
}

//��ʾ�ı��˵�
void ListMenu()
{
	printf("  �γ̲˵�\n");
	printf("===========\n");
	printf("1.����ɼ�\n");
	printf("2.ͳ�ƴ���\n");
	printf("3.���\n");
	printf("4.����ɼ�\n");
	printf("0. �˳�\n");
	printf("===========\n");
}
