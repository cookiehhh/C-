//��n!�汾2
//����汾1������: �������ͣ�12!û�����⣬13!�����

main()
{
	int n ;
	double factfun(int n); //��������

	n = input();

	printf("n = %d , n! = %.0f\n" , n , factfun(n) );

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

double factfun(int n)
{
	double fact = 1 ;
	int i ;

	for ( i = 1 ; 	i <= n ; 	i ++ ) 
	{
		fact = fact * i ;					
	}

	return  fact ;
}

