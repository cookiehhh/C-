/*
�ı��˵���4�棬switchʵ�ֶ�·��֧��ģ�黯���
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
	int choice;

	void ListMenu(); //��������
	ListMenu(); //��������

	printf("�������ѡ��");
	scanf("%d" , &choice);

	switch(choice)
	{
	case 1:
		ListC();
		break;
	case 2:
		ListCsharp();
		break;
	case 3:
		ListJava();
		break;
	default:
		printf("�������\n");	
	}// end switch

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
	printf("===========\n");
}
