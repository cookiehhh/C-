//�汾7������while(1)

#include <stdio.h>
#define  N  10

main()
{
	int price , guessPrice , count ;
	char choice ;

	//srand(); //������ʱ�亯�������ӣ��´����л����ͬһ����

	srand((unsigned)time(NULL));  //����ʱ�亯��������

	while (1)
	{
		price = 1 + rand() % 100 ; //���������1-100
		count = 1;

		while (count <= N  && price != guessPrice)
		{
			printf("������۸�(1-100)��");
			scanf("%d", &guessPrice);

			if ( price == guessPrice)
			{
				printf("��Ӯ�ˣ�\n");
				//break ;
			}
			else if (guessPrice > price)
				printf("���ˣ�\n");
			else 
				printf("���ˣ�\n");	

			//count ++ ; 
			//count = count +1 ;
			count += 1 ;
		}// end while (count)
		if (count > N )
			printf("���Ѿ�����%d�Σ������ˣ�\n" , N);

		printf("������Ϸ��?(Y/N)");
		choice = getche();

		if (choice != 'Y'  &&  choice != 'y' ) //�߼�������2��������ͬ��Ϊ��
			break ;

		system("cls");
		printf("��ӭ������Ϸ.....");	
	} // end while(1)
	printf("Game over!\n");
}