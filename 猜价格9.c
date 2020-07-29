//随机数产生价格
//加入while(1)，保证游戏一直运行，直到用户按n退出。
//加入关数，分数。
//加入状态变量won

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
		printf("欢迎进入游戏第%d关，" ,level);
		printf("你有%d次猜价格机会\n\n" ,times);

		while (count <= times && won == 0)
		{
			printf("请输入你的价格%d(1-100)：" , count);
			scanf("%d" , &yourPrice);

			if ( yourPrice == price)
			{
				printf("你赢了！\n");
				won = 1 ;
			}
			else if ( yourPrice > price)
				printf("高了！\n");
			else
				printf("低了！\n");	
			++count ;
		}//end while
		if (won == 0)
			printf("你输了！\n");
		
		score += (times - count +1 ) * 100 * level * level ;
		printf("你的分数为：%d\n" , score);
		printf("继续游戏吗?(N或n退出，任意键继续)");
		choice = getche();
		if (choice == 'N' || choice == 'n')
			break;
		system("cls");
		printf("你当前的分数为：%d，请继续游戏....\n" , score);

		if (won == 1) //赢了进入下一关
		{
			level ++ ;
			times --;		
		}
		else //输了可以从第一关开始，分数清0
		{
			level = 1 ;
			times = 10;	
			count = 0;
			score = 0;  //分数清0
		}
	}//end while(1)
}