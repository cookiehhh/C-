# include <stdio.h>
#define N  1000000

main()
{
	int up = 0 , down = 0 , i , r ;

	srand((unsigned)time(NULL));  //����ʱ�亯��������

	for (i = 1 ; i <= N ; i++)
	{
		r = 1 + rand() % 100 ; //���������1-100

		if (r <= 50)
			up ++ ;
		else 
			down ++ ;	
	}

	printf("һ��ģ����%d��\n", N);
	printf("����%d��\n", up);
	printf("����%d��\n", down);
}