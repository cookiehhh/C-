//��·��֧

main()
{
	int price = 80 , guessPrice;

	while (1)
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
	}


	printf("Game over!\n");
}