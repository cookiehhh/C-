//�汾3������2 - sqrt(n)
#include <math.h>

main()
{
	int n ,  i  , k;

	do
	{
		printf("���������3��������n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n���Ǵ���3�����������������룡\n");	
	}	while ( n <= 3);


	k = sqrt(n);
	for (i = 2 ; i <= k ; i++)
	{
		if ( n % i == 0)
			break ;	
	}

	if (i <= k )
		printf("%d����������" , n);
	else 
		printf("%d��������" , n);
}