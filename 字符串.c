main()
{
	//用单个字符进行初始化，注意数组长度要足够,
	//要有'\0'的空间，否则会多输出一些字符
	//char name[10] = {'L','i','u','x','u','e'};

	//建议使用字符串常量初始化，注意数组长度要足够
	char name1[10] = "Liuxue";
	char name[10] = "LiuXue123";

	int i;

	double a , b = 456.678;;

	scanf("%lf" , &a);
	printf("%.2f\t%.2f\n" , a , b);
	//printf("a= %E\n" , a);
	//printf("a= %g\n" , a);



	//int a = 0xFF ;
	//short int a = 65;
	//printf("a = %#o\n" , a) ;

	//strcat (name1 , name );

	//char name[10];

	//name = "Liuxue" ;  //不能赋值
	//strcpy(name, "Liuxue");

	//printf("输入你的名字:");
	//scanf("%s" , name);  //不能输入空格到字符数组
	//gets(name);  //能输入空格到字符数组

	//printf("Hello!%s\n"  , name);
	//puts("Hello!");
	//puts(name1);
	//puts(name);

	for (i=0 ; i < 10 ; i++)
		printf("%c" , name[i]);
		//putchar(name[i]);

	//printf("\n%d\n" , strcmp(name1 , name));
	//printf("数组name的大小：%d\n" ,sizeof(name));
	//printf("字符串name的长度：%d\n" ,strlen(name));
}