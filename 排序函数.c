//ð�ݷ����� ,Լ�����������0��Ԫ��,n�������ʵ��Ԫ�ظ���
void bubblesort(int a[] ,int n)
{
	int i , j , temp;
	int flag =1; //��¼�Ƿ��н���

	//���ѭ�����ƱȽϵ�������һ��n-1��
	for (j = 1 ; j < n  && flag == 1 ; j++)
	{
		flag = 0 ;//���豾��û�н���

		//�ڲ�ѭ������ÿһ�˱ȽϵĴ���(n-j��)
		for(i = 1 ; i <= n-j ; i ++ )
		{
			if (a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp ;
				flag = 1 ;//�н�����Ҫ������һ��			
			}		
		}	
	}
}

//ѡ������ ,Լ�����������0��Ԫ��,n�������ʵ��Ԫ�ظ���
void selectsort(int a[] ,int n)
{
	int i , j ,min ,temp;//min������СԪ�ص��±�

	//�����ƱȽϵ�������һ��n-1��
	for (i = 1 ; i < n ; i++)
	{
		min = i ; //�ȼ���i��Ԫ����С

		//�ڲ����ÿһ�˱ȽϵĴ���
		for ( j = i+1 ; j <= n; j++)
		{
			if (a[j] < a [min])
				min = j ;		
		}//end for j

		if (min != i)//���i��Ԫ�ز�����С������
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;		
		}	
	}//end for i
}//end selectsort
