main()
{
	int n , i , j , k ;

	for (n = 100 ; n <= 999 ; n++)
	{
		i = n % 10 ; //��λ
		j = n /10 % 10; // ʮλ��
		k = n /100; //��λ��

		if (i*i*i + j*j*j + k*k*k  == n) 
			printf("%d\t" , n);
	}

}