//求1+2+...+100
//版本2: n 从键盘输入

main()
{
	int n , sum ;

	printf("请输入n:");
	scanf("%d" , &n);

	sum = (1 + n) * n / 2 ; 

	printf("n = %d , sum = %d\n" , n , sum );
}
