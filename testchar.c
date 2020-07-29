main()
{
	char ch1 = 'A' , ch2 = 65 , ch3 , ch4 ; //可以用字符常量或者整数对字符变量初始化

	ch3 = ch1 + 32 ;  // 字符变量可以参与运算

	printf("输入一个字符：");
	//scanf("%c" , &ch4); //可以输入多个字符，回车结束
	ch4 = getche(); 


	printf("\nch1 = %c, ASCII = %d\n" , ch1 , ch1);
	printf("ch2 = %c, ASCII = %d\n" , ch2 , ch2);
	printf("ch3 = %c, ASCII = %d\n" , ch3 , ch3);
	printf("ch4 = %c, ASCII = %d\n" , ch4 , ch4);
}