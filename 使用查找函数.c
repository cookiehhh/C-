/* ����2���������浽�ļ�   ���Һ���.c �У�����reuse

//elem������0��Ԫ�����������ڣ�ʵ����length��Ԫ��
int search_seq(int elem[] , int length , int key)
{
	int i ;

	elem[0] = key ;//0��λ����Ϊ������

	for ( i = length ; elem[i] != key ; --i	)
		;

	return i;
}

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
*/

#define N 10
#include "���Һ���.c"

main()
{
	int key , arr[N+1] = {0, 5,7,19,21, 22, 33, 44,55,66,77};
	int location;

	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d" , &key);
	location = 	search_seq(arr , N ,key);
	//location = 	search_bin(arr , N ,key);

	if (location == 0)
		printf("δ�ҵ�%d\n" ,key);
	else 
		printf("�ҵ�%d,�ڵ�%d��λ��\n" ,key,location);
}