//�汾3����׳ˣ��õݹ�

main()
{
	int n  ;
	double time; 
	double factfun(int n);//��������

	n = input();
	time =  factfun(n); 

	printf("n = %d ,  n! = %.0f\n" , n , time);
	printf("��Ҫ%.0f����\n" ,time);
	printf("��Ҫ%.0f��\n" ,time/1e9);
	printf("��Ҫ%.0f����\n" ,time/1e9/60);	
	printf("��Ҫ%.0fСʱ\n" ,time/1e9/60/60);
	printf("��Ҫ%.0f��\n" ,time/1e9/60/60/24);	
	printf("��Ҫ%.0f��\n" ,time/1e9/60/60/24/365);
}

//����һ������
int input()
{
	int n ;

	do
	{
		printf("�ж��ٸ���ĸ��Ҫ��������һ����������");
		scanf("%d" , &n);
		if (n <= 0)
			printf("�������%d����һ��������\n",n);
	}while( n <= 0);

	return n;
}

//��n!
double factfun(int n)
{
	if (n == 1 || n == 0) //�ݹ���ֹ����
		return 1 ;
	else   //�ݹ鹫ʽ
		return factfun(n-1) * n ; 
}
