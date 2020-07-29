//求n!版本3,递归法

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
	if ( n == 1 || n == 0) //递归终止条件
		return 1 ;
	else
		return factfun(n - 1) * n ;  //递归公式
}

