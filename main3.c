#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	
	printf("1-pp %.10d\n", -12345);
	ft_printf("2-fp %.10d\n", -12345);
	
	printf("1a-pp %.10d\n", 123);
	ft_printf("2a-fp %.10d\n", 123);

	printf("%5x", 52625);
	ft_printf("%5x", 52625);

	printf("g %-70p\n",&a01);

	//printf("a %08.5i\n", 34);
//printf("b %010.5i\n", -216);
//printf("c %08.5i\n", 0);
//printf("d %08.3i\n", 8375);
//printf("e %08.3i\n", -8473);
//printf("f %08i\n", -8473);

	//ft_printf("a2%08.5i\n", 34);
//ft_printf("b2%010.5i\n", -216);
//ft_printf("c2%08.5i\n", 0);
//ft_printf("d2%08.3i\n", 8375);
//ft_printf("e2%08.3i\n", -8473);
//ft_printf("f2%08i\n", -8473);



	while (1)
	{
		;
	}
	
	return (0);
}