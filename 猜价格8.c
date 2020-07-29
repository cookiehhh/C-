//使用计次循环
//利用逻辑表达式，去掉break
//随机数产生价格
//加入while(1)，保证游戏一直运行，直到用户按n退出。
//加入关数，分数。

# include <stdio.h>

main()
{
	int price , yourPrice = -1 , count;
	int level = 1 , times = 10 ,score = 0;
	char choice;

//	srand();
	srand((unsigned)time(NULL)); 

	while(1)
	{
		price = 1 + rand() % 100;
		count = 1 ;
		printf("欢迎进入游戏第%d关，" ,level);
		printf("你有%d次猜价格机会\n\n" ,times);

		while (count <= times && yourPrice != price)
		{
			printf("请输入你的价格%d(1-100)：" , count);
			scanf("%d" , &yourPrice);

			if ( yourPrice == price)
			{
				printf("你赢了！\n");
			}
			else if ( yourPrice > price)
				printf("高了！\n");
			else
				printf("低了！\n");	
			++count ;
		}//end while
		if (count > times)
			printf("你输了！\n");

		score += (times - count +1 ) *100 ;
		printf("你的分数为：%d\n" , score);
		printf("继续游戏吗?(N或n退出，任意键继续)");
		choice = getche();
		if (choice == 'N' || choice == 'n')
			break;
		system("cls");
		printf("你当前的分数为：%d，请继续游戏....\n" , score);
		if (count <= times)
		{
			level ++ ;
			times --;		
		}
		else 
		{
			level = 1 ;
			times = 10;	
			count = 0;
		}
	}//end while(1)
}