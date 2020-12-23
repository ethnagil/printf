/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/23 18:01:22 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_va_argtostr(char spec, char *convert, va_list args, int *cnull)
{
	char *prstr;

	prstr = NULL;
	if (spec == 'c')
	{
		prstr = ft_c_to_str((unsigned char)va_arg(args, int), cnull, convert);
	}
	else if (spec == 's')
		prstr = ft_strdup(va_arg(args, char *));
	else if (spec == 'p')
		prstr = ft_itoa_base(va_arg(args, long long), HEXLOW);
	else if (spec == 'd' || spec == 'i')
		prstr = ft_itoa_base((long long)(va_arg(args, int)), TEN);
	else if (spec == 'u')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), TEN);
	else if (spec == 'x')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), HEXLOW);
	else if (spec == 'X')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), HEX);
	else if (spec == '%')
		prstr = ft_strdup("%");
	if (!prstr)
		prstr = ft_strdup("(null)");
	prstr = ft_apply_convert(prstr, convert, spec);
	return (prstr);
}

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
