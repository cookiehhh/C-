//��1+2+...+100
//�汾6: n �Ӽ�������,��do...while����Ϸ����ж�
//��do...while�����ۼ�

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
	do
	{
		sum = sum + i ;
		i ++ ;	
	}	while (i <= n);

	printf("n = %d , sum = %d\n" , n , sum );
}
