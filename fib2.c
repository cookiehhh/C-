// һ�����2����

main()
{
	int  f1 = 1 , f2 = 1 , fib , i ;

	printf("Fibnacci���У�\n");
	printf("%d\t%d", f1 , f2);

	for ( i = 2 ; i <= 12 ; i++)
	{
		f1 = f1 + f2 ;
		f2 = f2 + f1 ;
		printf("\t%d\t%d", f1 , f2);
	}
}