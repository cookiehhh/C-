main()
{
	int m =100 , n =60 ;
	void swap (int x , int y);//��������

	printf("main 1: m = %d , n = %d\n" , m , n);
	swap(m, n);
	printf("main 2: m = %d , n = %d\n" , m , n);	
}

void swap (int x , int y)
{
	int temp;
	
	printf("����swap 1: x = %d , y = %d\n" , x , y);
	//���ñ���temp����2��������ֵ
	temp = x ;
	x = y ;
	y = temp ;

	printf("����swap 2: x = %d , y = %d\n" , x , y);
}
