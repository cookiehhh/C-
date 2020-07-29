//ʵ��strcpy�ַ������ƵĹ���,�汾1
void mystrcpy(char s1[] ,const char s2[] )
{
	int i = 0 ;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i] ;//����ַ�����
		i++;
	}
	s1[i] = '\0';//�ַ���������־
}

//ʵ��strcpy�ַ������ƵĹ���,�汾2
void mystrcpy2(char *s1,const char *s2 )
{
	int i = 0 ;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i] ;//����ַ�����
		i++;
	}
	s1[i] = '\0';//�ַ���������־
}

//ʵ��strcpy�ַ������ƵĹ���,�汾3
void mystrcpy3(char *s1,const char *s2 )
{
	while (*s2 != '\0')
	{
		*s1 = *s2 ;//����ַ�����
		s1++;
		s2++;
		//*s1 ++ = *s2 ++ ;//�������п��Լ�Ϊһ��
	}
	*s1 = '\0';//�ַ���������־
}

//ʵ��strcat�ַ������ӵĹ���
void mystrcat(char s1[] ,const char s2[] )
{
	int i = 0 , j = 0 ;

	while (s1[i] != '\0')//��s1��β
		i++;

	while (s2[j] != '\0')
	{
		s1[i] = s2[j] ;//����ַ�����
		i++;
		j++;
	}
	s1[i] = '\0';//�ַ���������־
}

//ʵ��strlen���ַ������ȵĹ���
int  mystrlen(const char s1[] )
{
	int i = 0 ;

	while (s1[i] != '\0')
	{
		i++;
	}
	return i;
}

//ʵ��strcmp�ַ����ȽϵĹ���
int  mystrcmp(const char s1[] ,const char s2[] )
{
	int i = 0 ;

	while (s1[i]== s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	//return (s1[i]-s2[i]); //TC��Լ��
	return sign(s1[i]-s2[i]);//VC��Լ��
}

//���ر���x�ķ���
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
	//printf("�ַ���s1�ĳ��ȣ�%d\n" ,strlen(s1));
	//printf("�ַ���s1�ĳ��ȣ�%d\n" ,mystrlen(s1));


	printf("%d\n" , strcmp(s1,s2));
	printf("%d\n" , mystrcmp(s1,s2));
	
	if (strcmp(s1,s2) == 0)
		printf("���\n");
	else if (mystrcmp(s1,s2) > 0)
		printf("S1 > S2\n");
	else 
		printf("S1< S2\n");

}



