main()
{
	int rooster , hen , chicken ;

	for ( rooster = 0 ; rooster < 100 / 5 ; rooster ++ )
		for ( hen = 0 ; hen < 100 / 3 ; hen ++)
		{
			chicken = 100 - rooster - hen ;

			if (rooster *5 + hen *3 + (double)chicken / 3 == 100 )
				printf ("%d\t%d\t%d\n" ,rooster , hen , chicken );

		}

}