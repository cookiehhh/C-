//ʹ�üƴ�ѭ��
//�����߼����ʽ��ȥ��break
//����������۸�
//����while(1)����֤��Ϸһֱ���У�ֱ���û���n�˳���
//���������������

# include <stdio.h>

main()
{
	int price , yourPrice = -1 , count;
	int level = 1 , times = 10 ,score = 0;
	char choice;

//	srand();
	srand((unsigned)time(NULL)); 

	while(1)
	{
		price = 1 + rand() % 100;
		count = 1 ;
		printf("��ӭ������Ϸ��%d�أ�" ,level);
		printf("����%d�β¼۸����\n\n" ,times);

		while (count <= times && yourPrice != price)
		{
			printf("��������ļ۸�%d(1-100)��" , count);
			scanf("%d" , &yourPrice);

			if ( yourPrice == price)
			{
				printf("��Ӯ�ˣ�\n");
			}
			else if ( yourPrice > price)
				printf("���ˣ�\n");
			else
				printf("���ˣ�\n");	
			++count ;
		}//end while
		if (count > times)
			printf("�����ˣ�\n");

		score += (times - count +1 ) *100 ;
		printf("��ķ���Ϊ��%d\n" , score);
		printf("������Ϸ��?(N��n�˳������������)");
		choice = getche();
		if (choice == 'N' || choice == 'n')
			break;
		system("cls");
		printf("�㵱ǰ�ķ���Ϊ��%d���������Ϸ....\n" , score);
		if (count <= times)
		{
			level ++ ;
			times --;		
		}
		else 
		{
			level = 1 ;
			times = 10;	
			count = 0;
		}
	}//end while(1)
}