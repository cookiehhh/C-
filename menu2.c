/*
�ı��˵��ڶ��棬��·��֧
2017.9.25
*/

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


//������
main()
{
	int choice;

	ListMenu();
	printf("�������ѡ��");
	scanf("%d" , &choice);

	if (choice == 1)
	{
		printf("C���ԣ�2317 ��4ѧ��\n");
		printf("�Ͽν�ʦ����ѧ��OFFICE:��һ����1��30\n");
	}
	else if (choice == 2)
	{
		printf("C#���ԣ�4210 ��6ѧ��\n");
		printf("�Ͽν�ʦ������죬OFFICE:��������1��30\n");
	}
	else if (choice == 3)
	{
		printf("Java���ԣ�4208 ��6ѧ��\n");
		printf("�Ͽν�ʦ���ԣ�OFFICE:��������1��30\n");
	}
	else 
		printf("�������\n");

	getch();
}
