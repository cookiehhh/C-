//求1+2+...+100
//版本9: 递归

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
		printf("请输入正整数n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n不是正整数，重新输入！\n");	
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