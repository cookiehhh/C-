//�汾2�������n��������,û��ǰ��0

main()
{
	int n , count = 0;
	int m = 0 ; //m����n��������

	do
	{
		printf("����һ����������");
		scanf("%d" , &n);
		
		if (n <= 0)
			printf("�������%d����һ��������\n",n);
	}while( n <= 0);

	printf("n = %d,\n" , n);

	while (n > 0 )
	{
		m = m *10 + n % 10; //����������
		n = n / 10 ;
		count ++;	
	}
	printf("n��һ��%dλ��\n" , count);
	printf("n��������Ϊ:%d\n" , m);
}