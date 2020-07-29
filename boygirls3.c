//版本3：从键盘输入人数
main()
{
	int boys , girls , sum ; //变量定义

	printf("请输入男生数：");
	scanf("%d" , &boys);   //&boys，变量名前要加地址符号&
	printf("请输入女生数：");
	scanf("%d" , &girls);

	sum = boys + girls ;

	printf("班级总人数 = %d\n" , sum);
	printf("男生人数 = %d\n" , boys);
	printf("女生人数 = %d\n" , girls);
}