//�汾3������2- sqrt(n)
#include <math.h>
#include "��������.c"

main()
{ 
	int n ;

	for ( n = 100 ; n <= 200 ; n++)
	{
		if (primeFun(n) == 1)
			printf("%d\t" , n);	
	}
}