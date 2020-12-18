/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/18 19:34:20 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/* need to remove 3 more lines */


int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	convert[MAXCONV];
	char	*printstr;

	printstr = NULL;
//	if (!format)
//		return(0);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i = ft_readconvert(convert, format, i, args);
			if (format[i])
			{
				printstr = ft_va_argtostr(format[i], convert, args);
				if (printstr)
					ft_putstr_fd(printstr, 1);
			}
		}
		else
			ft_putchar_fd(format[i], 1);
		if (format[i])
			i++;
	}
	if (printstr)
		free(printstr);
	va_end(args);
	return (0);
}
