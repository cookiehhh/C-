//验证6到100之内的所有偶数能够拆分为2个素数之和
//素数函数.c文件中是原来版本中的isPrimeFun(int n)
//通过文件包含实现reuse(重用、复用)

#include "素数函数.c"

main()
{
	int i ,j ;

	for ( i = 6; i <= 100 ; i += 2)  //穷举偶数
	{
		for ( j = 3 ; j <= i/2 ; j += 2) // 穷举寻找一个数对（j, i-j）都是素数
		{
			if ( primeFun(j) && primeFun(i-j))
			{
				printf("%d + %d = %d\n" , j , i-j ,i);
				break;
			}
		}
	}
}