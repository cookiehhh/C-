main()
{
	int price = 80 , guessPrice;

	printf("������۸�(1-100)��");
	scanf("%d", &guessPrice);


	if ( price == guessPrice)
		printf("��Ӯ�ˣ�\n");	
	else 
		printf("�����ˣ�\n");

	/*
	if ( price != guessPrice)
		printf("�����ˣ�\n");	
	else 
		printf("��Ӯ�ˣ�\n");
	*/
	printf("Game over!\n");
}