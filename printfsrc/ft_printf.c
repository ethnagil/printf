/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2021/01/08 18:23:23 by egillesp         ###   ########lyon.fr   */
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
		prstr = ft_itoa_basep(va_arg(args, unsigned long long), HEXLOW);
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

int		ft_wildcard(int value, char *convert, char dot, int j)
{
	char	*wildcard;
	int		k;

	k = 0;
	if ((value < 0) && (dot == '.'))
	{
		convert[j - 1] = 0;
		return (j - 1);
	}
	wildcard = ft_itoa_base((long long)value, TEN);
	if (!wildcard)
		return (j);
	while (wildcard[k])
		convert[j++] = wildcard[k++];
	free(wildcard);
	return (j);
}

int		ft_readconvert(char *convert, const char *format, int f, va_list args)
{
	int		j;
	int		value;
	char	dot;

	ft_bzero(convert, MAXCONV);
	j = 0;
	while (ft_elementof((char)format[++f], FLAGS))
		if (!(ft_elementof((char)format[f], convert)))
			convert[j++] = format[f];
	while ((ft_isdigit(format[f])) || (ft_elementof((char)format[f], "-.")) ||
		(ft_elementof((char)format[f], L_MODIFIER)))
	{
		if (format[f] == '*')
		{
			dot = format[f - 1];
			value = va_arg(args, int);
			j = ft_wildcard(value, convert, dot, j);
			f++;
		}
		else
			convert[j++] = format[f++];
	}
	return (f);
}

int		ft_print_variable(const char *format, va_list args, int *f)
{
	char	convert[MAXCONV];
	char	*printstr;
	int		len;
	int		cnull;

	printstr = NULL;
	cnull = 0;
	*f = ft_readconvert(convert, format, *f, args);
	if ((format[*f]) && (*f > 0))
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
