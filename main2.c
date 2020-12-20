#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	printf("p0 % .3s\n", "cccc");
	ft_printf("f0 % .3s\n", "cccc");
	printf("pp %.50d\n", 10000);
	ft_printf("fp %.50d\n", 10000);
	return (0);
}
