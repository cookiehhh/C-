//求100 之内的孪生素数（相差为2的2个数都是素数）
#include <math.h>
#include "素数函数.c"

main()
{ 
	int n ;

	for ( n = 3 ; n <= 100 ; n += 2)
	{
		if (primeFun(n) == 1  &&  primeFun(n + 2) == 1)
			printf("%d\t%d\n" , n ,n+2);	
	}

}