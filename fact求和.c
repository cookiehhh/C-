//��1��+2!+...+50! 

main()
{
	int n , i ;
	double sum = 0 ;
	double factfun(int n);//��������

	n = input();
	
	for (i = 1 ; i <= n ; i++)
	{
		sum += factfun(i) ; 
	}

	printf("n = %d ,  n! = %.0f = %g\n" , n , sum,sum );
}

//����һ������
int input()
{

	int n ;

	do
	{
		printf("����һ����������");
		scanf("%d" , &n);
		if (n <= 0)
			printf("�������%d����һ��������\n",n);
	}while( n <= 0);

	return n;
}

//��n!
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
