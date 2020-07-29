//演示：实参到形参的传递:单向值传递

void swap(int x , int y)
{
	int  temp;


	printf("2: x = %d , y= %d\n" , x ,y );

	temp = x ;
	x = y ;
	y = temp ;

	printf("3: x = %d , y= %d\n" , x ,y );
}

main()
{
	int m = 10 , n = 99 ;

	printf("1: m = %d , n = %d\n" , m ,n );

	swap(m ,n);

	printf("4: m = %d , n = %d\n" , m ,n );
}