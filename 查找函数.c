//˳�����
//elem������0��Ԫ�����������ڣ�ʵ����length��Ԫ��
int search_seq(int elem[] , int length , int key)
{
	int i ;

	elem[0] = key ;//0��λ����Ϊ������

	for ( i = length ; elem[i] != key ; --i	)
		;

	return i;
}

//�۰����
//elem����������0��Ԫ�أ�ʵ����length��Ԫ��
int search_bin(int elem[] , int length , int key)
{
	int mid , low = 1 , high = length;

	while (low <= high)
	{
		mid = (low + high)/2 ;
		if (key == elem[mid])
			return mid ; //�ҵ�
		else if (key < elem[mid])
			high = mid -1 ;
		else 
			low = mid + 1;	
	}
	return 0; //δ�ҵ�������0
}

