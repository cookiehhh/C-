/*
�ı��˵���6�棬switchʵ�ֶ�·��֧��ģ�黯���
��char���int��Ϊ����ѡ������ͣ������ʽ�쳣
2017.9.25
*/

void ListC()
{
	printf("C���ԣ�2317 ��4ѧ��\n");
	printf("�Ͽν�ʦ����ѧ��OFFICE:��һ����1��30\n");
}

void ListCsharp()
{
	printf("C#���ԣ�4210 ��6ѧ��\n");
	printf("�Ͽν�ʦ������죬OFFICE:��������1��30\n");
}

void ListJava()
{	
	printf("Java���ԣ�4208 ��6ѧ��\n");
	printf("�Ͽν�ʦ���ԣ�OFFICE:��������1��30\n");
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
		//choice = getchar() ;
		choice = getche() ; //���뵥���ַ������ûس�
		printf("\n");

		switch(choice)
		{
		case '0':
			return;
		case '1':
			ListC();
			break;
		case '2':
			ListCsharp();
			break;
		case '3':
			ListJava();
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
	printf("1.C����\n");
	printf("2.C#����\n");
	printf("3.Java����\n");
	printf("0. �˳�\n");
	printf("===========\n");
}
