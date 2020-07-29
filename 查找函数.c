//顺序查找
//elem数组中0号元素用作监视哨，实际有length个元素
int search_seq(int elem[] , int length , int key)
{
	int i ;

	elem[0] = key ;//0号位置作为监视哨

	for ( i = length ; elem[i] != key ; --i	)
		;

	return i;
}

//折半查找
//elem数组中舍弃0号元素，实际有length个元素
int search_bin(int elem[] , int length , int key)
{
	int mid , low = 1 , high = length;

	while (low <= high)
	{
		mid = (low + high)/2 ;
		if (key == elem[mid])
			return mid ; //找到
		else if (key < elem[mid])
			high = mid -1 ;
		else 
			low = mid + 1;	
	}
	return 0; //未找到，返回0
}

