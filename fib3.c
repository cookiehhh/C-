main()
{
	int n ;

	do 
	{
		printf("����fibnacci���еĵڼ��");
		scanf("%d" , &n);

		if (n<1)
			printf("�������");
	}while (n < 1);

	printf("fibnacci���еĵ�%d��:%d\n" , n ,fib(n));
}

int fib(int n )
{
	if (n == 1 || n == 2)
		return 1;
	else 
		return fib(n-2)+fib(n-1);
}