//多路分支

main()
{
	int price = 80 , guessPrice;

	while (1)
	{
		printf("请输入价格(1-100)：");
		scanf("%d", &guessPrice);

		if ( price == guessPrice)
		{
			printf("你赢了！\n");
			break ;
		}
		else if (guessPrice > price)
			printf("高了！\n");
		else 
			printf("低了！\n");	
	}


	printf("Game over!\n");
}