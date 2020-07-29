main()
{
	int men , women , children ;

	for (men = 0 ; men < 36/4 ; men++)
		for (women = 0 ; women < 36 / 3 ; women ++ )
		{
			children = 36 - men - women;

			if (men *4+ women * 3 + children /2.0 == 36)
				printf("%d\t%d\t%d\n",men , women , children);
		}
}