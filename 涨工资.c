#define N  3

void listPayment(int p[])
{
	int i ;

	for (i = 0 ; i < N ; i++)
		printf("%d\t" , p[i]);
}

//给某人涨工资
void add(int x)
{
	x += 1000;
	printf("%d\n" ,x);
}

//给所有人涨工资
void addall(int p[])// int p[] = int *p
{
	int i ;

	for (i = 0 ; i < N ; i++)
	{
		p[i] += 1000;
		printf("%d\t" , p[i]);	
	}		
}

main()
{
	int payment[N] = {800,900,1000};

	listPayment(payment);

	add(payment[0]);//数组元素做实参，是值传递
	printf("%d\n" ,payment[0]);//虽然形参改变，但不影响实参

	addall(payment);//数组名做实参，是地址传递
	listPayment(payment);//对形参数组元素的改变，影响实参数组元素

}