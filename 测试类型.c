/*
�ı��˵���6�棬 ��while(1) ʵ��ѭ��
���ַ����ͽ����5���е��쳣���û���Ӧ����������ʱ�����ַ����������������С�
2017.10.20
*/

#include <stdio.h>

//��ʾ�γ̲˵�
void ListMenu()
{
	printf("   �γ̲˵�\n");
	printf(" ============\n");
	printf(" 1. short����\n");
	printf(" 2. char����\n");
	printf(" 3. unsigned short����\n");
	printf(" 4. unsigned char����\n");
	printf(" ============\n");
}

//����short
void testshort()
{
	short  x = 32766 ; 

	printf("shortռ%d���ֽ�\n"  , sizeof(short));
	printf("short����xռ%d���ֽ�\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
}

//����char
void testchar()
{
	char  x = 126 ; 

	printf("charռ%d���ֽ�\n"  , sizeof(char));
	printf("char����xռ%d���ֽ�\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);

}

//����unsigned short
void testushort()
{
	unsigned short  x = 65534 ; 

	printf("unsigned shortռ%d���ֽ�\n"  , sizeof(unsigned short));
	printf("unsigned short����xռ%d���ֽ�\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
}

//����unsigned char
void testuchar()
{
	unsigned char  x = 254 ; 

	printf("unsigned charռ%d���ֽ�\n"  , sizeof(unsigned char));
	printf("unsigned char����xռ%d���ֽ�\n"  , sizeof(x));
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);
	x ++ ;
	printf("x = %d\n"  , x);

}

//������
main()
{
	char choice;

	while(1) //����ѭ��
	{
		system("cls");//���� = clear screen
		ListMenu(); //��������
		printf("���������ѡ��");
		//scanf("%c" , &choice);
		choice = getche();
		printf("\n");

		switch(choice)
		{
		case 0:
			return ;
		case '1':
			testshort();
			break;
		case '2':
			testchar();
			break;
		case '3':
			testushort();
			break;
		case '4':
			testuchar();
			break;
		default :
			printf("�������\n");
		}//end switch
		printf("Press any key to continue ......");
		getch();//�Ӽ������������ַ�
	}//end while
}//end main
