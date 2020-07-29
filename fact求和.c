//求1！+2!+...+50! 

main()
{
	int n , i ;
	double sum = 0 ;
	double factfun(int n);//函数声明

	n = input();
	
	for (i = 1 ; i <= n ; i++)
	{
		sum += factfun(i) ; 
	}

	printf("n = %d ,  n! = %.0f = %g\n" , n , sum,sum );
}

//输入一个整数
int input()
{

	int n ;

	do
	{
		printf("输入一个正整数：");
		scanf("%d" , &n);
		if (n <= 0)
			printf("输入错误！%d不是一个正整数\n",n);
	}while( n <= 0);

	return n;
}

//求n!
double factfun(int n)
{
	double fact = 1;
	int i;
		
	for (i = 1 ;  i <= n ; ++ i )
	{
		fact = fact * i ;
	}

	return fact ;
}
