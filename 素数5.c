//版本4：抽取函数,测试2- sqrt(n)
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

	return isPrime ;//是素数，返回1；否则，返回0
}

main()
{ 
	int n ;

	do
	{
		printf("请输入大于3的正整数n:");
		scanf("%d" , &n);

		if ( n <= 3)
			printf("n不是大于3的正整数，重新输入！\n");	
	}	while ( n <= 3);

	if (primeFun(n) == 0 )
		printf("%d不是素数！" , n);
	else 
		printf("%d是素数！" , n);
}