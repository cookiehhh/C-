//��n!
//�汾1: �������ͣ�12!û�����⣬13!�����

main()
{
	int n ;

	n = input();

	printf("n = %d , n! = %d\n" , n , factfun(n) );

}

int  input()
{
	int n ;

	do
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);

	return n ;
}

int factfun(int  n)
{
	int fact = 1 , i ;

	for ( i = 1 ; 	i <= n ; 	i ++ ) 
	{
		fact = fact * i ;					
	}

	return  fact ;
}