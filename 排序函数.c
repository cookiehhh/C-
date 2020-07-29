//冒泡法排序 ,约定舍弃数组的0号元素,n是数组的实际元素个数
void bubblesort(int a[] ,int n)
{
	int i , j , temp;
	int flag =1; //记录是否有交换

	//外层循环控制比较的趟数，一共n-1趟
	for (j = 1 ; j < n  && flag == 1 ; j++)
	{
		flag = 0 ;//假设本趟没有交换

		//内层循环控制每一趟比较的次数(n-j次)
		for(i = 1 ; i <= n-j ; i ++ )
		{
			if (a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp ;
				flag = 1 ;//有交换，要进行下一趟			
			}		
		}	
	}
}

//选择法排序 ,约定舍弃数组的0号元素,n是数组的实际元素个数
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
