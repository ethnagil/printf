/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/19 17:35:45 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_variable(const char *format, va_list args, int *f)
{
	char	convert[MAXCONV];
	char	*printstr;
	int		len;

	*f = *f + 1;
	printstr = NULL;
	*f = ft_readconvert(convert, format, *f, args);
 	if (format[*f])
 	{
 		printstr = ft_va_argtostr(format[*f], convert, args);
 		ft_putstr_fd(printstr, 1);
 		len = ft_strlen(printstr);
		if (printstr)
			free(printstr);
		return (len);
	}
	return(0);
 }

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		f;
	int		len;

	len = 0;
	va_start(args, format);
	f = 0;
	while (format[f])
	{
		if (format[f] == '%')
	//	{
			len += ft_print_variable(format, args, &f);
	//		printstr = ft_variable(format, args, &n);
	//		i = ft_readconvert(convert, format, ++i, args);
	//		if (format[i])
	//		{
	//			printstr = ft_va_argtostr(format[i], convert, args);
	//			ft_putstr_fd(printstr, 1);
	//			n = n + ft_strlen(printstr);
	//		}
	//	}
		else
		{
			ft_putchar_fd(format[f], 1);
			len++;
		}
		if (format[f])
			f++;
	}
//		free(printstr);
	va_end(args);
	return (len);
}
