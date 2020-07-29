main()
{
	int  f1 = 1 , f2 = 1 , fib , i ;

	printf("FibnacciÊıÁĞ£º\n");
	printf("%d\t%d", f1 , f2);

	for ( i = 3 ; i <= 24 ; i++)
	{
		fib = f1 + f2 ;
		printf("\t%d", fib);

		f1 = f2 ;
		f2 = fib;	
	}
}