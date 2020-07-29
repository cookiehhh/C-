main()
{
	int price = 80 , guessPrice;

	printf("请输入价格(1-100)：");
	scanf("%d", &guessPrice);

	if ( price == guessPrice  )
		printf("你赢了！\n");

	printf("Game over!\n");
}