/* 以下2个函数保存到文件   查找函数.c 中，便于reuse

//elem数组中0号元素用作监视哨，实际有length个元素
int search_seq(int elem[] , int length , int key)
{
	int i ;

	elem[0] = key ;//0号位置作为监视哨

	for ( i = length ; elem[i] != key ; --i	)
		;

	return i;
}

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
*/

#define N 10
#include "查找函数.c"

main()
{
	int key , arr[N+1] = {0, 5,7,19,21, 22, 33, 44,55,66,77};
	int location;

	printf("请输入要查找的数据：");
	scanf("%d" , &key);
	location = 	search_seq(arr , N ,key);
	//location = 	search_bin(arr , N ,key);

	if (location == 0)
		printf("未找到%d\n" ,key);
	else 
		printf("找到%d,在第%d个位置\n" ,key,location);
}