//��100 ֮�ڵ��������������Ϊ2��2��������������
#include <math.h>
#include "��������.c"

main()
{ 
	int n ;

	for ( n = 3 ; n <= 100 ; n += 2)
	{
		if (primeFun(n) == 1  &&  primeFun(n + 2) == 1)
			printf("%d\t%d\n" , n ,n+2);	
	}

}