//版本7：加入while(1)

#include <stdio.h>
#define  N  10

main()
{
	int price , guessPrice , count ;
	char choice ;

	//srand(); //不利用时间函数做种子，下次运行会产生同一个数

	srand((unsigned)time(NULL));  //利用时间函数做种子

	while (1)
	{
		price = 1 + rand() % 100 ; //产生随机数1-100
		count = 1;

		while (count <= N  && price != guessPrice)
		{
			printf("请输入价格(1-100)：");
			scanf("%d", &guessPrice);

			if ( price == guessPrice)
			{
				printf("你赢了！\n");
				//break ;
			}
			else if (guessPrice > price)
				printf("高了！\n");
			else 
				printf("低了！\n");	

			//count ++ ; 
			//count = count +1 ;
			count += 1 ;
		}// end while (count)
		if (count > N )
			printf("你已经猜满%d次！你输了！\n" , N);

		printf("继续游戏吗?(Y/N)");
		choice = getche();

		if (choice != 'Y'  &&  choice != 'y' ) //逻辑与连接2个条件，同真为真
			break ;

		system("cls");
		printf("欢迎继续游戏.....");	
	} // end while(1)
	printf("Game over!\n");
}