/*����ע�͵����ݿ��Ա�����������.c���ļ���
  ���ļ���������reuse


//ѡ������ , Լ�����������0��Ԫ��,n�������ʵ��Ԫ�ظ���
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
*/

#include "������.c"

main()
{
	int i , array[10] = {0,88,99,77,44,66,55,11,22,33};

	selectsort(array ,9);
	//bubblesort(array ,9);

	for(i = 1 ; i <= 9 ; i++)
		printf ("%d\t" , array[i]);
}