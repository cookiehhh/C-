//求n!版本2
//解决版本1的问题: 整数类型，12!没有问题，13!溢出了

main()
{
	int n ;
	double factfun(int n); //函数声明

	n = input();

	printf("n = %d , n! = %.0f\n" , n , factfun(n) );

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

