//�汾3������2- sqrt(n)
#include <math.h>

main()
{ 
	int n ,  i  , k ;
	int isPrime = 1; //��־�������ٶ�������

	do
	{
		printf("���������3��������n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n���Ǵ���3�����������������룡\n");	
	}	while ( n <= 3);

	k = sqrt(n) ;
	for (i = 2 ; i <= k  && isPrime == 1 ; i++)
	{
		if ( n % i == 0)
			isPrime = 0; //	�ж���������
	}

	if (isPrime == 0 )
		printf("%d����������" , n);
	else 
		printf("%d��������" , n);
}