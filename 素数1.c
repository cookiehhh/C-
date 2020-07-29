main()
{
	int n ,  i ;

	do
	{
		printf("请输入大于3的正整数n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n不是大于3的正整数，重新输入！\n");	
	}	while ( n <= 3);


	for (i = 2 ; i <= n-1 ; i++)
	{
		if ( n % i == 0)
			break ;	
	}

	if (i <= n-1 )
		printf("%d不是素数！" , n);
	else 
		printf("%d是素数！" , n);
}