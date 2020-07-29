/*以下注释的内容可以保存在排序函数.c的文件中
  用文件包含进行reuse

//冒泡法排序 ,约定舍弃数组的0号元素,n是数组的实际元素个数
void bubblesort(int a[] ,int n)
{
	int i , j , temp;
	int flag =1; //记录是否有交换

	//外层循环控制比较的趟数，一共n-1趟
	for (j = 1 ; j < n && flag == 1  ; j++) //
	{
		flag = 0 ;//假设本趟没有交换

		//内层循环控制每一趟比较的次数(n-j次)
		for(i = 1 ; i <= n-j ; i ++ )
		{
			if (a[i] > a[i+1]) //逆序交换
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp ;
				flag = 1 ;//有交换，要进行下一趟			
			}		
		}	
	}
}
*/
#include "排序函数.c"

main()
{
	int i , array[10] = {0,88,99,77,44,66,55,11,22,33};

	bubblesort(array ,9);

	for(i = 1 ; i <= 9 ; i++)
		printf ("%d\t" , array[i]);
}