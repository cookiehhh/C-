//��1+2+...+100
//�汾10: ���κ�

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
		printf("������������n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n�������������������룡\n");	
	}	while ( n <= 0);

	return n ;
}
