//�汾4����ȡ����,����2- sqrt(n)
#include <math.h>

int  primeFun(int m)
{
	int i , k ,isPrime = 1;

	k = sqrt(m) ;
	for (i = 2 ; i <= k  && isPrime == 1 ; i++)
	{
		if ( m % i == 0)
			isPrime = 0;	
	}

	return isPrime ;//������������1�����򣬷���0
}

main()
{ 
	int n ;

	do
	{
		printf("���������3��������n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n���Ǵ���3�����������������룡\n");	
	}	while ( n <= 3);

	if (primeFun(n) == 0 )
		printf("%d����������" , n);
	else 
		printf("%d��������" , n);
}