//��֤6��100֮�ڵ�����ż���ܹ����Ϊ2������֮��
//��������.c�ļ�����ԭ���汾�е�primeFun(int n)
//ͨ���ļ�����ʵ��reuse(���á�����)

#include "��������.c"

main()
{
	int i ,j ;
	int count = 0 ;

	for ( i = 50000 ; i <=60000 ; i += 2)
	{
		int checked = 0 ; //i��δ��֤����־����ֵΪ0
		for ( j = 3 ; checked == 0 && j <= i/2 ; j += 2)
		{
			if ( primeFun(j) && primeFun(i-j))
			{
				printf("%d + %d = %d\n" , j , i-j ,i);
				checked = 1 ;//i������֤����־����ֵΪ1
			}
		}
		if (checked == 0)
		{
			count ++ ;
			printf("���췢�֣�%d�����ϸ�°ͺղ��룡\n" ,i);
		}
	}
	if (count == 0)
		printf("������֤������ż�������ϸ�°ͺղ���.\n");
	else 
		printf("���췢�֣���%d���������ϸ�°ͺղ��룡\n" ,count);
}