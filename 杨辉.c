#define N  10

main()
{
	int  i , j ,yang[N][N] ;

	for (i = 0 ; i < N ; i++)
	{
		yang[i][0] = 1 ;
		yang[i][i] = 1 ;	
	}

	for ( i = 2 ; i < N ; i++ )
		for ( j = 1 ; j < i ; j ++ )
		{
			yang[i][j] = yang[i-1][j] + yang[i-1][j-1] ;		
		}

	for ( i = 0 ; i < N ; i++ )
	{
		for ( j = 0 ; j <= i ; j ++ )
			printf("%d\t" , yang[i][j]);

		printf("\n") ;
	}
}