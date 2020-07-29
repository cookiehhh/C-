//版本0：输入一个三位数，输出逆序数

main()
{
	int n , i , j , k ;

	do
	{
		printf("输入一个三位数：");
		scanf("%d" , &n);
		
		if (n < 100  || n > 999)
			printf("输入错误！%d不是一个三位数\n",n);
	}while( n < 100  || n > 999 );

	printf("n = %d,\n逆序数为:" , n);

	i = n % 10 ; //个位
	j = n /10 % 10; // 十位数
	k = n /100; //百位数
	printf("%d%d%d\n" ,  i , j , k);
}