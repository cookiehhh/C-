//��n!�汾3,�ݹ鷨

main()
{
	int n ;
	double factfun(int n); //��������

	n = input();

	printf("n = %d , n! = %.0f\n" , n , factfun(n) );

}

int  input()
{
	int n ;

	do
	{
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);

	return n ;
}

double factfun(int n)
{
	if ( n == 1 || n == 0) //�ݹ���ֹ����
		return 1 ;
	else
		return factfun(n - 1) * n ;  //�ݹ鹫ʽ
}

