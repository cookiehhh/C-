//�汾6����������۸�

#include <stdio.h>
#define  N  10

main()
{
	int price , guessPrice , count = 1;

	srand((unsigned)time(NULL));  //����ʱ�亯��������
	price = 1 + rand() % 100 ; //���������1-100

	while (count <= N)
	{
		printf("������۸�(1-100)��");
		scanf("%d", &guessPrice);

		if ( price == guessPrice)
		{
			printf("��Ӯ�ˣ�\n");
			break ;
		}
		else if (guessPrice > price)
			printf("���ˣ�\n");
		else 
			printf("���ˣ�\n");	

		//count ++ ; 
		//count = count +1 ;
		count += 1 ;
	}

	if (count > N )
		printf("���Ѿ�����%d�Σ������ˣ�\n" , N);

	printf("Game over!\n");
}