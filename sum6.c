//求1+2+...+100
//版本6: n 从键盘输入,用do...while加入合法性判断
//用do...while进行累加

main()
{
	int n , sum , i ;

	do
	{
		printf("请输入正整数n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n不是正整数，重新输入！\n");	
	}	while ( n <= 0);

	//sum = (1 + n) * n / 2 ; 
	i = 1 ;
	sum = 0 ;
	do
	{
		sum = sum + i ;
		i ++ ;	
	}	while (i <= n);

	printf("n = %d , sum = %d\n" , n , sum );
}
