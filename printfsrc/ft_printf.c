/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/22 17:21:17 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_variable(const char *format, va_list args, int *f)
{
	char	convert[MAXCONV];
	char	*printstr;
	int		len;
	int		cnull;

	*f = *f + 1;
	printstr = NULL;
	cnull = 0;
	*f = ft_readconvert(convert, format, *f, args);
	if (format[*f])
	{
		printstr = ft_va_argtostr(format[*f], convert, args, &cnull);
		len = ft_strlen(printstr);
		if (cnull == -1)
			ft_putchar_fd('\0', 1);
		ft_putstr_fd(printstr, 1);
		if (cnull == 1)
			ft_putchar_fd('\0', 1);
		if (cnull != 0)
			len++;
		if (printstr)
			free(printstr);
		return (len);
	}
	return (0);
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
			len += ft_print_variable(format, args, &f);
		else
		{
			ft_putchar_fd(format[f], 1);
			len++;
		}
		if (format[f])
			f++;
	}
	va_end(args);
	return (len);
}
