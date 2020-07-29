main()
{
	int m =100 , n =60 ;
	void swap (int x , int y);//函数声明

	printf("main 1: m = %d , n = %d\n" , m , n);
	swap(m, n);
	printf("main 2: m = %d , n = %d\n" , m , n);	
}

void swap (int x , int y)
{
	int temp;
	
	printf("调用swap 1: x = %d , y = %d\n" , x , y);
	//利用变量temp交换2个变量的值
	temp = x ;
	x = y ;
	y = temp ;

	printf("调用swap 2: x = %d , y = %d\n" , x , y);
}
