main()
{
	int rooster , hen , chicken ;

	for (rooster = 0 ; rooster < 100/5 ; rooster++)
	{
		for (hen = 0 ; hen < 100 / 3 ; hen ++ )
		{
			for ( chicken = 0 ; chicken < 100 ; chicken ++ )
			{
				if ((rooster *5 + hen * 3 + chicken /3.0 ==100 ) && (rooster + hen + chicken == 100) )
					printf("%d\t%d\t%d\n",rooster , hen , chicken);
			}
		}
	}
}