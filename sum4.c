//求1+2+...+100
//版本4: n 从键盘输入,用do...while加入合法性判断

main()
{
	int n , sum ;

	do
	{
		printf("请输入正整数n:");
		scanf("%d" , &n);

		if ( n <= 0)
			printf("n不是正整数，重新输入！\n");	
	}	while ( n <= 0);


	sum = (1 + n) * n / 2 ; 

	printf("n = %d , sum = %d\n" , n , sum );

}