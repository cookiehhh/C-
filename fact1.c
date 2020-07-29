//求n!
//版本1: 整数类型，12!没有问题，13!溢出了

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
		printf("请输入正整数n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n不是正整数，重新输入！\n");	
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