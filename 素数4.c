//版本3：测试2- sqrt(n)
#include <math.h>

main()
{ 
	int n ,  i  , k ;
	int isPrime = 1; //标志变量，假定是素数

	do
	{
		printf("请输入大于3的正整数n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n不是大于3的正整数，重新输入！\n");	
	}	while ( n <= 3);

	k = sqrt(n) ;
	for (i = 2 ; i <= k  && isPrime == 1 ; i++)
	{
		if ( n % i == 0)
			isPrime = 0; //	判定不是素数
	}

	if (isPrime == 0 )
		printf("%d不是素数！" , n);
	else 
		printf("%d是素数！" , n);
}