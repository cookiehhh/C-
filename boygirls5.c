//版本5：一次从键盘输入多个人数,计算比例
main()
{
	int boys , girls , sum ; //变量定义
	float ratio1 , ratio2 ;

	printf("请输入男生数  女生数：");
	scanf("%d;%d" , &boys , &girls);   //&boys，&girls变量名前要加地址符号&

	sum = boys + girls ;
	ratio1 = (float)boys / sum *100;
	//ratio2 = (float)girls / sum *100;
	ratio2 = 100.0 * girls / sum ;

	printf("班级总人数 = %d\n" , sum);
	printf("男生人数 = %d, 比例 = %.2f %%\n" , boys ,ratio1);
	printf("女生人数 = %d, 比例 = %.2f %%\n" , girls,ratio2);
}