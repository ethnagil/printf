/*                                                        :::      ::::::::   */
/*   functest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp </var/mail/egillesp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:33:06 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/12 15:35:08 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef void *(*flag_function)(char *, char);

void *ft_y(char *str, char sp)
{
	int i;

	printf("sp %c\n", sp);
	i = 0;
	while (str[i] == '0')
		str[i++] = 'y';
	return(str);
}

void *ft_zero(char *str, char sp)
{
	int i;
   
	printf("sp %c\n", sp);
	i = 0;
	while (i < 9) 
	{
		if (str[i] == 32)
		{
		str[i] = '0';
		}
		i++;
	}
	return(str);
}

int	ft_functest(char *str, void *(*flag)(char *, char))
{
	char *str2;
	char sp = 's';

		if (!flag)
					return(-1) ;
		printf("str %s\n", str);
		str = flag(str, sp);
		printf("str2 %s\n", str);
		return(1);
}

int	main()
{
	char *str;
	flag_function current[3];

	current[0] = &ft_y;
	current[1] = &ft_zero;

	str = (char *)malloc(sizeof (char) * 20);
	str[0] = ' ';
	str[1] = ' ';
	str[2] = 'h';
	str[3] = 'i';
	str[4] = '\0';
	ft_functest(str, current[1]);
	ft_functest(str, current[0]);
	free(str);
	printf("%6.8f\n", 123.123);
	printf("%d\n", (int)123.222);
	printf("%f\n", 123.222 - (int)123.222);
	return (0);
}
