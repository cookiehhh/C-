//�汾1��ÿ�����n�����λ�ϵ�����

main()
{
	int n , count = 0;

	do
	{
		printf("����һ����������");
		scanf("%d" , &n);
		
		if (n <= 0)
			printf("�������%d����һ��������\n",n);
	}while( n <= 0);

	printf("n = %d,\n������Ϊ:" , n);

	while (n > 0 )
	{
		printf("%d" , n % 10);
		n = n / 10 ;
		count ++;	
	}
	printf("\nn��һ��%dλ��\n" , count);
}