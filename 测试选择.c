/*以下注释的内容可以保存在排序函数.c的文件中
  用文件包含进行reuse


//选择法排序 , 约定舍弃数组的0号元素,n是数组的实际元素个数
void selectsort(int a[] ,int n)
{
	int i , j ,min ,temp;//min保存最小元素的下标

	//外层控制比较的趟数，一共n-1趟
	for (i = 1 ; i < n ; i++)
	{
		min = i ; //先假设i号元素最小

		//内层控制每一趟比较的次数
		for ( j = i+1 ; j <= n; j++)
		{
			if (a[j] < a [min])
				min = j ;		
		}//end for j

		if (min != i)//如果i号元素不是最小，交换
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;		
		}	
	}//end for i
}//end selectsort
*/

#include "排序函数.c"

main()
{
	int i , array[10] = {0,88,99,77,44,66,55,11,22,33};

	selectsort(array ,9);
	//bubblesort(array ,9);

	for(i = 1 ; i <= 9 ; i++)
		printf ("%d\t" , array[i]);
}