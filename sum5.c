//��1+2+...+100
//�汾4: n �Ӽ�������,��do...while����Ϸ����ж�

main()
{
	int n , sum , i ;

	do
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);

	//sum = (1 + n) * n / 2 ; 
	i = 1 ;
	sum = 0 ;
	while (i <= n)
	{
		sum = sum + i ;
		i ++ ;	
	}

	printf("n = %d , sum = %d\n" , n , sum );
}
