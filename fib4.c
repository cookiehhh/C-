//ʹ�����飬�����ڵ���
#define N  24

main()
{
	int fib[N + 1] = {0,1,1}, i;

	printf("Fibnacci���У�\n");
	printf("%d\t%d\t" , fib[1] , fib[2]);

	for ( i = 3 ; i <= N ; i++)
	{
		fib[i] = fib[i-2] + fib[i-1] ;
		printf("%d\t" , fib[i]);		
	}
}