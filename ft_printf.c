/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:44:59 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/14 18:22:23 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

/*
** while loop to read each character in string passed to ft_printf{          **
** 		if  not %, putstr {
** 			if %, pass to ft_format_string {
					while element of flags
**						for each letter, add function to convert[*]
							test for overrides (0 ignored if -)
					while numeric
						create 1st precision
					if '.'
						while numeric
							create 2nd precision
					while element of length modifier
						add function to convert
					if element of specifiers
							ft_va_argcall - get argument & convert to string
							ft_precision - convert to specified precision
							ft_runconvert
							ft_putstr
			}
		}
	}
*/



#DEFINE FLAGS "-0 ";
#DEFINE L_MOFIFIER "lh";
#DEFINE SPECIFIER "cspdiuxX";
#DEFINE TEN "0123456789";
#DEFINE HEX "0123456789ABCDEF";
#DEFINE hex "0123456789abcdef";
typedef void *(*flag_function)(char *, char);

char *ft_flag_neg(char *str, char sp)
{
	str = ft_strjoin(str, "-neg");
	return (str);
}

char *ft_flag_space(char *str, char sp)
{
	str = ft_strjoin(str, "-space");
	return (str);
}

char *ft_flag_zero(char *str, char sp)
{
	str = ft_strjoin(str, "-zero");
	return (str);
}

char *ft_flag_hash(char *str, char sp)
{
	str = ft_strjoin(str, "-hash");
	return (str);
}

char	*ft_itoa_base(long long int n, char *base)
{
	char		*str;
	long long	i;
	char		neg;

	neg = 0;
	i = ft_strlen(base);
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (2 + neg)))
		return (NULL);
	if (n >= i)
		str = ft_strjoin(ft_itoa_base(n / i, base), ft_itoa_base(n % i, base));
	else if (n < i)
	{
		if (neg = 1)
			str[0] = '-';
		str[0 + neg] = base[n];
		str[1 + neg] = '\0';
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if ((s3 = (char *)malloc(sizeof(char) * (i + 1))) != 0)
	{
		i = 0;
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
		s3[i] = '\0';
		if (s1)
			free(s1);
		return (s3);
	}
	return (0);
}

char *ft_build_convert(flag_function **convert_fts, char *convert, int *specifier1, 
		int *specifier2)
{
	int i;

	i = 0;
	*specifier1 = 0;
	*specifier2 = 0;
	while ((ft_elementof((char)convert[i], FLAGS)) 
	{
		if (convert[i] = '-')
			convert_fts[i] = &ft_flag_neg;
		if (convert[i] = ' ')
			convert_fts[i] = &ft_flag_space;
		if ((convert[i] = '0') && (!ft_elementof('-', convert)))
			convert_fts[i] = &ft_flag_zero;
		if (convert[i] = '#')
			convert_fts[i] = &ft_flag_hash;	
		i++;
	}
	convert[i] = NULL;
	while ((ft_numeric(convert[i]) 
		*specifier1 = (*specifier1 * 10) + (format[i++] - 48);
	if 	(convert[i] = '.')
		while ((ft_numeric(convert[i]) 
			*specifier2 = (*specifier2 * 10) + (format[i++] - 48);
	/* add length modifiers here */
	}
}

char *ft_apply_convert(char *printstr, char *convert, char spec)
{
	flag_function	convert_fts[ft_strlen(convert)];
	int				specifier1;
	int				specifier2;
	int				i;

	i = 0;
	/* add pointers to functions in table and calculate length specifiers */
	ft_build_convert(convert_fts, convert, &specifier1, &specifier2);
	/* modifiy the string with length specifiers */
	printstr = ft_run_length(printstr, specifier1, specifier2, spec);
	/* run conversion functions */
	while (convert_fts[i])
		printstr = convert_fts[i](printstr, spec);
	return (printstr);
}

int		ft_elementof(char c, char *elements)
{
		int i;

		i = 0;
		while(elements[i])
		{
			if (elements[i] == c)
				return (1);
			i++;
		}
		return (0);
}

char *ft_va_argostr(char spec, char *convert, va_list args)
{
	char *printstr;

	printstr = NULL;
	if (c == 'c')
		printstr = ft_strdup((char *)va_arg(args, int));
	else if (c == 's')
		printstr = ft_strdup(va_arg(args, char *));
	else if (c == 'p')
		printstr = ft_itoa_base(va_arg(args, long long), TEN);
	else if (c == 'd' || c == 'i')
		printstr = ft_itoa_base((long long)va_arg(args, int), TEN);
	else if (c == 'u')
		printstr = ft_itoa_base((long long)va_arg(args, unsigned int, TEN),
		flags);
	else if (c == 'x')i
		printstr = ft_itoa_base((long long)va_args(args, unsigned int), hex);
	else if (c == 'X')
		printstr = ft_itoa_base((long long)va_args(args, unsigned int), HEX);
	else if (c == '%')
		printstr = ft_strdup("%");
	if (printstr)
		printstr = ft_apply_convert(printstr, convert, spec);
	else
		return (0);
	return (printstr);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	convert[15];

	va_start(ap, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while ((ft_elementof((char)format[i], FLAGS)) ||
					((ft_numeric(format[i]) || (format[i] = '.')) ||
					((ft_elementof((char)format[i], L_MODIFIER))
				convert[j++] = format[i++]; 
			if ((ft_elementof((char)format[i], SPECIFIER))
				ft_putstr(ft_va_argtostr(format[i], convert);
			else
				printf("format error\n");
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(ap);
	return (0);
}

