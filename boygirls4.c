//版本4：一次从键盘输入多个人数
main()
{
	int boys , girls , sum ; //变量定义

	printf("请输入男生数  女生数：");
	scanf("%d%d" , &boys , &girls);   //&boys，&girls变量名前要加地址符号&

	sum = boys + girls ;

	printf("班级总人数 = %d\n" , sum);
	printf("男生人数 = %d\n" , boys);
	printf("女生人数 = %d\n" , girls);
}