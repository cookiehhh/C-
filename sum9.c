//��1+2+...+100
//�汾9: �ݹ�

main()
{
	int n ,sum  ;

	n = input();

	sum = sumfun(n)	;

	printf("n = %d , sum = %d\n" , n , sum );

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

int sumfun(int  n)
{
	if ( n == 1)
		return 1 ;
	else 
		return sumfun(n-1) + n ;
}