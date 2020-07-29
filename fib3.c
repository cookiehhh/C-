main()
{
	int n ;

	do 
	{
		printf("想求fibnacci数列的第几项？");
		scanf("%d" , &n);

		if (n<1)
			printf("输入错误！");
	}while (n < 1);

	printf("fibnacci数列的第%d项:%d\n" , n ,fib(n));
}

int fib(int n )
{
	if (n == 1 || n == 2)
		return 1;
	else 
		return fib(n-2)+fib(n-1);
}