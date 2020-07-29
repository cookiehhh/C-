//°æ±¾3£º²âÊÔ2- sqrt(n)
#include <math.h>
#include "ËØÊıº¯Êı.c"

main()
{ 
	int n ;

	for ( n = 100 ; n <= 200 ; n++)
	{
		if (primeFun(n) == 1)
			printf("%d\t" , n);	
	}
}