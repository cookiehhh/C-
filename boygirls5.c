//�汾5��һ�δӼ�������������,�������
main()
{
	int boys , girls , sum ; //��������
	float ratio1 , ratio2 ;

	printf("������������  Ů������");
	scanf("%d;%d" , &boys , &girls);   //&boys��&girls������ǰҪ�ӵ�ַ����&

	sum = boys + girls ;
	ratio1 = (float)boys / sum *100;
	//ratio2 = (float)girls / sum *100;
	ratio2 = 100.0 * girls / sum ;

	printf("�༶������ = %d\n" , sum);
	printf("�������� = %d, ���� = %.2f %%\n" , boys ,ratio1);
	printf("Ů������ = %d, ���� = %.2f %%\n" , girls,ratio2);
}