//��1+2+...+100
//�汾3: n �Ӽ�������,����Ϸ����ж�

main()
{
	int n = -1, sum ;

	while ( n <= 0)
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}

	sum = (1 + n) * n / 2 ; 

	printf("n = %d , sum = %d\n" , n , sum );

}
