//��1+2+...+100
//�汾6: n �Ӽ�������,��do...while����Ϸ����ж�
//��for�����ۼ�

main()
{
	int n , sum = 0 , i ;

	do
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);

	for ( i = 1 ; i <= n ; i ++ ) 
	{
		sum = sum + i ;					
	}

	printf("n = %d , sum = %d\n" , n , sum );
}
