//求1+2+...+100
//版本8: 函数化

main()
{
	int n ,sum  ;

	n = input();//输入一个正整数 

	sum = sumfun(n)	;//求和 

	printf("n = %d , sum = %d\n" , n , sum );
}

//输入一个正整数
int  input( )
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

//求和 
int sumfun(int  n)
{
	int sum = 0 , i ;

	for ( i = 1 ; 	i <= n ; 	i ++ ) 
	{
		sum = sum + i ;					
	}

	return  sum ;
}
