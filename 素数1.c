main()
{
	int n ,  i ;

	do
	{
		printf("���������3��������n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n���Ǵ���3�����������������룡\n");	
	}	while ( n <= 3);


	for (i = 2 ; i <= n-1 ; i++)
	{
		if ( n % i == 0)
			break ;	
	}

	if (i <= n-1 )
		printf("%d����������" , n);
	else 
		printf("%d��������" , n);
}