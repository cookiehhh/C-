//��1+2+...+100
//�汾4: n �Ӽ�������,��do...while����Ϸ����ж�

main()
{
	int n , sum ;

	do
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);


	sum = (1 + n) * n / 2 ; 

	printf("n = %d , sum = %d\n" , n , sum );

}