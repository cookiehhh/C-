//��1+2+...+100
//�汾8: ������

main()
{
	int n ,sum  ;

	n = input();//����һ�������� 

	sum = sumfun(n)	;//��� 

	printf("n = %d , sum = %d\n" , n , sum );
}

//����һ��������
int  input( )
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

//��� 
int sumfun(int  n)
{
	int sum = 0 , i ;

	for ( i = 1 ; 	i <= n ; 	i ++ ) 
	{
		sum = sum + i ;					
	}

	return  sum ;
}
