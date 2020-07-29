//版本2：计算出n的逆序数,没有前导0

main()
{
	int n , count = 0;
	int m = 0 ; //m保存n的逆序数

	do
	{
		printf("输入一个正整数：");
		scanf("%d" , &n);
		
		if (n <= 0)
			printf("输入错误！%d不是一个正整数\n",n);
	}while( n <= 0);

	printf("n = %d,\n" , n);

	while (n > 0 )
	{
		m = m *10 + n % 10; //生成逆序数
		n = n / 10 ;
		count ++;	
	}
	printf("n是一个%d位数\n" , count);
	printf("n的逆序数为:%d\n" , m);
}