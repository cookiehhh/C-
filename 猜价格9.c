//����������۸�
//����while(1)����֤��Ϸһֱ���У�ֱ���û���n�˳���
//���������������
//����״̬����won

# include <stdio.h>

main()
{
	int price , yourPrice = -1 , count , won;
	int level = 1 , times = 10 ,score = 0;
	char choice;

	srand((unsigned)time(NULL)); 

	while(1)
	{
		won = 0 ;
		price = 1 + rand() % 100;
		count = 1 ;
		printf("��ӭ������Ϸ��%d�أ�" ,level);
		printf("����%d�β¼۸����\n\n" ,times);

		while (count <= times && won == 0)
		{
			printf("��������ļ۸�%d(1-100)��" , count);
			scanf("%d" , &yourPrice);

			if ( yourPrice == price)
			{
				printf("��Ӯ�ˣ�\n");
				won = 1 ;
			}
			else if ( yourPrice > price)
				printf("���ˣ�\n");
			else
				printf("���ˣ�\n");	
			++count ;
		}//end while
		if (won == 0)
			printf("�����ˣ�\n");
		
		score += (times - count +1 ) * 100 * level * level ;
		printf("��ķ���Ϊ��%d\n" , score);
		printf("������Ϸ��?(N��n�˳������������)");
		choice = getche();
		if (choice == 'N' || choice == 'n')
			break;
		system("cls");
		printf("�㵱ǰ�ķ���Ϊ��%d���������Ϸ....\n" , score);

		if (won == 1) //Ӯ�˽�����һ��
		{
			level ++ ;
			times --;		
		}
		else //���˿��Դӵ�һ�ؿ�ʼ��������0
		{
			level = 1 ;
			times = 10;	
			count = 0;
			score = 0;  //������0
		}
	}//end while(1)
}