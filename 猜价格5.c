//版本5：限定次数
#define  N  10

main()
{
	int price = 80 , guessPrice , count = 1;

	while (count <= N)
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

		//count ++ ; 
		//count = count +1 ;
		count += 1 ;
	}

	if (count > N )
		printf("你已经猜满%d次！你输了！\n" , N);

	printf("Game over!\n");
}