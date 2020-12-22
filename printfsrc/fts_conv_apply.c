/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_conv_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:00:21 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/22 17:35:13 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_readconvert(char *convert, const char *format, int f, va_list args)
{
	int		j;
	int		k;
	char	*wildcard;

	ft_bzero(convert, MAXCONV);
	j = 0;
	while ((ft_elementof((char)format[f], FLAGS)) ||
		(ft_isdigit(format[f]) || (format[f] == '.')) ||
		(ft_elementof((char)format[f], L_MODIFIER)))
	{
		if (format[f] == '*')
		{
			k = 0;
			wildcard = ft_itoa_base((long long)va_arg(args, int), TEN, 0);
			while (wildcard[k])
				convert[j++] = wildcard[k++];
			j--;
		}
		else
			convert[j] = format[f];
		j++;
		f++;
	}
	return (f);
}

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
//		prstr = ft_flag_hash(ft_itoa_base(va_arg(args, long long), hex, 0), spec);
		prstr = ft_itoa_base(va_arg(args, long long), hex, 0);
	else if (spec == 'd' || spec == 'i')
		prstr = ft_itoa_base((long long)(va_arg(args, int)), TEN, 0);
	else if (spec == 'u')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), TEN, 0);
	else if (spec == 'x')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), hex, 0);
	else if (spec == 'X')
		prstr = ft_itoa_base((long long)(va_arg(args, unsigned int)), HEX, 0);
	else if (spec == '%')
		prstr = ft_strdup("%");
	if (!prstr)
		prstr = ft_strdup("(null)");
	prstr = ft_apply_convert(prstr, convert, spec);
	return (prstr);
}

char	*ft_apply_convert(char *prstr, char *convert, char spec)
{
//	flag_function	convert_fts[ft_strlen(convert)];
	flag_function	*convert_fts;
	int				specifier1;
	int				specifier2;
	int				i;

	convert_fts = malloc(sizeof(flag_function) * (ft_strlen(convert) + 1));
	if (!convert_fts)
		return (0);
	i = 0;
	if (ft_check_convert(convert, spec))
	{
		ft_build_convert(convert_fts, convert, &specifier1, &specifier2);
		prstr = ft_run_length(prstr, specifier1, specifier2, spec);
		while (convert_fts[i])
		{
			prstr = convert_fts[i++](prstr, spec);
		}
	}
	if (spec == 'p')
		prstr = ft_flag_hash(prstr, spec);
	free(convert_fts);
	return (prstr);
}

int		ft_check_convert(char *convert, char spec)
{
	int i;

	(void)spec;
	i = 0;
	while (convert[i])
	{
		if ((convert[i] == '0') && ((ft_elementof('-', convert)) || (ft_elementof('.', convert))))
		{
			while (convert[i])
			{
				convert[i] = convert[(i) + 1];
				i++;
			}
		}
		if ((convert[i] == '.') || (!convert[i]) || ((convert[i] != '0') && ft_isdigit(convert[i])))
				break;
//		if (convert[i])
			i++;
	}
	return (1);
}

void	ft_build_convert(flag_function *convert_fts, char *convert,
		int *specifier1, int *specifier2)
{
	int i;
	int neg;

	i = 0;
	neg = 1;
	*specifier1 = 0;
	*specifier2 = 0;
	while ((ft_elementof((char)convert[i], FLAGS)))
	{
		if (convert[i] == '-')
			convert_fts[i] = &ft_flag_neg;
		if (convert[i] == ' ')
			convert_fts[i] = &ft_flag_space;
		if (convert[i] == '0')
			convert_fts[i] = &ft_flag_zero;
		i++;
	}
	convert_fts[i] = NULL;
	while (ft_isdigit(convert[i]))
		*specifier1 = ((*specifier1 * 10) + (convert[i++] - 48));
	if (convert[i++] == '.')
	{
		if (convert[i] == '-')
		{
			neg = -1;
			i++;
		}
		else if (!ft_isdigit(convert[i]))
			*specifier2 = 'n';
		while (ft_isdigit(convert[i]))
				*specifier2 = ((*specifier2 * 10) + (convert[i++] - 48));
		*specifier2 *= neg;
		if (*specifier2 == 0)
			*specifier2 = 'n';
	}
}
