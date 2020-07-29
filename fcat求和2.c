//求1！+2!+...+50!  
#define N 50

main()
{
	int n , i ;
	double sum = 0 ;
	double factfun(int n);//函数声明

	for (i = 1 ; i <= N ; i++)
	{
		sum += factfun(i) ; 
	}

	printf("1！+2!+...+50! = %.0f = %g\n" , sum, sum);
}

//求n！ 
double factfun(int n)
{
	if (n == 1 || n == 0)
		return 1 ;
	else 
		return factfun(n-1) * n ;
}
