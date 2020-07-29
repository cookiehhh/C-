//实现strcpy字符串复制的功能,版本1
void mystrcpy(char s1[] ,const char s2[] )
{
	int i = 0 ;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i] ;//逐个字符复制
		i++;
	}
	s1[i] = '\0';//字符串结束标志
}

//实现strcpy字符串复制的功能,版本2
void mystrcpy2(char *s1,const char *s2 )
{
	int i = 0 ;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i] ;//逐个字符复制
		i++;
	}
	s1[i] = '\0';//字符串结束标志
}

//实现strcpy字符串复制的功能,版本3
void mystrcpy3(char *s1,const char *s2 )
{
	while (*s2 != '\0')
	{
		*s1 = *s2 ;//逐个字符复制
		s1++;
		s2++;
		//*s1 ++ = *s2 ++ ;//以上三行可以简化为一行
	}
	*s1 = '\0';//字符串结束标志
}

//实现strcat字符串连接的功能
void mystrcat(char s1[] ,const char s2[] )
{
	int i = 0 , j = 0 ;

	while (s1[i] != '\0')//找s1的尾
		i++;

	while (s2[j] != '\0')
	{
		s1[i] = s2[j] ;//逐个字符复制
		i++;
		j++;
	}
	s1[i] = '\0';//字符串结束标志
}

//实现strlen求字符串长度的功能
int  mystrlen(const char s1[] )
{
	int i = 0 ;

	while (s1[i] != '\0')
	{
		i++;
	}
	return i;
}

//实现strcmp字符串比较的功能
int  mystrcmp(const char s1[] ,const char s2[] )
{
	int i = 0 ;

	while (s1[i]== s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	//return (s1[i]-s2[i]); //TC下约定
	return sign(s1[i]-s2[i]);//VC下约定
}

//返回变量x的符号
int sign(int x)
{
	if (x > 0)
		return 1;
	else if (x < 0)
		return -1;
	else 
		return 0;
}


main()
{
	char s1[20]="china" , s2[10] = "China";

	//mystrcat(s1,s2);
	//mystrcpy3(s1,s2);
	//puts(s1);
	//printf("字符串s1的长度：%d\n" ,strlen(s1));
	//printf("字符串s1的长度：%d\n" ,mystrlen(s1));


	printf("%d\n" , strcmp(s1,s2));
	printf("%d\n" , mystrcmp(s1,s2));
	
	if (strcmp(s1,s2) == 0)
		printf("相等\n");
	else if (mystrcmp(s1,s2) > 0)
		printf("S1 > S2\n");
	else 
		printf("S1< S2\n");

}



