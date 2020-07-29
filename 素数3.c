//版本3：测试2 - sqrt(n)
#include <math.h>

main()
{
	int n ,  i  , k;

	do
	{
		printf("请输入大于3的正整数n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n不是大于3的正整数，重新输入！\n");	
	}	while ( n <= 3);


	k = sqrt(n);
	for (i = 2 ; i <= k ; i++)
	{
		if ( n % i == 0)
			break ;	
	}

	if (i <= k )
		printf("%d不是素数！" , n);
	else 
		printf("%d是素数！" , n);
}