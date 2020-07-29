//∞Ê±æ3£∫≤‚ ‘2- sqrt(n)
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

main()
{ 
	int n ;

	for ( n = 100 ; n <= 200 ; n++)
	{
		if (primeFun(n) == 1)
			printf("%d\t" , n);	
	}
}