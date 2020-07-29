//求1+2+...+100
//版本10: 带参宏

# define  SUM(n)  ((1 + (n)) * (n) / 2)

main()
{
	int n ,sum  ;

	n = input();

	sum = SUM(n) ; 

	printf("n = %d , sum  = %d\n" , n ,  sum );

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
