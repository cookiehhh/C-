//求1+2+...+100
//版本6: n 从键盘输入,用do...while加入合法性判断
//用for进行累加

main()
{
	int n , sum = 0 , i ;

	do
	{
		printf("请输入正整数n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n不是正整数，重新输入！\n");	
	}	while ( n <= 0);

	for ( i = 1 ; i <= n ; i ++ ) 
	{
		sum = sum + i ;					
	}

	printf("n = %d , sum = %d\n" , n , sum );
}
