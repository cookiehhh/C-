main()
{
	int n , i , j , k ;

	for (n = 100 ; n <= 999 ; n++)
	{
		i = n % 10 ; //个位
		j = n /10 % 10; // 十位数
		k = n /100; //百位数

		if (i*i*i + j*j*j + k*k*k  == n) 
			printf("%d\t" , n);
	}

}