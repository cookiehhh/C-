main()
{
	//�õ����ַ����г�ʼ����ע�����鳤��Ҫ�㹻,
	//Ҫ��'\0'�Ŀռ䣬���������һЩ�ַ�
	//char name[10] = {'L','i','u','x','u','e'};

	//����ʹ���ַ���������ʼ����ע�����鳤��Ҫ�㹻
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

	//name = "Liuxue" ;  //���ܸ�ֵ
	//strcpy(name, "Liuxue");

	//printf("�����������:");
	//scanf("%s" , name);  //��������ո��ַ�����
	//gets(name);  //������ո��ַ�����

	//printf("Hello!%s\n"  , name);
	//puts("Hello!");
	//puts(name1);
	//puts(name);

	for (i=0 ; i < 10 ; i++)
		printf("%c" , name[i]);
		//putchar(name[i]);

	//printf("\n%d\n" , strcmp(name1 , name));
	//printf("����name�Ĵ�С��%d\n" ,sizeof(name));
	//printf("�ַ���name�ĳ��ȣ�%d\n" ,strlen(name));
}