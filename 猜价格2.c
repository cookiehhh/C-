main()
{
	int price = 80 , guessPrice;

	printf("ÇëÊäÈë¼Û¸ñ(1-100)£º");
	scanf("%d", &guessPrice);


	if ( price == guessPrice)
		printf("ÄãÓ®ÁË£¡\n");	
	else 
		printf("ÄãÊäÁË£¡\n");

	/*
	if ( price != guessPrice)
		printf("ÄãÊäÁË£¡\n");	
	else 
		printf("ÄãÓ®ÁË£¡\n");
	*/
	printf("Game over!\n");
}