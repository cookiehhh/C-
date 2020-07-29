main()
{
	int n , i , j , k ;

	for (i = 1 ; i <= 9 ; i++) //百位数
		for (j = 0 ; j <= 9 ; j++)//shiweishu
			for (k = 0 ; k <= 9 ; k++)//个位数
			{
				n = i*100 + j*10 +k ;
				if (i*i*i + j*j*j + k*k*k  == n) 
					printf("%d\n" , n);
			}

}