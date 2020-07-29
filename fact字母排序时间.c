//版本3：求阶乘，用递归

main()
{
	int n  ;
	double time; 
	double factfun(int n);//函数声明

	n = input();
	time =  factfun(n); 

	printf("n = %d ,  n! = %.0f\n" , n , time);
	printf("需要%.0f纳秒\n" ,time);
	printf("需要%.0f秒\n" ,time/1e9);
	printf("需要%.0f分钟\n" ,time/1e9/60);	
	printf("需要%.0f小时\n" ,time/1e9/60/60);
	printf("需要%.0f天\n" ,time/1e9/60/60/24);	
	printf("需要%.0f年\n" ,time/1e9/60/60/24/365);
}

//输入一个整数
int input()
{
	int n ;

	do
	{
		printf("有多少个字母需要排序，输入一个正整数：");
		scanf("%d" , &n);
		if (n <= 0)
			printf("输入错误！%d不是一个正整数\n",n);
	}while( n <= 0);

	return n;
}

//求n!
double factfun(int n)
{
	if (n == 1 || n == 0) //递归终止条件
		return 1 ;
	else   //递归公式
		return factfun(n-1) * n ; 
}
