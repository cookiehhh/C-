//素数函数 ，若n为素数，返回1

#include <math.h>

int  primeFun(int n)
{
	int i , k ,isPrime = 1;

	k = sqrt(n) ;
	for (i = 2 ; i <= k  && isPrime == 1 ; i++)
	{
		if ( n % i == 0)
			isPrime = 0;	
	}

	return isPrime ;
}
