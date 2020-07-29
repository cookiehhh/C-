# include <stdio.h>
#define N  1000000

main()
{
	int up = 0 , down = 0 , i , r ;

	srand((unsigned)time(NULL));  //利用时间函数做种子

	for (i = 1 ; i <= N ; i++)
	{
		r = 1 + rand() % 100 ; //产生随机数1-100

		if (r <= 50)
			up ++ ;
		else 
			down ++ ;	
	}

	printf("一共模拟了%d次\n", N);
	printf("向上%d次\n", up);
	printf("向下%d次\n", down);
}