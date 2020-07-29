//版本1：每次输出n的最低位上的数字

main()
{
	int n , count = 0;

	do
	{
		printf("输入一个正整数：");
		scanf("%d" , &n);
		
		if (n <= 0)
			printf("输入错误！%d不是一个正整数\n",n);
	}while( n <= 0);

	printf("n = %d,\n逆序数为:" , n);

	while (n > 0 )
	{
		printf("%d" , n % 10);
		n = n / 10 ;
		count ++;	
	}
	printf("\nn是一个%d位数\n" , count);
}