//��֤6��100֮�ڵ�����ż���ܹ����Ϊ2������֮��
//��������.c�ļ�����ԭ���汾�е�isPrimeFun(int n)
//ͨ���ļ�����ʵ��reuse(���á�����)

#include "��������.c"

main()
{
	int i ,j ;

	for ( i = 6; i <= 100 ; i += 2)  //���ż��
	{
		for ( j = 3 ; j <= i/2 ; j += 2) // ���Ѱ��һ�����ԣ�j, i-j����������
		{
			if ( primeFun(j) && primeFun(i-j))
			{
				printf("%d + %d = %d\n" , j , i-j ,i);
				break;
			}
		}
	}
}