#define N  3

void listPayment(int p[])
{
	int i ;

	for (i = 0 ; i < N ; i++)
		printf("%d\t" , p[i]);
}

//��ĳ���ǹ���
void add(int x)
{
	x += 1000;
	printf("%d\n" ,x);
}

//���������ǹ���
void addall(int p[])// int p[] = int *p
{
	int i ;

	for (i = 0 ; i < N ; i++)
	{
		p[i] += 1000;
		printf("%d\t" , p[i]);	
	}		
}

main()
{
	int payment[N] = {800,900,1000};

	listPayment(payment);

	add(payment[0]);//����Ԫ����ʵ�Σ���ֵ����
	printf("%d\n" ,payment[0]);//��Ȼ�βθı䣬����Ӱ��ʵ��

	addall(payment);//��������ʵ�Σ��ǵ�ַ����
	listPayment(payment);//���β�����Ԫ�صĸı䣬Ӱ��ʵ������Ԫ��

}