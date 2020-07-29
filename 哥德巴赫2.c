//验证6到100之内的所有偶数能够拆分为2个素数之和
//素数函数.c文件中是原来版本中的primeFun(int n)
//通过文件包含实现reuse(重用、复用)

#include "素数函数.c"

main()
{
	int i ,j ;
	int count = 0 ;

	for ( i = 50000 ; i <=60000 ; i += 2)
	{
		int checked = 0 ; //i尚未验证，标志变量值为0
		for ( j = 3 ; checked == 0 && j <= i/2 ; j += 2)
		{
			if ( primeFun(j) && primeFun(i-j))
			{
				printf("%d + %d = %d\n" , j , i-j ,i);
				checked = 1 ;//i经过验证，标志变量值为1
			}
		}
		if (checked == 0)
		{
			count ++ ;
			printf("惊天发现！%d不符合哥德巴赫猜想！\n" ,i);
		}
	}
	if (count == 0)
		printf("经过验证，上述偶数均符合哥德巴赫猜想.\n");
	else 
		printf("惊天发现！共%d个数不符合哥德巴赫猜想！\n" ,count);
}